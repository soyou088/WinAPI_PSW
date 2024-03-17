#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class ASwitch : public AActor
{
public:
	// constrcuter destructer
	ASwitch();
	~ASwitch();

	// delete Function
	ASwitch(const ASwitch& _Other) = delete;
	ASwitch(ASwitch&& _Other) noexcept = delete;
	ASwitch& operator=(const ASwitch& _Other) = delete;
	ASwitch& operator=(ASwitch&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* Collision = nullptr;


	

};

