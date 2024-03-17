#include "Snake.h"

ASnake::ASnake()
{
}

ASnake::~ASnake()
{
}

void ASnake::BeginPlay()
{
	Render = CreateImageRenderer(WonderRenderOrder::Monster);
	Render->SetImage("Snake2.png");
	Render->SetTransform({ {0, 0}, {300, 300} });
	Render->CreateAnimation("Snake", "Snake2.png", 0, 12, 0.1f, true); // 움직이는 상태
	Render->CreateAnimation("Death", "Snake2.png", 13, 13, 0.1f, true);
	
	Render->ChangeAnimation("Snake");

	Collision = CreateCollision(WonderCollisionOrder::Monster);
	Collision->SetPosition({ 0,-28 });
	Collision->SetScale({ 50, 50 });
	Collision->SetColType(ECollisionType::Rect);



}


void ASnake::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY() - 5, Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA)
	{
		GravityVector = FVector::Zero;
		ColGra = true;
	}
}

void ASnake::DesMoveUpdate(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
	AddActorLocation((JumpVector + ColMoveVector) * _DeltaTime);
	AddActorLocation(GravityVector * _DeltaTime);

	if (ColSnake == true && ColGra == true)
	{
		Destroy();
	}

}

void ASnake::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::PlayerBullet, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		Render->ChangeAnimation("Death");
		ColSnake = true;
	}

	if (ColSnake == true)
	{
		DesMoveUpdate(_DeltaTime);

	}
}
