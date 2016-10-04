#ifndef __ACTION_BOX__
#define __ACTION_BOX__

#include "cocos2d.h"
#include"MultiResolution.h"

USING_NS_CC;

class ActionBox
{
public:
	static FiniteTimeAction *ActionBox::MagicJinAction();
	static FiniteTimeAction *ActionBox::MagicLightAction();
	static FiniteTimeAction *ActionBox::MagicRodAction();
	static void *ActionBox::ResultWin(Sprite *Win);
	static void *ActionBox::ResultLose(Sprite *Lose1, Sprite *Lose2, Sprite *Lose3, Sprite *Lose4);
	

};
#endif // !__ACTION_BOX__
