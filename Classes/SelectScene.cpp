#include"SelectScene.h"

USING_NS_CC;

bool SelectScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	MainScene *_mainScene{ MainScene::create() };
	TransitionFade *fade = TransitionFade::create(1.0f, _mainScene);
	Director::getInstance()->replaceScene(fade);

	return true;
}