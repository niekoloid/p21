/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���[�U��`����t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "max.h"
#include "SXFComFunctionC.h"
#include "SXFStruct.h"
#include "SXFTableUniqueCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFUsertype_checkC  :public SXFComFunctionC,SXFTableUniqueCheckC
{
public:
	int str_rule_check(Userdefined_Linetype_Struct* IN_usertype_str);
	int Feature_rule_check(Userdefined_Linetype_Struct* IN_usertype_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFUsertype_checkC();
	virtual ~SXFUsertype_checkC();
};

#endif // !defined(AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_)
