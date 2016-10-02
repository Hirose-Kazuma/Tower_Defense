#include "VoidScene.h"
#include "MainScene.h"


//�������̃V�[���ɖ߂�
bool VoidScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Timer = 0;

	//���t���[������
	//this->scheduleUpdate();

	return true;
}

void VoidScene::update(float delta)
{
	Timer += delta;

}

void VoidScene::onEnterTransitionDidFinish()
{
	MainScene *_selectScene{ MainScene::create() };
	TransitionFade *fade = TransitionFade::create(1.0f, _selectScene);
	Director::getInstance()->replaceScene(_selectScene);
}