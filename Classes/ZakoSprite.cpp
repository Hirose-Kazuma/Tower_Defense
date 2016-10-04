#include "ZakoSprite.h"

USING_NS_CC;

bool ZakoSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	countFlg = 0;

	zako = Sprite::create("zako_1.png");
	zako->setScale(0.6);
	addChild(zako);

	scheduleUpdate();

	return true;
}

void ZakoSprite::update(float delta)
{
	countFlg++;

	if (countFlg == 10)
	{
		zako->setTexture("zako_2.png");
	}
	else if (countFlg == 20)
	{
		zako->setTexture("zako_1.png");
		countFlg = 0;
	}
}
