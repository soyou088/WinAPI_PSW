#include "WonderCore.h"
#include "PlayerLevel.h"
#include "TitleLevel.h"
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
	// Window ũ��
	MainWindow.SetWindowScale({ 256 * 2, 240 * 2 });
	// Window ��ġ
	MainWindow.SetWindowPosition({ 800 , 0 });


	UEngineCore::BeginPlay();
	UEngineDirectory NewDir;

	NewDir.MoveParent();
	NewDir.Move("ContentsResources");

	// ��� ������ �Ⱦ��.
	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	                                               // �̹��� �ڸ��� 5���� 2��
	UEngineResourcesManager::GetInst().CuttingImage("Player_1_R.png", 6, 2);
	UEngineResourcesManager::GetInst().CuttingImage("Player_1_L.png", 6, 2);
	UEngineResourcesManager::GetInst().CuttingImage("Monster1.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Bee.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Snake.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Bonfire.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Stone.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Agg.png", 2, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Angel.png", 2, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Spring.png", 2, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Death.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Bullet.png", 4, 1);


	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("Title"));

	CreateLevel<UTitleLevel>("Title");
	CreateLevel<UPlayLevel>("Player");
	ChangeLevel("Title");


}

void UWonderCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}