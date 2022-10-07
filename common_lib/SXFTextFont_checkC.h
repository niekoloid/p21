/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								作成日：2000.4.14

	１．クラス概要
		文字フォントフィーチャのルールチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTEXTFONT_CHECKC_H__F88E18A1_12F0_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTEXTFONT_CHECKC_H__F88E18A1_12F0_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFTableUniqueCheckC.h"
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFTextFont_checkC  :public SXFTableUniqueCheckC
{
public:
	int Feature_rule_checkC(Text_Font_Struct* IN_Struct,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFTextFont_checkC();
	virtual ~SXFTextFont_checkC();

};

#endif // !defined(AFX_SXFTEXTFONT_CHECKC_H__F88E18A1_12F0_11D4_A76E_00000EB03267__INCLUDED_)
