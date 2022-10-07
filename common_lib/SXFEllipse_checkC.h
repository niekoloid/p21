/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ȉ~�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;

class SXFEllipse_checkC   : public SXFTableCheckC , SXFComFunctionC
{
public:
	int str_rule_check(Ellipse_Struct* IN_ellipse_str);
	int attr_rule_check(Ellipse_Struct* IN_ellipse_str);
	int Feature_rule_check(Ellipse_Struct* IN_ellipse_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFEllipse_checkC();
	virtual ~SXFEllipse_checkC();

};

#endif // !defined(AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_)
