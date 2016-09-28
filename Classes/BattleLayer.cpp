#include "BattleLayer.h"

bool BattleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	HouseHP[0] = 3;
	HouseHP[1] = 3;


	//�^�b�`�C�x���g�擾
	auto listener = EventListenerTouchOneByOne::create();
	// �Ώۂ̃C�x���g�����s���ꂽ��A���ʂ̃C�x���g�͔�������Ȃ�����
	listener->setSwallowTouches(true);
	// �^�b�`���ꂽ�u�ԂɌĂ΂�郁�\�b�h��o�^
	listener->onTouchBegan = CC_CALLBACK_2(BattleLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleLayer::onTouchEnded, this);
	// �C�x���g�̎��s�̗D�揇�ʂ��m�[�h�̏d�Ȃ菇�Ɉˑ�������
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	StartSprite();

	//EnemyDisplay();

	//���t���[������
	this->scheduleUpdate();

	return true;
}

void BattleLayer::StartSprite()
{
	House[0] = Sprite::create("house.png");
	House[0]->setPosition(Vec2(designResolutionSize.width * 0.1, designResolutionSize.height * 0.6));
	E_HouseRect = House[0]->getBoundingBox();
	addChild(House[0]);

	
	House[1] = Sprite::create("house.png");
	House[1]->setPosition(Vec2(designResolutionSize.width * 0.9, designResolutionSize.height * 0.6));
	P_HouseRect = House[1]->getBoundingBox();
	addChild(House[1]);
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
					CharBattle(i, n);

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

	//�G���_�̂����蔻��
	for (int i = 0; i < sizeof(_playerlayer) / sizeof(_playerlayer[0]); i++)
	{
		if (_playerlayer[i] == nullptr)break;

		PlayerRect = _playerlayer[i]->getBoundingBox();

		if (PlayerRect.intersectsRect(E_HouseRect))
		{
			_playerlayer[i]->stopAllActions();
		}
		else
		{

		}
	}

	//�������_�̂����蔻��
	for (int i = 0; i < sizeof(_enemylayer) / sizeof(_enemylayer[0]); i++)
	{
		if (_enemylayer[i] == nullptr)break;

		EnemyRect = _enemylayer[i]->getBoundingBox();

		if (EnemyRect.intersectsRect(P_HouseRect))
		{
			_enemylayer[i]->stopAllActions();
		}
		else
		{

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

void BattleLayer::CharBattle(int E_Num, int P_Num)
{
	E_HP[E_Num] -= P_AT[P_Num];
}

void BattleLayer::BaseBattle(int BaseNum, int Num)
{
	if (BaseNum == 0)
	{
		HouseHP[BaseNum] -= P_AT[Num];
	}
	else if(BaseNum == 1)
	{
		HouseHP[BaseNum] -= E_AT[Num];
	}
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
			TouchSpriteNum = i;
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

	PlayerSwipe(Direction, TouchSpriteNum);
}


//Player�X���C�v����
void BattleLayer::PlayerSwipe(int DirectionS, int Num)
{
	if (DirectionS == 0)
	{
		_playerlayer[Num]->ChangeDirection();
	}
	else if (DirectionS == 1)
	{
		_playerlayer[Num]->ChangeDirection();
	}
	else if (DirectionS == 2)
	{
		if (_playerlayer[Num]->getPosition().y < designResolutionSize.height * 0.6)
		{
			auto move = MoveTo::create(1, Point(_playerlayer[Num]->getPosition().x,
				_playerlayer[Num]->getPosition().y + designResolutionSize.height * 0.1));
			_playerlayer[Num]->runAction(move);
		}
	}
	else if (DirectionS == 3)
	{
		if (_playerlayer[Num]->getPosition().y > designResolutionSize.height * 0.4)
		{
			auto move = MoveTo::create(1, Point(_playerlayer[Num]->getPosition().x,
				_playerlayer[Num]->getPosition().y - designResolutionSize.height * 0.1));
			_playerlayer[Num]->runAction(move);
		}
	}
}