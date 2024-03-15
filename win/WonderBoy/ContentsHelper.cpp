#include "ContentsHelper.h"

UWindowImage* UContentsHelper::ColMapImage = nullptr;
UWindowImage* UContentsHelper::ColMonsterImage = nullptr;

bool UContentsHelper::UIOn = false;
bool UContentsHelper::RockOn = false;

UContentsHelper::UContentsHelper()
{
}

UContentsHelper::~UContentsHelper()
{
}

FVector UContentsHelper::GetMousePos()
{
	return GEngine->MainWindow.GetMousePosition();
}