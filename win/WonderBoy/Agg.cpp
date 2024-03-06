#include "Agg.h"

Agg::Agg()
{
}

Agg::~Agg()
{
}

void Agg::BeginPlay()
{
	AActor::BeginPlay();

	{
		Render = CreateImageRenderer(WonderRenderOrder::Monster);
		Render->SetImage("Agg.png");
		Render->SetTransform({ {0, 0 }, {400, 400} });

		Render->CreateAnimation("Idel_Agg", "Agg.png", 0, 0, 0.1f, true); 
		Render->ChangeAnimation("Idel_Agg");
	}

	{
		Render->CreateAnimation("Destory_Agg", "Agg.png", 1, 1, 0.1f, true);
	}
}

void Agg::Tick(float _DeltaTime)
{
}
