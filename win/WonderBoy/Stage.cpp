#include "Stage.h"

AStage::AStage()
{
}

AStage::~AStage()
{
}

void AStage::BeginPlay()
{
	Render = CreateImageRenderer(WonderRenderOrder::UI);

	Render->CreateAnimation("Stage", "Stage.png", 0, 0, 1.0f, true);
	Render->SetImage("Stage.png");
	Render->SetTransform({ {0, 0 }, {180, 180} });

	Render->ChangeAnimation("Stage");
}

void AStage::Tick(float _DeltaTime)
{
	
}

