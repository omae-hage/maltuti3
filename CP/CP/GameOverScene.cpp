#include"GameOverScene.h"
#include "DxLib.h"
#include"SceneManager.h"

/*********************

*�ϐ��錾

**********************/

int GameOverImage;
int GameOverSE;
int GameOverFlag;

/*********************

*�v���g�^�C�v�錾

**********************/

/*********************

*�v���g�^�C�v�錾

* �����G�Ȃ�

*�߂�l�G�G���[���

**********************/

int GameOverScene_Initialize(void)
{
	int ret = 0;

	//�摜�ǂݍ���
	GameOverImage = LoadGraph("images/gameover.png");

	//�����ǂݎ��
	GameOverSE = LoadSoundMem("sounds/gameover_se.mp3");

	GameOverFlag = FALSE;

	//�G���[�`�F�b�N
	if (GameOverImage == -1)
	{
		ret = -1;
	}

	return ret;
}

/*********************

*�Q�[���I�[�o�[��ʁF�X�V����

*�����F�Ȃ�

*�߂�l�F�Ȃ� 

**********************/

void GameOverScene_Update(void)
{
	//�Q�[���I�[�o�[�����Đ��`�F�b�N
	if (CheckSoundMem(GameOverSE) == 0)
	{
		if (GameOverFlag == TRUE)
		{
			Change_Scene(E_GAME_OVER);
		}
		else
		{
			PlaySoundMem(GameOverSE, DX_PLAYTYPE_BACK);
			GameOverFlag = TRUE;
		}
	}
}

/*********************

*�Q�[���[�o�[��ʁF�`�揈��

*�����F�Ȃ�
 
*�߂�l�F�Ȃ� 

**********************/

void GameOverScene_Draw(void)
{
	//�Q�[���I�[�o�[�摜�\��
	DrawGraph(0, 0, GameOverImage, FALSE);
}