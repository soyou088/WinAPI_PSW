#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"
#include <EnginePlatform/EngineSound.h>

// Ό³Έν : 
class ABulletActor : public AActor
{
public:
	// constrcuter destruster
	ABulletActor();
	~ABulletActor();

	// delete Function
	ABulletActor(const ABulletActor& _Other) = delete;
	ABulletActor(ABulletActor&& _Other) noexcept = delete;
	ABulletActor& operator=(const ABulletActor& _Other) = delete;
	ABulletActor& operator=(ABulletActor&& _Other) noexcept = delete;
	
	void SetBulletAcc(FVector _Value)
	{
		BulletAcc = _Value;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

	UCollision* BCollision = nullptr;
	UImageRenderer* Render = nullptr;

	UEngineSoundPlayer Sound;

	FVector BulletAcc = FVector::Right * 650.0f;

	FVector GravityAcc = FVector::Down * 700.0f;
	FVector GravityVector = FVector::Zero;


	void Move(float _DeltaTime);
	void ColBullet();
	void CalGravityVector(float _DeltaTime);
};