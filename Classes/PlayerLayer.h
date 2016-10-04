#ifndef __PLAYER_LAYER__
#define __PLAYER_LAYER__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

class PlayerLayer :public Sprite
{
private:

public:
	Sprite* PlayerPic;

	Vec2 NowPos;

	float Timer;
	float GameSpeed;
	bool Flipflag;
	bool Moveflag;
	int MoveDirection;

	int AtackPattern;
	int HP;
	int AT;
	int COST;
	int SOUND;

	int soundID;
	String* sound_name;

	bool init();
	void update(float delta);
	void SetStatus0();
	void SetStatus1();
	void SetStatus2();
	void SetStatus3();
	void SetStatus4();
	void SetStatus5();
	void ChangeDirection();
	void ChangeSpeed(float delta);
	void SoundPlaye();
	

	CREATE_FUNC(PlayerLayer);
};


#endif // !__PLAYER_LAYER__
