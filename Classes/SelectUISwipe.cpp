#include "SelectUISwipe.h"

bool SelectUISwipe::init()
{
	if (!Layer::init())
	{
		return false;
	}

	ButtonType = 0;


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

	//毎フレーム処理
	this->scheduleUpdate();

	ButtonDisplay();

	return true;
}


//ボタン表示
void SelectUISwipe::ButtonDisplay()
{
	//キャラボタン
	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		if (ButtonType == 0)Button[i] = Sprite::create("B_Sword.png");
		else if(ButtonType == 1)Button[i] = Sprite::create("B_Rod.png");
		else if (ButtonType == 2)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 3)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 4)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 5)Button[i] = Sprite::create("B_Sword.png");

		ButtonType++;

		PicSize = Button[i]->getContentSize();

		Button[i]->setPosition(Vec2(designResolutionSize.width * 0.1 + (i * PicSize.width),
			designResolutionSize.height * 0.18));
		this->addChild(Button[i], 1);
	}



	//コスト表示01
	CostSprite[0] = Sprite::create("num_0.png");
	CostSprite[0]->setPosition(Vec2(designResolutionSize.width * 0.95, designResolutionSize.height * 0.1));
	addChild(CostSprite[0]);

	//コスト表示10
	CostSprite[1] = Sprite::create("num_0.png");
	CostSprite[1]->setPosition(Vec2(designResolutionSize.width * 0.9, designResolutionSize.height * 0.1));
	addChild(CostSprite[1]);
}


//----------------------------------------------------------------
//毎フレーム処理
//----------------------------------------------------------------
void SelectUISwipe::update(float delta)
{
	//総コスト表示01
	CostNum[0] = _battlelayer->P_TotalCost % 10;
	filename[0] = String::createWithFormat("num_%d.png", CostNum[0]);
	CostSprite[0]->setTexture(filename[0]->getCString());

	//総コスト表示10
	CostNum[1] = _battlelayer->P_TotalCost / 10;
	filename[1] = String::createWithFormat("num_%d.png", CostNum[1]);
	CostSprite[1]->setTexture(filename[1]->getCString());
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
	_battlelayer->PlayerDisplay(Num, 0.1);
}


//上スワイプ判定
void SelectUISwipe::ButtonSwipeUP(int Num)
{
	_battlelayer->PlayerDisplay(Num, 0);
}


//下スワイプ判定
void SelectUISwipe::ButtonSwipeDOUW(int Num)
{
	_battlelayer->PlayerDisplay(Num, 0.2);
}

//pullボタン判定
void SelectUISwipe::ButtonPull(int Num)
{
	_battlelayer->ButtonMenu(Num);
}