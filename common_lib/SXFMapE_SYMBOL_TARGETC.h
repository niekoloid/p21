/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.h						作成日：2000.04.17

	１．クラス概要
		SYMBOL_TARGETを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_TARGETC_CLASS_
#define _SXFMapE_SYMBOL_TARGETC_CLASS_

#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"

class SXFMapE_SYMBOL_TARGETC:public SXFMapEntityBaseC{
public :
	SXFMapE_SYMBOL_TARGETC( );
	SXFMapE_SYMBOL_TARGETC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_SYMBOL_TARGETC( );

	int	SetParameter( );

public:

/*
  ENTITY symbol_target
	SUBTYPE OF (geometric_representation_item);
	  placement : axis2_placement;
	  x_scale	: positive_ratio_measure;
	  y_scale	: positive_ratio_measure;
  END_ENTITY; -- symbol_target
*/

	CString m_Name;

	int m_Placement_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_Placement_p;

	double m_Scale_x;
	double m_Scale_y;

};
#endif
////////////////////////////
