#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// FSM�� ���ؼ� �˾ƺ���.
// �ѹ��� �Ѱ��� ���¸��� ������.
// �÷��̾ �ѹ��� 1���� �Լ����� �����Ѵ�.

// ���� :
class APlayer : public AActor
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// ���� ���� �Լ�
	void GravityCheck(float _DeltaTime);
	// �� ���¸��� ������ ���� ���� ����Ǿ�� �Ѵ�.
	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	// ���� �ֿ� ������Ʈ
	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Move(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void MoveStart();
	void JumpStart();

	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";



private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float FreeMoveSpeed = 700.0f;

	float MoveSpeed = 500.0f;
	float Gravity = 500.0f;
};

