#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"


// Ό³Έν :
class ABridge : public AActor
{	
public:
	// constrcuter destructer
	ABridge();
	~ABridge();

	// delete Function
	ABridge(const ABridge& _Other) = delete;
	ABridge(ABridge&& _Other) noexcept = delete;
	ABridge& operator=(const ABridge& _Other) = delete;
	ABridge& operator=(ABridge&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);

private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;

	FVector DownMove = FVector::Down * 200.0f;

};

