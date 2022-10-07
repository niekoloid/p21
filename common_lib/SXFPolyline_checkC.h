/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.h								作成日：2000.4.3

	１．クラス概要
	折線フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFPolyline_checkC  : virtual public SXFTableCheckC , public SXFComFunctionC
{
public:
	int polystr_rule_check(Polyline_Struct* IN_polyline_str);
	int Feature_rule_check(Polyline_Struct* IN_polyline_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	int attr_rule_check(Polyline_Struct* IN_polyline_str);
	SXFPolyline_checkC();
	virtual ~SXFPolyline_checkC();
};

#endif // !defined(AFX_SXFPOLYLINE_CHECKC_H__72D65A22_0949_11D4_A76E_00000EB03267__INCLUDED_)
