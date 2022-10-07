/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.h								作成日：2000.4.3

	１．クラス概要
	レイヤフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFLAYER_CHECKC_H__70C850E0_0A29_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLAYER_CHECKC_H__70C850E0_0A29_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableUniqueCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFLayer_checkC  :public SXFTableUniqueCheckC
{
public:
	int str_rule_check(Layer_Struct* IN_layer_str);
	int Feature_rule_check(Layer_Struct* IN_layer_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFLayer_checkC();
	virtual ~SXFLayer_checkC();
};

#endif // !defined(AFX_SXFLAYER_CHECKC_H__70C850E0_0A29_11D4_A76E_00000EB03267__INCLUDED_)
