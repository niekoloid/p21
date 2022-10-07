/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.h								作成日：2000.4.3

	１．クラス概要
	既定義シンボルフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFEXSYMBOL_CHECKC_H__1C2F3FC5_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXSYMBOL_CHECKC_H__1C2F3FC5_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;

class SXFExSymbol_checkC  : public SXFTableCheckC,SXFComFunctionC
{
public:
	int str_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str);
	int attr_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str);
	int Feature_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str,
							SXFTableManagerC* IN_TableManger,
							CString IN_InstanceID);
	SXFExSymbol_checkC();
	virtual ~SXFExSymbol_checkC();
};

#endif // !defined(AFX_SXFEXSYMBOL_CHECKC_H__1C2F3FC5_0971_11D4_A76E_00000EB03267__INCLUDED_)
