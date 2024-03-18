#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class Bridge : public AActor
{
public:
	// constrcuter destructer
	Bridge();
	~Bridge();

	// delete Function
	Bridge(const Bridge& _Other) = delete;
	Bridge(Bridge&& _Other) noexcept = delete;
	Bridge& operator=(const Bridge& _Other) = delete;
	Bridge& operator=(Bridge&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:

	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;

};

