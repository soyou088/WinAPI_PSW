#include "UI_Back.h"

AUI_Back::AUI_Back()
{
}

AUI_Back::~AUI_Back()
{
}

void AUI_Back::BeginPlay()
{
	AActor::BeginPlay();

		Render = CreateImageRenderer(WonderRenderOrder::UI);

		Render->CreateAnimation("UI_Back", "UI_Back.png", 0, 0, 1.0f, true);
		Render->SetImage("UI_Back.png");
		Render->SetTransform({ {0, 0 }, {700, 75} });

		Render->ChangeAnimation("UI_Back");

		Render->CameraEffectOff();
}

void AUI_Back::Tick(float _DeltaTime)
{
}

