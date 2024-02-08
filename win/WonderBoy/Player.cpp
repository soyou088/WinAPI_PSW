#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(WonderRenderOrder::Player);
	Renderer->SetImage("Player_R.png");
	Renderer->SetTransform({ {0,0}, {128, 128} });
	Renderer->CreateAnimation("Idle_Right", "Player_R.png", 0, 0, 0.1f, true);
	Renderer->CreateAnimation("Move_Right", "Player_R.png", 1, 5, 0.1f, true);

	Renderer->CreateAnimation("Idle_Left", "Player_L.png", 0, 0, 0.1f, true);
	Renderer->CreateAnimation("Move_Left", "Player_L.png", 1, 5, 0.1f, true);

	Renderer->ChangeAnimation("Idle_Right");


	StateChange(EPlayState::Idle);
}

void APlayer::GravityCheck(float _DeltaTime)
{
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color != Color8Bit(255, 0, 255, 0))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Gravity);
	}
}

void APlayer::DirCheck()
{
	EActorDir Dir = DirState;
	if (EngineInput::IsPress(VK_LEFT))
	{
		Dir = EActorDir::Left;
	}
	if (EngineInput::IsPress(VK_RIGHT))
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
	if (EngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Left * _DeltaTime * 500.0f);
	}

	if (EngineInput::IsPress(VK_RIGHT))
	{
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (EngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Up * _DeltaTime * 500.0f);
	}

	if (EngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Down * _DeltaTime * 500.0f);
	}

	if (EngineInput::IsDown('2'))
	{
		StateChange(EPlayState::Idle);
	}
}

void APlayer::FreeMove(float _DeltaTime)
{
	FVector MovePos;

	if (EngineInput::IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (EngineInput::IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (EngineInput::IsPress(VK_UP))
	{
		MovePos += FVector::Up * _DeltaTime * FreeMoveSpeed;
	}

	if (EngineInput::IsPress(VK_DOWN))
	{
		MovePos += FVector::Down * _DeltaTime * FreeMoveSpeed;
	}

	AddActorLocation(MovePos);
	GetWorld()->AddCameraPos(MovePos);

	if (EngineInput::IsDown('1'))
	{
		StateChange(EPlayState::Idle);
	}
}


void APlayer::Idle(float _DeltaTime)
{
	// 왼쪽 오른쪽도 안되고 있고.
	// 여기서는 정말
	// 가만히 있을때만 어떻게 할지 신경쓰면 됩니다.
	if (true == EngineInput::IsDown('1'))
	{
		StateChange(EPlayState::FreeMove);
		return;
	}

	if (true == EngineInput::IsDown('2'))
	{
		StateChange(EPlayState::CameraFreeMove);
		return;
	}


	if (
		true == EngineInput::IsPress(VK_LEFT) ||
		true == EngineInput::IsPress(VK_RIGHT)
		)
	{
		StateChange(EPlayState::Move);
		return;
	}

	if (
		true == EngineInput::IsDown(VK_SPACE)
		)
	{
		StateChange(EPlayState::Jump);
		return;
	}

	GravityCheck(_DeltaTime);
}
void APlayer::Jump(float _DeltaTime)
{

}

void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	GravityCheck(_DeltaTime);

	if (true == EngineInput::IsFree(VK_LEFT) && EngineInput::IsFree(VK_RIGHT))
	{
		StateChange(EPlayState::Idle);
		return;
	}

	FVector MovePos = FVector::Zero;
	if (EngineInput::IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (EngineInput::IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * FreeMoveSpeed;
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

	// APlayer* Player = GetWorld()->GetActorOfName("Player");
}


void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (EngineInput::IsAnykeyDown())
	{
		int a = 0;
	}

	if (EngineInput::IsAnykeyUp())
	{
		int a = 0;
	}



	StateUpdate(_DeltaTime);
}
