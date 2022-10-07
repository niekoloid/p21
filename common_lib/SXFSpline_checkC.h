/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�X�v���C���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSPLINE_CHECKC_H__1C2F3FC0_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSPLINE_CHECKC_H__1C2F3FC0_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;

class SXFSpline_checkC  : public SXFTableCheckC , SXFComFunctionC
{
public:
	int str_rule_check(Spline_Struct* IN_spline_str);
	int attr_rule_check(Spline_Struct* IN_spline_str);
	int Feature_rule_check(Spline_Struct* IN_spline_str,
							SXFTableManagerC* IN_TableManager,
							int AssemType,
							CString IN_InstanceID);
	SXFSpline_checkC();
	virtual ~SXFSpline_checkC();

};

#endif // !defined(AFX_SXFSPLINE_CHECKC_H__1C2F3FC0_0971_11D4_A76E_00000EB03267__INCLUDED_)
