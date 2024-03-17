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

	CApple = CreateCollision(WonderCollisionOrder::Object);
	CApple->SetPosition({ 0,-28 });
	CApple->SetScale({ 100, 100 });
	CApple->SetColType(ECollisionType::CirCle);

	DApple = CreateCollision(WonderCollisionOrder::Object);
	DApple->SetPosition({ 0,-28 });
	DApple->SetScale({ 20, 20 });
	DApple->SetColType(ECollisionType::CirCle);


}


void AFruit::Score()
{
	CApple->Destroy();
}




void AFruit::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != CApple && true == CApple->CollisionCheck(WonderCollisionOrder::Player, Result))
	{

		AActor* MCol = Result[0]->GetOwner();
		Collision();
	}
	if (nullptr != DApple && true == DApple->CollisionCheck(WonderCollisionOrder::Player, Result))
	{

		AActor* MCol = Result[0]->GetOwner();
		Apple->ActiveOff();
	}

}

void AFruit::Collision()
{

	switch (FruitNumber)
	{
	case 1:
		Apple = CreateImageRenderer(WonderRenderOrder::Object);
		Apple->SetImage("Apple.png");
		Apple->SetTransform({ {0, -28 }, {30, 35} });
		Score();
		break;
	case 2:
		Apple = CreateImageRenderer(WonderRenderOrder::Object);
		Apple->SetImage("Banana.png");
		Apple->SetTransform({ {20, -100 }, {30, 35} });

		Score();
		break;
	case 3:
		Apple = CreateImageRenderer(WonderRenderOrder::Object);
		Apple->SetImage("Carrot.png");
		Apple->SetTransform({ {0, -28 }, {30, 35} });
		Score();
		break;
	case 4:
		Apple = CreateImageRenderer(WonderRenderOrder::Object);
		Apple->SetImage("Melon.png");
		Apple->SetTransform({ {0, -28 }, {30, 35} });
		Score();

		break;
	}
}


