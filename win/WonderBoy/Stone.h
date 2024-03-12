#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AStone : public AActor
{
public:
	// constrcuter destructer
	AStone();
	~AStone();

	// delete Function
	AStone(const AStone& _Other) = delete;
	AStone(AStone&& _Other) noexcept = delete;
	AStone& operator=(const AStone& _Other) = delete;
	AStone& operator=(AStone&& _Other) noexcept = delete;

protected:

	void BeginPlay();
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;
};

