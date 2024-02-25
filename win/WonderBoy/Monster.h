#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AMonster : public AActor
{
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime) override;

private:

	UImageRenderer* Snail = nullptr;
	UImageRenderer* Bee = nullptr;
	UImageRenderer* Snake = nullptr;
	UImageRenderer* Stone = nullptr;
	UImageRenderer* frog = nullptr;
	UImageRenderer* bonfire = nullptr;

	UCollision* Collision;


	float MoveVector = 50.0f;
	void AddMoveVector();

	void Destroy();
	void MoveUpdate(float _DeltaTime);
	void HillDown();
	void MoveFront();
	void MoveUp();
};

