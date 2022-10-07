/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����Ȑ���`�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;

class SXFCcurveorg_checkC  :public SXFTableCheckC
{
public:
	int str_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str);
	int attr_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str);
	int Feature_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFCcurveorg_checkC();
	virtual ~SXFCcurveorg_checkC();

};

#endif // !defined(AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_)
