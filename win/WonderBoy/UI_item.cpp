#include "UI_item.h"
#include "Bullet.h"

AUI_item::AUI_item()
{
}

AUI_item::~AUI_item()
{
}

void AUI_item::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::UI);
	UIRender = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("UI_item", "UI_item.png", 0, 0, 1.0f, true);
	Render->SetImage("UI_item.png");
	Render->SetTransform({ {0, 0 }, {145, 36} });


	UIRender->CreateAnimation("UIEX_3", "UIEX_3.png", 0, 0, 1.0f, true);
	UIRender->SetImage("UIEX_3.png");
	UIRender->SetTransform({ {0, 0 }, {145, 36} });

	UIRender->ActiveOff();

	Render->ChangeAnimation("UI_item");

	Render->CameraEffectOff();
	UIRender->CameraEffectOff();
}



void AUI_item::SetUI()
{
	UIRender->ActiveOn();
	UIRender->ChangeAnimation("UIEX_3");
}




void AUI_item::Tick(float _DeltaTime)
{
	Render->ActiveOn();
	if (UContentsHelper::UIOn == true)
	{
		SetUI();
	}
}



