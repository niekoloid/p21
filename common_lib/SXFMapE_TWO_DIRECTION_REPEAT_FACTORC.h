/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TWO_DIRECTION_REPEAT_FACTORC.h						作成日：2000.04.17

	１．クラス概要
		TWO_DIRECTION_REPEAT_FACTORを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_TWO_DIRECTION_REPEAT_FACTORC_CLASS_
#define _SXFMapE_TWO_DIRECTION_REPEAT_FACTORC_CLASS_

#include "SXFMapE_VECTORC.h"

class SXFMapE_TWO_DIRECTION_REPEAT_FACTORC:public SXFMapEntityBaseC{
public :
	SXFMapE_TWO_DIRECTION_REPEAT_FACTORC( );
	SXFMapE_TWO_DIRECTION_REPEAT_FACTORC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_TWO_DIRECTION_REPEAT_FACTORC( );

	int	SetParameter( );

public:

/*
  ENTITY two_direction_repeat_factor
	SUBTYPE OF (one_direction_repeat_factor);
	  second_repeat_factor : vector;
  END_ENTITY; -- two_direction_repeat_factor
*/

	CString m_Name;

	int m_FirstFactor_Inst;
	SXFMapE_VECTORC* m_FirstFactor_p;

	int m_SecondFactor_Inst;
	SXFMapE_VECTORC* m_SecondFactor_p;

};
#endif
////////////////////////////
