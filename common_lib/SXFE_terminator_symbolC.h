/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	terminator_symbol�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_TERMINATOR_SYMBOL_H_
#define _E_TERMINATOR_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_EnumC;
class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_terminator_symbolC : public SXFD_InstC {
protected :
	int type_flag;
public :
//
//	Constructor
//
	SXFE_terminator_symbolC(SXFD_EnumC*,SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
	SXFE_terminator_symbolC(SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_TERMINATOR_SYMBOL_H_
