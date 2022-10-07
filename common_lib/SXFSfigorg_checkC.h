/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.h								作成日：2000.4.3

	１．クラス概要
	複合図形定義フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFSfigorg_checkC  :public SXFCheckInfoC
{
public:
	int str_rule_check(Sfigorg_Struct* IN_sfigorg_str);
	int Feature_rule_check(Sfigorg_Struct* IN_sfigorg_str,
							CString IN_InstanceID);
	SXFSfigorg_checkC();
	virtual ~SXFSfigorg_checkC();

};

#endif // !defined(AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_)
