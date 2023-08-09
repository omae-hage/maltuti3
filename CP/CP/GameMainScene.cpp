#include"GameMainScene.h"
#include "DxLib.h"
#include "SceneManager.h"

/********************

*�}�N����`

*****************/

#define TIMELIMIT           (3600*3) //��������
#define NUMBER_IMAGE_MAX (10)      //�����摜��



/********************

*�^��`

*****************/



/********************

*�ϐ��錾

*****************/

int GameScore;

int GameLevel;

int GameMission;

int GameTime;

int GameCount;  //����������Ȃ��悤�ɂ��邽�߂̃J�E���g

int NumberImage[NUMBER_IMAGE_MAX];  //�����p�摜

/********************

*�v���g�^�C�v�錾

*****************/

/********************

*�Q�[�����C����ʁG����������

*�����G�Ȃ�

*�߂�l�G�G���[���

*****************/

int GameMinScene_Initialize(void)
{
	int ret = 0;
	int i;

	//��ʓǂݍ���
	LoadDivGraph("images/unmber.png", NUMBER_IMAGE_MAX, NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);
	
	//�X�e�[�W���������
	ret = StageInitialize();

	//�G���[�`�F�b�N
	for (i = 0; i < NUMBER_IMAGE_MAX; i++)
	{
		if (NumberImage[i] == D_ERROR)
		{
			ret = ERROR;

			break;
		}
	}
	//�Q�[���v���C�����񂩂ǂ����H
	if (GameCount == 0)
	{
		GameScore = 0;     //�X�R�A�̏�����
		
		GameLevel = 1;    //�Q�[�����x���̏�����

		set_StageMission(3);   //�~�b�V�����̏�����

		GameCount++;          //����̂����Ă�


	}
	else
	{
		GameLevel++;            //�Q�[�����x���̍X�V

		Set_StageMission(3);    //�~�b�V�����𑝂₷
	}
	GameTime = TIMELIMIT;    //���`�~���Ԃ̏�����

	return ret;
}



/********************

*�Q�[�����C����ʁF�X�V����

*�����@�F�@�Ȃ�

*�߂�l�@�F�@�Ȃ�

*****************/

void GameMainScene_Update(void)
{
	switch (Get_StageState())
	{

	case 0:
		SelectBlock();  //�u���b�N��I������
		break;

	case 2:
		MoveBlock();    //�u���b�N���ړ�������
		break;

	case 3:
		CheckBlock();   //�u���b�N�̊m�F

	case 4:
		CheckClear();   //�N���A�`�F�b�N
		break;

	default:
		break;
	}

	//�������Ԃ̍X�V
	GameTime--;

	//�������Ԃ��Ȃ��Ȃ�����A�Q�[���I�[�o�[�ɑJ�ڂ���
	if (GameTime < 0)
	{
		change_scene(E_GAME_OVER);

	}
	//�~�b�V������B��������A�Q�[���N���A�ɑJ�ڂ���
	if (Get_StageClearFlag())
	{
		change_scene(E_GAME_CLEAR);
	}
}

/********************

*���[m�W�����C���֐��@�F�@�`�揈��
 
* �����@�F�@�Ȃ�

* �߂�l�@�F�@�Ȃ�

*****************/

void GameMainScene_Draw(void)
{
	int PosX = 600;
	int tmp_levle = GameLevel;
	int tmp_score = Get_StageSoore();
}

