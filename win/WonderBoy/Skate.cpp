#include "Skate.h"

ASkate::ASkate()
{
}

ASkate::~ASkate()
{
}

void ASkate::BeginPlay()
{
	Renderer->CreateAnimation("Skate_Right", "Skate_R.png", 0, 1, 0.1f, true); // ���������� ����Ÿ��
	Renderer->CreateAnimation("Skate_Left", "Skate_L.png", 0, 1, 0.1f, true); // �������� ����Ÿ��

	Renderer->CreateAnimation("Skatebrake_Right", "Skate_R.png", 2, 3, 0.1f, true); // ������ �극��ũ
	Renderer->CreateAnimation("Skatebrake_Left", "Skate_L.png", 2, 3, 0.1f, true); // ���� �극��ũ

	Renderer->CreateAnimation("SkateJump_Right", "Skate_R.png", 4, 4, 0.1f, true); // ������ ���� ����
	Renderer->CreateAnimation("SkateJump_Left", "Skate_L.png", 4, 4, 0.1f, true); // ���� ���� ����

	Renderer->ChangeAnimation("Skate");
}

void ASkate::SkateStart()
{

}

void ASkate::SkateJumpStart()
{

}

void ASkate::SkatebrakeStart()
{

}
