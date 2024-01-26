#include "CadillacsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayerLevel.h"

CadillacsCore::CadillacsCore()
	: EngineCore()
{
}

CadillacsCore::~CadillacsCore()
{
}

// 게임시작
void CadillacsCore::BeginPlay()
{
	SetFrame(60);

	// "Title Level" + "을 만들다가 에러가 났습니다";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void CadillacsCore::Tick(float _DeltaTime)
{
	// 플레이어 움직여야 한다.
}

void CadillacsCore::End()
{
}