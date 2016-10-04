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

	MoveDirection = 1;


	//音声読み込み
	SimpleAudioEngine::sharedEngine()->preloadEffect("Sound_0.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Sound_1.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Sound_2.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Sound_3.mp3");



	//毎フレーム処理
	this->scheduleUpdate();

	return true;
}

void PlayerLayer::update(float delta)
{
	Timer += delta;

	if (Timer >= (1.0f * GameSpeed))
	{
		auto move1 = MoveBy::create((1 * GameSpeed), Vec2(MoveDirection * 64, 0));	//現在位置から移動
		this->runAction(move1);
		Timer = 0;
	}

	/*NowPos = this->getPosition();

	if (Moveflag == false) 
	{
		this->setPosition(Vec2(NowPos.x + ((1 * GameSpeed) * MoveDirection), NowPos.y));
	}*/
}

void PlayerLayer::SetStatus0()
{
	this->initWithFile("C_Sword.png");
	this->setScale(0.2);

	AtackPattern = 1;
	HP = 10;
	AT = 2;
	COST = 5;
	SOUND = 1;
}

void PlayerLayer::SetStatus1()
{
	this->initWithFile("C_Rod.png");
	this->setScale(0.2);

	AtackPattern = 1;
	HP = 10;
	AT = 3;
	COST = 7;
	SOUND = 0;
}

void PlayerLayer::SetStatus2()
{
	this->initWithFile("Player.png");
	this->setFlipX(true);

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
	SOUND = 0;
}

void PlayerLayer::SetStatus3()
{
	this->initWithFile("Player.png");
	this->setFlipX(true);

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
	SOUND = 0;
}

void PlayerLayer::SetStatus4()
{
	this->initWithFile("Player.png");
	this->setFlipX(true);

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
	SOUND = 0;
}

void PlayerLayer::SetStatus5()
{
	this->initWithFile("Player.png");
	this->setFlipX(true);

	AtackPattern = 1;
	HP = 3;
	AT = 1;
	COST = 1;
	SOUND = 0;
}

void PlayerLayer::ChangeDirection()
{
	if (Flipflag == true)
	{
		this->setFlipX(false);
		Flipflag = false;
		MoveDirection *= -1;
	}
	else
	{
		this->setFlipX(true);
		Flipflag = true;
		MoveDirection *= -1;
	}
}

void PlayerLayer::ChangeSpeed(float delta)
{
	GameSpeed = delta;
}


void PlayerLayer::SoundPlaye()
{
	sound_name = String::createWithFormat("sound_%d.mp3", SOUND);

	soundID = SimpleAudioEngine::sharedEngine()->playEffect(sound_name->getCString());
}