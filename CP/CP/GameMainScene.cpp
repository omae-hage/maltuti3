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
		GameScore = 0;
		
		GameLevel = 1;


	}
}