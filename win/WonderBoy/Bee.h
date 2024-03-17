#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class ABee : public AActor

{
public:
	// constrcuter destructer
	ABee();
	~ABee();

	// delete Function
	ABee(const ABee& _Other) = delete;
	ABee(ABee&& _Other) noexcept = delete;
	ABee& operator=(const ABee& _Other) = delete;
	ABee& operator=(ABee&& _Other) noexcept = delete;

protected:


	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void MoveStart();
	void DestroyStart();


	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";

private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision;

	UEngineSoundPlayer Sound;

	FVector MoveVector = FVector::Left * 30.0f;
	FVector DownMove = FVector::Down* 200.0f;
	
	FVector JumpVector = FVector::Up * 500.0f;
	
	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	FVector ColMoveVector = FVector::Right * 100.0f;
	
	bool ColGra = false;
	bool ColBee = false;

	void CalGravityVector(float _DeltaTime);
	void Move(float _DeltaTime);
	void DesMoveUpdate(float _DeltaTime);
};

