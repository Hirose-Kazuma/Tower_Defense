#include "BattleLayer.h"

bool BattleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	HouseHP[0] = 3;
	HouseHP[1] = 3;


	//タッチイベント取得
	auto listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	listener->setSwallowTouches(true);
	// タッチされた瞬間に呼ばれるメソッドを登録
	listener->onTouchBegan = CC_CALLBACK_2(BattleLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleLayer::onTouchEnded, this);
	// イベントの実行の優先順位をノードの重なり順に依存させる
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	StartSprite();

	//EnemyDisplay();

	//毎フレーム処理
	this->scheduleUpdate();

	return true;
}

void BattleLayer::StartSprite()
{
	House[0] = Sprite::create("house.png");
	House[0]->setPosition(Vec2(designResolutionSize.width * 0.1, designResolutionSize.height * 0.6));
	E_HouseRect = House[0]->getBoundingBox();
	addChild(House[0]);

	
	House[1] = Sprite::create("house.png");
	House[1]->setPosition(Vec2(designResolutionSize.width * 0.9, designResolutionSize.height * 0.6));
	P_HouseRect = House[1]->getBoundingBox();
	addChild(House[1]);
}

void BattleLayer::update(float delta)
{
	SpawnTimer += delta;

	if (SpawnTimer >= 3.0f)
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

			//攻撃
			if (EnemyRect.intersectsRect(PlayerRect))
			{
				_enemylayer[i]->stopAllActions();
				_playerlayer[n]->stopAllActions();

				AtackTime += delta;

				//攻撃
				if (Atackflag == false)
				{
					CharBattle(i, n);

					Atackflag = true;

					//要改善 死亡処理
					if (E_HP[i] <= 0)
					{
						_enemylayer[i]->setVisible(false);
						_enemylayer[i]->setPosition(0, 0);

						E_Desflag[i] = true;
					}
				}
				else if (AtackTime >= 3.0)
				{
					AtackTime = 0;
					Atackflag = false;
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
			_playerlayer[i]->stopAllActions();
		}
		else
		{

		}
	}

	//味方拠点のあたり判定
	for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
	{
		if (_enemylayer[i] == nullptr)break;

		EnemyRect = _enemylayer[i]->getBoundingBox();

		if (EnemyRect.intersectsRect(P_HouseRect))
		{
			_enemylayer[i]->stopAllActions();
		}
		else
		{

		}
	}
	
}

void BattleLayer::EnemyDisplay()
{
	_enemylayer[EnemyCount] = EnemyLayer::create();
	_enemylayer[EnemyCount]->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * 0.5));

	/*if (CharNum == 0)_enemylayer[EnemyCount]->SetStatus0();
	else if (CharNum == 1)_enemylayer[EnemyCount]->SetStatus1();
	else if (CharNum == 2)_enemylayer[EnemyCount]->SetStatus2();
	else if (CharNum == 3)_enemylayer[EnemyCount]->SetStatus3();
	else if (CharNum == 4)_enemylayer[EnemyCount]->SetStatus4();
	else if (CharNum == 5)_enemylayer[EnemyCount]->SetStatus5();*/

	addChild(_enemylayer[EnemyCount]);
	
	E_PATTERN[EnemyCount] = _enemylayer[EnemyCount]->AtackPattern;
	E_AT[EnemyCount] = _enemylayer[EnemyCount]->AT;
	E_HP[EnemyCount] = _enemylayer[EnemyCount]->HP;
	E_COST[EnemyCount] = _enemylayer[EnemyCount]->COST;

	EnemyCount++;
}

void BattleLayer::PlayerDisplay(int CharNum, float Pos)
{
	//キャラ振り分けはクラスの関数で設定

	_playerlayer[PlayerCount] = PlayerLayer::create();
	_playerlayer[PlayerCount]->setPosition(Vec2(designResolutionSize.width * 0.7, designResolutionSize.height * (0.4 + Pos)));

	if (CharNum == 0)_playerlayer[PlayerCount]->SetStatus0();
	else if(CharNum == 1)_playerlayer[PlayerCount]->SetStatus1();
	else if (CharNum == 2)_playerlayer[PlayerCount]->SetStatus2();
	else if (CharNum == 3)_playerlayer[PlayerCount]->SetStatus3();
	else if (CharNum == 4)_playerlayer[PlayerCount]->SetStatus4();
	else if (CharNum == 5)_playerlayer[PlayerCount]->SetStatus5();

	addChild(_playerlayer[PlayerCount]);

	P_PATTERN[PlayerCount] = _playerlayer[PlayerCount]->AtackPattern;
	P_AT[PlayerCount] = _playerlayer[PlayerCount]->AT;
	P_HP[PlayerCount] = _playerlayer[PlayerCount]->HP;
	P_COST[PlayerCount] = _playerlayer[PlayerCount]->COST;

	PlayerCount++;

}

void BattleLayer::CharBattle(int E_Num, int P_Num)
{
	E_HP[E_Num] -= P_AT[P_Num];
}

void BattleLayer::BaseBattle(int BaseNum, int Num)
{
	if (BaseNum == 0)
	{
		HouseHP[BaseNum] -= P_AT[Num];
	}
	else if(BaseNum == 1)
	{
		HouseHP[BaseNum] -= E_AT[Num];
	}
}

//タッチ開始
bool BattleLayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//タッチポイント
	Vec2 tp = pTouch->getLocation();

	SwipeDirectionX = tp.x;
	SwipeDirectionY = tp.y;

	//このレイヤー内のオブジェクトがタッチされているか
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;

		if (_playerlayer[i]->getBoundingBox().containsPoint(tp))
		{
			_playerlayer[i]->stopAllActions();
			TouchSpriteNum = i;
			return true;
		}
	}

	return false;
}


//タッチ終了
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

	PlayerSwipe(Direction, TouchSpriteNum);
}


//Playerスワイプ処理
void BattleLayer::PlayerSwipe(int DirectionS, int Num)
{
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