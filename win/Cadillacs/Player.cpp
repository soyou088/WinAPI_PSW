#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineInput.h>
#include "Bullet.h"
#include <EngineBase\EngineTime.h>
#include <vector>
#include <list>
#include <conio.h>




Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	//{
	//	EngineTime NewTime;
	//	NewTime.TimeCheckStart();
	//	std::vector<int> NewInt;
	//	for (int i = 0; i < 10000000; i++)
	//	{
	//		NewInt.push_back(i);
	//	}
	//	float Time = NewTime.TimeCheck();
	//	int a = 0;
	//}
	//{
	//	EngineTime NewTime;
	//	NewTime.TimeCheckStart();
	//	std::list<int> NewInt;
	//	for (int i = 0; i < 10000000; i++)
	//	{
	//		NewInt.push_back(i);
	//	}
	//	float Time = NewTime.TimeCheck();
	//	int a = 0;
	//}



	SetActorLocation({ 100, 100 });
	SetActorScale({ 100, 100 });
}

void Player::Tick(float _DeltaTime)
{
	// 1�ʿ� 2���� �����ߴٸ�
	// Tick�� Tick���� �ð���? 
	// 0.5�� �ϲ���.

	// 1�ʿ� 100�� �����ϴ� �ְ� �ִٰ� Ĩ�ô�.
	// 0.5�ʿ� ���ȼ��� �������� �ϳ���?
	// 100 * 0.5


	if (true == EngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up * 500.0f * _DeltaTime);
	}


	if (true == EngineInput::IsPress(VK_DOWN))
	{
		AddActorLocation(FVector::Down * 500.0f * _DeltaTime);
	}


	// QSkillCool += 0.1f;
	// QSkillCool += ��¥ �����Ӱ� ������ ���̿� �Ҹ�� ���� �ð��̾�� �Ѵ�.;

	// �ʴ� 2�� �����ߴٰ� �ص�
	// 0.5 0.5 0.5 0.5 
	// 2���� ������ 
	// �ʴ� 2�� ����ȴٰ� Ĩ�ô�.
	if (true == EngineInput::IsDown('Q'))
	{
		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
		NewBullet->SetActorLocation(GetActorLocation());
		NewBullet->SetDir(FVector::Right);
	}

	HDC WindowDC = GEngine->MainWindow.GetWindowDC();
	FTransform Trans = GetTransform();
	Rectangle(WindowDC, Trans.iLeft(), Trans.iTop(), Trans.iRight(), Trans.iBottom());
}