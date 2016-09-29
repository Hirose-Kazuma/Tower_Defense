#ifndef __TITLE_BACK_LAYER__
#define __TITLA_BACK_LAYER__

#include"cocos2d.h"
#include"MultiResolution.h"

USING_NS_CC;

class TitleBackLayer : public Layer
{
public:
	CREATE_FUNC(TitleBackLayer);

	bool init();
	void update(float delta);

	Sprite *BackGround;

	Point UP_Pos;
	Point Middle_Pos;
	Point Down_Pos;

	int CountFlg;
};
#endif // !__TITLE_BACK_LAYER__
