#ifndef __SELECT_UI_REVOLVER__
#define __SELECT_UI_REVOLVER__

#include "cocos2d.h"
#include "MultiResolution.h"

#define PI 3.1415926535

USING_NS_CC;

class SelectUIRevolver :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	Sprite* Button[6];

	Size PicSize;

	float SwipeDirection;
	float Radius;	//ボタン配置半径

	bool init();
	void ButtonDisplay();

	CREATE_FUNC(SelectUIRevolver);
};

#endif // !__SELECT_UI_REVOLVER__
