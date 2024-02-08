#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum WonderRenderOrder
{
	Map,
	Monster,
	Player
};

enum class EActorDir
{
	Left,
	Right,
};

enum class EPlayState
{
	None,
	CameraFreeMove,
	FreeMove,
	Idle,
	Move,
	Jump,
};



// Ό³Έν :
class UContentsHelper
{
public:
	static class APlayer* MainPlayer;
	static UWindowImage* ColMapImage;
	static FVector GetMousePos();

private:
	// constrcuter destructer
	UContentsHelper();
	~UContentsHelper();
};

