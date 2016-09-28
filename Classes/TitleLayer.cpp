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

//タッチイベントの所得
void TitleLayer::TouchEvent()
{
	auto listener = EventListenerTouchOneByOne::create();

	//タッチ開始時
	listener->onTouchBegan = [this](Touch *touch, Event *event)
	{
		TouchBegan(touch, event);
		return true;
	};

	//タッチ中時
	listener->onTouchMoved = [this](Touch *touch, Event *event)
	{
		TouchMove(touch, event);
		return true;
	};

	//タッチ終わり時
	listener->onTouchEnded = [this](Touch *touch, Event *event)
	{
		TouchEnd(touch, event);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

//タッチ開始時
void TitleLayer::TouchBegan(Touch *touch, Event *event)
{
}


//タッチ中時
void TitleLayer::TouchMove(Touch *touch, Event *event)
{
}

//タッチ終わり時
void TitleLayer::TouchEnd(Touch *touch, Event *event)
{
}
