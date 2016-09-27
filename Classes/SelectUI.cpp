#include "SelectUI.h"

bool SelectUI::init()
{
	if (!Layer::init())
	{
		return false;
	}


	//タッチイベント取得
	auto listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	listener->setSwallowTouches(true);
	// タッチされた瞬間に呼ばれるメソッドを登録
	listener->onTouchBegan = CC_CALLBACK_2(SelectUI::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUI::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	ButtonDisplay();

	return true;
}

//ボタン表示
void SelectUI::ButtonDisplay()
{
	//キャラボタン
	for (int i = 0; i < sizeof(Button)/sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("TestButton.png");
		Button[i]->setScale(0.5);

		PicSize = Button[i]->getContentSize();

		Button[i]->setPosition(Vec2(designResolutionSize.width * 0.1 + (i * PicSize.width) * 0.45 ,
								    designResolutionSize.height * 0.1));
		this->addChild(Button[i]);
	}

	//上中下ボタン
	for (int n = 0; n < sizeof(AMLButton) / sizeof(AMLButton[0]); n++)
	{
		AMLButton[n] = Sprite::create("TestButton.png");
		AMLButton[n]->setScale(0.3);

		PicSize = AMLButton[n]->getContentSize();

		AMLButton[n]->setPosition(Vec2(designResolutionSize.width * 0.8 + (n * PicSize.width) * 0.3,
			designResolutionSize.height * 0.1));
		this->addChild(AMLButton[n]);

	}
}


//タッチ開始
bool SelectUI::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();


	return true;
}


//タッチ終了
void SelectUI::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	//キャラボタンタッチ
	if (Button[0]->getBoundingBox().containsPoint(tp))
	{
		log("0");
	}
	else if(Button[1]->getBoundingBox().containsPoint(tp))
	{
		log("1");
	}
	else if (Button[2]->getBoundingBox().containsPoint(tp))
	{
		log("2");
	}
	else if (Button[3]->getBoundingBox().containsPoint(tp))
	{
		log("3");
	}
	else if (Button[4]->getBoundingBox().containsPoint(tp))
	{
		log("4");
	}
	else if (Button[5]->getBoundingBox().containsPoint(tp))
	{
		log("5");
	}

	//上中下ボタンタッチ
	if (AMLButton[0]->getBoundingBox().containsPoint(tp))
	{
		log("UP");
	}
	else if(AMLButton[1]->getBoundingBox().containsPoint(tp))
	{
		log("MIDDLE");
	}
	else if (AMLButton[2]->getBoundingBox().containsPoint(tp))
	{
		log("LOWER");
	}
}