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
//	GetActorLocation().X - 1; // Left ������ ���� ������
//	GetActorLocation().X + 1; // Right �������� ���� ������
//
//
//
//	// �ϴ� ���⼭ ���� �� �ʿ䰡 ������ ?
//	// �̸� ������ �س��� bullet�� ���� ������ ���̸� �Ǵ°ǰ� ? �����غ���
//	// bullet�� Actor�� ��� �������� �ұ� ?
//	// �÷��̾ ������ ���� GetActorLocation().X -1 ���� bullet�� ������.
//	// Bullet�� AddBulletPos(FVector::Right)
//	// 
//	// �÷��̾ �������� ���� GetActorLocation().X +1 ���� bullet�� ������.
//	// Bullet�� AddBulletPos(FVector::Left) 
//	// 
//	// �̷��� �����δ�.	
//
//	// UCollision* CreateCollision(int _Order = 0);
//	// UImageRenderer* CreateImageRenderer(int _Order = 0);
//	// �̰� ���� �ɱ� ?
//	// 
//	// Gravity�� üũ �ؾ��Ѵ�. �߷��� �޾ƾ� �Ѵ�.
//	// �̹��� ȸ��
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
