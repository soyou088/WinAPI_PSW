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

		Snail->CreateAnimation("Move_Monster", "Monster1.png", 0, 1, 1.0f, true); // �����̴� ����
		Snail->ChangeAnimation("Move_Monster");
	}
	
	{
		Bee = CreateImageRenderer(WonderRenderOrder::Monster);
		Bee->SetImage("Bee.png");
		Bee->SetTransform({ {200, 873 }, {400, 400} });

		Bee->CreateAnimation("Move_Bee", "Bee.png", 0, 1, 1.0f, true); // �����̴� ����
		Bee->ChangeAnimation("Move_Bee");
	}

	{
		Snake = CreateImageRenderer(WonderRenderOrder::Monster);
		Snake->SetImage("Snake.png");
		Snake->SetTransform({ {200, 873 }, {400, 400} });

		Snake->CreateAnimation("Move_Snake", "Snake.png", 0, 1, 1.0f, true); // �����̴� ����
		Snake->ChangeAnimation("Move_Snake");
	}

	//{
	//	Frog = CreateImageRenderer(WonderRenderOrder::Monster);
	//	Frog->SetImage("Frog.png");
	//	Frog->SetTransform({ {200, 873 }, {400, 400} });

	//	Frog->CreateAnimation("Move_Frog", "Frog.png", 0, 1, 1.0f, true); // �����̴� ����
	//	Frog->ChangeAnimation("Move_Frog");
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

void AMonster::BeeMove()
{
	// ���� ������ ���鼭 ���Ʒ��� �Դٸ� ���ٸ�
	
}

void AMonster::MoveUpdate(float _DeltaTime)
{

}

void AMonster::Destroy()
{
	// ���⿡ ������ �ı��ȴ�.
}

void AMonster::Tick(float _DeltaTime)
{
	AddActorLocation(FVector::Left * _DeltaTime);
}
