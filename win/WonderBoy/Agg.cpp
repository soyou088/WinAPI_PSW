#include "Agg.h"

AAgg::AAgg()
{
}

AAgg::~AAgg()
{
}

void AAgg::BeginPlay()
{
	AActor::BeginPlay();

		Render = CreateImageRenderer(WonderRenderOrder::Object);
		Render->SetImage("Agg.png");
		Render->SetTransform({ {0, 0 }, {400, 400} });

		Render->CreateAnimation("Idel_Agg", "Agg.png", 0, 0, 0.1f, true); 
		Render->ChangeAnimation("Idel_Agg");

		Render->CreateAnimation("Destory_Agg", "Agg.png", 1, 1, 0.1f, true);

		Collision = CreateCollision(WonderCollisionOrder::Object);
		Collision->SetPosition({ 0,-30 });
		Collision->SetScale({ 70, 50 });
		Collision->SetColType(ECollisionType::Rect);
}

//void AAgg::ColAgg()
//{
//	AddActorLocation(JumpVector * JumpPower);
//}

void AAgg::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}
}

void AAgg::CalLastMoveVector(float _DeltaTime)
{
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
}

void AAgg::MoveLastMoveVector(float _DeltaTime)
{
	AddActorLocation(LastMoveVector * _DeltaTime);
}

void AAgg::MoveUpdate(float _DeltaTime)
{
	CalLastMoveVector(_DeltaTime);
	CalGravityVector(_DeltaTime);
	MoveLastMoveVector(_DeltaTime);
}


void AAgg::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		// 닿았을때 포물선을 그린다 , GetColor하고 Destroy
		Render->ChangeAnimation("Destory_Agg");
		MoveUpdate(_DeltaTime);

	}
}

