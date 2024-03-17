#include "Switch.h"
#include "ContentsHelper.h"


ASwitch::ASwitch()
{
}

ASwitch::~ASwitch()
{
}

void ASwitch::BeginPlay()
{
	Collision = CreateCollision(WonderCollisionOrder::Switch);
	Collision->SetPosition({ 0,-30 });
	Collision->SetScale({ 20, 100 });
	Collision->SetColType(ECollisionType::Rect);

	ColApple = CreateCollision(WonderCollisionOrder::Apple);
	ColApple->SetPosition({ 0,-30 });
	ColApple->SetScale({ 20, 1000 });
	ColApple->SetColType(ECollisionType::Rect);
	 
}

void ASwitch::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		UContentsHelper::RockOn = true;
	}

	if (nullptr != ColApple && true == ColApple->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		UContentsHelper::AppleOn = true;
	}
}

