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

// ���ӽ���
void CadillacsCore::BeginPlay()
{
	SetFrame(60);

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
}