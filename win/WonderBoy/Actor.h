#pragma once

// Ό³Έν :
class Actor
{
public:
	// constrcuter destructer
	Actor();
	~Actor();

	// delete Function
	Actor(const Actor& _Other) = delete;
	Actor(Actor&& _Other) noexcept = delete;
	Actor& operator=(const Actor& _Other) = delete;
	Actor& operator=(Actor&& _Other) noexcept = delete;

protected:


private:

};

