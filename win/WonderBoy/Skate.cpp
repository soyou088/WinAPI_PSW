#include "Skate.h"

ASkate::ASkate()
{
}

ASkate::~ASkate()
{
}

void ASkate::BeginPlay()
{
	Renderer->CreateAnimation("Skate_Right", "Skate_R.png", 0, 1, 0.1f, true); // 오른쪽으로 보드타기
	Renderer->CreateAnimation("Skate_Left", "Skate_L.png", 0, 1, 0.1f, true); // 왼쪽으로 보드타기

	Renderer->CreateAnimation("Skatebrake_Right", "Skate_R.png", 2, 3, 0.1f, true); // 오른쪽 브레이크
	Renderer->CreateAnimation("Skatebrake_Left", "Skate_L.png", 2, 3, 0.1f, true); // 왼쪽 브레이크

	Renderer->CreateAnimation("SkateJump_Right", "Skate_R.png", 4, 4, 0.1f, true); // 오른쪽 보드 점프
	Renderer->CreateAnimation("SkateJump_Left", "Skate_L.png", 4, 4, 0.1f, true); // 왼쪽 보드 점프

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
