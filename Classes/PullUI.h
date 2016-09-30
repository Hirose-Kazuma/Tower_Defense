#ifndef __PULL_UI__
#define __PULL_UI__

#include "cocos2d.h"
#include "MultiResolution.h"
#include "SelectUISwipe.h"

USING_NS_CC;

class PullUI :public Layer
{
private:
	// タッチイベント処理
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

public:
	SelectUISwipe* _selectuiswipe;

	Sprite* DownUI;
	Sprite* ButtonUI[5];

	Rect ButtonRect[5];
	Rect SubRect;
	Vec2 PullPos;

	String* file_name;

	MoveTo* move[5];

	float PosNum[5] = { 0.2f,0.4f,0.6f,0.8f,0.5f };
	float PosNumY[5] = { 0.85f,0.85f,0.85f,0.85f,1.0f };
	int SelectButton;
	bool Scrollflag;
	int n;

	bool init();
	void StartPic();
	void update(float delta);
	void ScrollLayer(bool flag);

	CREATE_FUNC(PullUI);
};

#endif // !__PULL_UI__
