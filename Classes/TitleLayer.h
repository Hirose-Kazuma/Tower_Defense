#ifndef __TITLE_LAYER__
#define __TITLE_LAYER__

#include "cocos2d.h"

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
