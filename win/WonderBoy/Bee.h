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
	void BeginPlay();
	void Tick(float _DeltaTime) override;

	void Move();

private:
	UImageRenderer* Bee = nullptr;

	UCollision* Collision;

	
};

