/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�_�}�[�J�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_F_POINT_MARKER_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_)
#define AFX_F_POINT_MARKER_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;

class SXFPoint_Marker_checkC : public SXFTableCheckC, SXFComFunctionC
{
public:
	int attr_rule_check(Point_Marker_Struct* IN_point_marker_str);
	int str_rule_check(Point_Marker_Struct* IN_point_marker_str);
	int Feature_rule_check(Point_Marker_Struct* IN_point_marker_str,
						SXFTableManagerC* IN_TableManager,
						CString IN_InstanceID);
	SXFPoint_Marker_checkC();
	virtual ~SXFPoint_Marker_checkC();
};

#endif // !defined(AFX_F_POINT_MARKER_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_)
