#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum WonderRenderOrder
{
	Map,
	PlayerBullet,
	Monster,
	Player,
};

enum class WonderCollisionOrder
{
	PlayerBullet,
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
	Run,
	Jump,
	Attack,
};



// Ό³Έν :
class UContentsHelper
{
public:
	static class APlayer* MainPlayer;
	static UWindowImage* ColMapImage;
	static UWindowImage* ColMonsterImage;
	static FVector GetMousePos();

private:
	// constrcuter destructer
	UContentsHelper();
	~UContentsHelper();
};

