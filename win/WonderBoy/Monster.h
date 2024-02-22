#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// ���� :
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

	UImageRenderer* Renderer = nullptr;
	UCollision* Collision;


	float MoveVector = 10.0f;
	void AddMoveVector();

	void Destroy();
	void MoveUpdate(float _DeltaTime);
	void HillDown();
	void MoveFront();
	void MoveUp();
};
