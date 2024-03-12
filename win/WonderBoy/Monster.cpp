#include "Monster.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"

AMonster::AMonster()
{
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
	AActor::BeginPlay();


		Snail = CreateImageRenderer(WonderRenderOrder::Monster);
		Snail->SetImage("Monster1.png");
		Snail->SetTransform({ {0,0 }, {200, 200} });

		Snail->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // 움직이는 상태
		Snail->ChangeAnimation("Move_Monster");

		Snail->CreateAnimation("Death_Monster", "Monster1.png", 2, 2, 0.0f, true);

	
		Collision = CreateCollision(WonderCollisionOrder::Monster);
		Collision->SetPosition({ 0,-28 });
		Collision->SetScale({ 50, 50 });
		Collision->SetColType(ECollisionType::Rect);
	
}

void AMonster::HillDown()
{
	while (true)
	{
		Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(100, 0, 0, 0))
		{
			AddActorLocation(FVector::Down);
		}
		else
		{
			break;
		}

	}
}
void AMonster::AddMoveVector(float _DeltaTime)
{
	MoveVector += MoveVector * _DeltaTime;
}

void AMonster::MoveFront(float _DeltaTime)
{
	// MoveUpdate(_DeltaTime);
	AddActorLocation(FVector::Left);
}

void AMonster::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY() - 5, Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA)
	{
		GravityVector = FVector::Zero;
		ColGra = true;
	}
}

void AMonster::DesMoveUpdate(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	AddActorLocation((JumpVector + ColMoveVector) * _DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);

	if (ColSnail == true && ColGra == true)
	{
		Destroy();
	}


	int a = 0;
}

void AMonster::MoveUpdate(float _DeltaTime)
{
	MoveVector += MoveVector * _DeltaTime;
}

void AMonster::Tick(float _DeltaTime)
{
	MoveUpdate(_DeltaTime);
	AddActorLocation(FVector::Left * _DeltaTime);

	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::PlayerBullet, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		Snail->ChangeAnimation("Death_Monster");
		ColSnail = true;
	}

	if (ColSnail == true)
	{
		DesMoveUpdate(_DeltaTime);

	}
}
