#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "cocos2d.h"

#include "TitleBackLayer.h"
#include "TitleLayer.h"

USING_NS_CC;

class TitleScene :public Scene
{
public:
	CREATE_FUNC(TitleScene);

	bool init();

	TitleBackLayer *_titleBackLayer;
	TitleLayer *_titleLayer;


};
#endif // !__TITLE_SCENE_H__
