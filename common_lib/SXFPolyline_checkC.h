/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ܐ��t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFPolyline_checkC  : virtual public SXFTableCheckC , public SXFComFunctionC
{
public:
	int polystr_rule_check(Polyline_Struct* IN_polyline_str);
	int Feature_rule_check(Polyline_Struct* IN_polyline_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	int attr_rule_check(Polyline_Struct* IN_polyline_str);
	SXFPolyline_checkC();
	virtual ~SXFPolyline_checkC();
};

#endif // !defined(AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_)
