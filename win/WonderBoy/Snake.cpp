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
	Render->SetImage("Snake.png");
	Render->SetTransform({ {0, 0}, {400, 400} });
	Render->CreateAnimation("Snake1", "Snake.png", 0, 1, 0.05f, true); // 움직이는 상태
	Render->CreateAnimation("Snake2", "Snake.png", 2, 2, 0.1f, true);
	Render->CreateAnimation("Death", "Snake.png", 3, 3, 0.1f, true);
	
	Render->ChangeAnimation("Snake1");

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
	// 0.1초후 애니메이션을 체인지 한다. 이걸 반복
	// Render->ChangeAnimation("Snake2");
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
