#ifndef __CROW_SPRITE__
#define __CROW_SPRITE__

#include"cocos2d.h"

USING_NS_CC;

class CrowSprite :public Sprite
{
public:
	CREATE_FUNC(CrowSprite);

	bool init();
	void update(float delta);

	Sprite *Crow;
	int countFlg;
};
#endif // !__CROW_SPRITE__
