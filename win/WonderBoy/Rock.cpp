#include "Rock.h"

ARock::ARock()
{
}

ARock::~ARock()
{
}

void ARock::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);
	Render->SetImage("Rock.png");
	Render->SetTransform({ {0, 0 }, {300, 300} });
	Render->CreateAnimation("Rock", "Rock.png", 0, 3, 0.1f, true); // 움직이는 상태
	Render->ChangeAnimation("Rock");



	Collision = CreateCollision(WonderCollisionOrder::Rock);
	Collision->SetPosition({ 0,-30 });
	Collision->SetScale({ 68, 68});
	Collision->SetColType(ECollisionType::CirCle);


}



void ARock::Move(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	AddActorLocation(MoveVector * _DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);
}


void ARock::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}
}


void ARock::Tick(float _DeltaTime)
{
	if (true == UContentsHelper::RockOn )
	{
		Move(_DeltaTime);
	}
}