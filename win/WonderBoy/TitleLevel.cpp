#include "TitleLevel.h"
#include "TitleLogo.h"
#include "EngineCore\EngineCore.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		ATitleLogo* Logo = SpawnActor<ATitleLogo>();
	}


}
void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsPress('P'))
	{
		GEngine->ChangeLevel("Player");
	}

}
void UTitleLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UTitleLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}