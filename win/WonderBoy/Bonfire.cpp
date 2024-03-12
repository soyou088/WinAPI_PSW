#include "Bonfire.h"

ABonfire::ABonfire()
{
}

ABonfire::~ABonfire()
{
}

void ABonfire::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Monster);
	Render->SetImage("Bonfire_2_2.png");
	Render->SetTransform({ {0, 0 }, {350, 400} });

	Render->CreateAnimation("Move_Bonfire", "Bonfire_2_2.png", 0, 2, 0.1f, true); // 움직이는 상태
	Render->ChangeAnimation("Move_Bonfire");

	Collision = CreateCollision(WonderCollisionOrder::Bonfire);
	Collision->SetPosition({ 0,-40 });
	Collision->SetScale({ 50, 70 });
	Collision->SetColType(ECollisionType::Rect);

}
void ABonfire::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
	}
}
