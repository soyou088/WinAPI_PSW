#include "Life.h"

ALife::ALife()
{
}

ALife::~ALife()
{
}

void ALife::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("Life", "Life.png", 0, 0, 1.0f, true);
	Render->SetImage("Life.png");
	Render->SetTransform({ {0, 0 }, {38, 38} });

	Render->ChangeAnimation("Life");

	Render->CameraEffectOff();
}

void ALife::Tick(float _DeltaTime)
{
}

