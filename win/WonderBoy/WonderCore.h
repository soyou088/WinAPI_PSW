#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class UWonderCore : public UEngineCore
{
public:
	// constrcuter destructer
	UWonderCore();
	~UWonderCore();

	// delete Function
	UWonderCore(const UWonderCore& _Other) = delete;
	UWonderCore(UWonderCore&& _Other) noexcept = delete;
	UWonderCore& operator=(const UWonderCore& _Other) = delete;
	UWonderCore& operator=(UWonderCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

