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

	
	{
		Snail = CreateImageRenderer(WonderRenderOrder::Monster);
		Snail->SetImage("Monster1.png");
		Snail->SetTransform({ {200, 873 }, {200, 200} });

		Snail->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // 움직이는 상태
		Snail->ChangeAnimation("Move_Monster");
	}
	
	{
		Bee = CreateImageRenderer(WonderRenderOrder::Monster);
		Bee->SetImage("Bee.png");
		Bee->SetTransform({ {200, 873 }, {400, 400} });

		Bee->CreateAnimation("Move_Bee", "Bee.png", 0, 1, 1.0f, true); // 움직이는 상태
		Bee->ChangeAnimation("Move_Bee");
	}

	{
		Bee = CreateImageRenderer(WonderRenderOrder::Monster);
		Bee->SetImage("Snake.png");
		Bee->SetTransform({ {200, 873 }, {400, 400} });

		Bee->CreateAnimation("Move_Snake", "Snake.png", 0, 1, 1.0f, true); // 움직이는 상태
		Bee->ChangeAnimation("Move_Snake");
	}

	//{
	//	Bee = CreateImageRenderer(WonderRenderOrder::Monster);
	//	Bee->SetImage("Stone.png");
	//	Bee->SetTransform({ {200, 873 }, {400, 400} });

	//	Bee->CreateAnimation("Move_Stone", "Stone.png", 0, 1, 1.0f, true); // 움직이는 상태
	//	Bee->ChangeAnimation("Move_Stone");
	//}




	{
		Collision = CreateCollision(WonderCollisionOrder::Monster);
		Collision->SetScale({ 10, 100 });
		Collision->SetColType(ECollisionType::Rect);
	}
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
void AMonster::AddMoveVector()
{
	MoveVector;
}

void AMonster::MoveFront()
{
	AddActorLocation(FVector::Left);
}

void AMonster::MoveUpdate(float _DeltaTime)
{

}

void AMonster::Destroy()
{
	// 무기에 닿으면 파괴된다.
}

void AMonster::Tick(float _DeltaTime)
{


	//MoveFront();
	AddActorLocation(FVector::Left * _DeltaTime);
}
