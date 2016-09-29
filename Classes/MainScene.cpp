#include "MainScene.h"
#include "ActionBox.h"

Scene* MainScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MainScene::create();

	scene->addChild(layer);

	return scene;
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//MoveDirection = -1;	//左方向
	//EnemyHP = 3;
	//PlayerPOW = 1;

	//Touch_Flg = false;

	//StartPic();
	//this->schedule(schedule_selector(MainScene::PlayerAction), 2);

	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = [this](Touch *touch, Event *event)
	//{
	//	if (Touch_Flg == false)
	//	{
	//		Touch_Flg = true;
	//		Magic_Jin();
	//	}
	//	else if (Touch_Flg == true)
	//	{
	//		Touch_Flg = false;
	//		//Sword_Create();
	//	}

	//	return true;
	//};
	//listener->onTouchMoved = [this](Touch *touch, Event *event)
	//{
	//	
	//	return true;
	//};
	//listener->onTouchEnded = [this](Touch *touch, Event *event)
	//{
	//	
	//	return true;
	//};
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	_backlayer = BackLayer::create();
	addChild(_backlayer, 0);

	_selectuiswipe = SelectUISwipe::create();
	addChild(_selectuiswipe, 2);

	return true;
}

//画像表示
void MainScene::StartPic()
{
	//背景色
	auto bg_color = LayerColor::create(Color4B::GREEN, designResolutionSize.width, designResolutionSize.height);
	this->addChild(bg_color);

	//Player
	PlayerPic = Sprite::create("Player.png");
	PlayerPic->setPosition(Vec2(designResolutionSize.width * 0.6, designResolutionSize.height * 0.5));
	addChild(PlayerPic, 0);

	//Enemy
	EnemyPic = Sprite::create("Enemy.png");
	EnemyPic->setPosition(Vec2(designResolutionSize.width * 0.5, designResolutionSize.height * 0.5));
	addChild(EnemyPic, 0);

	EnemyPos = EnemyPic->boundingBox();
	//log
}

//画像移動
void MainScene::MoveSprite()
{

}

//Player行動
void MainScene::PlayerAction(float delta)
{
	PlayerPos = PlayerPic->boundingBox();
	//EnemyPos = EnemyPic->boundingBox();


	if (PlayerPos.intersectsRect(EnemyPos))
	{
		EnemyHP -= PlayerPOW;

		if (EnemyHP <= 0) PicDes();
	}
	else 
	{
		auto move1 = MoveBy::create(1, Vec2(MoveDirection * 64, 0));	//現在位置から移動
		//auto roop = RepeatForever::create(move1);

		PlayerPic->runAction(move1);
	}
}

void MainScene::PicDes()
{
	EnemyPic->removeFromParentAndCleanup(true);

	EnemyPos = Rect(0, 0, 0, 0);
}

void MainScene::Magic_Jin()
{
	//魔法陣表示
	_magicNode = MagicNode::create();
	_magicNode->setPosition(Vec2(designResolutionSize.width * 0.3, designResolutionSize.height * 0.5));
	_magicNode->setScale(0.1);
	addChild(_magicNode);

	//魔法陣アクション
	_magicNode->runAction(ActionBox::MagicJinAction());

	//杖表示
	Sprite *Test_Rod = Sprite::create("C_Rod.png");
	Test_Rod->setScale(0.5);
	Test_Rod->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Test_Rod->setPosition(_magicNode->getPosition());
	Test_Rod->setOpacity(0);
	addChild(Test_Rod);


	//杖アクション
	Test_Rod->runAction(ActionBox::MagicRodAction());


	//
	Sprite *MagicLight = Sprite::create("DrawNode.png");
	MagicLight->setColor(Color3B::RED);
	MagicLight->setPosition(_magicNode->getPosition());
	MagicLight->setScale(0.5);
	MagicLight->setOpacity(0);
	addChild(MagicLight);

	MagicLight->runAction(ActionBox::MagicLightAction());

}
