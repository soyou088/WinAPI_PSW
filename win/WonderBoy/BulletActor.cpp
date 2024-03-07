#include "BulletActor.h"
#include "ContentsHelper.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>



ABulletActor::ABulletActor()
{
}

ABulletActor::~ABulletActor()
{
}

void ABulletActor::BeginPlay()
{
	{
		// Bullet Collision
		BRenderer = CreateImageRenderer(WonderRenderOrder::PlayerBullet);
		BRenderer->SetImage("Bullet_C.png");
		BRenderer->SetTransform({ {0,0}, {130, 130} });


		BRenderer->CreateAnimation("Bullet", "Bullet_C.png", 0, 3, 0.05f, true);
		BCollision = CreateCollision(WonderCollisionOrder::PlayerBullet);
		BCollision->SetScale({ 10,10 });
		BCollision->SetColType(ECollisionType::Rect);

		BRenderer->ChangeAnimation("Bullet");
	}
}


void ABulletActor::Tick(float _DeltaTime)
{
	Move(_DeltaTime);

	ABulletActor* Bullet = nullptr;

	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		FVector BulletDir = FVector::Right;

		FVector BulletDirNormal = BulletDir.Normalize2DReturn();
	}
	else
	{
		FVector BulletDir = FVector::Left;

		FVector BulletDirNormal = BulletDir.Normalize2DReturn();
	}

	//std::vector<UCollision*> Result;
	//if (true == BCollision->CollisionCheck(WonderCollisionOrder::Monster, Result))
	//{
	//	Result[0]->GetOwner()
	//	
	//		
	//	return;
	//}

}

void ABulletActor::Move(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	if (DirState == EActorDir::Left)
	{
		AddActorLocation(-BulletAcc * _DeltaTime);
	}
	else
	{

		AddActorLocation(BulletAcc * _DeltaTime);
	}
	AddActorLocation(GravityVector * _DeltaTime);
}

void ABulletActor::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA)
	{
		GravityVector = FVector::Zero;
		Destroy();
	}
}
