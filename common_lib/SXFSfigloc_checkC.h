/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.h								作成日：2000.4.3

	１．クラス概要
	複合図形配置フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFSfigloc_checkC   : public SXFComFunctionC,SXFTableCheckC
{
public:
	int str_rule_check(Sfigloc_Struct* IN_sfigloc_str);
	int attr_rule_check(Sfigloc_Struct* IN_sfigloc_str);
	int Feature_rule_check(Sfigloc_Struct* IN_sfigloc_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);
	SXFSfigloc_checkC();
	virtual ~SXFSfigloc_checkC();
};

#endif // !defined(AFX_SXFSFIGLOC_CHECKC_H__1C2F3FC4_0971_11D4_A76E_00000EB03267__INCLUDED_)
