#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

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

	void BeginPlay();
	void Tick(float _DeltaTime) override;
	
	void MoveStart();
	void DestroyStart();

	void Move(float _DeltaTime);

	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision;

	FVector MoveVector = FVector::Left * 50.0f;
	FVector DownMove = FVector::Down* 130.0f;
	

	void Destroy();
};

