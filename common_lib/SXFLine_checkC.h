/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.h								作成日：2000.3.27

	１．クラス概要
	線分フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#if !defined(AFX_F_LINE_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_)
#define AFX_F_LINE_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFLine_checkC : virtual public SXFTableCheckC , public SXFComFunctionC
{
public:
	int attr_rule_check(Line_Struct* IN_line_str);
	int linestr_rule_check(Line_Struct* IN_line_str);
	int Feature_rule_check(Line_Struct* IN_line_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFLine_checkC();
	virtual ~SXFLine_checkC();
};

#endif // !defined(AFX_F_LINE_H__8A01EFE2_FA65_11D3_A76E_00000EB03267__INCLUDED_)
