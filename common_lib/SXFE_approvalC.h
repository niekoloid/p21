/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_approvalC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	approval�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_)
#define AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_InstC;
class SXFD_StrC;

class SXFE_approvalC : public SXFD_InstC  
{
public:
	SXFE_approvalC(SXFD_InstC* inst,SXFD_StrC* str);
	virtual ~SXFE_approvalC();

};

#endif // !defined(AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_)
