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

	// 플레이어 100, 100 => Actor
	// 상체? 100, 100 - 50 => Renderer
	// 하체? 100, 100 + 50 => Renderer

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
	// 플레이어 기준
	// Ptr->SetPosition({0.0, -50.0f}); // 500, 500
	// Ptr->SetImage("AAAA.png"); // 500, 500
	// Ptr->SetScale();
	// Ptr->SetImageScaleSetting(); 


	// CreateDefaultSubObject<UStaticMeshRenderer>();

	// n장 랜더할수 있게 만들어야 한다.
	// 상체와 하체로 나뉜다고 쳐보자.

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
	// 1초에 2번을 실행했다면
	// Tick과 Tick사의 시간은? 
	// 0.5초 일꺼다.

	// 1초에 100을 가야하는 애가 있다고 칩시다.
	// 0.5초에 몇픽셀씩 움직여야 하나요?
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
	// QSkillCool += 진짜 프레임과 프레임 사이에 소모된 현실 시간이어야 한다.;

	// 초당 2번 실행했다고 해도
	// 0.5 0.5 0.5 0.5 
	// 2차가 지나야 
	// 초당 2번 실행된다고 칩시다.
	if (true == EngineInput::IsDown('Q'))
	{
		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
		NewBullet->SetActorLocation(GetActorLocation());
		NewBullet->SetDir(FVector::Right);
	}
}