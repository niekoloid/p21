/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_symbol_targetC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	symbol_target�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_SYMBOL_TARGET_H_
#define _E_SYMBOL_TARGET_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_symbol_targetC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_symbol_targetC(SXFD_StrC*,SXFD_InstC*,SXFD_RealC*,SXFD_RealC*);
} ;

#endif	// _E_SYMBOL_TARGET_H_
