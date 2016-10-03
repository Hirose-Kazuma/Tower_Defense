#include "IwasiSprite.h"

USING_NS_CC;

bool IwasiSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	countFlg = 0;

	iwasi = Sprite::create("iwasi_3.png");
	iwasi->setScale(0.6);
	addChild(iwasi);

	scheduleUpdate();

	return true;
}

void IwasiSprite::update(float delta)
{
	countFlg++;

	if (countFlg == 10)
	{
		iwasi->setTexture("iwasi_4.png");
	}
	else if (countFlg == 20)
	{
		iwasi->setTexture("iwasi_3.png");
		countFlg = 0;
	}
}
