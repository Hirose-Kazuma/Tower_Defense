#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "MagicNode.h"


USING_NS_CC;

class MainScene :public Scene
{
private:

public:

	bool Touch_Flg;

	int MoveDirection;	//êiçsï˚å¸
	int EnemyHP;
	int PlayerPOW;

	Rect PlayerPos;
	Rect EnemyPos;

	Sprite* PlayerPic;
	Sprite* EnemyPic;

	MagicNode* _magicNode;

	static cocos2d::Scene* createScene();

	bool init();
	void StartPic();
	void MoveSprite();
	void PlayerAction(float delta);
	void PicDes();
	void Magic_Jin();
	void Sword_Create();



	CREATE_FUNC(MainScene);

	//log

};

#endif // !__MAIN_SCENE__
