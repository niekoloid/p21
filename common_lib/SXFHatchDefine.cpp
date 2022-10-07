#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SXFHatchDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void init_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl){
	for(int i = 0; i < TYPE_COUNT;i++){
		HatchBoundaryTbl[i].n_id = 0;
		HatchBoundaryTbl[i].sz_id = 0;
		HatchBoundaryTbl[i].p_id = NULL;
	}
}

int alc_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl){
	int *int_wk;

	if( HatchBoundaryTbl->p_id == NULL ) {
		HatchBoundaryTbl->p_id = (int*)malloc(sizeof (int) * ID_DATA);
		if( HatchBoundaryTbl->p_id == NULL )
			return -1;

		memset(HatchBoundaryTbl->p_id, 0x00, sizeof(int) * ID_DATA);
		HatchBoundaryTbl->sz_id = ID_DATA;

	}
	else {
		if(HatchBoundaryTbl->sz_id < HatchBoundaryTbl->n_id){
			int_wk = (int*)realloc(HatchBoundaryTbl->p_id, 
					sizeof(int) * (HatchBoundaryTbl->sz_id + ID_DATA));
			if( int_wk == NULL )
				return -1;
			HatchBoundaryTbl->p_id = int_wk;
			int_wk = HatchBoundaryTbl->p_id + HatchBoundaryTbl->sz_id;
			memset(int_wk, 0x00, sizeof(int) * ID_DATA);
			HatchBoundaryTbl->sz_id += ID_DATA;
		}
	}
	return 1;

}

int set_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl,int IN_SetID){
	int *int_wk;

	HatchBoundaryTbl->n_id++;
	int ret = alc_HatchBoundaryTbl(HatchBoundaryTbl);
	if (ret < 0)
		return ret;
	int_wk = HatchBoundaryTbl->p_id + HatchBoundaryTbl->n_id - 1;
	*int_wk = IN_SetID;
	return 1;
}

void term_HatchBoundaryTbl(HatchBoundary* HatchBoundaryTbl){
	for (int i = 0; i < TYPE_COUNT; i++){
		if (HatchBoundaryTbl[i].p_id != NULL){
			free(HatchBoundaryTbl[i].p_id);
		}
	}
}

BOOL copy_HatchBoundaryTbl(HatchBoundary *HatchBoundaryTbl,HatchBoundary *wk_HatchBoundaryTbl){
	init_HatchBoundaryTbl(wk_HatchBoundaryTbl);
	wk_HatchBoundaryTbl->n_id = HatchBoundaryTbl->n_id;
	int ret = alc_HatchBoundaryTbl(wk_HatchBoundaryTbl);
	if (ret < 0)
		return FALSE;
	wk_HatchBoundaryTbl->sz_id = HatchBoundaryTbl->sz_id;
	for (int i = 0; i < HatchBoundaryTbl->n_id; i++){
		*(wk_HatchBoundaryTbl->p_id+i) = *(HatchBoundaryTbl->p_id+i);
	}
	return TRUE;
}

