/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDim_checkC.h								作成日：2000.4.3

	１．クラス概要
	角度寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFANGULARDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFANGULARDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFArc_checkC.h"
#include "SXFText_String_checkC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFAngularDim_checkC  : public SXFProj_checkC ,
							public SXFArrow_checkC,
							public SXFArc_checkC,
							public SXFText_String_checkC
{
public:
	int str_rule_check(AngularDim_Struct* IN_angulardim_str);
	int attr_rule_check(AngularDim_Struct* IN_angulardim_str);
	int Feature_rule_check(AngularDim_Struct* IN_angulardim_str,
							SXFTableManagerC* IN_Table,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFAngularDim_checkC();
	virtual ~SXFAngularDim_checkC();

};

#endif // !defined(AFX_SXFANGULARDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_)
