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


