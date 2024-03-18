#include "Bridge.h"

ABridge::ABridge()
{
}

ABridge::~ABridge()
{
}

void ABridge::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);

	Render->SetImage("Bridge.png");
	Render->SetTransform({ {0, 0 }, {180, 40} });


	Collision = CreateCollision(WonderCollisionOrder::Bridge);
	Collision->SetPosition({ 0,-28 });
	Collision->SetScale({ 180, 40 });
	Collision->SetColType(ECollisionType::Rect);

}

void ABridge::Move(float _DeltaTime)
{
	FVector PPos = GetActorLocation();

	if (PPos.Y > 700)
	{
		DownMove.Y = -100.0f;
	}
	if (PPos.Y < 400)
	{
		DownMove.Y = 100.0f;
	}

	AddActorLocation(DownMove * _DeltaTime);
}

void ABridge::Tick(float _DeltaTime)
{
	Move(_DeltaTime);
}


