#include"TitleBackLayer.h"

USING_NS_CC;

bool TitleBackLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto BackGround = LayerColor::create(Color4B::WHITE, designResolutionSize.width, designResolutionSize.height);
	this->addChild(BackGround);

	return true;
}