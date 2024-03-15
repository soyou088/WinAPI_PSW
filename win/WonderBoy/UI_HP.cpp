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

	Render->CreateAnimation("HP", "HP", 0, 29, 2.0f, true);
	Render->ChangeAnimation("HP");

	Render->SetImage("A.png");
	Render->SetTransform({ {0, 0}, {380, 32} });

	Render->CameraEffectOff();

}

void AUI_HP::Tick(float _DeltaTime)
{
}

