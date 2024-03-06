#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class ABonfire : public AActor
{
public:
	// constrcuter destructer
	ABonfire();
	~ABonfire();

	// delete Function
	ABonfire(const ABonfire& _Other) = delete;
	ABonfire(ABonfire&& _Other) noexcept = delete;
	ABonfire& operator=(const ABonfire& _Other) = delete;
	ABonfire& operator=(ABonfire&& _Other) noexcept = delete;

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

