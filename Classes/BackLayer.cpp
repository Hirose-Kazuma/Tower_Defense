#include "BackLayer.h"

bool BackLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Timer = 0.0f;

	StartPic();

	//���t���[������
	this->scheduleUpdate();

	return true;
}

void BackLayer::StartPic()
{
	//�w�i�F��
	/*auto bg_color = LayerColor::create(Color4B::WHITE, designResolutionSize.width, designResolutionSize.height);
	this->addChild(bg_color);*/

	bg_Sprite = Sprite::create("Back.png");
	bg_Sprite->setPosition(Vec2(designResolutionSize * 0.5));
	addChild(bg_Sprite);


}

void BackLayer::update(float delta)
{
	
}

void BackLayer::ScrollLayer(float delta)
{

}