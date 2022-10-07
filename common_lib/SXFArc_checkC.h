/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.h								作成日：2000.4.3

	１．クラス概要
	円弧フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFARC_CHECKC_H__72D65A23_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFARC_CHECKC_H__72D65A23_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFArc_checkC   : virtual public SXFTableCheckC , public SXFComFunctionC
{
public:
	int arcstr_rule_check(Arc_Struct* IN_arc_str, bool check_same_angle = true);
	int attr_rule_check(Arc_Struct* IN_arc_str);
	int Feature_rule_check(Arc_Struct* IN_arc_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFArc_checkC();
	virtual ~SXFArc_checkC();
};

#endif // !defined(AFX_SXFARC_CHECKC_H__72D65A23_0949_11D4_A76E_00000EB03267__INCLUDED_)
