#include"Stage.h"
#include"DxLib.h"
#include"InputControl.h"

/*********************

*�}�N����`

**********************/

#define HEIGHT            (12)    //�u���b�N�z�u�T�C�Y�i�����j
#define WIDTH             (12)�@�@//�u���b�N�z�u�T�C�Y�i���j
#define BLOCKSIZE         (48)�@�@//�u���b�N�T�C�Y
#define BLOCK_IMAGE_MAX   (10)�@�@//�u���b�N������

#define ITEM_MAX           (8)    //�A�C�e���ő吔

#define SELECT_CURSOR      (0)
#define NEXT_CURSOR        (1)
#define TMP_CURSOR         (2)

/*********************

*�^��`

**********************/

typedef struct
{
	int flg;
	int x, y;
	int width, height;
	int image;
	int  backup;
}T_Object;

enum
{
	E_NONE,
	E_ONCE,
	E_SECOND
};

/*********************

*�ϐ��錾

**********************/

T_Object Block[HEIGHT][WIDTH];
T_CURSOR Select[3];
int Item[ITEM_MAX];
int 
