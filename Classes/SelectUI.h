#ifndef __SELECT_UI__
#define __SELECT_UI__

#include "cocos2d.h"
#include "MultiResolution.h"

USING_NS_CC;

class SelectUI :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	Sprite* Button[6];
	Sprite* AMLButton[3];

	Size PicSize;

	bool init();
	void ButtonDisplay();
	void ButtonTouch();

	CREATE_FUNC(SelectUI);
};

#endif // !__SELECT_UI__
