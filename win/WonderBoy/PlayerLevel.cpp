#include "PlayerLevel.h"
#include "Player.h"
#include "BackGroundMap.h"
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
	Map->SetMapImage("Stage1.png");
	Map->SetColMapImage("Stage1_Col.png");
	Map->SwitchDebug();


	APlayer* Player = SpawnActor<APlayer>();
	Player->SetName("Player");
	Player->SetActorLocation({ 100, 100 });
	

	

}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
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