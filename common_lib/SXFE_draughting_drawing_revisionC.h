/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_drawing_revisionC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	draughting_drawing_revision�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B
	�X�V			2004.01.30			K.Naono				Ver3.0�Ή�

**/
#ifndef _E_DRAUGHTING_DRAWING_REVISION_H_
#define _E_DRAUGHTING_DRAWING_REVISION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_draughting_drawing_revisionC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_draughting_drawing_revisionC(SXFD_StrC*,SXFD_InstC*);
	~SXFE_draughting_drawing_revisionC();

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	SXFE_draughting_drawing_revisionC(SXFD_StrC*,SXFD_InstC*,SXFD_StrC*);
//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30

private:
	SXFD_StrC* m_str;
} ;

#endif	// _E_DRAUGHTING_DRAWING_REVISION_H_
