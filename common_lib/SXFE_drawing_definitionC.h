/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	drawing_definition�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B
	�X�V			2004.01.30			K.Naono				Ver3.0�Ή�

**/
#ifndef _E_DRAWING_DEFINITION_H_
#define _E_DRAWING_DEFINITION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_drawing_definitionC : public SXFD_InstC {
protected :
	SXFD_StrC* m_str;
public :
//
//	Constructor
//
	~SXFE_drawing_definitionC();
	SXFE_drawing_definitionC(SXFD_StrC*);

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	SXFE_drawing_definitionC(SXFD_StrC*, SXFD_StrC*) ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
} ;

#endif	// _E_DRAWING_DEFINITION_H_
