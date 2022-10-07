/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TWO_DIRECTION_REPEAT_FACTORC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TWO_DIRECTION_REPEAT_FACTOR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
