#include "SelectUIRevolver.h"

bool SelectUIRevolver::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(SelectUIRevolver::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectUIRevolver::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	Radius = 500.0f;

	ButtonDisplay();

	return true;
}


//�{�^���\��
void SelectUIRevolver::ButtonDisplay()
{
	float theta = 360.0f / sizeof(Button);

	for (int i = 0; i < sizeof(Button) / sizeof(Button[0]); i++)
	{
		Button[i] = Sprite::create("TestButton.png");
		Button[i]->setScaleX(0.5);

		PicSize = Button[i]->getContentSize();

		// 270 �x�̈ʒu�����ʂɂ���悤��
		float angle = theta * i + 270.0f;
		float radians = angle * PI / 180.0f;
		float x = Radius * cos(radians);
		float y = Radius * sin(radians);
		Button[i]->setPosition(Vec2(x, y));

		addChild(Button[i]);
	}


	//float theta = 360.0f / sizeof(Button);
	//for (int n = 0; n < sizeof(Button); n++)
	//{
	//	// 270 �x�̈ʒu�����ʂɂ���悤��  
	//	float angle = theta * n + 270.0f;
	//	float radians = angle * PI / 180.0f;
	//	float x = Radius * cos(radians);
	//	float y = Radius * sin(radians);
	//	Button[n]->setPosition(Vec2(x, y));
	//}
}


//�^�b�`�J�n
bool SelectUIRevolver::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	SwipeDirection = tp.y;

	return true;
}


//�^�b�`�I��
void SelectUIRevolver::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	//�X���C�v����
	//+������@�@-������
	SwipeDirection -= tp.y;

}