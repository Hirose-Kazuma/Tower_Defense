#ifndef __BACK_LAYER__
#define __BACK_LAYRE__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

class BackLayer :public Layer
{
private:

public:
	Sprite* bg_Sprite;

	int Timer;

	bool init();
	void StartPic();
	void update(float delta);
	void ScrollLayer(float delta);

	CREATE_FUNC(BackLayer);
};

#endif // ! __ENEMY_LAYER__
