#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class AFruit : public AActor
{
public:
	// constrcuter destructer
	AFruit();
	~AFruit();

	// delete Function
	AFruit(const AFruit& _Other) = delete;
	AFruit(AFruit&& _Other) noexcept = delete;
	AFruit& operator=(const AFruit& _Other) = delete;
	AFruit& operator=(AFruit&& _Other) noexcept = delete;

	int FruitNumber = 0;
protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Collision();

private:
	UImageRenderer* Apple = nullptr;

	UEngineSoundPlayer Sound;

	UCollision* ColCheck = nullptr;
	UCollision* DesCheck = nullptr;

	void Score();

};
