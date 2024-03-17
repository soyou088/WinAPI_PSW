#include "Fruit.h"
#include "ContentsHelper.h"

AFruit::AFruit()
{
}

AFruit::~AFruit()
{
}

void AFruit::BeginPlay()
{
	AActor::BeginPlay();

	Apple = CreateImageRenderer(WonderRenderOrder::Object);

	Apple->SetImage("Apple.png");
	Apple->SetTransform({ {0, -28 }, {30, 35} });
	Apple->ActiveOff();

	CApple = CreateCollision(WonderCollisionOrder::Apple);
	CApple->SetPosition({ 0,-28 });
	CApple->SetScale({ 30, 35 });
	CApple->SetColType(ECollisionType::CirCle);

}


void AFruit::Score()
{
	Destroy();
}


void AFruit::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != CApple && true == CApple->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		Score();
	}


	if (true == UContentsHelper::AppleOn)
	{
		Apple->ActiveOn();
	}
}


