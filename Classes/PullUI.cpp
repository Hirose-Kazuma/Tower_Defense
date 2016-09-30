#include "PullUI.h"

bool PullUI::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(PullUI::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(PullUI::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	_selectuiswipe = SelectUISwipe::create();
	addChild(_selectuiswipe, -1);

	StartPic();

	//���t���[������
	this->scheduleUpdate();

	return true;
}

void PullUI::StartPic()
{
	//���n
	ButtonUI[4] = Sprite::create("PullUI_bg.png");
	ButtonUI[4]->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	ButtonUI[4]->setPosition(Vec2(designResolutionSize.width * 0.5, designResolutionSize.height * 1.3));
	addChild(ButtonUI[4], 0);

	

	//�e�{�^��
	for (int i = 0; i < sizeof(ButtonUI) / sizeof(ButtonUI[0]) - 1; i++)
	{
		file_name = String::createWithFormat("PullUI_%d.png", i);
		ButtonUI[i] = Sprite::create(file_name->getCString());
		ButtonUI[i]->setPosition(Vec2(designResolutionSize.width * PosNum[i], designResolutionSize.height * 1.15));
		ButtonRect[i] = ButtonUI[i]->getBoundingBox();
		addChild(ButtonUI[i], 1);

		
	}
}

void PullUI::update(float delta)
{
	//�e�̍��W������
}

void PullUI::ScrollLayer(bool flag)
{
	//01�����݂�
	Scrollflag ^= true;

	//�o�Ă���
	if (Scrollflag == true)
	{
		for (int i = 0; i < 5; i++)
		{
			move[i] = MoveTo::create(0.1, Vec2(designResolutionSize.width * PosNum[i], designResolutionSize.height * PosNumY[i]));

			ButtonUI[i]->runAction(move[i]);
		}
	}
	//��������
	else if (Scrollflag == false)
	{
		for (int i = 0; i < 5; i++)
		{
			move[i] = MoveTo::create(0.1, Vec2(designResolutionSize.width * 0.5 + PosNum[i], designResolutionSize.height * 1.3));

			ButtonUI[i]->runAction(move[i]);
		}
	}
}


bool PullUI::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	bool Buttonflag = false;

	//�{�^���^�b�`
	for (int i = 0; i < sizeof(ButtonUI) / sizeof(ButtonUI[0]) - 1; i++)
	{
		if (ButtonUI[i]->getBoundingBox().containsPoint(tp))
		{
			_selectuiswipe->ButtonPull(i);

			Buttonflag = true;

			return true;
		}
	}

	//��g�^�b�`
	if (ButtonUI[4]->getBoundingBox().containsPoint(tp) && Buttonflag == false )
	{
		ScrollLayer(Scrollflag);

		return true;
	}

	
	return false;
}


//�^�b�`�I��
void PullUI::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

}