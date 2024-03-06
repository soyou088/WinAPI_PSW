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
	Render->SetImage("Bonfire.png");
	Render->SetTransform({ {0, 0 }, {350, 350} });

	Render->CreateAnimation("Move_Bonfire", "Bonfire_2_2.png", 0, 2, 0.1f, true); // 움직이는 상태
	Render->ChangeAnimation("Move_Bonfire");
}
void ABonfire::Tick(float _DeltaTime)
{
}
