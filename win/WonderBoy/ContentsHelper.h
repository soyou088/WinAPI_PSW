#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum class WonderRenderOrder
{
	Map,
	Monster,
	Object,
	PlayerBullet,
	Player,
	Skate,
	UI,
};

enum class WonderCollisionOrder
{
	PlayerBullet, // ������
	Monster, 
	Stone,
	Bonfire,
	Bullet,
	Object,
	Player,

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
	Destroy,
	SkateMove,
	SkateJump,
	SkateBrake,
};




// ���� :
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

