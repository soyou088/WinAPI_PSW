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
	void Bullet();
	void SkateMove(float _DeltaTime);
	void SkateJump(float _DeltaTime);
	void SkateBrake(float _DeltaTime);


	// ���� ���� �Լ���
	void IdleStart();
	void MoveStart();
	void RunStart();
	void JumpStart();

	void SkateStart();
	void SkateJumpStart();
	void SkateBrakeStart();

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

	FVector MoveAcc = FVector::Right * 100.0f;	//500
	FVector MoveVector = FVector::Zero;
	float MoveMaxSpeed = 500.0f;
	void AddMoveVector(const FVector& _DirDelta);

	FVector RunAcc = FVector::Right * 700.0f;	//700
	FVector RunVector = FVector::Zero;
	float RunMaxSpeed = 1000.0f;
	void AddRunVector(const FVector& _DirDelta);

	FVector GravityAcc = FVector::Down * 2000.0f;
	FVector GravityVector = FVector::Zero;

	FVector JumpPower = FVector::Up * 800;
	FVector JumpVector = FVector::Zero;
	float JumpMax = 800.0f;

	// ���� ���� ��� ������ ��
	FVector LastMoveVector = FVector::Zero;
	FVector MovePos = FVector::Zero;


	FVector SkateMoveVector = FVector::Right * 200.0f;

	EPlayState BeforeRunState = EPlayState::None;
	
	//FVector SkateJumpPower = FVector::Up * 800;
	//FVector SkateJumpVector = FVector::Zero;

	bool SkateCheck = false;

	void CameraSet(float _DeltaTime);
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void MoveLastMoveVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);
	void ColorJump();
	void HillUP(Color8Bit _Color);
	void PlayerGo();
	void WallCheck();
	void NextAnimation();
	void FinBullet();
	bool testgr = false;
};

