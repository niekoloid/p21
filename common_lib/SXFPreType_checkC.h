/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreType_checkC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
		����`����t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFPRETYPE_CHECKC_H__F88E18A0_12F0_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRETYPE_CHECKC_H__F88E18A0_12F0_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFTableUniqueCheckC.h"
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFPreType_checkC  :public SXFTableUniqueCheckC
{
public:
	int Feature_rule_check(Predefined_Linetype_Struct* IN_Struct,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFPreType_checkC();
	virtual ~SXFPreType_checkC();

};

#endif // !defined(AFX_SXFPRETYPE_CHECKC_H__F88E18A0_12F0_11D4_A76E_00000EB03267__INCLUDED_)
