#include "PlayerLevel.h"
#include "Player.h"

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}


void UPlayLevel::BeginPlay()
{
	// ULevel* const This = this;
	this->SpawnActor<Player>();

	// SpawnActor<Player>();

	// ������ 
	// �÷��̾�
	// ���
	// ����
	// ������ �ڵ�� ���⼭ �� ������ �Ѵ�.
}