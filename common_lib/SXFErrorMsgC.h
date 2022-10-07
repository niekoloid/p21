/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.h								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�G���[���b�Z�[�W���X�g�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#ifndef _ERRORMSGC_H_
#define	_ERRORMSGC_H_

#include <afx.h>
#include "SXFErrorCode.h"

class SXFErrorRecC;

class SXFErrorMsgC {
public:
	static void	RecordError(SXFErrorCode IN_Code, const char* IN_Name,int IN_param, ...);
	static void	RecordError2(SXFErrorCode IN_Code, const char* IN_Name,int IN_param, ...);
	static SXFErrorRecC*	PeekError();
};


#endif	// _ERRORMSGC_H_ 
