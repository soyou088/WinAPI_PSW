#include "BulletActor.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"



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
		BRenderer->SetImage("Bullet.png");
		BRenderer->SetTransform({ {0,0}, {200, 200} });


		BRenderer->CreateAnimation("Bullet", "Bullet.png", 0, 3, 0.1f, true);
		BCollision = CreateCollision(WonderCollisionOrder::PlayerBullet);
		BCollision->SetScale({ 10,10 });
		BCollision->SetColType(ECollisionType::Rect);
	}
}




void ABulletActor::Tick(float _DeltaTime)
{
	Move(_DeltaTime);
}

//void ABulletActor::Bullet()
//{
//
//	BulletVector = BulletAcc;
//	FVector GetPos = GetActorLocation();
//
//
//
//	GetActorLocation().X - 1; // Left 왼쪽을 볼때 나간다
//	GetActorLocation().X + 1; // Right 오른쪽을 볼때 나간다
//
//
//
//	// 일단 여기서 렌더 할 필요가 있을까 ?
//	// 미리 렌더를 해놓고 bullet을 실행 했을때 보이면 되는건가 ? 생각해보자
//	// bullet의 Actor는 어떻게 움직여야 할까 ?
//	// 플레이어가 왼쪽을 볼때 GetActorLocation().X -1 에서 bullet이 나간다.
//	// Bullet의 AddBulletPos(FVector::Right)
//	// 
//	// 플레이어가 오른쪽을 볼때 GetActorLocation().X +1 에서 bullet이 나간다.
//	// Bullet의 AddBulletPos(FVector::Left) 
//	// 
//	// 이렇게 움직인다.	
//
//	// UCollision* CreateCollision(int _Order = 0);
//	// UImageRenderer* CreateImageRenderer(int _Order = 0);
//	// 이걸 쓰면 될까 ?
//	// 
//	// Gravity를 체크 해야한다. 중력을 받아야 한다.
//	// 이미지 회전
//
//}


void ABulletActor::Move(float _DeltaTime)
{
	AddActorLocation(BulletAcc * _DeltaTime);
	CalGravityVector(_DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);

}


void ABulletActor::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA || Color == Color8Bit(100, 0, 0, 0))
	{
		GravityVector = FVector::Zero;
		Destroy();
	}

}
