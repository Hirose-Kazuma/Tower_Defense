#include "EnemyLayer.h"


bool EnemyLayer::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Timer = 0;
	MoveDirection = -1;

	//毎フレーム処理
	this->scheduleUpdate();

	//PicDisplay();

	return true;
}

void EnemyLayer::update(float delta)
{
	Timer += delta;

	Animation(AnimationPattern);

	if (Timer >= (1.0f * GameSpeed)) 
	{
		auto move1 = MoveBy::create((1 * GameSpeed), Vec2(MoveDirection * 64, 0));	//現在位置から移動

		this->runAction(move1);

		Timer = 0;
	}
}

void EnemyLayer::PicDisplay()
{
	this->initWithFile("Enemy.png");
	this->setFlipX(true);
}


//烏
void EnemyLayer::SetStatus0()
{
	this->initWithFile("Crow_1.png");
	this->setScale(0.2);

	AnimationPattern = 0;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

//雑魚
void EnemyLayer::SetStatus1()
{
	this->initWithFile("zako_1.png");
	this->setScale(0.2);

	AnimationPattern = 1;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

//鰯
void EnemyLayer::SetStatus2()
{
	this->initWithFile("iwasi_1.png");
	this->setScale(0.2);

	AnimationPattern = 2;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus3()
{
	this->initWithFile("Enemy.png");

	AnimationPattern = 0;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus4()
{
	this->initWithFile("Enemy.png");

	AnimationPattern = 0;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::SetStatus5()
{
	this->initWithFile("Enemy.png");

	AnimationPattern = 0;
	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
}

void EnemyLayer::ChangeDirection()
{
	MoveDirection *= -1;

	if (Flipflag == true)
	{
		this->setFlipX(false);
		Flipflag = false;
	}
	else
	{
		this->setFlipX(true);
		Flipflag = true;
	}
}


void EnemyLayer::Animation(int SpriteType)
{
	//カラスアニメーション
	if (SpriteType == 0)
	{
		countFlg++;

		if (countFlg == (10 * GameSpeed))
		{
			this->setTexture("Crow_2.png");
		}
		else if (countFlg == (20 * GameSpeed))
		{
			this->setTexture("Crow_1.png");
			countFlg = 0;
		}
	}
	//雑魚アニメーション
	else if (SpriteType == 1)
	{
		countFlg++;

		if (countFlg == (10 * GameSpeed))
		{
			this->setTexture("zako_2.png");
		}
		else if (countFlg == (20 * GameSpeed))
		{
			this->setTexture("zako_1.png");
			countFlg = 0;
		}
	}
	//鰯アニメーション
	else if (SpriteType == 2)
	{
		countFlg++;

		if (countFlg == (10 * GameSpeed))
		{
			this->setTexture("iwasi_2.png");
		}
		else if (countFlg == (20 * GameSpeed))
		{
			this->setTexture("iwasi_1.png");
			countFlg = 0;
		}
	}
}

void EnemyLayer::ChangeSpeed(float delta)
{
	GameSpeed = delta;
}