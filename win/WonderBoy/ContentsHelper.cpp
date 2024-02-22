#include "ContentsHelper.h"

UWindowImage* UContentsHelper::ColMapImage = nullptr;

UWindowImage* UContentsHelper::ColMonsterImage = nullptr;

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