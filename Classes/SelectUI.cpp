#include "SelectUI.h"

bool SelectUI::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(SelectUI::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUI::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	ButtonDisplay();

	return true;
}

//�{�^���\��
void SelectUI::ButtonDisplay()
{
	//�L�����{�^��
	for (int i = 0; i < sizeof(Button)/sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("TestButton.png");
		Button[i]->setScale(0.5);

		PicSize = Button[i]->getContentSize();

		Button[i]->setPosition(Vec2(designResolutionSize.width * 0.1 + (i * PicSize.width) * 0.45 ,
								    designResolutionSize.height * 0.1));
		this->addChild(Button[i]);
	}

	//�㒆���{�^��
	for (int n = 0; n < sizeof(AMLButton) / sizeof(AMLButton[0]); n++)
	{
		AMLButton[n] = Sprite::create("TestButton.png");
		AMLButton[n]->setScale(0.3);

		PicSize = AMLButton[n]->getContentSize();

		AMLButton[n]->setPosition(Vec2(designResolutionSize.width * 0.8 + (n * PicSize.width) * 0.3,
			designResolutionSize.height * 0.1));
		this->addChild(AMLButton[n]);

	}
}


//�^�b�`�J�n
bool SelectUI::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();


	return true;
}


//�^�b�`�I��
void SelectUI::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	//�L�����{�^���^�b�`
	if (Button[0]->getBoundingBox().containsPoint(tp))
	{
		log("0");
	}
	else if(Button[1]->getBoundingBox().containsPoint(tp))
	{
		log("1");
	}
	else if (Button[2]->getBoundingBox().containsPoint(tp))
	{
		log("2");
	}
	else if (Button[3]->getBoundingBox().containsPoint(tp))
	{
		log("3");
	}
	else if (Button[4]->getBoundingBox().containsPoint(tp))
	{
		log("4");
	}
	else if (Button[5]->getBoundingBox().containsPoint(tp))
	{
		log("5");
	}

	//�㒆���{�^���^�b�`
	if (AMLButton[0]->getBoundingBox().containsPoint(tp))
	{
		log("UP");
	}
	else if(AMLButton[1]->getBoundingBox().containsPoint(tp))
	{
		log("MIDDLE");
	}
	else if (AMLButton[2]->getBoundingBox().containsPoint(tp))
	{
		log("LOWER");
	}
}