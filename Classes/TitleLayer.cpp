#include"TitleLayer.h"

USING_NS_CC;

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	TouchEvent();
	return true;
}

//�^�b�`�C�x���g�̏���
void TitleLayer::TouchEvent()
{
	auto listener = EventListenerTouchOneByOne::create();

	//�^�b�`�J�n��
	listener->onTouchBegan = [this](Touch *touch, Event *event)
	{
		TouchBegan(touch, event);
		return true;
	};

	//�^�b�`����
	listener->onTouchMoved = [this](Touch *touch, Event *event)
	{
		TouchMove(touch, event);
		return true;
	};

	//�^�b�`�I��莞
	listener->onTouchEnded = [this](Touch *touch, Event *event)
	{
		TouchEnd(touch, event);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

//�^�b�`�J�n��
void TitleLayer::TouchBegan(Touch *touch, Event *event)
{
}


//�^�b�`����
void TitleLayer::TouchMove(Touch *touch, Event *event)
{
}

//�^�b�`�I��莞
void TitleLayer::TouchEnd(Touch *touch, Event *event)
{
}
