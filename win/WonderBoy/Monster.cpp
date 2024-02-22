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
		Renderer = CreateImageRenderer(WonderRenderOrder::Monster);
		Renderer->SetImage("Monster1.png");
		Renderer->SetTransform({ {0,0}, {200, 200} });

		Renderer->CreateAnimation("Idle_Monster", "Monster1.png", 0, 0, 0.1f, true); // 가만히 있는 상태
		Renderer->CreateAnimation("Move_Left", "Monster1.png", 0, 1, 0.1f, true); // 움지이는 상태

		Renderer->ChangeAnimation("Idle_Monster"); // 가만히 있는상태
	}

	{
		Collision = CreateCollision(WonderCollisionOrder::Monster);
		Collision->SetScale({100, 100});
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
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Monster, Result))
	{
		Collision->Destroy();
		Collision = nullptr;
	}

	APlayer* Player = APlayer::GetMainPlayer();
	if (nullptr == Player)
	{
		MsgBoxAssert("플레이어가 존재하지 않습니다.");
	}

	//MoveFront();
	AddActorLocation(FVector::Left * _DeltaTime);
}
