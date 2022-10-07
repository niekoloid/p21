/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���a���@�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFDIAMETERDIM_CHECKC_H__099E9DA0_09A9_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFDIAMETERDIM_CHECKC_H__099E9DA0_09A9_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFLine_checkC.h"
#include "SXFText_String_checkC.h"
#include "SXFCheckInfoC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFDiameterDim_checkC   : public SXFArrow_checkC,
								public SXFLine_checkC,
								public SXFText_String_checkC
{
public:
	int str_rule_check(DiameterDim_Struct* IN_diameterdim_str);
	int attr_rule_check(DiameterDim_Struct* IN_diameterdim_str);
	int Feature_rule_check(DiameterDim_Struct* IN_diameterdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_ComInfo);
	SXFDiameterDim_checkC();
	virtual ~SXFDiameterDim_checkC();

};

#endif // !defined(AFX_SXFDIAMETERDIM_CHECKC_H__099E9DA0_09A9_11D4_A76E_00000EB03267__INCLUDED_)
