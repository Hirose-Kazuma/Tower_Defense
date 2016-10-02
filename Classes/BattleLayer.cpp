#include "BattleLayer.h"
#include "VoidScene.h"
#include "TitleScene.h"

bool BattleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	GameSpeed = 1.0f;//等倍
	HouseHP[0] = 3;
	HouseHP[1] = 3;
	P_TotalCost = 99;
	E_TotalCost = 5;


	//タッチイベント取得
	auto listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	listener->setSwallowTouches(true);
	// タッチされた瞬間に呼ばれるメソッドを登録
	listener->onTouchBegan = CC_CALLBACK_2(BattleLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(BattleLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleLayer::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	StartSprite();


	//毎フレーム処理
	this->scheduleUpdate();

	return true;
}



//----------------------------------------------------------------
//初期画像
//----------------------------------------------------------------
void BattleLayer::StartSprite()
{
	//敵拠点
	House[0] = Sprite::create("house.png");
	House[0]->setPosition(Vec2(designResolutionSize.width * 0.9, designResolutionSize.height * 0.6));
	E_HouseRect = House[0]->getBoundingBox();
	addChild(House[0]);

	//自拠点
	House[1] = Sprite::create("house.png");
	House[1]->setPosition(Vec2(designResolutionSize.width * 0.1, designResolutionSize.height * 0.6));
	P_HouseRect = House[1]->getBoundingBox();
	addChild(House[1]);

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
void BattleLayer::update(float delta)
{
	//一時停止していないとき
	if (Stopflag == false)
	{

		SpawnTimer += delta;

		if (SpawnTimer >= (3.0f * GameSpeed))
		{
			EnemyDisplay();

			SpawnTimer = 0;
		}

		//敵とのあたり判定
		for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
		{
			if (_enemylayer[i] == nullptr)break;
			for (int n = 0; n < sizeof(_playerlayer) / sizeof(_playerlayer[0]); n++)
			{
				if (_playerlayer[n] == nullptr)break;

				EnemyRect = _enemylayer[i]->getBoundingBox();
				PlayerRect = _playerlayer[n]->getBoundingBox();

				//当たっているとき
				if (EnemyRect.intersectsRect(PlayerRect))
				{
					_enemylayer[i]->stopAllActions();
					_playerlayer[n]->stopAllActions();

					P_AtackTime[i] += delta;
					E_AtackTime[n] += delta;

					//Player攻撃
					if (P_Atackflag == false)
					{
						CharBattle(0, i, n);

						P_Atackflag = true;
					}
					//Player攻撃ディレイ
					else if (P_AtackTime[i] >= (3.0 * GameSpeed))
					{
						P_AtackTime[i] = 0;
						P_Atackflag = false;
					}


					//Enemy攻撃
					if (E_Atackflag == false)
					{
						CharBattle(1, n, i);

						E_Atackflag = true;
					}
					//Player攻撃ディレイ
					else if (E_AtackTime[n] >= (3.0 * GameSpeed))
					{
						E_AtackTime[n] = 0;
						E_Atackflag = false;
					}
				}
				//進軍
				else
				{

				}
			}
		}

		//プレイヤーどうしのあたり判定
		for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
		{
			if (_playerlayer[i] == nullptr)break;
			for (int n = 0; n < (sizeof(_playerlayer) / sizeof(_playerlayer[0])) - 1; n++)
			{
				if (_playerlayer[n] == nullptr || i == n)break;

				PlayerRect = _playerlayer[i]->getBoundingBox();
				SubRect = _playerlayer[n]->getBoundingBox();

				if (PlayerRect.intersectsRect(SubRect))
				{
					_playerlayer[i]->stopAllActions();
				}
				else
				{

				}
			}
		}

		//敵どうしのあたり判定
		for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
		{
			if (_enemylayer[i] == nullptr)break;
			for (int n = 0; n < (sizeof(_enemylayer) / sizeof(_enemylayer[0])) - 1; n++)
			{
				if (_enemylayer[n] == nullptr || i == n)break;

				EnemyRect = _enemylayer[i]->getBoundingBox();
				SubRect = _enemylayer[n]->getBoundingBox();

				if (EnemyRect.intersectsRect(SubRect))
				{
					_enemylayer[i]->stopAllActions();
				}
				else
				{

				}
			}
		}

		//敵拠点のあたり判定
		for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
		{
			if (_playerlayer[i] == nullptr)break;

			PlayerRect = _playerlayer[i]->getBoundingBox();

			if (PlayerRect.intersectsRect(E_HouseRect))
			{
				P_AtackTime[i] += delta;

				_playerlayer[i]->stopAllActions();
				

				//Player攻撃
				if (P_Atackflag == false)
				{
					BaseBattle(0, i);

					P_Atackflag = true;
				}
				//Player攻撃ディレイ
				else if (P_AtackTime[i] >= (3.0 * GameSpeed))
				{
					P_AtackTime[i] = 0;
					P_Atackflag = false;
				}
			}
		}

		//味方拠点のあたり判定
		for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
		{
			if (_enemylayer[i] == nullptr)break;

			EnemyRect = _enemylayer[i]->getBoundingBox();

			if (EnemyRect.intersectsRect(P_HouseRect))
			{
				E_AtackTime[i] += delta;

				_enemylayer[i]->stopAllActions();
				


				//Enemy攻撃
				if (E_Atackflag == false)
				{
					BaseBattle(1, i);

					E_Atackflag = true;
				}
				//enemy攻撃ディレイ
				else if (E_AtackTime[i] >= (3.0 * GameSpeed))
				{
					E_AtackTime[i] = 0;
					E_Atackflag = false;
				}
			}
		}
	}


	//総コスト表示01
	CostNum[0] = P_TotalCost % 10;
	filename[0] = String::createWithFormat("num_%d.png", CostNum[0]);
	CostSprite[0]->setTexture(filename[0]->getCString());

	//総コスト表示10
	CostNum[1] = ((P_TotalCost / 10));// - (P_TotalCost % 10));
	log("%d", CostNum[1]);
	filename[1] = String::createWithFormat("num_%d.png", CostNum[1]);
	CostSprite[1]->setTexture(filename[1]->getCString());
}



//----------------------------------------------------------------
//Enemy生成
//----------------------------------------------------------------
void BattleLayer::EnemyDisplay()
{
	_enemylayer[EnemyCount] = EnemyLayer::create();
	_enemylayer[EnemyCount]->setPosition(Vec2(designResolutionSize.width * 0.8, designResolutionSize.height * 0.5));
	_enemylayer[EnemyCount]->SetStatus2();
	_enemylayer[EnemyCount]->ChangeSpeed(GameSpeed);

	/*if (CharNum == 0)_enemylayer[EnemyCount]->SetStatus0();
	else if (CharNum == 1)_enemylayer[EnemyCount]->SetStatus1();
	else if (CharNum == 2)_enemylayer[EnemyCount]->SetStatus2();
	else if (CharNum == 3)_enemylayer[EnemyCount]->SetStatus3();
	else if (CharNum == 4)_enemylayer[EnemyCount]->SetStatus4();
	else if (CharNum == 5)_enemylayer[EnemyCount]->SetStatus5();*/

	E_PATTERN[EnemyCount] = _enemylayer[EnemyCount]->AtackPattern;
	E_AT[EnemyCount] = _enemylayer[EnemyCount]->AT;
	E_HP[EnemyCount] = _enemylayer[EnemyCount]->HP;
	E_COST[EnemyCount] = _enemylayer[EnemyCount]->COST;

	//COST判定
	if (E_TotalCost >= E_COST[EnemyCount])
	{
		addChild(_enemylayer[EnemyCount]);

		E_TotalCost -= E_COST[EnemyCount];
		EnemyCount++;
	}
	else
	{
		_enemylayer[EnemyCount] = nullptr;
	}
}



//----------------------------------------------------------------
//Player生成
//----------------------------------------------------------------
void BattleLayer::PlayerDisplay(int CharNum, float Pos)
{
	//キャラ振り分けはクラスの関数で設定
	_playerlayer[PlayerCount] = PlayerLayer::create();
	_playerlayer[PlayerCount]->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * (0.4 + Pos)));
	_playerlayer[PlayerCount]->ChangeSpeed(GameSpeed);

	if (CharNum == 0)_playerlayer[PlayerCount]->SetStatus0();
	else if(CharNum == 1)_playerlayer[PlayerCount]->SetStatus1();
	else if (CharNum == 2)_playerlayer[PlayerCount]->SetStatus2();
	else if (CharNum == 3)_playerlayer[PlayerCount]->SetStatus3();
	else if (CharNum == 4)_playerlayer[PlayerCount]->SetStatus4();
	else if (CharNum == 5)_playerlayer[PlayerCount]->SetStatus5();

	
	P_PATTERN[PlayerCount] = _playerlayer[PlayerCount]->AtackPattern;
	P_AT[PlayerCount] = _playerlayer[PlayerCount]->AT;
	P_HP[PlayerCount] = _playerlayer[PlayerCount]->HP;
	P_COST[PlayerCount] = _playerlayer[PlayerCount]->COST;

	//COST判定
	if (P_TotalCost >= P_COST[PlayerCount])
	{
		addChild(_playerlayer[PlayerCount]);

		P_TotalCost -= P_COST[PlayerCount];
		PlayerCount++;
	}
	else
	{
		_playerlayer[PlayerCount] = nullptr;
	}

}



//----------------------------------------------------------------
//キャラバトル
//----------------------------------------------------------------
void BattleLayer::CharBattle(int AttackDir, int E_Num, int P_Num)
{
	if (AttackDir == 0) 
	{
		E_HP[E_Num] -= P_AT[P_Num];

		//要改善 死亡処理
		if (E_HP[E_Num] <= 0)
		{
			_enemylayer[E_Num]->setVisible(false);
			_enemylayer[E_Num]->setPosition(0, 0);

			P_AtackTime[E_Num] = 0;
		}
	}
	else if (AttackDir == 1)
	{
		P_HP[P_Num] -= E_AT[E_Num];

		//死亡処理
		if (P_HP[P_Num] <= 0)
		{
			_playerlayer[P_Num]->setVisible(false);
			_playerlayer[P_Num]->setPosition(0, 0);

			E_AtackTime[P_Num] = 0;
		}
	}
}



//----------------------------------------------------------------
//拠点攻撃
//----------------------------------------------------------------
void BattleLayer::BaseBattle(int BaseNum, int Num)
{
	if (BaseNum == 0)
	{
		HouseHP[BaseNum] -= P_AT[Num];
		P_AtackTime[Num];

		if (HouseHP[0] <= 0)
		{
			if (Winflag == false)
			{
				House[0]->removeFromParentAndCleanup(true);
				Winflag = true;
			}
			Director::getInstance()->getActionManager()->removeAllActions();
			log("Player Win!!");
		}
	}
	else if (BaseNum == 1)
	{
		HouseHP[BaseNum] -= E_AT[Num];
		E_AtackTime[Num] = 0;

		if (HouseHP[1] <= 0)
		{
			if (Winflag == false)
			{
				House[1]->removeFromParentAndCleanup(true);
				Winflag = true;
			}
			Director::getInstance()->getActionManager()->removeAllActions();
			log("Enemy Win!!");
		}
	}
}



//----------------------------------------------------------------
//タッチ開始
//----------------------------------------------------------------
bool BattleLayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント 見えてる範囲でとってる
	Vec2 tp = pTouch->getLocation();

	SwipeDirectionX = tp.x;
	SwipeDirectionY = tp.y;

	tp.x -= PointRepairX;

	//このレイヤー内のオブジェクトがタッチされているか
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;

		if (_playerlayer[i]->getBoundingBox().containsPoint(tp))
		{
			_playerlayer[i]->stopAllActions();
			TouchSpriteNum = i;

			//Spriteがタッチされているか
			SpriteTouchflag = true;
		}
	}

	return true;
}



//----------------------------------------------------------------
//タッチ中
//----------------------------------------------------------------
void BattleLayer::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	//Layer移動させるマン
	Vec2 swipe = pTouch->getDelta();

	//Spriteがタッチされていないとき
	if (SpriteTouchflag == false)
	{
		PointRepairX += swipe.x;
	}

	Vec2 layerpos = this->getPosition();

	if (SpriteTouchflag != true)
	{
		this->setPosition(Vec2(layerpos.x + swipe.x, layerpos.y));
	}
}



//----------------------------------------------------------------
//タッチ終了
//----------------------------------------------------------------
void BattleLayer::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	//スワイプ判定
	//+左方向	-右方向
	SwipeDirectionX -= tp.x;
	//+上方向　　-下方向
	SwipeDirectionY -= tp.y;

	//右
	if (SwipeDirectionX <= 0 && SwipeDirectionY >= -100 && SwipeDirectionY <= 100)
	{
		Direction = 0;
	}
	//左
	else if (SwipeDirectionX >= 0 && SwipeDirectionY >= -100 && SwipeDirectionY <= 100)
	{
		Direction = 1;
	}
	//上
	else if (SwipeDirectionY <= 0 && SwipeDirectionX >= -100 && SwipeDirectionX <= 100)
	{
		Direction = 2;
	}
	//下
	else if (SwipeDirectionY >= 0 && SwipeDirectionX >= -100 && SwipeDirectionX <= 100)
	{
		Direction = 3;
	}
	//エラー回避
	if (_playerlayer[TouchSpriteNum] != nullptr)
	{
		PlayerSwipe(Direction, TouchSpriteNum);
	}
}



//----------------------------------------------------------------
//Playerスワイプ処理
//----------------------------------------------------------------
void BattleLayer::PlayerSwipe(int DirectionS, int Num)
{
	if (SpriteTouchflag == true) {
		if (DirectionS == 0)
		{
			_playerlayer[Num]->ChangeDirection();
		}
		else if (DirectionS == 1)
		{
			_playerlayer[Num]->ChangeDirection();
		}
		else if (DirectionS == 2)
		{
			if (_playerlayer[Num]->getPosition().y < designResolutionSize.height * 0.6)
			{
				auto move = MoveTo::create(1, Point(_playerlayer[Num]->getPosition().x,
					_playerlayer[Num]->getPosition().y + designResolutionSize.height * 0.1));
				_playerlayer[Num]->runAction(move);
			}
		}
		else if (DirectionS == 3)
		{
			if (_playerlayer[Num]->getPosition().y > designResolutionSize.height * 0.4)
			{
				auto move = MoveTo::create(1, Point(_playerlayer[Num]->getPosition().x,
					_playerlayer[Num]->getPosition().y - designResolutionSize.height * 0.1));
				_playerlayer[Num]->runAction(move);
			}
		}
	}

	SpriteTouchflag = false;
}



//----------------------------------------------------------------
//魔法陣
//----------------------------------------------------------------
void BattleLayer::Magic_Jin()
{
	//魔法陣表示
	_magicNode = MagicNode::create();
	//_magicNode->setPosition(Vec2(designResolutionSize.width * 0.3, designResolutionSize.height * 0.5));
	_magicNode->setScale(0.05);
	addChild(_magicNode);

	//魔法陣アクション
	_magicNode->runAction(ActionBox::MagicJinAction());

	//杖表示
	Sprite *Test_Rod = Sprite::create("C_Rod.png");
	Test_Rod->setScale(0.5);
	Test_Rod->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Test_Rod->setPosition(_magicNode->getPosition());
	Test_Rod->setOpacity(0);
	addChild(Test_Rod);


	//杖アクション
	Test_Rod->runAction(ActionBox::MagicRodAction());


	//
	Sprite *MagicLight = Sprite::create("DrawNode.png");
	MagicLight->setColor(Color3B::RED);
	MagicLight->setPosition(_magicNode->getPosition());
	MagicLight->setScale(0.25);
	MagicLight->setOpacity(0);
	addChild(MagicLight);

	MagicLight->runAction(ActionBox::MagicLightAction());

}



//----------------------------------------------------------------
//メニューボタン
//----------------------------------------------------------------
void BattleLayer::ButtonMenu(int Num)
{
	//早送り
	if (Num == 0)
	{
		if (Doublespeedflag == false)
		{
			GameSpeed = 0.5f;//倍速

			Doublespeedflag = true;
		}
		else
		{
			GameSpeed = 1.0f;//通常

			Doublespeedflag = false;
		}

		//存在しているPlayerを倍速処理
		for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
		{
			if (_playerlayer[i] == nullptr)break;

			_playerlayer[i]->ChangeSpeed(GameSpeed);
		}
		//存在しているEnemyを倍速処理
		for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
		{
			if (_enemylayer[i] == nullptr)break;

			_enemylayer[i]->ChangeSpeed(GameSpeed);
		}
	}
	//一時停止
	else if (Num == 1)
	{
		//停止
		if (Stopflag == false)
		{
			//存在しているPlayerをストップ
			for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
			{
				if (_playerlayer[i] == nullptr)break;

				_playerlayer[i]->pauseSchedulerAndActions();
			}
			//存在しているEnemyをストップ
			for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
			{
				if (_enemylayer[i] == nullptr)break;

				_enemylayer[i]->pauseSchedulerAndActions();
			}

			Stopflag = true;
		}
		//再生
		else
		{
			//存在しているPlayerを再生
			for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
			{
				if (_playerlayer[i] == nullptr)break;

				_playerlayer[i]->resumeSchedulerAndActions();
			}
			//存在しているEnemyを再生
			for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
			{
				if (_enemylayer[i] == nullptr)break;

				_enemylayer[i]->resumeSchedulerAndActions();
			}

			Stopflag = false;
		}
	}
	//最初から		できてない
	else if (Num == 2)
	{
		VoidScene *_selectScene{ VoidScene::create() };
		TransitionFade *fade = TransitionFade::create(1.0f, _selectScene);
		Director::getInstance()->replaceScene(fade); 
	}
	//やめる
	else if (Num == 3)
	{
		TitleScene *_selectScene{ TitleScene::create() };
		TransitionFade *fade = TransitionFade::create(1.0f, _selectScene);
		Director::getInstance()->replaceScene(fade);
	}
}