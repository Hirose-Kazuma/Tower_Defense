#ifndef __MAGIC_NODE__
#define __MAGIC_NODE__

#include "cocos2d.h"

USING_NS_CC;

class MagicNode :public Node
{
public:
	CREATE_FUNC(MagicNode);

	bool init();
	void update(float delta);

	float RotateSpeed;

	Sprite* Magic_Inside;
	Sprite* Magic_Outside;
};
#endif // !__MAGIC_NODE__
