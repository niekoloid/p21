/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_representation_contextC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	representation_context�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_REPRESENTATION_CONTEXT_H_
#define _E_REPRESENTATION_CONTEXT_H_

#include "SXFD_InstC.h"

class SXFPart21FileC;
//
//
//
class SXFE_representation_contextC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_representation_contextC();
//
//
//
	void WriteP21(SXFPart21FileC* IN_file);
} ;

#endif	// _E_REPRESENTATION_CONTEXT_H_
