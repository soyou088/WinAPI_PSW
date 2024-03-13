#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AUI_Back : public AActor
{
public:
	// constrcuter destructer
	AUI_Back();
	~AUI_Back();

	// delete Function
	AUI_Back(const AUI_Back& _Other) = delete;
	AUI_Back(AUI_Back&& _Other) noexcept = delete;
	AUI_Back& operator=(const AUI_Back& _Other) = delete;
	AUI_Back& operator=(AUI_Back&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Render = nullptr;
};

