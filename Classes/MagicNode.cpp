#include "MagicNode.h"

bool MagicNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	Node *magic = Node::create();
	magic->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	magic->setScaleY(0.5);
	addChild(magic);


	Magic_Inside = Sprite::create("magic_inside.png");
	Magic_Inside->setScale(0.5);
	Magic_Inside->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	magic->addChild(Magic_Inside);
	Magic_Outside = Sprite::create("magic_outside.png");
	Magic_Outside->setScale(0.5);
	Magic_Outside->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	magic->addChild(Magic_Outside);

	Magic_Inside->runAction(RepeatForever::create(RotateBy::create(1.0, 160)));
	Magic_Outside->runAction(RepeatForever::create(RotateBy::create(1.0, -160)));

	scheduleUpdate();
	return true;
}
void MagicNode::update(float delta)
{

}