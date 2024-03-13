#include "UI_item.h"

AUI_item::AUI_item()
{
}

AUI_item::~AUI_item()
{
}

void AUI_item::BeginPlay()
{
	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("UI_item", "UI_item.png", 0, 0, 1.0f, true);
	Render->SetImage("UI_item.png");
	Render->SetTransform({ {0, 0 }, {145, 36} });

	Render->ChangeAnimation("UI_item");

	Render->CameraEffectOff();
}

void AUI_item::Tick(float _DeltaTime)
{
}

