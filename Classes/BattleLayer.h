#ifndef __BATTLE_LAYER__
#define __BATTLE_LAYRE__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "EnemyLayer.h"
#include "PlayerLayer.h"

USING_NS_CC;

class BattleLayer :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	EnemyLayer* _enemylayer[1000];
	PlayerLayer* _playerlayer[1000];

	bool Displayflag;
	bool Atackflag;
	bool E_Desflag[1000];
	bool P_Desflag[1000];
	bool Winflag;
	bool SpriteTouchflag;

	float AtackTime;
	float SpawnTimer;
	float SwipeDirectionX;
	float SwipeDirectionY;

	int P_Cost;
	int P_PulasCost;
	int E_Cost;
	int E_PulasCost;
	int Direction;
	int TouchSpriteNum;
	int EnemyCount;
	int PlayerCount;
	int E_HP[1000];
	int E_AT[1000];
	int E_COST[1000];
	int E_PATTERN[1000];
	int P_HP[1000];
	int P_AT[1000];
	int P_COST[1000];
	int P_PATTERN[100];
	int HouseHP[2];

	Rect EnemyRect;
	Rect PlayerRect;
	Rect SubRect;
	Rect E_HouseRect;
	Rect P_HouseRect;

	Sprite* House[2];


	bool init();
	void update(float delta);
	void StartSprite();
	void EnemyDisplay();
	void PlayerDisplay(int CharNum, float Pos);
	void CharBattle(int E_Num, int P_Num);
	void BaseBattle(int BaseNum, int Num);
	void PlayerSwipe(int DirectionS ,int Num);
	CREATE_FUNC(BattleLayer);
};

#endif // ! __ENEMY_LAYER__
