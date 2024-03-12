#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// Ό³Έν :
class AJumpping : public AActor
{
public:
	// constrcuter destructer
	AJumpping();
	~AJumpping();

	// delete Function
	AJumpping(const AJumpping& _Other) = delete;
	AJumpping(AJumpping&& _Other) noexcept = delete;
	AJumpping& operator=(const AJumpping& _Other) = delete;
	AJumpping& operator=(AJumpping&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Render = nullptr;

	UCollision* Collision;



};