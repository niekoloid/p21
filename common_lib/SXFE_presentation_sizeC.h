/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	presentation_size�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_PRESENTATION_SIZE_H_
#define _E_PRESENTATION_SIZE_H_

#include "SXFD_InstC.h"

class SXFPart21FileC;
//
//
//
class SXFE_presentation_sizeC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_presentation_sizeC(SXFD_InstC*,SXFD_InstC*);
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_PRESENTATION_SIZE_H_
