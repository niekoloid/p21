#ifndef _SXFHATCHDEFINE_H_
#define _SXFHATCHDEFINE_H_

#include <afx.h>

#define TYPE_COUNT 3
#define TYPE_LINE 0
#define TYPE_ARC 1
#define TYPE_ELLIPSE_ARC 2

//確保する領域数
#define ID_DATA 256

//ハッチングの外形、中抜きの情報
typedef struct HatchBoundaryDF{
	short n_id;			//外形、中抜きの要素数
	short sz_id;		//確保した領域数
	int *p_id;			//外形、中抜きのIDのポインタ
} HatchBoundary;

void init_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
int alc_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
int set_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl,int IN_SetID);
void term_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl);
BOOL copy_HatchBoundaryTbl(HatchBoundary *HatchBoundaryTbl,HatchBoundary *wk_HatchBoundaryTbl);

#endif
