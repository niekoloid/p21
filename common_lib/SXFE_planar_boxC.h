/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_boxC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	planar_box�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_PLANAR_BOX_H_
#define _E_PLANAR_BOX_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_planar_boxC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_planar_boxC(SXFD_StrC*,SXFD_RealC*,SXFD_RealC*,SXFD_InstC*);
} ;

#endif	// _E_PLANAR_BOX_H_
