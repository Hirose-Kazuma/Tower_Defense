#include "SelectUISwipe.h"

bool SelectUISwipe::init()
{
	if (!Layer::init())
	{
		return false;
	}


	//�^�b�`�C�x���g�擾
	auto listener = EventListenerTouchOneByOne::create();
	// �Ώۂ̃C�x���g�����s���ꂽ��A���ʂ̃C�x���g�͔�������Ȃ�����
	listener->setSwallowTouches(true);
	// �^�b�`���ꂽ�u�ԂɌĂ΂�郁�\�b�h��o�^
	listener->onTouchBegan = CC_CALLBACK_2(SelectUISwipe::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUISwipe::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	_battlelayer = BattleLayer::create();
	addChild(_battlelayer, 0);

	ButtonDisplay();

	return true;
}


//�{�^���\��
void SelectUISwipe::ButtonDisplay()
{
	//�L�����{�^��
	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("B_Sword.png");
		Button[i]->setScaleY(0.7);

		PicSize = Button[i]->getContentSize();

		Button[i]->setPosition(Vec2(designResolutionSize.width * 0.1 + (i * PicSize.width),
			designResolutionSize.height * 0.18));
		this->addChild(Button[i], 1);
	}
}

//�^�b�`�J�n
bool SelectUISwipe::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	SwipeDirection = tp.y;

	return true;
}


//�^�b�`�I��
void SelectUISwipe::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	//�X���C�v����
	//+������@�@-������
	SwipeDirection -= tp.y;


	//�L�����{�^���^�b�`
	if		(Button[0]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(0);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(0);
		}
		else
		{
			ButtonSwipeUP(0);
		}
	}
	else if (Button[1]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(1);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(1);
		}
		else
		{
			ButtonSwipeUP(1);
		}
	}
	else if (Button[2]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(2);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(2);
		}
		else
		{
			ButtonSwipeUP(2);
		}
	}
	else if (Button[3]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(3);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(3);
		}
		else
		{
			ButtonSwipeUP(3);
		}
	}
	else if (Button[4]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(4);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(4);
		}
		else
		{
			ButtonSwipeUP(4);
		}
	}
	else if (Button[5]->getBoundingBox().containsPoint(tp))
	{
		if (SwipeDirection >= -50 && 50 >= SwipeDirection)
		{
			ButtonTap(5);
		}
		else if (SwipeDirection <= 0)
		{
			ButtonSwipeDOUW(5);
		}
		else
		{
			ButtonSwipeUP(5);
		}
	}
}


//�{�^���^�b�v����
void SelectUISwipe::ButtonTap(int Num)
{
	log("Number%d--tap", Num);

	_battlelayer->PlayerDisplay(Num, 0.1);
}


//��X���C�v����
void SelectUISwipe::ButtonSwipeUP(int Num)
{
	log("Number%d--down", Num);

	_battlelayer->PlayerDisplay(Num, 0);
}


//���X���C�v����
void SelectUISwipe::ButtonSwipeDOUW(int Num)
{
	log("Number%d--up", Num);

	_battlelayer->PlayerDisplay(Num, 0.2);
}
