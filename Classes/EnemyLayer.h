#ifndef __ENEMY_LAYER__
#define __ENEMY_LAYRE__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

/*
�K�v�ȏ��
�L�����̎��
�U�����@
HP
AT
�R�X�g
*/

class EnemyLayer :public Sprite
{
private:

public:
	Sprite* EnemyPic;

	float Timer;
	bool Flipflag;
	int MoveDirection;

	int AtackPattern;
	int HP;
	int AT;
	int COST;


	bool init();
	void update(float delta);
	void PicDisplay();
	void SetStatus0();
	void SetStatus1();
	void SetStatus2();
	void SetStatus3();
	void SetStatus4();
	void SetStatus5();
	void ChangeDirection();

	CREATE_FUNC(EnemyLayer);
};

#endif // ! __ENEMY_LAYER__
