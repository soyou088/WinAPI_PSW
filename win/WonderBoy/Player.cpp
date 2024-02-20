#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"



void APlayer::AddMoveVector(const FVector& _DirDelta)
{
	MoveVector += _DirDelta * MoveAcc;
}

void APlayer::CalMoveVector(float _DeltaTime)
{
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}
	CheckPos.Y -= 30;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	if (true == UEngineInput::IsFree(VK_LEFT) && true == UEngineInput::IsFree(VK_RIGHT))
	{
		if (0.001 <= MoveVector.Size2D())
		{
			MoveVector += (-MoveVector) * _DeltaTime * MoveAcc; // 감속하는 코드
		}
		else {
			MoveVector = float4::Zero;
		}
	}

	if (MoveMaxSpeed <= MoveVector.Size2D())
	{
		MoveVector = FVector::Zero;
	}
}

void APlayer::MoveLastMoveVector(float _DeltaTime)
{
	// 카메라는 x축으로만 움직여야 하니까.


	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
	AddActorLocation(LastMoveVector * _DeltaTime);

}

void APlayer::CalLastMoveVector(float _DeltaTime)
{
	// 제로로 만들어서 초기화 시킨다.
	LastMoveVector = FVector::Zero;
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
	LastMoveVector + JumpVector;
}

void APlayer::MoveUpdate(float _DeltaTime)
{
	CalMoveVector(_DeltaTime); // 움직임 계산 값
	CalGravityVector(_DeltaTime);// 중력 계산 값
	CalLastMoveVector(_DeltaTime); // 다 던한 값
	MoveLastMoveVector(_DeltaTime); // 카메라
	// 이동을 하고 났더니 내가 땅에 처박혀 있을수 있죠?
}

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();

	// 카메라 세팅
	GetWorld()->AddCameraPos({ 0, 540 });



	Renderer = CreateImageRenderer(WonderRenderOrder::Player);
	Renderer->SetImage("Player_R.png");
	Renderer->SetTransform({ {0,0}, {200, 200} });

	Renderer->CreateAnimation("Idle_Right", "Player_R.png", 0, 1, 0.1f, true); // 가만히 있는 상태
	Renderer->CreateAnimation("Move_Right", "Player_R.png", 1, 5, 0.1f, true); // 오른쪽으로 움직이는 상태

	Renderer->CreateAnimation("Idle_Left", "Player_L.png", 0, 1, 0.1f, true); // 가만히 있는 상태
	Renderer->CreateAnimation("Move_Left", "Player_L.png", 1, 5, 0.1f, true); // 왼쪽으로 움직이는 상태

	Renderer->CreateAnimation("Jump_Right", "Player_R.png", 5, 5, 0.1f, true); // 오른쪽으로 점프하기
	Renderer->CreateAnimation("Jump_Left", "Player_L.png", 5, 5, 0.1f, true); // 왼쪽으로 점프하기

	Renderer->ChangeAnimation("Idle_Right"); // 가만히 있는상태


	StateChange(EPlayState::Idle);
}

void APlayer::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA)
	{
		GravityVector = FVector::Zero;
	}

}

void APlayer::DirCheck()
{
	EActorDir Dir = DirState;
	if (UEngineInput::IsPress(VK_LEFT))
	{
		Dir = EActorDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		Dir = EActorDir::Right;
	}

	if (Dir != DirState)
	{
		DirState = Dir;
		std::string Name = GetAnimationName(CurAnimationName);
		Renderer->ChangeAnimation(Name);
	}
}


std::string APlayer::GetAnimationName(std::string _Name)
{
	std::string DirName = "";

	switch (DirState)
	{
	case EActorDir::Left:
		DirName = "_Left";
		break;
	case EActorDir::Right:
		DirName = "_Right";
		break;
	default:
		break;
	}

	CurAnimationName = _Name;

	return _Name + DirName;

}

void APlayer::IdleStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Idle"));
	DirCheck();
}

void APlayer::MoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Move"));
	DirCheck();
}

void APlayer::JumpStart()
{
	JumpVector = JumpPower;
	Renderer->ChangeAnimation(GetAnimationName("Jump"));
	DirCheck();

}

void APlayer::StateChange(EPlayState _State)
{
	// 이전상태와 지금 상태가 같지 않아
	// 이전에는 move 지금은 Idle
	if (State != _State)
	{
		switch (_State)
		{
		case EPlayState::Idle:
			IdleStart();
			break;
		case EPlayState::Move:
			MoveStart();
			break;
		case EPlayState::Jump:
			JumpStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void APlayer::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::CameraFreeMove:
		CameraFreeMove(_DeltaTime);
		break;
	case EPlayState::FreeMove:
		FreeMove(_DeltaTime);
		break;
	case EPlayState::Idle:
		Idle(_DeltaTime);
		break;
	case EPlayState::Move:
		Move(_DeltaTime);
		break;
	case EPlayState::Jump:
		Jump(_DeltaTime);
		break;
	default:
		break;
	}


}

void APlayer::CameraFreeMove(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Left * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Up * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Down * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::Idle);
	}
}

void APlayer::FreeMove(float _DeltaTime)
{
	FVector MovePos;

	if (UEngineInput::IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		MovePos += FVector::Up * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		MovePos += FVector::Down * _DeltaTime * FreeMoveSpeed;
	}

	AddActorLocation(MovePos);
	GetWorld()->AddCameraPos(MovePos);

	if (UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::Idle);
	}
}


void APlayer::Idle(float _DeltaTime)
{
	MoveVector = FVector::Zero;
	// 왼쪽 오른쪽도 안되고 있고.
	// 여기서는 정말
	// 가만히 있을때만 어떻게 할지 신경쓰면 됩니다.
	if (true == UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::FreeMove);
		return;
	}

	if (true == UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::CameraFreeMove);
		return;
	}

	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT)
		)
	{
		StateChange(EPlayState::Move);
		return;
	}

	if (
		true == UEngineInput::IsDown(VK_SPACE)
		)
	{
		StateChange(EPlayState::Jump);
		return;
	}

	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	MoveUpdate(_DeltaTime);
}

void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	MoveUpdate(_DeltaTime);

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(EPlayState::Idle);
		return;
	}

	FVector MovePos = FVector::Zero;
	if (UEngineInput::IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(EPlayState::Jump);
		return;
	}

	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}
	CheckPos.Y -= 30;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);
	if (Color != Color8Bit(255, 0, 255, 0))
	{
		AddActorLocation(MovePos);
		GetWorld()->AddCameraPos(MovePos);
	}

	while (true)
	{
		Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(255, 0, 255, 0))
		{
			AddActorLocation(FVector::Up);
			//FVector CameraPos = GetActorLocation();
			//int CPos = GetActorLocation().iY();

			//FVector a = { 0,CPos,0,0 };

			//GetWorld()->AddCameraPos(a);
		}
		else
		{
			break;
		}
	}

}

void APlayer::Jump(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	MoveUpdate(_DeltaTime);


	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		JumpVector += JumpPower * _DeltaTime;
		JumpVector = FVector::Zero;
		StateChange(EPlayState::Idle);
		return;
	}

}

void APlayer::Run(float _DeltaTime)
{
	DirCheck();

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(EPlayState::Idle);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsPress('Q'))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT) && UEngineInput::IsPress('Q'))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(EPlayState::Jump);
		return;
	}


	MoveUpdate(_DeltaTime);
}



void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsAnykeyDown())
	{
		int a = 0;
	}

	if (UEngineInput::IsAnykeyUp())
	{
		int a = 0;
	}




	StateUpdate(_DeltaTime);
}
