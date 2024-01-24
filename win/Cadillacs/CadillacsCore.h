#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class CadillacsCore : public EngineCore
{
public:
	// constrcuter destructer
	CadillacsCore();
	~CadillacsCore();

	// delete Function
	CadillacsCore(const CadillacsCore& _Other) = delete;
	CadillacsCore(CadillacsCore&& _Other) noexcept = delete;
	CadillacsCore& operator=(const CadillacsCore& _Other) = delete;
	CadillacsCore& operator=(CadillacsCore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void End() override;

private:

};

