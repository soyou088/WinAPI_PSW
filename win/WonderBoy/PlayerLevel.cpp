#include "PlayerLevel.h"
#include "Player.h"
#include "Monster.h"
#include "Bee.h"
#include "Bonfire.h"
#include "Jumpping.h"
#include "Agg.h"
#include "BackGroundMap.h"
#include "BulletActor.h"
#include <EngineCore\EngineCore.h>

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}

void UPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();
	

	ABackGroundMap* Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("Map3.png");
	Map->SetColMapImage("ColMap3.png");

	AMonster* Monster = SpawnActor<AMonster>();
	Monster->SetName("Monster");
	
	ABee* Bee = SpawnActor<ABee>();
	Bee->SetName("Bee");
	Bee->SetActorLocation({ 200, 800 });

	ABonfire* Bonfire = SpawnActor<ABonfire>();
	Bonfire->SetName("Bonfire");
	Bonfire->SetActorLocation({ 11234,885 });

	AJumpping* Jumpping = SpawnActor<AJumpping>();
	Jumpping->SetName("Jumpping");
	Jumpping->SetActorLocation({ 17875,890 });

	AAgg* Agg = SpawnActor<AAgg>();
	Agg->SetName("Agg");
	Agg->SetActorLocation({ 250,875 });

	APlayer* Player = SpawnActor<APlayer>();
	Player->SetName("Player");
	Player->SetActorLocation({ 150, 873 });

}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	FVector Pos = GetCameraPos();
	// ���� ī�޶� ��ġ
	if (0.0f >= Pos.X)
	{
		Pos.X = 0.0f;
	}

	SetCameraPos(Pos);
}

void UPlayLevel::LevelStart(ULevel* _Level)
{
	// ���⼭ ���ҽ��� �ε��ϰ�
	// ���͵� ���⼭ �����
	int a = 0;
}
void UPlayLevel::LevelEnd(ULevel* _Level)
{
	// ���ҽ��� ������.
	// ���͸� �����Ѵ�.
	int a = 0;
}