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
	void IwasiCreate();
	void ZakoCreate();
	void CrowCreate();
	void ArrayDelete(int number);

	Sprite *BackGround;
	Vector<Sprite*> _enemyTeam;
	int TeamNumber;

	Point UP_Pos;
	Point Middle_Pos;
	Point Down_Pos;

	int CountFlg;
};
#endif // !__TITLE_BACK_LAYER__
