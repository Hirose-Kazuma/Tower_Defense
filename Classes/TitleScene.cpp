#include "TitleScene.h"

USING_NS_CC;

bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	_titleBackLayer = TitleBackLayer::create();
	addChild(_titleBackLayer, -1);
	_titleLayer = TitleLayer::create();
	addChild(_titleLayer, 1);

	return true;
}

