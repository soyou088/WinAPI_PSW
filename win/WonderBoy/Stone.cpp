#include "Stone.h"

AStone::AStone()
{
}

AStone::~AStone()
{
}

void AStone::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);

	Render->CreateAnimation("Stone", "BulletObject1.png", 0, 0, 1.0f, true);
	
	Render->SetImage("BulletObject1.png");
	Render->SetTransform({ {0, 0 }, {100, 100} });

	Render->ChangeAnimation("Stone");


	Collision = CreateCollision(WonderCollisionOrder::Object);
	Collision->SetScale({ 50, 50 });
	Collision->SetColType(ECollisionType::CirCle);
}

void AStone::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
	}

}
