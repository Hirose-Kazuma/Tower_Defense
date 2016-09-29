#ifndef __IWASI_SPRITE__
#define __IWASI_SPRITE__

#include "cocos2d.h"

USING_NS_CC;

class IwasiSprite : public Sprite
{
public:
	CREATE_FUNC(IwasiSprite);

	bool init();
	void update(float delta);

	Sprite *iwasi;
	int countFlg;
};
#endif // !__IWASI_SPRITE__
