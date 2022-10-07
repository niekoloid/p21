/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.h								作成日：2000.4.3

	１．クラス概要
	複合曲線定義フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;

class SXFCcurveorg_checkC  :public SXFTableCheckC
{
public:
	int str_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str);
	int attr_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str);
	int Feature_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFCcurveorg_checkC();
	virtual ~SXFCcurveorg_checkC();

};

#endif // !defined(AFX_SXFCCURVEORG_CHECKC_H__1E81D283_0A46_11D4_A76E_00000EB03267__INCLUDED_)
