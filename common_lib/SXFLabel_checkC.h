/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabel_checkC.h								�쐬���F2000.4.4

	�P�D�N���X�T�v
	���o�����t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFLABEL_CHECKC_H__6F7A9960_0A64_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLABEL_CHECKC_H__6F7A9960_0A64_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFText_String_checkC.h"
#include "SXFPolyline_checkC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFLabel_checkC  : public SXFArrow_checkC,
						public SXFPolyline_checkC,
						public SXFText_String_checkC
{
public:
	int str_rule_check(Label_Struct* IN_label_str);
	int attr_rule_check(Label_Struct* IN_label_str);
	int Feature_rule_check(Label_Struct* IN_label_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFLabel_checkC();
	virtual ~SXFLabel_checkC();

};

#endif // !defined(AFX_SXFLABEL_CHECKC_H__6F7A9960_0A64_11D4_A76E_00000EB03267__INCLUDED_)
