#include "ContentsHelper.h"

UWindowImage* UContentsHelper::ColMapImage = nullptr;
UWindowImage* UContentsHelper::ColMonsterImage = nullptr;

bool UContentsHelper::UIOn = false;
bool UContentsHelper::RockOn = false;
bool UContentsHelper::AppleOn = false;

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