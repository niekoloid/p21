/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.h								作成日：2000.4.3

	１．クラス概要
	用紙フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFSheet_checkC  :public SXFCheckInfoC
{
public:
	int Feature_rule_check(Sheet_Struct* IN_sheet_str);
	int str_rule_check(Sheet_Struct* in_sheet_str);
	SXFSheet_checkC();
	virtual ~SXFSheet_checkC();
};

#endif // !defined(AFX_SXFSHEET_CHECKC_H__9D6AD3A0_0A12_11D4_A76E_00000EB03267__INCLUDED_)
