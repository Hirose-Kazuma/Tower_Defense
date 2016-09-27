#include "BattleLayer.h"

bool BattleLayer::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(BattleLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleLayer::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	EnemyDisplay();

	//���t���[������
	this->scheduleUpdate();

	return true;
}

void BattleLayer::update(float delta)
{
	SpawnTimer += delta;

	if (SpawnTimer >= 3.0f)
	{
		EnemyDisplay();

		SpawnTimer = 0;
	}

	//�G�Ƃ̂����蔻��
	for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
	{
		if (_enemylayer[i] == nullptr)break;
		for (int n = 0; n < sizeof(_playerlayer) / sizeof(_playerlayer[0]); n++)
		{
			if (_playerlayer[n] == nullptr)break;

			EnemyRect = _enemylayer[i]->getBoundingBox();
			PlayerRect = _playerlayer[n]->getBoundingBox();

			//�U��
			if (EnemyRect.intersectsRect(PlayerRect))
			{
				_enemylayer[i]->stopAllActions();
				_playerlayer[n]->stopAllActions();

				AtackTime += delta;

				//�U��
				if (Atackflag == false)
				{
					Battle(i, n);

					Atackflag = true;

					//�v���P ���S����
					if (E_HP[i] <= 0)
					{
						_enemylayer[i]->setVisible(false);
						_enemylayer[i]->setPosition(0, 0);

						E_Desflag[i] = true;
					}
				}
				else if (AtackTime >= 3.0)
				{
					AtackTime = 0;
					Atackflag = false;
				}
			}
			//�i�R
			else
			{

			}
		}
	}

	//�v���C���[�ǂ����̂����蔻��
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;
		for (int n = 0; n < (sizeof(_playerlayer) / sizeof(_playerlayer[0])) - 1; n++)
		{
			if (_playerlayer[n] == nullptr || i == n)break;

			PlayerRect = _playerlayer[i]->getBoundingBox();
			SubRect = _playerlayer[n]->getBoundingBox();

			if (PlayerRect.intersectsRect(SubRect))
			{
				_playerlayer[i]->stopAllActions();
			}
			else
			{

			}
		}
	}

	//�G�ǂ����̂����蔻��
	for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
	{
		if (_enemylayer[i] == nullptr)break;
		for (int n = 0; n < (sizeof(_enemylayer) / sizeof(_enemylayer[0])) - 1; n++)
		{
			if (_enemylayer[n] == nullptr || i == n)break;

			EnemyRect = _enemylayer[i]->getBoundingBox();
			SubRect = _enemylayer[n]->getBoundingBox();

			if (EnemyRect.intersectsRect(SubRect))
			{
				_enemylayer[i]->stopAllActions();
			}
			else
			{

			}
		}
	}
}

void BattleLayer::EnemyDisplay()
{
	_enemylayer[EnemyCount] = EnemyLayer::create();
	_enemylayer[EnemyCount]->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * 0.5));

	/*if (CharNum == 0)_enemylayer[EnemyCount]->SetStatus0();
	else if (CharNum == 1)_enemylayer[EnemyCount]->SetStatus1();
	else if (CharNum == 2)_enemylayer[EnemyCount]->SetStatus2();
	else if (CharNum == 3)_enemylayer[EnemyCount]->SetStatus3();
	else if (CharNum == 4)_enemylayer[EnemyCount]->SetStatus4();
	else if (CharNum == 5)_enemylayer[EnemyCount]->SetStatus5();*/

	addChild(_enemylayer[EnemyCount]);
	
	E_PATTERN[EnemyCount] = _enemylayer[EnemyCount]->AtackPattern;
	E_AT[EnemyCount] = _enemylayer[EnemyCount]->AT;
	E_HP[EnemyCount] = _enemylayer[EnemyCount]->HP;
	E_COST[EnemyCount] = _enemylayer[EnemyCount]->COST;

	EnemyCount++;
}

void BattleLayer::PlayerDisplay(int CharNum, float Pos)
{
	//�L�����U�蕪���̓N���X�̊֐��Őݒ�

	_playerlayer[PlayerCount] = PlayerLayer::create();
	_playerlayer[PlayerCount]->setPosition(Vec2(designResolutionSize.width * 0.7, designResolutionSize.height * (0.4 + Pos)));

	if (CharNum == 0)_playerlayer[PlayerCount]->SetStatus0();
	else if(CharNum == 1)_playerlayer[PlayerCount]->SetStatus1();
	else if (CharNum == 2)_playerlayer[PlayerCount]->SetStatus2();
	else if (CharNum == 3)_playerlayer[PlayerCount]->SetStatus3();
	else if (CharNum == 4)_playerlayer[PlayerCount]->SetStatus4();
	else if (CharNum == 5)_playerlayer[PlayerCount]->SetStatus5();

	addChild(_playerlayer[PlayerCount]);

	P_PATTERN[PlayerCount] = _playerlayer[PlayerCount]->AtackPattern;
	P_AT[PlayerCount] = _playerlayer[PlayerCount]->AT;
	P_HP[PlayerCount] = _playerlayer[PlayerCount]->HP;
	P_COST[PlayerCount] = _playerlayer[PlayerCount]->COST;

	PlayerCount++;

}

void BattleLayer::Battle(int E_Num, int P_Num)
{
	E_HP[E_Num] -= P_AT[P_Num];
}

//�^�b�`�J�n
bool BattleLayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	SwipeDirectionX = tp.x;
	SwipeDirectionY = tp.y;

	//���̃��C���[���̃I�u�W�F�N�g���^�b�`����Ă��邩
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;

		if (_playerlayer[i]->getBoundingBox().containsPoint(tp))
		{
			_playerlayer[i]->stopAllActions();
			return true;
		}
	}

	return false;
}


//�^�b�`�I��
void BattleLayer::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//�^�b�`�|�C���g
	Vec2 tp = pTouch->getLocation();

	//�X���C�v����
	//+������	-�E����
	SwipeDirectionX -= tp.x;
	//+������@�@-������
	SwipeDirectionY -= tp.y;

	//�E
	if (SwipeDirectionX <= 0 && SwipeDirectionY >= -100 && SwipeDirectionY <= 100)
	{
		Direction = 0;
	}
	//��
	else if (SwipeDirectionX >= 0 && SwipeDirectionY >= -100 && SwipeDirectionY <= 100)
	{
		Direction = 1;
	}
	//��
	else if (SwipeDirectionY <= 0 && SwipeDirectionX >= -100 && SwipeDirectionX <= 100)
	{
		Direction = 2;
	}
	//��
	else if (SwipeDirectionY >= 0 && SwipeDirectionX >= -100 && SwipeDirectionX <= 100)
	{
		Direction = 3;
	}

	//�ǂ�Sprite���^�b�`���ꂽ��
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;

		if (_playerlayer[i]->getBoundingBox().containsPoint(tp))
		{
			PlayerSwipe(Direction, i);
		}
	}

	


}


//Player�X���C�v����
void BattleLayer::PlayerSwipe(int DirectionS, int Num)
{
	log("DirectionS %d", DirectionS);
	if (DirectionS == 0)
	{
		if (_playerlayer[Num]->getPosition().y < designResolutionSize.height * 0.6)
		{
			auto move = MoveTo::create(1, Point(_playerlayer[Num]->getPosition().x,
				_playerlayer[Num]->getPosition().y + designResolutionSize.height * 0.1));
			_playerlayer[Num]->runAction(move);
		}
	}
	else if (DirectionS == 1)
	{

	}
	else if (DirectionS == 2)
	{

	}
	else if (DirectionS == 3)
	{

	}
}