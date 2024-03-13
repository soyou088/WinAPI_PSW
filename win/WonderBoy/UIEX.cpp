#include "UIEX.h"

AUIEX::AUIEX()
{
}

AUIEX::~AUIEX()
{
}

void AUIEX::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("UIEX", "UIEX.png", 0, 0, 0.1f, true);
	Render->ChangeAnimation("UIEX");

	Render->SetImage("UIEX.png");
	Render->SetTransform({ {0, 0}, {512, 100} });

	Render->CameraEffectOff();
}

void AUIEX::Tick(float _DeltaTime)
{
}

