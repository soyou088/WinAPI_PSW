#include "Bridge.h"

Bridge::Bridge()
{
}

Bridge::~Bridge()
{
}

void Bridge::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);

	Render->SetImage("Bridge.png");
	Render->SetTransform({ {0, -10 }, {150, 50} });

}

void Bridge::Tick(float _DeltaTime)
{
}
