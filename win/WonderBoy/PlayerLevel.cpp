#include "PlayerLevel.h"
#include "Player.h"
#include "Monster.h"
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
	//Monster->SetActorLocation({ 200, 873 });

	APlayer* Player = SpawnActor<APlayer>();
	Player->SetName("Player");
	Player->SetActorLocation({ 150, 873 });
	//Player->SetActorLocation({150, 200});



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