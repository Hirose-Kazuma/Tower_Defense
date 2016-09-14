#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

class MainScene :public Scene
{
private:

public:
	int MoveDirection;	//êiçsï˚å¸
	int EnemyHP;
	int PlayerPOW;

	Rect PlayerPos;
	Rect EnemyPos;

	Sprite* PlayerPic;
	Sprite* EnemyPic;

	static cocos2d::Scene* createScene();

	bool init();
	void StartPic();
	void MoveSprite();
	void PlayerAction(float delta);
	void PicDes();

	CREATE_FUNC(MainScene);

};

#endif // !__MAIN_SCENE__
