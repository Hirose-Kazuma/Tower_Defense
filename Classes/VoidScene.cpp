#include "VoidScene.h"
#include "MainScene.h"


Scene* VoidScene::createScene()
{
	auto scene = Scene::create();

	auto layer = VoidScene::create();

	scene->addChild(layer);

	return scene;
}


//すぐ元のシーンに戻す
bool VoidScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Timer = 0;

	//毎フレーム処理
	//this->scheduleUpdate();

	return true;
}

void VoidScene::update(float delta)
{
	Timer += delta;

}

void VoidScene::onEnterTransitionDidFinish()
{
	log("WWWW");

	MainScene *_selectScene{ MainScene::create() };
	TransitionFade *fade = TransitionFade::create(1.0f, _selectScene);
	Director::getInstance()->replaceScene(_selectScene);
}