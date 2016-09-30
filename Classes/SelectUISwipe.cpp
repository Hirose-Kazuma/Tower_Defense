#include "SelectUISwipe.h"

bool SelectUISwipe::init()
{
	if (!Layer::init())
	{
		return false;
	}

	ButtonType = 0;


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
	addChild(_battlelayer, -1);

	ButtonDisplay();

	return true;
}


//�{�^���\��
void SelectUISwipe::ButtonDisplay()
{
	//�L�����{�^��
	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		if (ButtonType == 0)Button[i] = Sprite::create("B_Sword.png");
		else if(ButtonType == 1)Button[i] = Sprite::create("B_Rod.png");
		else if (ButtonType == 2)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 3)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 4)Button[i] = Sprite::create("B_Sword.png");
		else if (ButtonType == 5)Button[i] = Sprite::create("B_Sword.png");

		ButtonType++;

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

	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		if (Button[i]->getBoundingBox().containsPoint(tp))
		{
			ButtonNum = i;

			return true;
		}
	}

	return false;
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
	if (SwipeDirection >= -50 && 50 >= SwipeDirection)
	{
		ButtonTap(ButtonNum);
	}
	else if (SwipeDirection <= 0)
	{
		ButtonSwipeDOUW(ButtonNum);
	}
	else
	{
		ButtonSwipeUP(ButtonNum);
	}
}


//�{�^���^�b�v����
void SelectUISwipe::ButtonTap(int Num)
{
	_battlelayer->PlayerDisplay(Num, 0.1);
}


//��X���C�v����
void SelectUISwipe::ButtonSwipeUP(int Num)
{
	_battlelayer->PlayerDisplay(Num, 0);
}


//���X���C�v����
void SelectUISwipe::ButtonSwipeDOUW(int Num)
{
	_battlelayer->PlayerDisplay(Num, 0.2);
}

//pull�{�^������
void SelectUISwipe::ButtonPull(int Num)
{

}