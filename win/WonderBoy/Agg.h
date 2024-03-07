#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AAgg : public AActor
{
public:
	// constrcuter destructer
	AAgg();
	~AAgg();

	// delete Function
	AAgg(const AAgg& _Other) = delete;
	AAgg(AAgg&& _Other) noexcept = delete;
	AAgg& operator=(const AAgg& _Other) = delete;
	AAgg& operator=(AAgg&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;

	void ColAgg();

	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::Jump;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;

	FVector LastMoveVector = FVector::Zero;
	
	FVector MoveVector = FVector::Right * 30.0f;

	FVector JumpVector = FVector::Up * 70.0f;

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	void MoveUpdate(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void CalLastMoveVector(float _DeltaTime);
	void MoveLastMoveVector(float _DeltaTime);

};

