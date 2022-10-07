/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.h								作成日：2000.4.3

	１．クラス概要
	ユーザ定義線種フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "max.h"
#include "SXFComFunctionC.h"
#include "SXFStruct.h"
#include "SXFTableUniqueCheckC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFUsertype_checkC  :public SXFComFunctionC,SXFTableUniqueCheckC
{
public:
	int str_rule_check(Userdefined_Linetype_Struct* IN_usertype_str);
	int Feature_rule_check(Userdefined_Linetype_Struct* IN_usertype_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo);
	SXFUsertype_checkC();
	virtual ~SXFUsertype_checkC();
};

#endif // !defined(AFX_SXFUSERTYPE_CHECKC_H__70C850E2_0A29_11D4_A76E_00000EB03267__INCLUDED_)
