#ifndef __PLAYER_LAYER__
#define __PLAYER_LAYER__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

class PlayerLayer :public Sprite
{
public:
	Sprite* PlayerPic;

	float Timer;
	bool Flipflag;
	int MoveDirection;

	int AtackPattern;
	int HP;
	int AT;
	int COST;

	bool init();
	void update(float delta);
	void SetStatus0();
	void SetStatus1();
	void SetStatus2();
	void SetStatus3();
	void SetStatus4();
	void SetStatus5();
	void ChangeDirection();
	

	CREATE_FUNC(PlayerLayer);
};


#endif // !__PLAYER_LAYER__
