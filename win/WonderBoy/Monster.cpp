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
		snail = CreateImageRenderer(WonderRenderOrder::Monster);
		snail->SetImage("Monster1.png");
		snail->SetTransform({ {200, 873 }, {200, 200} });

		snail->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // 움직이는 상태
		snail->ChangeAnimation("Move_Monster");
	}
	
	{
		//Renderer = CreateImageRenderer(WonderRenderOrder::Monster);
		//Renderer->SetImage("Monster1.png");
		//Renderer->SetTransform({ {200, 873 }, {200, 200} });

		//Renderer->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // 움직이는 상태
		//Renderer->ChangeAnimation("Move_Monster");

	}




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
