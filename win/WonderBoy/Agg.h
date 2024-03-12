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


	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::Jump;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;

	FVector LastMoveVector = FVector::Zero;
	
	FVector MoveVector = FVector::Right * 100.0f;

	FVector JumpVector = FVector::Up * 730.0f;

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	bool ColGra = false;
	bool ColAgg = false;
	void CalGravityVector(float _DeltaTime);
	void AggMove(float _DeltaTime);

};

