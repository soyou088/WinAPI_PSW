#pragma once
#include <EngineCore\Level.h>

// Ό³Έν :
class UMonsterLevel : public ULevel
{
public:
	// constrcuter destructer
	UMonsterLevel();
	~UMonsterLevel();

	// delete Function
	UMonsterLevel(const UMonsterLevel& _Other) = delete;
	UMonsterLevel(UMonsterLevel&& _Other) noexcept = delete;
	UMonsterLevel& operator=(const UMonsterLevel& _Other) = delete;
	UMonsterLevel& operator=(UMonsterLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

private:

};

