#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AUI_item : public AActor
{
public:
	// constrcuter destructer
	AUI_item();
	~AUI_item();

	// delete Function
	AUI_item(const AUI_item& _Other) = delete;
	AUI_item(AUI_item&& _Other) noexcept = delete;
	AUI_item& operator=(const AUI_item& _Other) = delete;
	AUI_item& operator=(AUI_item&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;
	UImageRenderer* UIRender = nullptr;

	void SetUI();
};

