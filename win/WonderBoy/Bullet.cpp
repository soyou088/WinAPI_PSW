#include "Bullet.h"
#include "ContentsHelper.h"

ABullet::ABullet()
{
}

ABullet::~ABullet()
{
}

void ABullet::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);

	Render->CreateAnimation("BulletObject", "BulletObject1.png", 0, 0, 1.0f, true);
	Render->SetImage("BulletObject1.png");
	Render->SetTransform({ {0, -30 }, {100, 100} });

	Render->ChangeAnimation("BulletObject");

	Collision = CreateCollision(WonderCollisionOrder::Bullet);
	Collision->SetPosition({ 0,-28 });
	Collision->SetScale({ 50, 50 });
	Collision->SetColType(ECollisionType::Rect);

	Sound = UEngineSound::SoundPlay("item_get.wav");
	Sound.Off();
}


void ABullet::MakeBullet()
{
	Render->ActiveOn();
}






void ABullet::Tick(float _DeltaTime)
{	
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Object, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		MakeBullet();
	}

	if (true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		Render->ActiveOff();
		UContentsHelper::UIOn = true;
		Sound.On();
	}

}



