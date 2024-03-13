#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AUIEX : public AActor
{
public:
	// constrcuter destructer
	AUIEX();
	~AUIEX();

	// delete Function
	AUIEX(const AUIEX& _Other) = delete;
	AUIEX(AUIEX&& _Other) noexcept = delete;
	AUIEX& operator=(const AUIEX& _Other) = delete;
	AUIEX& operator=(AUIEX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;
};

