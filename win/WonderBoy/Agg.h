#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class Agg : public AActor
{
public:
	// constrcuter destructer
	Agg();
	~Agg();

	// delete Function
	Agg(const Agg& _Other) = delete;
	Agg(Agg&& _Other) noexcept = delete;
	Agg& operator=(const Agg& _Other) = delete;
	Agg& operator=(Agg&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;

	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
private:
	UImageRenderer* Render = nullptr;
};

