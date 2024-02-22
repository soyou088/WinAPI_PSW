#pragma once
#include <EngineCore\Actor.h>
#include "ContentsHelper.h"

// FSM�� ���ؼ� �˾ƺ���.
// �ѹ��� �Ѱ��� ���¸��� ������.
// �÷��̾ �ѹ��� 1���� �Լ����� �����Ѵ�.

// ���� :
class APlayer : public AActor

{
private:
	static APlayer* MainPlayer;
public:
	static APlayer* GetMainPlayer();

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
	// �� ���¸��� ������ ���� ���� ����Ǿ�� �Ѵ�.
	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	void SetPlayerCameraPos();

	// ���� �ֿ� ������Ʈ
	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Move(float _DeltaTime);
	void Run(float _DeltaTime);
	void Death(float _DeltaTime);
	void Col(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void MoveStart();
	void JumpStart();

	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";



private:
	UCollision* Collision = nullptr;

	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float FreeMoveSpeed = 700.0f;

	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 1000.0f;
	float MoveMaxSpeed = 1000.0f;
	void AddMoveVector(const FVector& _DirDelta);

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;


	FVector JumpPower = FVector::Up * 800;
	FVector JumpVector = FVector::Zero;
	float JumpMax = 800.0f;
	// ���� ���� ��� ������ ��
	FVector LastMoveVector = FVector::Zero;
	FVector MovePos = FVector::Zero;


	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void MoveLastMoveVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);
	void GroundUp();
	void HillUP();
};

