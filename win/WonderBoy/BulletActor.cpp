#include "BulletActor.h"
#include "ContentsHelper.h"
#include "Monster.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>




ABulletActor::ABulletActor()
{
}

ABulletActor::~ABulletActor()
{
	Sound.Off();
}

void ABulletActor::BeginPlay()
{
	{
		// Bullet Collision
		Render = CreateImageRenderer(WonderRenderOrder::PlayerBullet);
		Render->SetImage("Bullet_C.png");
		Render->SetTransform({ {0,0}, {130, 130} });


		Render->CreateAnimation("Bullet", "Bullet_C.png", 0, 3, 0.05f, true);
		BCollision = CreateCollision(WonderCollisionOrder::PlayerBullet);
		BCollision->SetScale({ 20,20 });
		BCollision->SetColType(ECollisionType::Rect);

		Render->ChangeAnimation("Bullet");
	}

		Sound = UEngineSound::SoundPlay("BulletSound.wav");
		Sound.On();

}

void ABulletActor::Move(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	AddActorLocation(BulletAcc * _DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);

	int a = 0;
}

void ABulletActor::ColBullet()
{
	AddActorLocation({-20, - 20});
}

void ABulletActor::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	std::vector<UCollision*> Result;
	if (Color == Color8Bit::MagentaA || true == BCollision->CollisionCheck(WonderCollisionOrder::Bonfire, Result))
	{
		GravityVector = FVector::Zero;
		Destroy();
	}
}



void ABulletActor::Tick(float _DeltaTime)
{

	ABulletActor* Bullet = nullptr;

	std::vector<UCollision*> Result;
	if (true == BCollision->CollisionCheck(WonderCollisionOrder::Stone, Result) 
		|| true == BCollision->CollisionCheck(WonderCollisionOrder::Object, Result) 
		|| true == BCollision->CollisionCheck(WonderCollisionOrder::Monster, Result)
		|| true == BCollision->CollisionCheck(WonderCollisionOrder::Rock, Result))
	{
		UCollision* BCollision = Result[0];
		AActor* Ptr = BCollision->GetOwner();
		AMonster* Monster = dynamic_cast<AMonster*>(Ptr);
		BulletAcc *= -0.2f;
		ColBullet();
		return;
	}




	Move(_DeltaTime);
}