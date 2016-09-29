#include"TitleBackLayer.h"
#include"IwasiSprite.h"
#include"ZakoSprite.h"
#include"CrowSprite.h"

USING_NS_CC;

bool TitleBackLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CountFlg = 0;

	UP_Pos = Point(designResolutionSize.width*1.1, designResolutionSize.height*0.8);
	Middle_Pos = Point(designResolutionSize.width*1.1, designResolutionSize.height*0.65);
	Down_Pos = Point(designResolutionSize.width*1.1, designResolutionSize.height*0.5);

	BackGround = Sprite::create("Back.png");
	BackGround->setPosition(designResolutionSize*0.5);
	addChild(BackGround);
		

	scheduleUpdate();
	return true;
}

void TitleBackLayer::update(float delta)
{
	CountFlg++;

	if (CountFlg == 10)
	{
		switch ((int)rand() % 4)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;

		default:
			break;
		}

		CountFlg = 0;
	}
}
