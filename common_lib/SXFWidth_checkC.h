/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.h							作成日：2000.4.14

	１．クラス概要
		線幅フィーチャのルールチェックを行うクラス
	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFWIDTH_CHECKC_H__266DAF62_1152_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFWIDTH_CHECKC_H__266DAF62_1152_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFComFunctionC.h"
#include "SXFStruct.h"
#include "SXFTableUniqueCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFWidth_checkC  :public SXFComFunctionC,SXFTableUniqueCheckC
{
public:
	int str_rule_check(Line_Width_Struct* IN_width_str);
	int Feature_rule_check(Line_Width_Struct* IN_width_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFWidth_checkC();
	virtual ~SXFWidth_checkC();
};

#endif // !defined(AFX_SXFWIDTH_CHECKC_H__266DAF62_1152_11D4_A76E_00000EB03267__INCLUDED_)
