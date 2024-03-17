#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class AMonster : public AActor
{
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

	UImageRenderer* Snail = nullptr;

	UEngineSoundPlayer Sound;


	UCollision* Collision = nullptr;

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	FVector MoveVector = FVector::Left * 500.0f;

	FVector JumpVector = FVector::Up * 500.0f;

	FVector ColMoveVector = FVector::Right * 100.0f;




	bool ColGra = false;
	bool ColSnail = false;

	void AddMoveVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);
	void HillDown();
	void MoveFront(float _DeltaTime);
	void DesMoveUpdate(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

};

