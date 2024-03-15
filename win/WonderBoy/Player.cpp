#include "Player.h"
#include "BulletActor.h"
#include "Skate.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include <EngineCore/EngineDebug.h>
#include "ContentsHelper.h"
#include <EngineBase/EngineDebug.h>




APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay(); // 부모에서 실행하는 함수를 해주는게 좋아서 했다.

	GetWorld()->AddCameraPos({ 0, 600 }); // 카메라세팅
	MainPlayer = this;
	{
		Renderer = CreateImageRenderer(WonderRenderOrder::Player);
		Renderer->SetImage("Player_1_R.png");
		Renderer->SetTransform({ {0,0}, {400, 330} });

		Renderer->CreateAnimation("Idle_Right", "Player_1_R.png", 0, 2, 0.1f, true); // 가만히 있는 상태
		Renderer->CreateAnimation("Move_Right", "Player_1_R.png", 0, 5, 0.05f, true); // 오른쪽으로 움직이는 상태

		Renderer->CreateAnimation("Idle_Left", "Player_1_L.png", 0, 2, 0.1f, true); // 가만히 있는 상태
		Renderer->CreateAnimation("Move_Left", "Player_1_L.png", 0, 5, 0.05f, true); // 왼쪽으로 움직이는 상태

		Renderer->CreateAnimation("Run_Right", "Player_1_R.png", 0, 5, 0.05f, true); // 오른쪽으로 달리는 상태
		Renderer->CreateAnimation("Run_Left", "Player_1_L.png", 0, 5, 0.05f, true); // 왼쪽으로 달리는 상태

		Renderer->CreateAnimation("Jump_Right", "Player_1_R.png", 5, 5, 0.1f, true); // 오른쪽으로 점프하기
		Renderer->CreateAnimation("Jump_Left", "Player_1_L.png", 5, 5, 0.1f, true); // 왼쪽으로 점프하기

		Renderer->CreateAnimation("Skate_Right", "Skate_R.png", 0, 1, 0.1f, true); // 오른쪽으로 보드타기
		Renderer->CreateAnimation("Skate_Left", "Skate_L.png", 0, 1, 0.1f, true); // 왼쪽으로 보드타기

		Renderer->CreateAnimation("SkateBrake_Right", "Skate_R.png", 2, 3, 0.1f, true); // 오른쪽 브레이크
		Renderer->CreateAnimation("SkateBrake_Left", "Skate_L.png", 2, 3, 0.1f, true); // 왼쪽 브레이크

		Renderer->CreateAnimation("SkateJump_Right", "Skate_R.png", 4, 4, 0.1f, true); // 오른쪽 보드 점프
		Renderer->CreateAnimation("SkateJump_Left", "Skate_L.png", 4, 4, 0.1f, true); // 왼쪽 보드 점프

		Renderer->CreateAnimation("Col_Right", "Player_1_R.png", 9, 9, 0.1f, true); // 오른쪽충돌
		Renderer->CreateAnimation("Col_Left", "Player_1_R.png", 9, 9, 0.1f, true); // 왼쪽 충돌

		Renderer->CreateAnimation("Bullet_Right", "Player_1_R.png", 7, 8, 0.1f, true); // 오른쪽 공격
		Renderer->CreateAnimation("Bullet_Left", "Player_1_L.png", 7, 8, 0.1f, true); // 왼쪽 공격

		Renderer->CreateAnimation("Death", "Death.png", 0, 1, 0.1f, true); // 죽기

		Renderer->CreateAnimation("ColStone_Right", "Player_1_R.png", 9, 9, 0.1f, true); // 오른쪽 col

		Renderer->ChangeAnimation("Idle_Right");
	}
	{
		// Player Collision
		Collision = CreateCollision(WonderCollisionOrder::Player);
		Collision->SetPosition({ 0,-50 });
		Collision->SetScale({ 50, 90 });
		Collision->SetColType(ECollisionType::Rect);
	}


	StateChange(EPlayState::Idle);
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

void APlayer::AddMoveVector(const FVector& _DirDelta)
{
	MoveVector += _DirDelta * MoveAcc;
	if (State == EPlayState::SkateMove)
	{
		MoveVector += _DirDelta * SkateMoveVector;
	}
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

	if (MoveMaxSpeed <= MoveVector.Size2D())
	{
		MoveVector = MoveVector.Normalize2DReturn() * MoveMaxSpeed;
	}
}

void APlayer::MoveLastMoveVector(float _DeltaTime)
{
	AddActorLocation(LastMoveVector * _DeltaTime);
}

void APlayer::CameraSet(float _DeltaTime)
{
	// 카메라 막기
	FVector CPos = GetWorld()->GetCameraPos();
	FVector PPos = GetActorLocation();
	float ScaleX = GEngine->MainWindow.GetWindowScale().X;
	if (PPos.X >= CPos.X + 160 && 0 < LastMoveVector.X && UContentsHelper::ColMapImage->GetScale().X  >= CPos.X + ScaleX)
	{
		GetWorld()->AddCameraPos(MoveVector * _DeltaTime);

	}
	
	FVector WallCheck = GetActorLocation();
	if (CPos.X > WallCheck.X - 45)
	{
		MoveVector = FVector::Right;
		return;
	}
}
void APlayer::CalLastMoveVector(float _DeltaTime)
{
	// 제로로 만들어서 초기화 시킨다.
	LastMoveVector = FVector::Zero;
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
}

void APlayer::HillUP(Color8Bit _Color)
{
	// _Color 일때 FVector UP한다.
	while (true)
	{
		Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY() - 1, Color8Bit::MagentaA);
		if (Color == _Color)
		{
		FVector playerpos = GetActorLocation();
			AddActorLocation(FVector::Up);
			GetWorld()->AddCameraPos(FVector::Up);
		}
		else
		{
			break;
		}
	}
}

void APlayer::PlayerGo()
{
	FVector CPos = GetWorld()->GetCameraPos();
	GetWorld()->SetCameraPos({ 13100,600 });
	SetActorLocation({	13170, 873 });
}

void APlayer::FinPlayGo()
{
	GetWorld()->SetCameraPos({ 19600 , -19 });
	SetActorLocation({ 19714, 318 });
}

void APlayer::WallCheck()
{
	FVector WallCheck = GetActorLocation();
	FVector CPos = GetWorld()->GetCameraPos();
	if (CPos.X >= WallCheck.X - 5)
	{
		return;
	}

}

void APlayer::NextAnimation()
{
	std::string NextAnimation = GetAnimationName("Run");
}


void APlayer::ColorJump()
{
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		JumpVector = FVector::Zero;
		GravityVector = FVector::Zero;
		return;
	}
}

void APlayer::SkateBrake(float _DeltaTime)
{
}

void APlayer::Bullet()
{
	FVector BPos = GetActorLocation();
	ABulletActor* Bullet = GetWorld()->SpawnActor<ABulletActor>();
	Bullet->SetName("Bullet");

	if (DirState == EActorDir::Right)
	{
		Bullet->SetBulletAcc(FVector::Right * 700.0f);
		Bullet->SetActorLocation({ BPos.X + 5 ,BPos.Y - 60 });
	}
	else
	{
		Bullet->SetBulletAcc(FVector::Left * 700.0f);
		Bullet->SetActorLocation({ BPos.X - 5 ,BPos.Y - 60 });
	}

	return;
}


void APlayer::MoveUpdate(float _DeltaTime)
{
	CalMoveVector(_DeltaTime); // 움직임 계산 값
	CalGravityVector(_DeltaTime);// 중력 계산 값	
	CalLastMoveVector(_DeltaTime); // 다 던한 값
	MoveLastMoveVector(_DeltaTime); // 카메라
	HillUP(Color8Bit(255, 0, 255, 0));
}

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}

void APlayer::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}
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
	AddActorLocation(FVector::Up * 10);
	DirCheck();
}

void APlayer::RunStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Bullet"));
	Bullet();
	DirCheck();
}

void APlayer::SkateStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Skate"));
	DirCheck();
}

void APlayer::SkateJumpStart()
{
	JumpVector = JumpPower;
	Renderer->ChangeAnimation(GetAnimationName("SkateJump"));
	DirCheck();
}

void APlayer::SkateBrakeStart()
{
	Renderer->ChangeAnimation(GetAnimationName("SkateBrake"));
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
		case EPlayState::Run:
			RunStart();
			break;
		case EPlayState::Jump:
			JumpStart();
			break;
		case EPlayState::SkateMove:
			SkateStart();
			break;
		case EPlayState::SkateJump:
			SkateJumpStart();
			break;
		case EPlayState::SkateBrake:
			SkateBrakeStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void APlayer::StateUpdate(float _DeltaTime)
{
	if (true != SkateCheck)
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
		case EPlayState::Run:
			Run(_DeltaTime);
			break;
		case EPlayState::Jump:
			Jump(_DeltaTime);
			break;
		case EPlayState::SkateMove:
			SkateMove(_DeltaTime);
			break;
		default:
			break;
		}
	}

	if (true == SkateCheck)
	{
		switch (State)
		{
		case EPlayState::CameraFreeMove:
			CameraFreeMove(_DeltaTime);
			break;
		case EPlayState::FreeMove:
			FreeMove(_DeltaTime);
			break;
		case EPlayState::SkateMove:
			SkateMove(_DeltaTime);
			break;
		case EPlayState::SkateJump:
			SkateJump(_DeltaTime);
			break;
		case EPlayState::SkateBrake:
			SkateBrake(_DeltaTime);
			break;
		case EPlayState::Attack:
			Run(_DeltaTime);
			break;
		default:
			break;
		}
	}

}




void APlayer::CameraFreeMove(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
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

	if (true == UEngineInput::IsPress(VK_LEFT) || true == UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(EPlayState::Move);
		return;
	}

	if (
		true == UEngineInput::IsDown('W')
		)
	{
		StateChange(EPlayState::Jump);
		return;
	}

	if (true == UEngineInput::IsDown('Q'))
	{
		BeforeRunState = EPlayState::Idle;
		StateChange(EPlayState::Run);
		return;
	}

	if (true == UEngineInput::IsDown('K'))
	{
		PlayerGo();
	}

	if (true == UEngineInput::IsDown('J'))
	{
		FinPlayGo();
	
	}



	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
		JumpVector = FVector::Zero;
	}


	CameraSet(_DeltaTime);
	MoveUpdate(_DeltaTime);
}


void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	


	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		FVector MoveDirVector = FVector::Zero;
		switch (DirState)
		{
		case EActorDir::Left:
			MoveDirVector = FVector::Right;
			break;
		case EActorDir::Right:
			MoveDirVector = FVector::Left;
			break;
		default:
			break;
		}
		if (80.0f <= abs(MoveVector.X))
		{
			AddMoveVector((MoveDirVector)*_DeltaTime);// 감속하는 코드
		}
		else
		{
			MoveVector = float4::Zero;
			StateChange(EPlayState::Idle);
			return;
		}
	}


	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}


	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
		FVector CPos = GetWorld()->GetCameraPos();
		int a = 0;
	}

	if (UEngineInput::IsPress('W'))
	{
		StateChange(EPlayState::Jump);
		return;
	}

	if (UEngineInput::IsPress('Q'))
	{
		BeforeRunState = EPlayState::Move;
		StateChange(EPlayState::Run);

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

	if (true == UEngineInput::IsPress('S'))
	{
		StateChange(EPlayState::SkateMove);
	}


	HillUP(Color8Bit(255, 0, 255, 0));
	CameraSet(_DeltaTime);
	MoveUpdate(_DeltaTime);

}

void APlayer::Run(float _DeltaTime)
{
	DirCheck();

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		if (UEngineInput::IsFree('Q'))
		{
			StateChange(BeforeRunState);
			return;
		}
		FVector MoveDirVector = FVector::Zero;
		switch (DirState)
		{
		case EActorDir::Left:
			MoveDirVector = FVector::Right;
			break;
		case EActorDir::Right:
			MoveDirVector = FVector::Left;
			break;
		default:
			break;
		}
		if (80.0f <= abs(MoveVector.X))
		{
			AddMoveVector((MoveDirVector)*_DeltaTime);// 감속하는 코드
		}
		else
		{
			MoveVector = float4::Zero;
			StateChange(EPlayState::Idle);
			return;
		}
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector((FVector::Left * _DeltaTime) * 5.f);
		Renderer->ChangeAnimation(GetAnimationName("Move"));
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector((FVector::Right * _DeltaTime) * 5.f);
		Renderer->ChangeAnimation(GetAnimationName("Move"));
	}

	if (UEngineInput::IsPress('W'))
	{
		StateChange(EPlayState::Jump);
		return;
	}
	if (UEngineInput::IsPress('Q'))
	{
		if (true == Renderer->IsCurAnimationEnd())
		{
			Renderer->ChangeAnimation(GetAnimationName("Move"));
		}
	}
	if (UEngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation(GetAnimationName("Bullet"));
		Bullet();
		if (true == UEngineInput::IsPress(VK_RIGHT))
		{
			Renderer->ChangeAnimation(GetAnimationName("Bullet"));
			Renderer->ChangeAnimation(GetAnimationName("Move"));
		}
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

	if (true == UEngineInput::IsPress('S'))
	{
		StateChange(EPlayState::SkateMove);
	}


	HillUP(Color8Bit(255, 0, 255, 0));
	CameraSet(_DeltaTime);
	MoveUpdate(_DeltaTime);
}



void APlayer::Jump(float _DeltaTime)
{

	if (JumpVector.Y == 0) 
	{
		StateChange(EPlayState::Move);
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsDown('Q') )
	{
		BeforeRunState = EPlayState::Jump;
		StateChange(EPlayState::Run);
		if (JumpVector.Y == 0)
		{
			StateChange(BeforeRunState);
		}
		return;
	}


	if (JumpMax <= JumpVector.Size2D())
	{
		JumpVector = JumpVector.Normalize2DReturn() * JumpMax;
	}

	MoveUpdate(_DeltaTime);
	CameraSet(_DeltaTime);


}

void APlayer::SkateMove(float _DeltaTime)
{

	SkateMoveVector = SkateMoveVector * _DeltaTime;

	DirCheck();
	// 가만히 있어도 앞으로 가는 상태
	// 상태는 함수
	AddActorLocation(SkateMoveVector * _DeltaTime);

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		FVector MoveDirVector = FVector::Zero;
		switch (DirState)
		{
		case EActorDir::Left:
			MoveDirVector = FVector::Right;
			break;
		case EActorDir::Right:
			MoveDirVector = FVector::Left;
			break;
		default:
			break;
		}
		if (10.0f <= abs(MoveVector.X))
		{
			AddMoveVector((MoveDirVector)*_DeltaTime);// 감속하는 코드
		}
		else
		{
			MoveVector = float4::Zero;
			StateChange(EPlayState::SkateMove);
			return;
		}
	}

	MoveUpdate(_DeltaTime);
	CameraSet(_DeltaTime);


	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}


	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		StateChange(EPlayState::SkateJump);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsPress('W'))
	{
		AddMoveVector(FVector::Left * _DeltaTime + JumpVector);
	}


	if (UEngineInput::IsPress(VK_RIGHT) && UEngineInput::IsPress('W'))
	{
		AddMoveVector(FVector::Right * _DeltaTime + JumpVector);
	}

	if (true == UEngineInput::IsDown('Q'))
	{
		StateChange(EPlayState::Attack);
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

	if (true == UEngineInput::IsPress('S'))
	{
		StateChange(EPlayState::SkateMove);
		SkateCheck = true;
	}


	HillUP(Color8Bit(255, 0, 255, 0));

}

void APlayer::SkateJump(float _DeltaTime)
{

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsDown('Q'))
	{
		StateChange(EPlayState::Attack);
		return;
	}

	if (JumpMax <= JumpVector.Size2D())
	{
		JumpVector = JumpVector.Normalize2DReturn() * JumpMax;
	}

	MoveUpdate(_DeltaTime);

	StateChange(EPlayState::SkateMove);
}

void APlayer::Col(float _DeltaTime)
{

}

void APlayer::Death(float _DeltaTime)
{

}


void APlayer::Tick(float _DeltaTime)
{
	std::string Mouse = std::to_string(UContentsHelper::GetMousePos().Y);
	std::string PlayerY = std::to_string(GetActorLocation().Y);

	Color8Bit mouse = UContentsHelper::ColMapImage->GetColor(UContentsHelper::GetMousePos().iX(), UContentsHelper::GetMousePos().iY() + 540, Color8Bit::MagentaA);
	if (mouse == Color8Bit(255, 0, 255, 0))
	{
		int a = 0;
	}


	UEngineDebug::DebugTextPrint(Mouse, 24);
	UEngineDebug::DebugTextPrint(PlayerY, 24);

	AActor::Tick(_DeltaTime);
	ColorJump();
	StateUpdate(_DeltaTime);
	FVector PlayerPos = GetActorLocation();

	if (true == UEngineInput::IsDown('I'))
	{
		SetActorLocation({ PlayerPos.X,GetWorld()->GetCameraPos().Y-300  });
		GravityVector = FVector::Zero;
	}

	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Monster, Result) 
		|| true == Collision->CollisionCheck(WonderCollisionOrder::Bonfire, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		Renderer->ChangeAnimation("Death");
		return;
	}
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Stone, Result))
	{
		AActor* SCol = Result[0]->GetOwner();
		Renderer->ChangeAnimation("ColStone_Right");
		return;
	}
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Rock, Result))
	{
		AActor* SCol = Result[0]->GetOwner();
		Renderer->ChangeAnimation("Death");
		return;
	}

	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Switch, Result))
	{
		AActor* SCol = Result[0]->GetOwner();
		return;
	}

	APlayer* Player = APlayer::GetMainPlayer();
	if (nullptr == Player)
	{
		MsgBoxAssert("플레이어가 존재하지 않습니다.");
	}



	UEngineDebug::DebugTextPrint("X : " + std::to_string(PlayerPos.X) + ", Y : " + std::to_string(PlayerPos.Y), 30.0f);


}


