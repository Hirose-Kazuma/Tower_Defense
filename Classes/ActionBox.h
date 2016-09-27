#ifndef __ACTION_BOX__
#define __ACTION_BOX__

#include "cocos2d.h"

USING_NS_CC;

class ActionBox
{
public:
	static FiniteTimeAction *ActionBox::MagicJinAction();
	static FiniteTimeAction *ActionBox::MagicLightAction();
	static FiniteTimeAction *ActionBox::MagicRodAction();

};
#endif // !__ACTION_BOX__
