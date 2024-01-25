#include "CadillacsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayerLevel.h"

ContentsCore::ContentsCore()
	: EngineCore()
{
}

ContentsCore::~ContentsCore()
{
}

// ���ӽ���
void ContentsCore::BeginPlay()
{
	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void ContentsCore::Tick(float _DeltaTime)
{
	// �÷��̾� �������� �Ѵ�.
}

void ContentsCore::End()
{
}