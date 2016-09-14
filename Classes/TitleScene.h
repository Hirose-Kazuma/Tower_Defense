#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "cocos2d.h"

USING_NS_CC;

class TitleScene :public Scene
{
public:
	CREATE_FUNC(TitleScene);

	bool init();
	void update(float delta);
	//

};
#endif // !__TITLE_SCENE_H__
