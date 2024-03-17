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
	Collision->SetScale({ 20, 1000 });
	Collision->SetColType(ECollisionType::Rect);
}

void ASwitch::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		UContentsHelper::RockOn = true;
	}


}

