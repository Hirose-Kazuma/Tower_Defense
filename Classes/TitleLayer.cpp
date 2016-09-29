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
	int poscount = 0;

	Sprite *Title1 = Sprite::create("Title_1.png");
	Sprite *Title2 = Sprite::create("Title_2.png");
	Sprite *Title3 = Sprite::create("Title_3.png");
	Sprite *Title4 = Sprite::create("Title_4.png");
	Sprite *Title5 = Sprite::create("Title_5.png");
	Sprite *Title6 = Sprite::create("Title_6.png");
	Sprite *Title7 = Sprite::create("Title_7.png");
	Sprite *Title8 = Sprite::create("Title_8.png");
	Sprite *Title9 = Sprite::create("Title_9.png");
	Sprite *Title10 = Sprite::create("Title_10.png");

	Title1->setPosition(biginPos.x + picsize * 0, biginPos.y);
	Title2->setPosition(biginPos.x + picsize * 1, biginPos.y);
	Title3->setPosition(biginPos.x + picsize * 2, biginPos.y);
	Title4->setPosition(biginPos.x + picsize * 3, biginPos.y);
	Title5->setPosition(biginPos.x + picsize*-1, biginPos.y - picsize);
	Title6->setPosition(biginPos.x + picsize * 0, biginPos.y - picsize);
	Title7->setPosition(biginPos.x + picsize * 1, biginPos.y - picsize);
	Title8->setPosition(biginPos.x + picsize * 2, biginPos.y - picsize);
	Title9->setPosition(biginPos.x + picsize * 3, biginPos.y - picsize);
	Title10->setPosition(biginPos.x + picsize * 4, biginPos.y - picsize);


	addChild(Title1);
	addChild(Title2);
	addChild(Title3);
	addChild(Title4);
	addChild(Title5);
	addChild(Title6);
	addChild(Title7);
	addChild(Title8);
	addChild(Title9);
	addChild(Title10);

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
