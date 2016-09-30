#include "PullUI.h"

bool PullUI::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(PullUI::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(PullUI::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	_selectuiswipe = SelectUISwipe::create();
	addChild(_selectuiswipe, -1);

	StartPic();

	//毎フレーム処理
	this->scheduleUpdate();

	return true;
}

void PullUI::StartPic()
{
	//下地
	ButtonUI[4] = Sprite::create("PullUI_bg.png");
	ButtonUI[4]->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	ButtonUI[4]->setPosition(Vec2(designResolutionSize.width * 0.5, designResolutionSize.height * 1.3));
	addChild(ButtonUI[4], 0);

	

	//各ボタン
	for (int i = 0; i < sizeof(ButtonUI) / sizeof(ButtonUI[0]) - 1; i++)
	{
		file_name = String::createWithFormat("PullUI_%d.png", i);
		ButtonUI[i] = Sprite::create(file_name->getCString());
		ButtonUI[i]->setPosition(Vec2(designResolutionSize.width * PosNum[i], designResolutionSize.height * 1.15));
		ButtonRect[i] = ButtonUI[i]->getBoundingBox();
		addChild(ButtonUI[i], 1);

		
	}
}

void PullUI::update(float delta)
{
	//親の座標分引く
}

void PullUI::ScrollLayer(bool flag)
{
	//01を交互に
	Scrollflag ^= true;

	//出てくる
	if (Scrollflag == true)
	{
		for (int i = 0; i < 5; i++)
		{
			move[i] = MoveTo::create(0.1, Vec2(designResolutionSize.width * PosNum[i], designResolutionSize.height * PosNumY[i]));

			ButtonUI[i]->runAction(move[i]);
		}
	}
	//引っ込む
	else if (Scrollflag == false)
	{
		for (int i = 0; i < 5; i++)
		{
			move[i] = MoveTo::create(0.1, Vec2(designResolutionSize.width * 0.5 + PosNum[i], designResolutionSize.height * 1.3));

			ButtonUI[i]->runAction(move[i]);
		}
	}
}


bool PullUI::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	bool Buttonflag = false;

	//ボタンタッチ
	for (int i = 0; i < sizeof(ButtonUI) / sizeof(ButtonUI[0]) - 1; i++)
	{
		if (ButtonUI[i]->getBoundingBox().containsPoint(tp))
		{
			_selectuiswipe->ButtonPull(i);

			Buttonflag = true;

			return true;
		}
	}

	//大枠タッチ
	if (ButtonUI[4]->getBoundingBox().containsPoint(tp) && Buttonflag == false )
	{
		ScrollLayer(Scrollflag);

		return true;
	}

	
	return false;
}


//タッチ終了
void PullUI::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

}