#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

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
	UImageRenderer* Banana = nullptr;
	UImageRenderer* Carrot = nullptr;
	UImageRenderer* Doll = nullptr;
	UImageRenderer* FruitE = nullptr;
	UImageRenderer* Melon = nullptr;
	UImageRenderer* Tomato = nullptr;


	UCollision* CApple = nullptr;
	UCollision* DApple = nullptr;
	UCollision* CCarrot = nullptr;
	UCollision* CDoll = nullptr;
	UCollision* CFruitE = nullptr;
	UCollision* CMelon = nullptr;
	UCollision* CTomato = nullptr;


	void Score();

};
