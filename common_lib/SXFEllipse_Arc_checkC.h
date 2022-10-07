/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ȉ~�ʃt�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFELLIPSE_ARC_CHECKC_H__72D65A25_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFELLIPSE_ARC_CHECKC_H__72D65A25_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFEllipse_Arc_checkC  : public SXFTableCheckC , SXFComFunctionC
{
public:
	int str_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str);
	int attr_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str);
	int Feature_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFEllipse_Arc_checkC();
	virtual ~SXFEllipse_Arc_checkC();

};

#endif // !defined(AFX_SXFELLIPSE_ARC_CHECKC_H__72D65A25_0949_11D4_A76E_00000EB03267__INCLUDED_)
