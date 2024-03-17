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
#include "Rock.h"
#include "Switch.h"
#include "Board.h"

#include "UI_Player.h"
#include "Stage.h"
#include "UI_Back.h"
#include "UIEX.h"
#include "UI_item.h"
#include "Life.h"
#include "UI_HP.h"

#include "Fruit.h"

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
	Map->SetMapImage("Map5.png");
	Map->SetColMapImage("ColMap7.png");

	AMonster* Monster2 = SpawnActor<AMonster>();
	Monster2->SetName("Monster2");
	Monster2->SetActorLocation({ 2268, 1019 });

	AMonster* Monster3 = SpawnActor<AMonster>();
	Monster3->SetName("Monster3");
	Monster3->SetActorLocation({ 2762, 1019 });

	AMonster* Monster4 = SpawnActor<AMonster>();
	Monster4->SetName("Monster4");
	Monster4->SetActorLocation({ 2922, 1019 });

	AMonster* Monster5 = SpawnActor<AMonster>();
	Monster5->SetName("Monster5");
	Monster5->SetActorLocation({ 4888, 1019 });

	AMonster* Monster6 = SpawnActor<AMonster>();
	Monster6->SetName("Monster6");
	Monster6->SetActorLocation({ 5654, 1019 });

	ABee* Bee = SpawnActor<ABee>();
	Bee->SetName("Bee");
	Bee->SetActorLocation({ 500, 800 });

	ASnake* Snake = SpawnActor<ASnake>();
	Snake->SetName("Snake");
	Snake->SetActorLocation({ 13788, 1021 });
	

	ABonfire* Bonfire = SpawnActor<ABonfire>();
	Bonfire->SetName("Bonfire");
	Bonfire->SetActorLocation({ 13103,1035});

	AJumpping* Jumpping = SpawnActor<AJumpping>();
	Jumpping->SetName("Jumpping");
	Jumpping->SetActorLocation({ 20806,396 });

	ABoard* Board = SpawnActor<ABoard>();
	Board->SetName("Board");
	Board->SetActorLocation({ 7348,1019 });
	Board->AllRenderersActiveOff();


	AAgg* Agg = SpawnActor<AAgg>();
	Agg->SetName("Agg");
	Agg->SetActorLocation({ 1787,1019 });

	AAgg* Agg2 = SpawnActor<AAgg>();
	Agg2->SetName("Agg2");
	Agg2->SetActorLocation({ 7146,1019 });

	AAgg* Agg3 = SpawnActor<AAgg>();
	Agg3->SetName("Agg3");
	Agg3->SetActorLocation({ 16070,489 });


	ABullet* BulletObject = SpawnActor<ABullet>();
	BulletObject->SetName("BulletObject");
	BulletObject->SetActorLocation({ 2001,1019 });
	BulletObject->AllRenderersActiveOff();
	
	AStone* Stone = SpawnActor<AStone>();
	Stone->SetName("Stone");
	Stone->SetActorLocation({ 3549,1019 });
	Stone->AllRenderersActiveOff();

	AStone* Stone2 = SpawnActor<AStone>();
	Stone2->SetName("Stone");
	Stone2->SetActorLocation({ 4058,1019 });
	Stone2->AllRenderersActiveOff();

	AStone* Stone3 = SpawnActor<AStone>();
	Stone3->SetName("Stone");
	Stone3->SetActorLocation({ 4196,1019 });
	Stone3->AllRenderersActiveOff();

	AStone* Stone4 = SpawnActor<AStone>();
	Stone4->SetName("Stone");
	Stone4->SetActorLocation({ 10610,1019 });
	Stone4->AllRenderersActiveOff();

	AStone* Stone5 = SpawnActor<AStone>();
	Stone5->SetName("Stone");
	Stone5->SetActorLocation({ 11443,1019 });
	Stone5->AllRenderersActiveOff();

	AStone* Stone6 = SpawnActor<AStone>();
	Stone6->SetName("Stone");
	Stone6->SetActorLocation({ 12595,1019 });
	Stone6->AllRenderersActiveOff();

	AStone* Stone7 = SpawnActor<AStone>();
	Stone7->SetName("Stone");
	Stone7->SetActorLocation({ 12775,1019 });
	Stone7->AllRenderersActiveOff();

	AStone* Stone8 = SpawnActor<AStone>();
	Stone8->SetName("Stone");
	Stone8->SetActorLocation({ 19285,369 });
	Stone8->AllRenderersActiveOff();

	AStone* Stone9 = SpawnActor<AStone>();
	Stone9->SetName("Stone");
	Stone9->SetActorLocation({ 19980,369 });
	Stone9->AllRenderersActiveOff();
	
	AStone* Stone10 = SpawnActor<AStone>();
	Stone10->SetName("Stone");
	Stone10->SetActorLocation({ 20071,369 });
	Stone10->AllRenderersActiveOff();


	ARock* Rock = SpawnActor<ARock>();
	Rock->SetName("Rock");
	Rock->SetActorLocation({ 14788 ,300 });

	ARock* Rock2 = SpawnActor<ARock>();
	Rock2->SetName("Rock");
	Rock2->SetActorLocation({ 15361 ,200});

	ARock* Rock3 = SpawnActor<ARock>();
	Rock3->SetName("Rock");
	Rock3->SetActorLocation({ 15934 ,100 });

	ASwitch* Switch = SpawnActor<ASwitch>();
	Switch->SetName("RockSwitch");
	Switch->SetActorLocation({ 13912, 1019 });



	// UI
	AStage* Stage = SpawnActor<AStage>();
	Stage->SetName("Stage");
	Stage->SetActorLocation({ 326, 830 });
	Stage->Destroy(2.0f);

//	AUIEX* UIEX = SpawnActor<AUIEX>();
//	UIEX->SetName("UIEX");
//	UIEX->SetActorLocation({ 256,55 });

	AUI_Back* UIBack = SpawnActor<AUI_Back>();
	UIBack->SetName("UI_Back");
	UIBack->SetActorLocation({ 350,40 });
	
	AUI_Player* UIPlayer = SpawnActor<AUI_Player>();
	UIPlayer->SetName("UI_PLayer");
	UIPlayer->SetActorLocation({ 70,12 });

	ALife* Life = SpawnActor<ALife>();
	Life->SetName("Life");
	Life->SetActorLocation({ 23,59 });

	ALife* Life2 = SpawnActor<ALife>();
	Life2->SetName("Life");
	Life2->SetActorLocation({ 61,59 });

	AUI_item* UIitem = SpawnActor<AUI_item>();
	UIitem->SetName("UI_item");
	UIitem->SetActorLocation({ 73,95});

	AUI_HP* UIHP = SpawnActor<AUI_HP>();
	UIHP->SetName("HP");
	UIHP->SetActorLocation({ 500, 59 });


	AFruit* Apple = SpawnActor<AFruit>();
	Apple->SetName("Apple");
	Apple->SetActorLocation({ 1047  ,1019 });
	Apple->FruitNumber = 1;

	AFruit* DApple = SpawnActor<AFruit>();
	DApple->SetName("DApple");
	DApple->SetActorLocation({ 1047  ,1019 });
	DApple->FruitNumber = 1;

	DApple = SpawnActor<AFruit>();
	DApple->SetName("DApple");
	DApple->SetActorLocation({ 1047  ,1019 });
	DApple->FruitNumber = 2;


	// Player
	APlayer* Player = SpawnActor<APlayer>();
	Player->SetName("Player");
	Player->SetActorLocation({ 227, 873 });

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