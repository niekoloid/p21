/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_clothoidC.h								�쐬���F2007.1.30

	�P�D�N���X�T�v
	clothoid�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.30			����				�Ȃ��B

**/
#ifndef _E_CLOTHOID_H_
#define _E_CLOTHOID_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_clothoidC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_clothoidC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_RealC *real);
} ;

#endif	// _E_CLOTHOID_H_
