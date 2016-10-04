#ifndef __TITLE_LAYER__
#define __TITLE_LAYER__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "SelectScene.h"
#include "MainScene.h"
#include "ActionBox.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;

class TitleLayer :public Layer
{
public:
	CREATE_FUNC(TitleLayer);

	bool init();

	void TouchEvent();
	void TouchBegan(Touch *touch, Event *event);
	void TouchMove(Touch *touch, Event *event);
	void TouchEnd(Touch *touch, Event *event);

};
#endif // !__TITLE_LAYER__
