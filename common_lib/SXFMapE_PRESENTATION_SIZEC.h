/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.h						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_SIZEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_PRESENTATION_SIZEC_CLASS_
#define _SXFMapE_PRESENTATION_SIZEC_CLASS_

#include "SXFMapE_DRAWING_SHEET_REVISIONC.h"
#include "SXFMapE_PLANAR_BOXC.h"

class SXFMapE_PRESENTATION_SIZEC:public SXFMapEntityBaseC{
public :
	SXFMapE_PRESENTATION_SIZEC( );
	SXFMapE_PRESENTATION_SIZEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PRESENTATION_SIZEC( );

	int	SetParameter( );

public:

/*
  ENTITY presentation_size;
	  unit : presentation_size_assignment_select;
	  size : planar_box;
	WHERE
	  ......
  END_ENTITY; -- presentation_size
*/

	int m_Unit_Inst;
	SXFMapE_DRAWING_SHEET_REVISIONC* m_Unit_p;

	int m_Size_Inst;
	SXFMapE_PLANAR_BOXC* m_Size_p;

};
#endif
////////////////////////////
