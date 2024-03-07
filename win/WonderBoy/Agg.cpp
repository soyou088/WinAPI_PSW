#include "Agg.h"

AAgg::AAgg()
{
}

AAgg::~AAgg()
{
}

void AAgg::BeginPlay()
{
	AActor::BeginPlay();

	{
		Render = CreateImageRenderer(WonderRenderOrder::Object);
		Render->SetImage("Agg.png");
		Render->SetTransform({ {0, 0 }, {400, 400} });

		Render->CreateAnimation("Idel_Agg", "Agg.png", 0, 0, 0.1f, true); 
		Render->ChangeAnimation("Idel_Agg");
	}

	{
		Render->CreateAnimation("Destory_Agg", "Agg.png", 1, 1, 0.1f, true);
	}
}


void AAgg::ColAgg()
{


}

void AAgg::Tick(float _DeltaTime)
{
}

