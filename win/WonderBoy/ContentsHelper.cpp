#include "ContentsHelper.h"

UWindowImage* UContentsHelper::ColMapImage = nullptr;
UWindowImage* UContentsHelper::ColMonsterImage = nullptr;

bool UContentsHelper::UIOn = false;
bool UContentsHelper::RockOn = false;
bool UContentsHelper::AppleOn = false;
bool UContentsHelper::BananaOn = false;
bool UContentsHelper::CarrotOn = false;
bool UContentsHelper::TomatoOn = false;
bool UContentsHelper::DollOn = false;
bool UContentsHelper::FruitEOn = false;
bool UContentsHelper::MelonOn = false

;
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