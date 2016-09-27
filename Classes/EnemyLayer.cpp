#include "EnemyLayer.h"


bool EnemyLayer::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Timer = 0;
	MoveDirection = 1;

	//–ˆƒtƒŒ[ƒ€ˆ—
	this->scheduleUpdate();

	PicDisplay();

	return true;
}

void EnemyLayer::update(float delta)
{
	Timer += delta;

	if (Timer >= 1.0f) 
	{
		auto move1 = MoveBy::create(1, Vec2(MoveDirection * 64, 0));	//Œ»ÝˆÊ’u‚©‚çˆÚ“®

		this->runAction(move1);

		Timer = 0;
	}
}

void EnemyLayer::PicDisplay()
{
	this->initWithFile("Enemy.png");
	//this->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * 0.5));
}

void EnemyLayer::SetStatus0()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus1()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus2()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus3()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus4()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus5()
{
	this->initWithFile("Enemy.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}