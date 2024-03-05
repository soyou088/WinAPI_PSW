#include "Skate.h"

ASkate::ASkate()
{
}

ASkate::~ASkate()
{
}

void ASkate::BeginPlay()
{

	Renderer = CreateImageRenderer(WonderRenderOrder::Skate);
	Renderer->SetImage("Skate_R.png");
	Renderer->SetTransform({ {0,0}, {130, 130} });

	Renderer->CreateAnimation("Skate_Right", "Skate_R.png", 0, 1, 0.1f, true); // 오른쪽으로 보드타기
	Renderer->CreateAnimation("Skate_Left", "Skate_L.png", 0, 1, 0.1f, true); // 왼쪽으로 보드타기

	Renderer->CreateAnimation("SkateBrake_Right", "Skate_R.png", 2, 3, 0.1f, true); // 오른쪽 브레이크
	Renderer->CreateAnimation("SkateBrake_Left", "Skate_L.png", 2, 3, 0.1f, true); // 왼쪽 브레이크

	Renderer->CreateAnimation("SkateJump_Right", "Skate_R.png", 4, 4, 0.1f, true); // 오른쪽 보드 점프
	Renderer->CreateAnimation("SkateJump_Left", "Skate_L.png", 4, 4, 0.1f, true); // 왼쪽 보드 점프

	Renderer->ChangeAnimation("Skate");
}

void ASkate::StateChange(EPlayState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case EPlayState::SkateMove:
			SkateMoveStart();
		case EPlayState::SkateJump:
			SkateJumpStart();
		case EPlayState::SkateBrake:
			SkateBrakeStart();
		default:
			break;
		}
	}
	State = _State;
}

void ASkate::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::SkateMove:
		SkateMoveStart();
	case EPlayState::SkateJump:
		SkateJumpStart();
	case EPlayState::SkateBrake:
		SkateBrakeStart();
		break;
	default:
		break;
	}
}


void ASkate::MoveUpdate(float _DeltaTime)
{
	CalMoveVector(_DeltaTime); // 움직임 계산 값
	CalGravityVector(_DeltaTime);// 중력 계산 값	
	CalLastMoveVector(_DeltaTime); // 다 던한 값
	MoveLastMoveVector(_DeltaTime); // 카메라
	HillUP(Color8Bit(100, 0, 0, 0));
}

void ASkate::SkateMoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Skate"));
	DirCheck();
}

void ASkate::SkateJumpStart()
{
	Renderer->ChangeAnimation(GetAnimationName("SkateJump"));
	DirCheck();
}

void ASkate::SkateBrakeStart()
{
	Renderer->ChangeAnimation(GetAnimationName("SkateBrake"));
	DirCheck();
}

void ASkate::DirCheck()
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

void ASkate::Move()
{
	DirCheck();
	MoveUpdate(_DeltaTime);

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
		if (70.0f <= abs(MoveVector.X))
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
}

void ASkate::Jump()
{
	
}

void ASkate::Brake()
{

}




