/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_vectorC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	vector�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_VECTOR_H_
#define _E_VECTOR_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;

//
//
//
class SXFE_vectorC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_vectorC(SXFD_StrC*,SXFD_InstC*,SXFD_RealC*);
} ;

#endif	// _E_VECTOR_H_ (pt = m_Data.GetNext(pos))
