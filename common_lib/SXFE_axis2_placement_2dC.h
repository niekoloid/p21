/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_axis2_placement_2dC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	axis2_placement_2d�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_AXIS2_PLACEMENT_2D_H_
#define _E_AXIS2_PLACEMENT_2D_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_axis2_placement_2dC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_axis2_placement_2dC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*);
	SXFE_axis2_placement_2dC(SXFD_StrC*,SXFD_InstC*,SXFD_StrC*);

} ;

#endif	// _E_AXIS2_PLACEMENT_2D_H_
