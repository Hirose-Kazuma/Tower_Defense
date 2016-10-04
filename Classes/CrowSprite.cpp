#include "CrowSprite.h"

USING_NS_CC;

bool CrowSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	countFlg = 0;

	Crow = Sprite::create("Crow_1.png");
	Crow->setScale(0.6);
	addChild(Crow);

	scheduleUpdate();

	return true;
}

void CrowSprite::update(float delta)
{
	countFlg++;

	if (countFlg == 10)
	{
		Crow->setTexture("Crow_2.png");
	}
	else if (countFlg==20)
	{
		Crow->setTexture("Crow_1.png");
		countFlg = 0;
	}
}
