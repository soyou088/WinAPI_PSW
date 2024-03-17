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
	PlayerBullet, // µΉµµ³Ά
	Monster, 
	Bonfire,
	Rock,
	Switch,
	Fruit,
	Banana,
	Bullet,
	Board,
	Stone,
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




// Ό³Έν :
class UContentsHelper
{
public:
	static class APlayer* MainPlayer;
	static UWindowImage* ColMapImage;
	static UWindowImage* ColMonsterImage;
	static FVector GetMousePos();
	static bool UIOn;
	static bool RockOn;
	static bool AppleOn;
	static bool BananaOn;
	static bool CarrotOn;
	static bool DollOn;
	static bool FruitEOn;
	static bool MelonOn;
	static bool TomatoOn;


private:
	// constrcuter destructer
	UContentsHelper();
	~UContentsHelper();
};

