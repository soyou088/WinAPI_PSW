#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"


// Ό³Έν :
class AUI_Player : public AActor

{
public:
	// constrcuter destructer
	AUI_Player();
	~AUI_Player();

	// delete Function
	AUI_Player(const AUI_Player& _Other) = delete;
	AUI_Player(AUI_Player&& _Other) noexcept = delete;
	AUI_Player& operator=(const AUI_Player& _Other) = delete;
	AUI_Player& operator=(AUI_Player&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;

};

