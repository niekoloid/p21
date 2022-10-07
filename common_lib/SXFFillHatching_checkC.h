/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�n�b�`���O�i���[�U��`�j�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFFILLHATCHING_CHECKC_H__1E81D281_0A46_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFFILLHATCHING_CHECKC_H__1E81D281_0A46_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;
class SXFWriteManagerC;
class SXFReadAP202ManagerC;
class SXFComInfoC;

class SXFFillHatching_checkC  : public SXFTableCheckC, SXFComFunctionC
{
public:
	int ReadAP202_Check(Fill_area_style_hatching_Struct *IN_Struct);
	int str_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str);
	int attr_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str);
	int Feature_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadAP202ManagerC* IN_ReadAP202Manager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFFillHatching_checkC();
	virtual ~SXFFillHatching_checkC();
	
	SXFReadAP202ManagerC* m_ReadAP202Manager;
	SXFWriteManagerC* m_WriteManager;

private:
	int StructCheck(Fill_area_style_hatching_Struct* IN_Struct);
};

#endif // !defined(AFX_SXFFILLHATCHING_CHECKC_H__1E81D281_0A46_11D4_A76E_00000EB03267__INCLUDED_)
