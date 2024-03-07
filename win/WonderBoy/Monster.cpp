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
		Snail->SetTransform({ {200, 873 }, {200, 200} });

		Snail->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // 움직이는 상태
		Snail->ChangeAnimation("Move_Monster");

		Snail->CreateAnimation("Death_Monster", "Monster1.png", 2, 2, 0.0f, true);
	
	//{
	//	Snake = CreateImageRenderer(WonderRenderOrder::Monster);
	//	Snake->SetImage("Snake.png");
	//	Snake->SetTransform({ {200, 873 }, {400, 400} });

	//	Snake->CreateAnimation("Move_Snake", "Snake.png", 0, 1, 1.0f, true); // 움직이는 상태
	//	Snake->ChangeAnimation("Move_Snake");
	//}

	//{
	//	Frog = CreateImageRenderer(WonderRenderOrder::Monster);
	//	Frog->SetImage("Frog.png");
	//	Frog->SetTransform({ {200, 873 }, {400, 400} });

	//	Frog->CreateAnimation("Move_Frog", "Frog.png", 0, 1, 1.0f, true); // 움직이는 상태
	//	Frog->ChangeAnimation("Move_Frog");
	//}



	
		Collision = CreateCollision(WonderCollisionOrder::Monster);
		Collision->SetPosition({ 0,-30 });
		Collision->SetScale({ 100, 100 });
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

void AMonster::MoveUpdate(float _DeltaTime)
{
	MoveVector += MoveVector * _DeltaTime;
}

void AMonster::Destroy()
{
	// 무기에 닿으면 파괴된다.
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
	}
}
