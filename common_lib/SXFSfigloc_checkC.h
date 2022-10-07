/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����}�`�z�u�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFSfigloc_checkC   : public SXFComFunctionC,SXFTableCheckC
{
public:
	int str_rule_check(Sfigloc_Struct* IN_sfigloc_str);
	int attr_rule_check(Sfigloc_Struct* IN_sfigloc_str);
	int Feature_rule_check(Sfigloc_Struct* IN_sfigloc_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFSfigloc_checkC();
	virtual ~SXFSfigloc_checkC();
};

#endif // !defined(AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_)
