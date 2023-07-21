#include "GameClearScene.h"
#include "DxLib.h"
#include "SceneManager.h"

/*********************

*�}�N����`

**********************/


/*********************

*�^��`

**********************/


/*********************

*�ϐ��錾

**********************/

int GameClearImage;
int GameClearSE;
int GameClearFlag;

/*********************

*�v���g�^�C�v�錾

**********************/

/*********************

*�Q�[���N���A��ʁF����������
* ���L�X�@�F�@�Ȃ�
* �߂�l�@�F�@�G���[���

**********************/

int GameClearScene_Initialize(void)
{
	int ret = 0;

	//�摜�̓ǂݍ���
	GameClearImage = LoadGraph("images/gameclear.png");
	
	//�����̓ǂݍ���
	GameClearSE = LoadSoundMem("sounds/gameclear_se.mp3");
	
	GameClearFlag = 0;

	//�G���[�`�F�b�N
	if (GameClearImage == -1)
	{
		ret = -1;
	}

	if (GameClearSE == -1)
	{
		ret = -1;
	}

	return ret;	

}

/*********************

*�Q�[���N���A��ʁF�X�V����
*�����@�F�@�Ȃ�
* �߂�l�@�F�@�Ȃ�

**********************/

void GameClearScene_Update(void)
{
	//�Q�[���N���A���ʉ��Đ��`���b�N
	if (CheckSoundMem(GameClearSE) == 0)
	{
		if (GameClearFlag == TRUE)
		{
			Change_Scene(E_GAME_MAIN);
		}
		else
		{
			PlaySoundMem(GameClearSE, DX_PLAYTYPE_BACK);
			GameClearFlag = TRUE;
		}
	}
	
}
/*********************

*�Q�[���N���A��ʁ@�F�@�`�揈��

*�����@�F�@�Ȃ�

*�߂�l�@�F�@�Ȃ�

**********************/

void GameClearScene_Draw(void)
{
	DrawGraph(0, 0, GameClearImage, FALSE);
}
