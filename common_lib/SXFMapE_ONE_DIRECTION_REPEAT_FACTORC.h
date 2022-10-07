/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ONE_DIRECTION_REPEAT_FACTORC.h						作成日：2000.04.17

	１．クラス概要
		ONE_DIRECTION_REPEAT_FACTORを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_ONE_DIRECTION_REPEAT_FACTORC_CLASS_
#define _SXFMapE_ONE_DIRECTION_REPEAT_FACTORC_CLASS_

#include "SXFMapE_VECTORC.h"

class SXFMapE_ONE_DIRECTION_REPEAT_FACTORC:public SXFMapEntityBaseC{
public :
	SXFMapE_ONE_DIRECTION_REPEAT_FACTORC( );
	SXFMapE_ONE_DIRECTION_REPEAT_FACTORC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_ONE_DIRECTION_REPEAT_FACTORC( );

	int	SetParameter( );

public:

/*
  ENTITY one_direction_repeat_factor
	SUBTYPE OF (geometric_representation_item);
	  repeat_factor : vector;
  END_ENTITY; -- one_direction_repeat_factor
*/

	CString m_Name;

	int m_Factor_Inst;
	SXFMapE_VECTORC* m_Factor_p;
};
#endif
////////////////////////////
