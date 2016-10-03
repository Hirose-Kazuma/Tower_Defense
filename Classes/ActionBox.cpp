#include"ActionBox.h"

FiniteTimeAction * ActionBox::MagicJinAction()
{
	ScaleBy *action1 = ScaleBy::create(0.3, 10.0);
	DelayTime *action2 = DelayTime::create(2.0);
	ScaleBy *action3 = ScaleBy::create(0.2, 0.1);
	RemoveSelf *action4 = RemoveSelf::create(true);

	Sequence  *Jin_action = Sequence::create(action1, action2, action3, action4, nullptr);
	return Jin_action;
}

FiniteTimeAction * ActionBox::MagicLightAction()
{
	float pic_size = Sprite::create("C_Rod.png")->getContentSize().height*0.25;
	float time = 1.0;

	DelayTime *action_light1 = DelayTime::create(0.5);
	Spawn *action_light2 = Spawn::create(MoveBy::create(time, Point(0, pic_size)), FadeIn::create(time), ScaleBy::create(time, 6), NULL);
	DelayTime *action_light3 = DelayTime::create(0.5);
	ScaleBy *action_light4 = ScaleBy::create(0.2, 0.01);
	RemoveSelf *action_light5 = RemoveSelf::create(true);

	Sequence *action_light = Sequence::create(action_light1, action_light2, action_light3, action_light4, action_light5, nullptr);

	return action_light;
}

FiniteTimeAction * ActionBox::MagicRodAction()
{
	DelayTime *action_Rod1 = DelayTime::create(1.5);
	FadeIn *action_Rod2 = FadeIn::create(1.5);
	Sequence *action_Rod = Sequence::create(action_Rod1, action_Rod2, nullptr);

	return action_Rod;
}

void * ActionBox::ResultWin(Sprite *Win)
{
	
	Win->setTexture("Win.png");
	Win->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Win->setPosition(designResolutionSize.width*0.5, designResolutionSize.height*0.5);
	Win->setScale(0);
	Win->setOpacity(0);

	float time = 0.5;
	float time1 = 1.0;
	ScaleTo *action1 = ScaleTo::create(time1, 1.0);
	FadeIn *action2 = FadeIn::create(time1);
	Spawn *action3 = Spawn::create(action1, action2, nullptr);
	Repeat *action4 = Repeat::create(Sequence::create(action2, action3, nullptr), 5);
	SkewTo *skew1 = SkewTo::create(time, 15, 0);
	SkewTo *skew2 = SkewTo::create(time, 0, 0);
	SkewTo *skew3 = SkewTo::create(time, -15, 0);
	SkewTo *skew4 = SkewTo::create(time, 0, 0);
	ScaleTo *bigScale = ScaleTo::create(time, 1.5);
	ScaleTo *smallScale = ScaleTo::create(time, 1.0);
	//RepeatForever *action5 = RepeatForever::create(Sequence::create(skew1, skew2, skew3, skew4, nullptr));

	Spawn *spawn1 = Spawn::create(skew1, bigScale, nullptr);
	Spawn *spawn2 = Spawn::create(skew2, smallScale, nullptr);
	Spawn *spawn3 = Spawn::create(skew3, bigScale, nullptr);
	Spawn *spawn4 = Spawn::create(skew4, smallScale, nullptr);

	Sequence *action5 = Sequence::create(spawn1, spawn2, spawn3, spawn4, nullptr);
	Repeat *action6 = Repeat::create(action5,-1);

	Sequence *action = Sequence::create(action3, action6, nullptr);

	Win->runAction(action);

	return nullptr;
}

void * ActionBox::ResultLose(Sprite * Lose1, Sprite * Lose2, Sprite * Lose3, Sprite * Lose4)
{
	Size picSize = Sprite::create("Lose_L.png")->getContentSize();

	Lose1->setTexture("Lose_L.png");
	Lose2->setTexture("Lose_o.png");
	Lose3->setTexture("Lose_s.png");
	Lose4->setTexture("Lose_e.png");

	Lose1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Lose2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Lose3->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Lose4->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

	Lose1->setPosition(designResolutionSize.width*0.5 - picSize.width * 1.5, designResolutionSize.height + picSize.height);
	Lose2->setPosition(designResolutionSize.width*0.5 - picSize.width * 0.5, designResolutionSize.height + picSize.height);
	Lose3->setPosition(designResolutionSize.width*0.5 - picSize.width * -0.5, designResolutionSize.height + picSize.height);
	Lose4->setPosition(designResolutionSize.width*0.5 - picSize.width * -1.5, designResolutionSize.height + picSize.height);

	MoveBy *Move1 = MoveBy::create(0.8, Point(0, -designResolutionSize.height*0.5 + picSize.height*0.5));
	MoveBy *Move2 = MoveBy::create(0.8, Point(0, -designResolutionSize.height*0.5 + picSize.height*0.5));
	MoveBy *Move3 = MoveBy::create(0.8, Point(0, -designResolutionSize.height*0.5 + picSize.height*0.5));
	MoveBy *Move4 = MoveBy::create(0.8, Point(0, -designResolutionSize.height*0.5 + picSize.height*0.5));

	DelayTime *Delay2 = DelayTime::create(1.0);
	DelayTime *Delay3 = DelayTime::create(2.0);
	DelayTime *Delay4 = DelayTime::create(3.0);

	RotateBy *Rotate4 = RotateBy::create(0.5, 75.0);

	Sequence *action1 = Sequence::create(Move1, nullptr);
	Sequence *action2 = Sequence::create(Delay2,Move2, nullptr);
	Sequence *action3 = Sequence::create(Delay3,Move3, nullptr);
	Sequence *action4 = Sequence::create(Delay4,Move4,Rotate4, nullptr);

	Lose1->runAction(action1);
	Lose2->runAction(action2);
	Lose3->runAction(action3);
	Lose4->runAction(action4);

	

	return nullptr;
}


