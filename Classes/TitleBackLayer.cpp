#include"TitleBackLayer.h"
#include"IwasiSprite.h"
#include"ZakoSprite.h"
#include"CrowSprite.h"

USING_NS_CC;

bool TitleBackLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CountFlg = 0;
	TeamNumber = 0;

	UP_Pos = Vec2(designResolutionSize.width*1.1, designResolutionSize.height*0.8);
	Middle_Pos = Vec2(designResolutionSize.width*1.1, designResolutionSize.height*0.65);
	Down_Pos = Vec2(designResolutionSize.width*1.1, designResolutionSize.height*0.5);

	BackGround = Sprite::create("Back.png");
	BackGround->setPosition(designResolutionSize*0.5);
	addChild(BackGround);
		
	//IwasiSprite *Iwasi = IwasiSprite::create();
	//Iwasi->setPosition(designResolutionSize*0.5);
	//Iwasi->setPosition(UP_Pos);
	////Iwasi->runAction(Sequence::create(MoveBy::create(10, Point((-(Iwasi->getContentSize().width)), Iwasi->getPositionY())),nullptr));
	//Iwasi->runAction(MoveTo::create(10, Vec2((-(Iwasi->getContentSize().width)*4), Iwasi->getPositionY())));
	//addChild(Iwasi);

	scheduleUpdate();
	return true;
}

void TitleBackLayer::update(float delta)
{
	CountFlg++;

	srand((unsigned int)time(NULL));

	if (CountFlg == 60)
	{
		switch ((int)rand() % 5)
		{
		case 0:
			IwasiCreate();
			break;
		case 1:
			ZakoCreate();
			break;
		case 2:
			CrowCreate();
			break;
		default:
			break;
		}

		CountFlg = 0;
	}
}

void TitleBackLayer::IwasiCreate()
{	
	Vec2 Pos;
	int Depth;

	switch ((int)rand() % 3)
	{
	case 0:
		Pos = UP_Pos;
		Depth = 1;
		break;
	case 1:
		Pos = Middle_Pos;
		Depth = 2;
		break;
	case 2:
		Pos = Down_Pos;
		Depth = 3;
		break;
	default:
		break;
	}

	auto iwasi = IwasiSprite::create();	
	iwasi->setPosition(Pos);
	addChild(iwasi, Depth);

	float endPos = Sprite::create("iwasi_1.png")->getContentSize().width;
	auto action1 = MoveTo::create(10, Vec2(-endPos, iwasi->getPositionY()));
	auto action2 = RemoveSelf::create(true);
	//auto action3 = CCCallFunc::create([=]() {ArrayDelete(TeamNumber); });

	auto action = Sequence::create(action1,  action2, nullptr);

	iwasi->runAction(action);

	//_enemyTeam.pushBack(iwasi);
	//TeamNumber++;
}

void TitleBackLayer::ZakoCreate()
{
	Vec2 Pos;
	int Depth;

	switch ((int)rand() % 3)
	{
	case 0:
		Pos = UP_Pos;
		Depth = 1;
		break;
	case 1:
		Pos = Middle_Pos;
		Depth = 2;
		break;
	case 2:
		Pos = Down_Pos;
		Depth = 3;
		break;
	default:
		break;
	}

	auto zako = ZakoSprite::create();
	zako->setPosition(Pos);
	addChild(zako, Depth);

	float endPos = Sprite::create("iwasi_1.png")->getContentSize().width;
	auto action1 = MoveTo::create(10, Vec2(-endPos, zako->getPositionY()));
	auto action2 = RemoveSelf::create(true);
	//auto action3 = CCCallFunc::create([=]() {ArrayDelete(TeamNumber); });

	auto action = Sequence::create(action1, action2, nullptr);

	zako->runAction(action);
}

void TitleBackLayer::CrowCreate()
{
	Vec2 Pos;
	int Depth;

	switch ((int)rand() % 3)
	{
	case 0:
		Pos = UP_Pos;
		Depth = 1;
		break;
	case 1:
		Pos = Middle_Pos;
		Depth = 2;
		break;
	case 2:
		Pos = Down_Pos;
		Depth = 3;
		break;
	default:
		break;
	}

	auto Crow = CrowSprite::create();
	Crow->setPosition(Pos);
	addChild(Crow, Depth);

	float endPos = Sprite::create("iwasi_1.png")->getContentSize().width;
	auto action1 = MoveTo::create(10, Vec2(-endPos, Crow->getPositionY()));
	auto action2 = RemoveSelf::create(true);
	//auto action3 = CCCallFunc::create([=]() {ArrayDelete(TeamNumber); });

	auto action = Sequence::create(action1, action2, nullptr);

	Crow->runAction(action);
}

void TitleBackLayer::ArrayDelete(int number)
{
}


