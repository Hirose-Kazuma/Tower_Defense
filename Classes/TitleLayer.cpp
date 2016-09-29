#include"TitleLayer.h"

USING_NS_CC;

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Sprite *TitleLabel_T = Sprite::create("Label_T.png");
	Sprite *TitleLabel_o = Sprite::create("Label_o.png");
	Sprite *TitleLabel_u = Sprite::create("Label_u.png");
	Sprite *TitleLabel_c = Sprite::create("Label_c.png");
	Sprite *TitleLabel_h = Sprite::create("Label_h.png");

	auto picSize = TitleLabel_u->getContentSize().width;
	TitleLabel_T->setPosition(designResolutionSize.width*0.5 - picSize * 2, designResolutionSize.height*0.3);
	TitleLabel_o->setPosition(designResolutionSize.width*0.5 - picSize, designResolutionSize.height*0.3);
	TitleLabel_u->setPosition(designResolutionSize.width*0.5, designResolutionSize.height*0.3);
	TitleLabel_c->setPosition(designResolutionSize.width*0.5 + picSize, designResolutionSize.height*0.3);
	TitleLabel_h->setPosition(designResolutionSize.width*0.5 + picSize * 2, designResolutionSize.height*0.3);

	addChild(TitleLabel_T);
	addChild(TitleLabel_o);
	addChild(TitleLabel_u);
	addChild(TitleLabel_c);
	addChild(TitleLabel_h);

	Vector<Sprite*> Title;
	Sprite *_title = Sprite::create();
	float picsize = Sprite::create("Title_1.png")->getContentSize().width;
	Point biginPos = Point(designResolutionSize.width*0.5-picsize*1.5, designResolutionSize.height*0.7);

	_title->setTexture("Title_1.png");
	Title.pushBack(_title);
	_title->setTexture("Title_2.png");
	Title.pushBack(_title);
	_title->setTexture("Title_3.png");
	Title.pushBack(_title);
	_title->setTexture("Title_4.png");
	Title.pushBack(_title);
	_title->setTexture("Title_5.png");
	Title.pushBack(_title);
	_title->setTexture("Title_6.png");
	Title.pushBack(_title);
	_title->setTexture("Title_7.png");
	Title.pushBack(_title);
	_title->setTexture("Title_8.png");
	Title.pushBack(_title);
	_title->setTexture("Title_9.png");
	Title.pushBack(_title);
	_title->setTexture("Title_10.png");
	Title.pushBack(_title);

	for (int i = 0; i < Title.size(); i++)
	{
		if (i < 4)
		{
			Title.at(i)->setPosition(biginPos.x + picsize*i, biginPos.y);
		}
		else
		{
			Title.at(i)->setPosition(biginPos.x + picsize*(i - 5), biginPos.y - picsize);
		}

		addChild(Title.at(i));
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
	MainScene *_selectScene{ MainScene::create() };
	TransitionFade *fade = TransitionFade::create(1.0f, _selectScene);
	Director::getInstance()->replaceScene(fade);
}
