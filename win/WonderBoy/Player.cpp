#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"



void APlayer::AddMoveVector(const FVector& _DirDelta)
{
	MoveVector += _DirDelta * MoveAcc;
}

void APlayer::CalMoveVector(float _DeltaTime)
{
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}
	CheckPos.Y -= 30;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	if (MoveMaxSpeed <= MoveVector.Size2D())
	{
		MoveVector = MoveVector.Normalize2DReturn() * MoveMaxSpeed;
	}

}

void APlayer::MoveLastMoveVector(float _DeltaTime)
{
	// ī�޶�� x�����θ� �������� �ϴϱ�.
	//PMoveVector = GetActorLocation();
	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
	AddActorLocation(LastMoveVector * _DeltaTime);
}

void APlayer::CalLastMoveVector(float _DeltaTime)
{
	// ���η� ���� �ʱ�ȭ ��Ų��.
	LastMoveVector = FVector::Zero;
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
}



void APlayer::HillUP(Color8Bit _Color)
{

	// Green �϶� FVector UP�Ѵ�.
	while (true)
	{
		Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY() - 1, Color8Bit::MagentaA);
		if (Color == _Color)//|| Color == Color8Bit::MagentaA)
		{
			AddActorLocation(FVector::Up);
			GetWorld()->AddCameraPos(FVector::Up);
		}

		else
		{
			break;
		}
	}
}

void APlayer::ColorJump()
{

	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(100,0,0,0) || Color == Color8Bit::MagentaA)
	{
		JumpVector = FVector::Zero;
 		StateChange(EPlayState::Move);
		return;
	}
}

void APlayer::Bullet()
{

	BulletVector = BulletAcc;
	FVector GetPos = GetActorLocation();



	GetActorLocation().X - 1; // Left ������ ���� ������
	GetActorLocation().X + 1; // Right �������� ���� ������



	// �ϴ� ���⼭ ���� �� �ʿ䰡 ������ ?
	// �̸� ������ �س��� bullet�� ���� ������ ���̸� �Ǵ°ǰ� ? �����غ���
	// bullet�� Actor�� ��� �������� �ұ� ?
	// �÷��̾ ������ ���� GetActorLocation().X -1 ���� bullet�� ������.
	// Bullet�� AddBulletPos(FVector::Right)
	// 
	// �÷��̾ �������� ���� GetActorLocation().X +1 ���� bullet�� ������.
	// Bullet�� AddBulletPos(FVector::Left) 
	// 
	// �̷��� �����δ�.	

	// UCollision* CreateCollision(int _Order = 0);
	// UImageRenderer* CreateImageRenderer(int _Order = 0);
	// �̰� ���� �ɱ� ?
	// 
	// Gravity�� üũ �ؾ��Ѵ�. �߷��� �޾ƾ� �Ѵ�.
	// �̹��� ȸ��

}


void APlayer::MoveUpdate(float _DeltaTime)
{
	CalMoveVector(_DeltaTime); // ������ ��� ��
	CalGravityVector(_DeltaTime);// �߷� ��� ��	
	CalLastMoveVector(_DeltaTime); // �� ���� ��
	MoveLastMoveVector(_DeltaTime); // ī�޶�
	HillUP(Color8Bit(100,0,0,0));
	// �̵��� �ϰ� ������ ���� ���� ó���� ������ ����
}

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay(); // �θ𿡼� �����ϴ� �Լ��� ���ִ°� ���Ƽ� �ߴ�.
	
	GetWorld()->AddCameraPos({ 0, 540 }); // ī�޶� ��
	MainPlayer = this;
	{
		Renderer = CreateImageRenderer(WonderRenderOrder::Player);
		Renderer->SetImage("Player_R.png");
		Renderer->SetTransform({ {0,0}, {200, 200} });

		Renderer->CreateAnimation("Idle_Right", "Player_R.png", 0, 1, 0.1f, true); // ������ �ִ� ����
		Renderer->CreateAnimation("Move_Right", "Player_R.png", 1, 5, 0.1f, true); // ���������� �����̴� ����

		Renderer->CreateAnimation("Idle_Left", "Player_L.png", 0, 1, 0.1f, true); // ������ �ִ� ����
		Renderer->CreateAnimation("Move_Left", "Player_L.png", 1, 5, 0.1f, true); // �������� �����̴� ����

		Renderer->CreateAnimation("Jump_Right", "Player_R.png", 5, 5, 0.1f, true); // ���������� �����ϱ�
		Renderer->CreateAnimation("Jump_Left", "Player_L.png", 5, 5, 0.1f, true); // �������� �����ϱ�

		Renderer->CreateAnimation("Col-Right", "Player_R.png", 6, 6, 0.1f, true); // �������浹
		Renderer->CreateAnimation("Col_Left", "Player_R.png", 7, 7, 0.1f, true); // ���� �浹
		
		Renderer->CreateAnimation("Death", "Death.png", 0, 1, 0.1f, true); // �ױ�

		

		Renderer->ChangeAnimation("Idle_Right"); // ������ �ִ»���
	}
	{
		// Player Collision
		Collision = CreateCollision(WonderCollisionOrder::Player);
		Collision->SetScale({ 10, 100 });
		Collision->SetColType(ECollisionType::Rect);
	}
	{
		// Bullet Collision
		BCollision = CreateCollision(WonderCollisionOrder::PlayerBullet);
		BCollision->SetScale({ 10,10 });
		BCollision->SetColType(ECollisionType::Rect);
	}

	StateChange(EPlayState::Idle);
}

void APlayer::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit::MagentaA || Color == Color8Bit(100,0,0,0))
	{
		GravityVector = FVector::Zero;
	}

}

void APlayer::DirCheck()
{
	EActorDir Dir = DirState;
	if (UEngineInput::IsPress(VK_LEFT))
	{
		Dir = EActorDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		Dir = EActorDir::Right;
	}

	if (Dir != DirState)
	{
		DirState = Dir;
		std::string Name = GetAnimationName(CurAnimationName);
		Renderer->ChangeAnimation(Name);
	}
}


std::string APlayer::GetAnimationName(std::string _Name)
{
	std::string DirName = "";

	switch (DirState)
	{
	case EActorDir::Left:
		DirName = "_Left";
		break;
	case EActorDir::Right:
		DirName = "_Right";
		break;
	default:
		break;
	}

	CurAnimationName = _Name;

	return _Name + DirName;

}

void APlayer::IdleStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Idle"));
	DirCheck();
}

void APlayer::MoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Move"));
	DirCheck();
}

void APlayer::JumpStart()
{
	JumpVector = JumpPower;
	Renderer->ChangeAnimation(GetAnimationName("Jump"));
	DirCheck();

}



void APlayer::StateChange(EPlayState _State)
{
	// �������¿� ���� ���°� ���� �ʾ�
	// �������� move ������ Idle
	if (State != _State)
	{
		switch (_State)
		{
		case EPlayState::Idle:
			IdleStart();
			break;
		case EPlayState::Move:
			MoveStart();
			break;
		case EPlayState::Jump:
			JumpStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void APlayer::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case EPlayState::CameraFreeMove:
		CameraFreeMove(_DeltaTime);
		break;
	case EPlayState::FreeMove:
		FreeMove(_DeltaTime);
		break;
	case EPlayState::Idle:
		Idle(_DeltaTime);
		break;
	case EPlayState::Move:
		Move(_DeltaTime);
		break;
	case EPlayState::Jump:
		Jump(_DeltaTime);
		break;
	default:
		break;
	}


}

void APlayer::CameraFreeMove(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Left * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Up * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
		// AddActorLocation(FVector::Down * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::Idle);
	}
}

void APlayer::FreeMove(float _DeltaTime)
{
	FVector MovePos;

	if (UEngineInput::IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		MovePos += FVector::Up * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		MovePos += FVector::Down * _DeltaTime * FreeMoveSpeed;
	}

	AddActorLocation(MovePos);
	GetWorld()->AddCameraPos(MovePos);

	if (UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::Idle);
	}
}


void APlayer::Idle(float _DeltaTime)
{
	MoveVector = FVector::Zero;
	// ���� �����ʵ� �ȵǰ� �ְ�.
	// ���⼭�� ����
	// ������ �������� ��� ���� �Ű澲�� �˴ϴ�.
	if (true == UEngineInput::IsDown('1'))
	{
		StateChange(EPlayState::FreeMove);
		return;
	}

	if (true == UEngineInput::IsDown('2'))
	{
		StateChange(EPlayState::CameraFreeMove);
		return;
	}

	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT)
		)
	{
		StateChange(EPlayState::Move);
		return;
	}

	if (
		true == UEngineInput::IsDown(VK_SPACE)
		)
	{
		StateChange(EPlayState::Jump);
		return;
	}

	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	MoveUpdate(_DeltaTime);
}


void APlayer::Move(float _DeltaTime)
{
	DirCheck();
	MoveUpdate(_DeltaTime);

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		FVector MoveDirVector = FVector::Zero;
		switch (DirState)
		{
		case EActorDir::Left:
			MoveDirVector = FVector::Right;
			break;
		case EActorDir::Right:
			MoveDirVector = FVector::Left;
			break;
		default:
			break;
		}
		if (10.0f <= abs(MoveVector.X))
		{
			AddMoveVector((MoveDirVector)*_DeltaTime);// �����ϴ� �ڵ�
		}
		else
		{
			MoveVector = float4::Zero;
			StateChange(EPlayState::Idle);
			return;
		}
	}


	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}


	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsPress(VK_SPACE))
	{
		StateChange(EPlayState::Jump);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsPress(VK_SPACE))
	{
		AddMoveVector(FVector::Left * _DeltaTime + JumpVector);
	}


	if (UEngineInput::IsPress(VK_RIGHT) && UEngineInput::IsPress(VK_SPACE))
	{
		AddMoveVector(FVector::Right * _DeltaTime + JumpVector);
	}


	if (UEngineInput::IsPress('Q'))
	{
		Bullet();
	}


	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}
	CheckPos.Y -= 30;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);
	if (Color != Color8Bit(255, 0, 255, 0))
	{
		AddActorLocation(MovePos);
		GetWorld()->AddCameraPos(MovePos);
	}

	HillUP(Color8Bit(100, 0, 0, 0));

}

void APlayer::Jump(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (UEngineInput::IsPress('Q'))
	{
		Bullet();
	}

	MoveUpdate(_DeltaTime);
	ColorJump();



	if (JumpMax <= JumpVector.Size2D())
	{
		JumpVector = JumpVector.Normalize2DReturn() * JumpMax;
	}
}

void APlayer::Col(float _DeltaTime)
{

}

void APlayer::Death(float _DeltaTime)
{

}


void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);

	std::vector<UCollision*> Result;
	if (nullptr != Collision && true == Collision->CollisionCheck(WonderCollisionOrder::Monster, Result))
	{
		AActor* MCol = Result[0]->GetOwner();
		Renderer->ChangeAnimation("Death"); 

	}

	APlayer* Player = APlayer::GetMainPlayer();
	if (nullptr == Player)
	{
		MsgBoxAssert("�÷��̾ �������� �ʽ��ϴ�.");
	}
}
