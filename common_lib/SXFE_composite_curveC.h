/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curveC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	composite_curve�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_COMPOSITE_CURVE_H_
#define _E_COMPOSITE_CURVE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
//
//
//
class SXFE_composite_curveC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_composite_curveC(SXFD_StrC*,SXFD_AggrC*,SXFD_BoolC*);
} ;

#endif	// _E_COMPOSITE_CURVE_H_
