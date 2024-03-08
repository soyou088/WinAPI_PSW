#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"


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
	
	EActorDir DirState = EActorDir::Right;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;
	void CalGravityVector(float _DeltaTime);


private:

	UCollision* BCollision = nullptr;
	UImageRenderer* Render = nullptr;

	FVector BulletAcc = FVector::Right * 700.0f;

	FVector GravityAcc = FVector::Down * 700.0f;
	FVector GravityVector = FVector::Zero;

	void Move(float _DeltaTime);
};