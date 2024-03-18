#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
}

ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	AActor::BeginPlay();

	UImageRenderer* Renderer = CreateImageRenderer();

	Renderer->SetImage("menu1.png");
	// 이미지가 나올 위치
	SetActorLocation({ 50, 50 });
	Renderer->SetTransform({ {300,240}, {700, 640} });
	Renderer->SetImageCuttingTransform({ {0,0}, {200, 200} });
	
	Renderer->CreateAnimation("Title", "Title", 0, 3, 0.3f, true);
	Renderer->ChangeAnimation("Title");
	// Renderer->SetImageToScale("Title.png");
}

void ATitleLogo::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);
	
	int a = 0;
}