/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_symbol_styleC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	symbol_style�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_SYMBOL_STYLE_H_
#define _E_SYMBOL_STYLE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_symbol_styleC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_symbol_styleC(SXFD_StrC*,SXFD_InstC*);
	SXFE_symbol_styleC(SXFD_StrC*,SXFD_StrC*);
} ;

#endif	// _E_SYMBOL_STYLE_H_
