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

		Render = CreateImageRenderer(WonderRenderOrder::Monster);
		Render->SetImage("Bee.png");
		Render->SetTransform({ {0, 0 }, {400, 400} });

		Render->CreateAnimation("Move_Bee", "Bee.png", 0, 1, 0.1f, true); // �����̴� ����
		Render->ChangeAnimation("Move_Bee");

		Render->CreateAnimation("Destroy_Bee", "Bee.png", 2, 2, 1.0f, true);



		Collision = CreateCollision(WonderCollisionOrder::Monster);
		Collision->SetPosition({ 0,0 });
		Collision->SetScale({ 50, 90 });
		Collision->SetColType(ECollisionType::Rect);
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
	// �������¿� ���� ���°� ���� �ʾ�
	// �������� move ������ Idle
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

void ABee::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY() - 5, Color8Bit(0,0,0,0));

	if (Color == Color8Bit(255,0,255,0))
	{
		GravityVector = FVector::Zero;
		ColGra = true;
	}
}

void ABee::Move(float _DeltaTime)
{
	FVector PPos = GetActorLocation();

	AddActorLocation(MoveVector * _DeltaTime);
	if (PPos.Y > 1000)
	{
		DownMove.Y = -200.0f;
	}
	if (PPos.Y < 920)
	{
		DownMove.Y = 200.0f;
	}

	AddActorLocation(DownMove * _DeltaTime);
}

void ABee::DesMoveUpdate(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	AddActorLocation((JumpVector + ColMoveVector) * _DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);

	if (ColBee == true && ColGra == true)
	{
		Destroy();
	}
}




void ABee::Tick(float _DeltaTime)
{
	Move(_DeltaTime);

	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::PlayerBullet, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		// ������� �������� �׸���
		ColBee = true;
	}
	if (ColBee == true)
	{
		Render->ChangeAnimation("Destroy_Bee");
		DesMoveUpdate(_DeltaTime);
	}


}
