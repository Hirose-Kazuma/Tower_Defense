#ifndef __VOID_SCENE__
#define __VOID_SCENE__

#include "cocos2d.h"

USING_NS_CC;

class VoidScene :public Scene
{
public:
	float Timer;


	static cocos2d::Scene* createScene();
	bool init();
	void update(float delta);
	void onEnterTransitionDidFinish();


	CREATE_FUNC(VoidScene);
};


#endif // !__VOID_SCENE__
