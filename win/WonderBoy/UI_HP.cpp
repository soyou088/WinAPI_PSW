#include "UI_HP.h"

AUI_HP::AUI_HP()
{
}

AUI_HP::~AUI_HP()
{
}

void AUI_HP::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("HP", "HP", 0, 8, 0.1f, true);
	Render->ChangeAnimation("HP");

	Render->SetImage("HP-0.png");
	Render->SetTransform({ {0, 0}, {280, 30} });

	Render->CameraEffectOff();

}

void AUI_HP::Tick(float _DeltaTime)
{
}

