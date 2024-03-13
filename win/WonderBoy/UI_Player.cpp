#include "UI_Player.h"

AUI_Player::AUI_Player()
{
}

AUI_Player::~AUI_Player()
{
}

void AUI_Player::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("UI_Player", "UI_Player", 0, 8, 0.1f, true);
	Render->ChangeAnimation("UI_Player");
	
	Render->SetImage("PLAYER1.png");
	Render->SetTransform({ {0, 0 }, {100, 30} });
	
	Render->CameraEffectOff();
	
}

void AUI_Player::Tick(float _DeltaTime)
{
}

