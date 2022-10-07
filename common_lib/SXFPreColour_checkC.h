/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColour_checkC.cpp								作成日：2000.4.14

	１．クラス概要
		既定義色フィーチャのルールチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFPRECOLOUR_CHECKC_H__2E711DE4_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRECOLOUR_CHECKC_H__2E711DE4_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFTableUniqueCheckC.h"
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFPreColour_checkC  :public SXFTableUniqueCheckC
{
public:
	int Feature_rule_check(Predefined_Colour_Struct* IN_Struct,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFPreColour_checkC();
	virtual ~SXFPreColour_checkC();

};

#endif // !defined(AFX_SXFPRECOLOUR_CHECKC_H__2E711DE4_12B6_11D4_A76E_00000EB03267__INCLUDED_)
