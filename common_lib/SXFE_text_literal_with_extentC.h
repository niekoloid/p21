/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	text_literal_with_extent�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_TEXT_LITERAL_WITH_EXTENT_H_
#define _E_TEXT_LITERAL_WITH_EXTENT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_EnumC;
//
//
//
class SXFE_text_literal_with_extentC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_text_literal_with_extentC(SXFD_StrC*,SXFD_StrC*,SXFD_InstC*,SXFD_StrC*,SXFD_EnumC*,SXFD_InstC*,SXFD_InstC*);
} ;

#endif	// _E_TEXT_LITERAL_WITH_EXTENT_H_
