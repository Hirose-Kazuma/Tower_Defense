#include "PlayerLayer.h"

/*
必要な情報
キャラの種類
攻撃方法
HP
AT
コスト
*/

bool PlayerLayer::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	MoveDirection = -1;

	//毎フレーム処理
	this->scheduleUpdate();

	return true;
}

void PlayerLayer::update(float delta)
{
	Timer += delta;

	if (Timer >= 1.0f)
	{
		auto move1 = MoveBy::create(1, Vec2(MoveDirection * 64, 0));	//現在位置から移動

		this->runAction(move1);

		Timer = 0;
	}
}

void PlayerLayer::SetStatus0()
{
	this->initWithFile("C_Sword.png");
	this->setScale(0.1);

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::SetStatus1()
{
	this->initWithFile("Player.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::SetStatus2()
{
	this->initWithFile("Player.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::SetStatus3()
{
	this->initWithFile("Player.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::SetStatus4()
{
	this->initWithFile("Player.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::SetStatus5()
{
	this->initWithFile("Player.png");

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void PlayerLayer::ChangeDirection()
{
	MoveDirection *= -1;
}