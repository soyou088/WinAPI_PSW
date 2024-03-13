#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"


// Ό³Έν :
class ALife : public AActor
{
public:
	// constrcuter destructer
	ALife();
	~ALife();

	// delete Function
	ALife(const ALife& _Other) = delete;
	ALife(ALife&& _Other) noexcept = delete;
	ALife& operator=(const ALife& _Other) = delete;
	ALife& operator=(ALife&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;

};

