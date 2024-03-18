#include "Jumpping.h"

AJumpping::AJumpping()
{
}

AJumpping::~AJumpping()
{
}

void AJumpping::BeginPlay()
{
	AActor::BeginPlay();

		Render = CreateImageRenderer(WonderRenderOrder::Object);
		Render->SetImage("Jumpping.png");
		Render->SetTransform({ {0, 0 }, {380, 400} });

		Render->CreateAnimation("Move_Jumpping", "Jumpping.png", 0, 0, 0.0f, true); // 움직이는 상태
		Render->ChangeAnimation("Move_Jumpping");

		Collision = CreateCollision(WonderCollisionOrder::Jumpping);
		Collision->SetScale({ 200, 20 });
		Collision->SetColType(ECollisionType::Rect);
}

void AJumpping::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
	}
}


