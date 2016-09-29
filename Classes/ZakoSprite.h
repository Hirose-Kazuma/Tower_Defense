#ifndef __ZAKO_SPRITE__
#define __ZAKO_SPRITE__

#include "cocos2d.h"

USING_NS_CC;

class ZakoSprite : public Sprite
{
public:

	CREATE_FUNC(ZakoSprite);

	bool init();
	void update(float delta);

	Sprite *zako;
	int countFlg;
};
#endif // !__ZAKO_SPRITE__
