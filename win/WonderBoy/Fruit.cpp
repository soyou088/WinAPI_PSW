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

	ColCheck = CreateCollision(WonderCollisionOrder::Fruit);
	ColCheck->SetPosition({ -230,-28 });
	ColCheck->SetScale({ 10, 1000 });
	ColCheck->SetColType(ECollisionType::Rect);

	DesCheck = CreateCollision(WonderCollisionOrder::Fruit);
	DesCheck->SetPosition({ 0,-28 });
	DesCheck->SetScale({ 30, 30 });
	DesCheck->SetColType(ECollisionType::CirCle);


	Sound = UEngineSound::SoundPlay("item_get.wav");
	Sound.Off();

}


void AFruit::Score()
{
	ColCheck->Destroy();
}




void AFruit::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != ColCheck && true == ColCheck->CollisionCheck(WonderCollisionOrder::Player, Result))
	{

		AActor* MCol = Result[0]->GetOwner();
		Collision();
	}
	if (nullptr != DesCheck && true == DesCheck->CollisionCheck(WonderCollisionOrder::Player, Result))
	{

		AActor* MCol = Result[0]->GetOwner();
		Apple->ActiveOff();
		Sound.On();
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
		Apple->SetTransform({ {20, -230 }, {35, 35} });
		DesCheck->SetPosition({ 20, -230 });
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
		Apple->SetImage("Apple.png");
		Apple->SetTransform({ {0, -28 }, {30, 35} });
		Score();
		break;
	case 5:
		Apple = CreateImageRenderer(WonderRenderOrder::Object);
		Apple->SetImage("Melon.png");
		Apple->SetTransform({ {0, -28 }, {30, 35} });
		Score();
		break;
	}
}


