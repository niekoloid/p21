/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.h								作成日：2000.4.3

	１．クラス概要
	楕円フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;

class SXFEllipse_checkC   : public SXFTableCheckC , SXFComFunctionC
{
public:
	int str_rule_check(Ellipse_Struct* IN_ellipse_str);
	int attr_rule_check(Ellipse_Struct* IN_ellipse_str);
	int Feature_rule_check(Ellipse_Struct* IN_ellipse_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFEllipse_checkC();
	virtual ~SXFEllipse_checkC();

};

#endif // !defined(AFX_SXFELLIPSE_CHECKC_H__72D65A24_0949_11D4_A76E_00000EB03267__INCLUDED_)
