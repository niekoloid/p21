/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_dimension_callout_relationshipC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	dimension_callout_relationship�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_DIMENSION_CALLOUT_RELATIONSHIP_H_
#define _E_DIMENSION_CALLOUT_RELATIONSHIP_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_dimension_callout_relationshipC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_dimension_callout_relationshipC(SXFD_StrC*,SXFD_StrC*,SXFD_InstC*,SXFD_InstC*);
} ;

#endif	// _E_DIMENSION_CALLOUT_RELATIONSHIP_H_
