/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.h								作成日：2007.1.29

	１．クラス概要
	弧長寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/

#if !defined(AFX_SXFCURVEDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCURVEDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFArc_checkC.h"
#include "SXFText_String_checkC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFCurveDim_checkC  : public SXFProj_checkC ,
							public SXFArrow_checkC,
							public SXFArc_checkC,
							public SXFText_String_checkC
{
public:
	int str_rule_check(CurveDim_Struct* IN_curvedim_str);
	int attr_rule_check(CurveDim_Struct* IN_curvedim_str);
	int Feature_rule_check(CurveDim_Struct* IN_curvedim_str,
							SXFTableManagerC* IN_Table,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFCurveDim_checkC();
	virtual ~SXFCurveDim_checkC();

};

#endif // !defined(AFX_SXFCURVEDIM_CHECKC_H__1C2F3FC6_0971_11D4_A76E_00000EB03267__INCLUDED_)
