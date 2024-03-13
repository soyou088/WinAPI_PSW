#include "PlayerLevel.h"
#include "Player.h"
#include "Monster.h"
#include "Bee.h"
#include "Snake.h"
#include "Bonfire.h"
#include "Jumpping.h"
#include "Agg.h"
#include "Bullet.h"
#include "Stone.h"

#include "UI_Player.h"
#include "Stage.h"
#include "UI_Back.h"

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

	AMonster* Monster2 = SpawnActor<AMonster>();
	Monster2->SetName("Monster2");
	Monster2->SetActorLocation({ 1437, 873 });

	AMonster* Monster3 = SpawnActor<AMonster>();
	Monster3->SetName("Monster3");
	Monster3->SetActorLocation({ 1931, 873 });

	AMonster* Monster4 = SpawnActor<AMonster>();
	Monster4->SetName("Monster4");
	Monster4->SetActorLocation({ 2091, 873 });

	AMonster* Monster5 = SpawnActor<AMonster>();
	Monster5->SetName("Monster5");
	Monster5->SetActorLocation({ 4057, 873 });

	AMonster* Monster6 = SpawnActor<AMonster>();
	Monster6->SetName("Monster6");
	Monster6->SetActorLocation({ 4823, 873 });

	ABee* Bee = SpawnActor<ABee>();
	Bee->SetName("Bee");
	Bee->SetActorLocation({ 500, 800 });

	
	ASnake* Snake = SpawnActor<ASnake>();
	Snake->SetName("Snake");
	Snake->SetActorLocation({ 11832, 875});
	
	ABonfire* Bonfire = SpawnActor<ABonfire>();
	Bonfire->SetName("Bonfire");
	Bonfire->SetActorLocation({ 11234,885 });

	AJumpping* Jumpping = SpawnActor<AJumpping>();
	Jumpping->SetName("Jumpping");
	Jumpping->SetActorLocation({ 17875,890 });


	AAgg* Agg = SpawnActor<AAgg>();
	Agg->SetName("Agg");
	Agg->SetActorLocation({ 897,875 });

	AAgg* Agg2 = SpawnActor<AAgg>();
	Agg2->SetName("Agg2");
	Agg2->SetActorLocation({ 6126,875 });


	ABullet* BulletObject = SpawnActor<ABullet>();
	BulletObject->SetName("BulletObject");
	BulletObject->SetActorLocation({ 1106,875 });
	BulletObject->AllRenderersActiveOff();
	


	AStone* Stone = SpawnActor<AStone>();
	Stone->SetName("Stone");
	Stone->SetActorLocation({ 3041,850 });
	Stone->AllRenderersActiveOff();

	AStone* Stone2 = SpawnActor<AStone>();
	Stone2->SetName("Stone");
	Stone2->SetActorLocation({ 3480,850 });
	Stone2->AllRenderersActiveOff();

	AStone* Stone3 = SpawnActor<AStone>();
	Stone3->SetName("Stone");
	Stone3->SetActorLocation({ 3599,850 });
	Stone3->AllRenderersActiveOff();

	AStone* Stone4 = SpawnActor<AStone>();
	Stone4->SetName("Stone");
	Stone4->SetActorLocation({ 9098,850 });
	Stone4->AllRenderersActiveOff();

	AStone* Stone5 = SpawnActor<AStone>();
	Stone5->SetName("Stone");
	Stone5->SetActorLocation({ 9811,850 });
	Stone5->AllRenderersActiveOff();

	AStone* Stone6 = SpawnActor<AStone>();
	Stone6->SetName("Stone");
	Stone6->SetActorLocation({ 10800,850 });
	Stone6->AllRenderersActiveOff();

	AStone* Stone7 = SpawnActor<AStone>();
	Stone7->SetName("Stone");
	Stone7->SetActorLocation({ 10957,850 });
	Stone7->AllRenderersActiveOff();

	AStone* Stone8 = SpawnActor<AStone>();
	Stone8->SetName("Stone");
	Stone8->SetActorLocation({ 16537,300 });
	Stone8->AllRenderersActiveOff();

	AStone* Stone9 = SpawnActor<AStone>();
	Stone9->SetName("Stone");
	Stone9->SetActorLocation({ 17130,300 });
	Stone9->AllRenderersActiveOff();
	
	AStone* Stone10 = SpawnActor<AStone>();
	Stone10->SetName("Stone");
	Stone10->SetActorLocation({ 17211,300});
	Stone10->AllRenderersActiveOff();



	// UI
	AStage* Stage = SpawnActor<AStage>();
	Stage->SetName("Stage");
	Stage->SetActorLocation({ 260, 700 });
	Stage->Destroy(2.0f);

	AUI_Back* UIBack = SpawnActor<AUI_Back>();
	UIBack->SetName("UI_Back");
	UIBack->SetActorLocation({ 250,85 });
	
	AUI_Player* UIPlayer = SpawnActor<AUI_Player>();
	UIPlayer->SetName("UI_PLayer");
	UIPlayer->SetActorLocation({ 70,10 });


	// Player
	APlayer* Player = SpawnActor<APlayer>();
	Player->SetName("Player");
	Player->SetActorLocation({ 150, 873 });

}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	FVector Pos = GetCameraPos();
	// 시작 카메라 위치
	if (0.0f >= Pos.X)
	{
		Pos.X = 0.0f;
	}

	SetCameraPos(Pos);

	
}

void UPlayLevel::LevelStart(ULevel* _Level)
{
	// 여기서 리소스를 로드하고
	// 액터도 여기서 만들고
	int a = 0;
}
void UPlayLevel::LevelEnd(ULevel* _Level)
{
	// 리소스도 날려요.
	// 액터를 삭제한다.
	int a = 0;
}