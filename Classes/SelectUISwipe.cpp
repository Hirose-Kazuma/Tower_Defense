#include "SelectUISwipe.h"

bool SelectUISwipe::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(SelectUISwipe::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUISwipe::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	_battlelayer = BattleLayer::create();
	addChild(_battlelayer, -1);

	ButtonDisplay();

	return true;
}


//ボタン表示
void SelectUISwipe::ButtonDisplay()
{
	//キャラボタン
	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("B_Sword.png");
		Button[i]->setScaleY(0.7);

		PicSize = Button[i]->getContentSize();

		Button[i]->setPosition(Vec2(designResolutionSize.width * 0.1 + (i * PicSize.width),
			designResolutionSize.height * 0.18));
		this->addChild(Button[i], 1);
	}
}

//タッチ開始
bool SelectUISwipe::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	SwipeDirection = tp.y;

	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		if (Button[i]->getBoundingBox().containsPoint(tp))
		{
			ButtonNum = i;

			return true;
		}
	}

	return false;
}


//タッチ終了
void SelectUISwipe::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	//スワイプ判定
	//+上方向　　-下方向
	SwipeDirection -= tp.y;


	//キャラボタンタッチ
	if (SwipeDirection >= -50 && 50 >= SwipeDirection)
	{
		ButtonTap(ButtonNum);
	}
	else if (SwipeDirection <= 0)
	{
		ButtonSwipeDOUW(ButtonNum);
	}
	else
	{
		ButtonSwipeUP(ButtonNum);
	}
}


//ボタンタップ判定
void SelectUISwipe::ButtonTap(int Num)
{
	log("Number%d--tap", Num);

	_battlelayer->PlayerDisplay(Num, 0.1);
}


//上スワイプ判定
void SelectUISwipe::ButtonSwipeUP(int Num)
{
	log("Number%d--down", Num);

	_battlelayer->PlayerDisplay(Num, 0);
}


//下スワイプ判定
void SelectUISwipe::ButtonSwipeDOUW(int Num)
{
	log("Number%d--up", Num);

	_battlelayer->PlayerDisplay(Num, 0.2);
}