#include "Skate.h"

ASkate::ASkate()
{
}

ASkate::~ASkate()
{
}

void ASkate::BeginPlay()
{

	Renderer = CreateImageRenderer(WonderRenderOrder::Skate);
	Renderer->SetImage("Skate_R.png");
	Renderer->SetTransform({ {0,0}, {130, 130} });

	Renderer->CreateAnimation("Skate_Right", "Skate_R.png", 0, 1, 0.1f, true); // ���������� ����Ÿ��
	Renderer->CreateAnimation("Skate_Left", "Skate_L.png", 0, 1, 0.1f, true); // �������� ����Ÿ��

	Renderer->CreateAnimation("SkateBrake_Right", "Skate_R.png", 2, 3, 0.1f, true); // ������ �극��ũ
	Renderer->CreateAnimation("SkateBrake_Left", "Skate_L.png", 2, 3, 0.1f, true); // ���� �극��ũ

	Renderer->CreateAnimation("SkateJump_Right", "Skate_R.png", 4, 4, 0.1f, true); // ������ ���� ����
	Renderer->CreateAnimation("SkateJump_Left", "Skate_L.png", 4, 4, 0.1f, true); // ���� ���� ����

	Renderer->ChangeAnimation("Skate");
}

void ASkate::SkateMoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Skate"));
	DirCheck();
}

void ASkate::SkateJumpStart()
{
	Renderer->ChangeAnimation(GetAnimationName("SkateJump"));
	DirCheck();
}

void ASkate::SkateBrakeStart()
{
	Renderer->ChangeAnimation(GetAnimationName("SkateBrake"));
	DirCheck();
}

void ASkate::DirCheck()
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

void ASkate::Move()
{

}

void ASkate::Jump()
{
	
}

void ASkate::Brake()
{

}


