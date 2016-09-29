#ifndef __SELECT_UI_SWIPE__
#define __SELECT_UI_SWIPE__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "BattleLayer.h"

USING_NS_CC;

class SelectUISwipe :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	BattleLayer* _battlelayer;

	Sprite* Button[6];

	Size PicSize;

	float SwipeDirection;

	int ButtonNum;
	int ButtonType;

	bool init();
	void ButtonDisplay();
	void ButtonTap(int Num);
	void ButtonSwipeUP(int Num);
	void ButtonSwipeDOUW(int Num);

	CREATE_FUNC(SelectUISwipe);
};

#endif // !__SELECT_UI_SWIPE__
