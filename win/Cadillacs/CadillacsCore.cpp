#include "CadillacsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayerLevel.h"

CadillacsCore::CadillacsCore()
{
}

CadillacsCore::~CadillacsCore()
{
}

void CadillacsCore::BeginPlay()
{
	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void CadillacsCore::Tick(float _DeltaTime)
{
	// �÷��̾� �������� �Ѵ�.
}

void CadillacsCore::End()
{
	int a = 0;
}