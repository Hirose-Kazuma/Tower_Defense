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
	addChild(_battlelayer, 0);

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

	return true;
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
	if		(Button[0]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(0);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(0);
		}
		else
		{
			ButtonSwipeUP(0);
		}
	}
	else if (Button[1]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(1);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(1);
		}
		else
		{
			ButtonSwipeUP(1);
		}
	}
	else if (Button[2]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(2);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(2);
		}
		else
		{
			ButtonSwipeUP(2);
		}
	}
	else if (Button[3]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(3);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(3);
		}
		else
		{
			ButtonSwipeUP(3);
		}
	}
	else if (Button[4]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(4);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(4);
		}
		else
		{
			ButtonSwipeUP(4);
		}
	}
	else if (Button[5]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(5);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(5);
		}
		else
		{
			ButtonSwipeUP(5);
		}
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
