#ifndef _SXFHATCHDEFINE_H_
#define _SXFHATCHDEFINE_H_

#include <afx.h>

#define TYPE_COUNT 3
#define TYPE_LINE 0
#define TYPE_ARC 1
#define TYPE_ELLIPSE_ARC 2

//�m�ۂ���̈搔
#define ID_DATA 256

//�n�b�`���O�̊O�`�A�������̏��
typedef struct HatchBoundaryDF{
	short n_id;			//�O�`�A�������̗v�f��
	short sz_id;		//�m�ۂ����̈搔
	int *p_id;			//�O�`�A��������ID�̃|�C���^
} HatchBoundary;

void init_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
int alc_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
int set_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl,int IN_SetID);
void term_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
BOOL copy_HatchBoundaryTbl(HatchBoundary *HatchBoundaryTbl,HatchBoundary *wk_HatchBoundaryTbl);

#endif
