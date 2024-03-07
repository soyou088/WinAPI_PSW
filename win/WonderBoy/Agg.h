#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AAgg : public AActor
{
public:
	// constrcuter destructer
	AAgg();
	~AAgg();

	// delete Function
	AAgg(const AAgg& _Other) = delete;
	AAgg(AAgg&& _Other) noexcept = delete;
	AAgg& operator=(const AAgg& _Other) = delete;
	AAgg& operator=(AAgg&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;


	void ColAgg();

	std::string GetAnimationName(std::string _Name);
	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision = nullptr;
	

};

