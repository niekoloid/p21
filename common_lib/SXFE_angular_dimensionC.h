/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_angular_dimensionC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	angular_dimension�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#ifndef _E_ANGULAR_DIMENSION_H_
#define _E_ANGULAR_DIMENSION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_angular_dimensionC : public SXFD_InstC {
public :
//
//	Constructor
//
	SXFE_angular_dimensionC(SXFD_StrC*,SXFD_AggrC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_ANGULAR_DIMENSION_H_