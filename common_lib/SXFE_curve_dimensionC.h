/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_dimensionC.h								�쐬���F2007.1.29

	�P�D�N���X�T�v
	curve_dimension�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/

#ifndef _E_CURVE_DIMENSION_H_
#define _E_CURVE_DIMENSION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_curve_dimensionC : public SXFD_InstC {
public :
//
//	Constructor
//
	SXFE_curve_dimensionC(SXFD_StrC*,SXFD_AggrC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_CURVE_DIMENSION_H_
