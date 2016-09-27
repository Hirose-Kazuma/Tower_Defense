#include "SelectUIRevolver.h"

bool SelectUIRevolver::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(SelectUIRevolver::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUIRevolver::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	Radius = 500.0f;

	ButtonDisplay();

	return true;
}


//ボタン表示
void SelectUIRevolver::ButtonDisplay()
{
	float theta = 360.0f / sizeof(Button);

	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("TestButton.png");
		Button[i]->setScaleX(0.5);

		PicSize = Button[i]->getContentSize();

		// 270 度の位置が正面にくるように
		float angle = theta * i + 270.0f;
		float radians = angle * PI / 180.0f;
		float x = Radius * cos(radians);
		float y = Radius * sin(radians);
		Button[i]->setPosition(Vec2(x, y));

		addChild(Button[i]);
	}


	//float theta = 360.0f / sizeof(Button);
	//for (int n = 0; n < sizeof(Button); n++)
	//{
	//	// 270 度の位置が正面にくるように  
	//	float angle = theta * n + 270.0f;
	//	float radians = angle * PI / 180.0f;
	//	float x = Radius * cos(radians);
	//	float y = Radius * sin(radians);
	//	Button[n]->setPosition(Vec2(x, y));
	//}
}


//タッチ開始
bool SelectUIRevolver::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	SwipeDirection = tp.y;

	return true;
}


//タッチ終了
void SelectUIRevolver::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	//スワイプ判定
	//+上方向　　-下方向
	SwipeDirection -= tp.y;

}