/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�p���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFSheet_checkC  :public SXFCheckInfoC
{
public:
	int Feature_rule_check(Sheet_Struct* IN_sheet_str);
	int str_rule_check(Sheet_Struct* in_sheet_str);
	SXFSheet_checkC();
	virtual ~SXFSheet_checkC();
};

#endif // !defined(AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_)
