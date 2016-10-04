#ifndef __BATTLE_LAYER__
#define __BATTLE_LAYRE__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "EnemyLayer.h"
#include "PlayerLayer.h"
#include "MagicNode.h"
#include "ActionBox.h"

USING_NS_CC;

class BattleLayer :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	EnemyLayer* _enemylayer[500];
	PlayerLayer* _playerlayer[500]; 
	MagicNode* _magicNode;

	bool Displayflag;
	bool P_Atackflag;
	bool E_Atackflag;
	bool Winflag;
	bool SpriteTouchflag;
	bool Doublespeedflag;
	bool Stopflag;

	float P_AtackTime[500];
	float E_AtackTime[500];
	float SpawnTimer;
	float SwipeDirectionX;
	float SwipeDirectionY;
	float GameSpeed;
	float PointRepairX;

	int P_TotalCost;
	int P_PulasCost;
	int E_TotalCost;
	int E_PulasCost;
	int Direction;
	int TouchSpriteNum;
	int EnemyCount;
	int PlayerCount;
	int E_HP[500];
	int E_AT[500];
	int E_COST[500];
	int E_PATTERN[500];
	int P_HP[500];
	int P_AT[500];
	int P_COST[500];
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
	void CharBattle(int AttackDir, int E_Num, int P_Num);
	void BaseBattle(int BaseNum, int Num);
	void PlayerSwipe(int DirectionS ,int Num);
	void Magic_Jin();
	void ButtonMenu(int Num);
	CREATE_FUNC(BattleLayer);
};

#endif // ! __ENEMY_LAYER__
