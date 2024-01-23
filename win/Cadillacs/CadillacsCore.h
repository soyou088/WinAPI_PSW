#pragma once
#include <EngineCore\EngineCore.h>

// ���� :
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
	void EngineStart() override;
	void EngineUpdate() override;
	void EngineEnd() override;

private:

};

