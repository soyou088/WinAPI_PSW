#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AUI_HP : public AActor
{
public:
	// constrcuter destructer
	AUI_HP();
	~AUI_HP();

	// delete Function
	AUI_HP(const AUI_HP& _Other) = delete;
	AUI_HP(AUI_HP&& _Other) noexcept = delete;
	AUI_HP& operator=(const AUI_HP& _Other) = delete;
	AUI_HP& operator=(AUI_HP&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;
};

