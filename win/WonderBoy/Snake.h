#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class ASnake : public AActor
{
public:
	// constrcuter destructer
	ASnake();
	~ASnake();

	// delete Function
	ASnake(const ASnake& _Other) = delete;
	ASnake(ASnake&& _Other) noexcept = delete;
	ASnake& operator=(const ASnake& _Other) = delete;
	ASnake& operator=(ASnake&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;

	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";

private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision;

	FVector MoveVector = FVector::Left * 50.0f;
	FVector DownMove = FVector::Down * 130.0f;

	FVector JumpVector = FVector::Up * 500.0f;

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	FVector ColMoveVector = FVector::Right * 100.0f;

	bool ColGra = false;
	bool ColSnake = false;

	void CalGravityVector(float _DeltaTime);
	void DesMoveUpdate(float _DeltaTime);
};

