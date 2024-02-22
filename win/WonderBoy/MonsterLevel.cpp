#include "Monster.h"
#include "MonsterLevel.h"
#include "BackGroundMonster.h"
#include <EngineCore\EngineCore.h>


UMonsterLevel::UMonsterLevel()
{
}

UMonsterLevel::~UMonsterLevel()
{
}

void UMonsterLevel::BeginPlay()
{
	ULevel::BeginPlay();

	ABackGroundMonster* Monster = SpawnActor<ABackGroundMonster>();
	Monster->SetMonsterImage("Monster1.png");
	Monster->SetColMonsterImage("ColMonster.png");

	AMonster* Monster = SpawnActor<AMonster>();
	Monster->SetName("Monster");
	Monster->SetActorLocation({ 150, 100 });
}

void UMonsterLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}


void UMonsterLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UMonsterLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}