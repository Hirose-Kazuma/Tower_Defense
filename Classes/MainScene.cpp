#include "MainScene.h"

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

	MoveDirection = -1;	//左方向
	EnemyHP = 3;
	PlayerPOW = 1;

	StartPic();
	this->schedule(schedule_selector(MainScene::PlayerAction), 2);

	return true;
}

//画像表示
void MainScene::StartPic()
{
	//背景色
	auto bg_color = LayerColor::create(Color4B::WHITE, designResolutionSize.width, designResolutionSize.height);
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
		log("Atack!!");

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