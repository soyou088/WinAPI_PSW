#include "Bee.h"
#include "Monster.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"

ABee::ABee()
{
}

ABee::~ABee()
{
}

std::string ABee::GetAnimationName(std::string _Name)
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



void ABee::BeginPlay()
{
	AActor::BeginPlay();

	{
		Render = CreateImageRenderer(WonderRenderOrder::Monster);
		Render->SetImage("Bee.png");
		Render->SetTransform({ {0, 0 }, {400, 400} });

		Render->CreateAnimation("Move_Bee", "Bee.png", 0, 1, 0.1f, true); // 움직이는 상태
		Render->ChangeAnimation("Move_Bee");

		Render->CreateAnimation("Destroy_Bee", "Bee.png", 2, 2, 1.0f, true);
	}
}

void ABee::MoveStart()
{
	Render->ChangeAnimation(GetAnimationName("Move"));
}

void ABee::DestroyStart()
{
	Render->ChangeAnimation(GetAnimationName("Destroy"));
}

void ABee::StateChange(EPlayState _State)
{
	// 이전상태와 지금 상태가 같지 않아
	// 이전에는 move 지금은 Idle
	if (State != _State)
	{
		switch (_State)
		{
		case EPlayState::Move:
			MoveStart();
			break;
		case EPlayState::Destroy:
			DestroyStart();
			break;
		default:
			break;
		}
	}
	State = _State;
}

void ABee::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::Move:
		Move(_DeltaTime);
		break;
	case EPlayState::Destroy:
		DestroyStart();
		break;
	default:
		break;
	}

}


void ABee::Move(float _DeltaTime)
{
	FVector PPos = GetActorLocation();

	AddActorLocation(MoveVector * _DeltaTime);
	if (PPos.Y > 873)
	{
		DownMove *= -1;
	}
	if (PPos.Y < 790)
	{
		DownMove *= -1;
	}

	AddActorLocation(DownMove * _DeltaTime);
}


void ABee::Destroy()
{
	Destroy();
}




void ABee::Tick(float _DeltaTime)
{
	Move(_DeltaTime);
}
