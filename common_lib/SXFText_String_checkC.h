/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.h								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�����v�f�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_F_TEXT_STRING_H__BD2C3C20_FA8A_11D3_A76E_00000EB03267__INCLUDED_)
#define AFX_F_TEXT_STRING_H__BD2C3C20_FA8A_11D3_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;

class SXFText_String_checkC  : virtual public SXFTableCheckC, public SXFComFunctionC
{
public:
	int textstr_rule_check(Text_Struct* IN_text_str);
	int attr_rule_check(Text_Struct* IN_text_str);
	int Feature_rule_check(Text_Struct* IN_text_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFText_String_checkC();
	virtual ~SXFText_String_checkC();
};

#endif // !defined(AFX_F_TEXT_STRING_H__BD2C3C20_FA8A_11D3_A76E_00000EB03267__INCLUDED_)
