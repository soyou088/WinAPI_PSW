#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class ASkate : public AActor
{
public:
	// constrcuter destructer
	ASkate();
	~ASkate();

	// delete Function
	ASkate(const ASkate& _Other) = delete;
	ASkate(ASkate&& _Other) noexcept = delete;
	ASkate& operator=(const ASkate& _Other) = delete;
	ASkate& operator=(ASkate&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;

	void SkateStart();
	void SkateJumpStart();
	void SkatebrakeStart();

private:
	UImageRenderer* Renderer = nullptr;

	FVector MoveAcc = FVector::Right * 800.0f;
	FVector MoveVector = FVector::Right * 100.0f;


};

