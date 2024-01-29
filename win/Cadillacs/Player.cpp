#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineInput.h>
#include "Bullet.h"
#include <EngineBase\EngineTime.h>
#include <vector>
#include <list>

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();

	// �÷��̾� 100, 100 => Actor
	// ��ü? 100, 100 - 50 => Renderer
	// ��ü? 100, 100 + 50 => Renderer

	{
		HPbarRenderer = CreateImageRenderer(0);
		HPbarRenderer->SetPosition({ 0, -50 });
		HPbarRenderer->SetScale({ 50, 10 });
	}

	{
		BodyRenderer = CreateImageRenderer(0);
		BodyRenderer->SetPosition({ 0, 30 });
		BodyRenderer->SetScale({ 50, 50 });
	}

	{
		HeadRenderer = CreateImageRenderer(0);
		HeadRenderer->SetPosition({ 0, 0 });
		HeadRenderer->SetScale({ 30, 10 });
	}
	
	{
		HandRenderer = CreateImageRenderer(0);
		HandRenderer->SetPosition({ 0, 1 });
		HandRenderer->SetScale({ 20, 20 });
	}
	// UImageRenderer* Ptr = CreateRenderer();
	// �÷��̾� ����
	// Ptr->SetPosition({0.0, -50.0f}); // 500, 500
	// Ptr->SetImage("AAAA.png"); // 500, 500
	// Ptr->SetScale();
	// Ptr->SetImageScaleSetting(); 


	// CreateDefaultSubObject<UStaticMeshRenderer>();

	// n�� �����Ҽ� �ְ� ������ �Ѵ�.
	// ��ü�� ��ü�� �����ٰ� �ĺ���.

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

	if (true == EngineInput::IsDown('T'))
	{
		HeadRenderer->Destroy();
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
}