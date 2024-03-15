#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// ���� :
class ABoard : public AActor
{
public:
	// constrcuter destructer
	ABoard();
	~ABoard();

	// delete Function
	ABoard(const ABoard& _Other) = delete;
	ABoard(ABoard&& _Other) noexcept = delete;
	ABoard& operator=(const ABoard& _Other) = delete;
	ABoard& operator=(ABoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MakeBullet();
private:
	UImageRenderer* Render = nullptr;


	UCollision* Collision = nullptr;

};

