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


void ABee::BeginPlay()
{
	AActor::BeginPlay();

	{
		Bee = CreateImageRenderer(WonderRenderOrder::Monster);
		Bee->SetImage("Bee.png");
		Bee->SetTransform({ {200, 873 }, {400, 400} });

		Bee->CreateAnimation("Move_Bee", "Bee.png", 0, 1, 1.0f, true); // 움직이는 상태
		Bee->ChangeAnimation("Move_Bee");
	}
}

void ABee::Move()
{
	
	AddActorLocation(FVector::Up);
}


void ABee::Tick(float _DeltaTime)
{
	AddActorLocation(FVector::Up * _DeltaTime);
	AddActorLocation(FVector::Left * _DeltaTime);

}
