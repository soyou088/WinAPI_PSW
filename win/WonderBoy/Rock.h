#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class ARock : public AActor
{
public:
	// constrcuter destructer
	ARock();
	~ARock();

	// delete Function
	ARock(const ARock& _Other) = delete;
	ARock(ARock&& _Other) noexcept = delete;
	ARock& operator=(const ARock& _Other) = delete;
	ARock& operator=(ARock&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:

	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;

	FVector MoveVector = FVector::Left * 70.0f;

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	bool MoveON = false;
	void Move(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

};

