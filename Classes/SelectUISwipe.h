#ifndef __SELECT_UI_SWIPE__
#define __SELECT_UI_SWIPE__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "BattleLayer.h"

USING_NS_CC;

class SelectUISwipe :public Layer
{
private:
	// �^�b�`�C�x���g����
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	BattleLayer* _battlelayer;

	Sprite* Button[6];
	Sprite* CostSprite[2];

	Size PicSize;

	float SwipeDirection;

	int ButtonNum;
	int ButtonType;
	int CostNum[2];

	String* filename[2];

	bool init();
	void update(float delta);
	void ButtonDisplay();
	void ButtonTap(int Num);
	void ButtonSwipeUP(int Num);
	void ButtonSwipeDOUW(int Num);
	void ButtonPull(int Num);

	CREATE_FUNC(SelectUISwipe);
};

#endif // !__SELECT_UI_SWIPE__
