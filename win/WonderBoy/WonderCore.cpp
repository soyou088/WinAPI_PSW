#include "WonderCore.h"
#include "PlayerLevel.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

UWonderCore::UWonderCore()
{
}

UWonderCore::~UWonderCore()
{
}

void UWonderCore::BeginPlay()
{
	// Window 크기
	MainWindow.SetWindowScale({ 256 * 4, 240 * 4 });
	// Window 위치
	MainWindow.SetWindowPosition({ 800 , 0 });


	UEngineCore::BeginPlay();
	UEngineDirectory NewDir;

	NewDir.MoveParent();
	NewDir.Move("ContentsResources");

	// 모든 파일을 훑어본다.
	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	                                                            // 5개씩 2줄
	UEngineResourcesManager::GetInst().CuttingImage("Player_R.png", 5, 2);
	UEngineResourcesManager::GetInst().CuttingImage("Player_L.png", 5, 2);
	//CreateLevel<UTitleLevel>("Title");
	CreateLevel<UPlayLevel>("Player");
	ChangeLevel("Player");


}

void UWonderCore::Tick(float _DeltaTime)
{
	 UWonderCore::Tick(_DeltaTime);
}