#include "Board.h"

ABoard::ABoard()
{
}

ABoard::~ABoard()
{
}

void ABoard::BeginPlay()
{
	AActor::BeginPlay();

	Render = CreateImageRenderer(WonderRenderOrder::Object);

	Render->CreateAnimation("Board", "Board.png", 0, 0, 1.0f, true);
	Render->SetImage("Board.png");
	Render->SetTransform({ {0, -10 }, {300, 150} });

	Render->ChangeAnimation("Board");

	Collision = CreateCollision(WonderCollisionOrder::Board);
	Collision->SetPosition({ 0,-28 });
	Collision->SetScale({ 100, 50 });
	Collision->SetColType(ECollisionType::Rect);

	Sound = UEngineSound::SoundPlay("item_get.wav");
	Sound.Off();
}


void ABoard::MakeBullet()
{
	Render->ActiveOn();
}

void ABoard::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Object, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		MakeBullet();
	}

	if (true == Collision->CollisionCheck(WonderCollisionOrder::Player, Result))
	{
		Sound.On();
		Render->ActiveOff();
	}
}
