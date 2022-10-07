/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.h								作成日：2000.4.3

	１．クラス概要
	ハッチング(既定義)フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFEXHATCH_CHECKC_H__70C850E4_0A29_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXHATCH_CHECKC_H__70C850E4_0A29_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"

class SXFTableManagerC;
class SXFWriteManagerC;
class SXFComInfoC;
class SXFReadAP202ManagerC;

class SXFExhatch_checkC  :public SXFTableCheckC
{
public:
	int ReadAP202_Check(Externally_Defined_Hatch_Struct* IN_Struct);
	int attr_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str);
	int str_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str);
	int Feature_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadAP202ManagerC* IN_ReadAP202Manager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFExhatch_checkC();
	virtual ~SXFExhatch_checkC();

	SXFReadAP202ManagerC* m_ReadAP202Manager;
	SXFWriteManagerC* m_WriteManager;
};

#endif // !defined(AFX_SXFEXHATCH_CHECKC_H__70C850E4_0A29_11D4_A76E_00000EB03267__INCLUDED_)
