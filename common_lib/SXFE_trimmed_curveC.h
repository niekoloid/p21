/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	trimmed_curve�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_TRIMMED_CURVE_H_
#define _E_TRIMMED_CURVE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;
//
//
//
class SXFE_trimmed_curveC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_trimmed_curveC(SXFD_StrC*,
		SXFD_InstC*,
		SXFD_AggrC*,
		SXFD_AggrC*,
		SXFD_BoolC*,
		SXFD_EnumC*);
} ;

#endif	// _E_TRIMMED_CURVE_H_
