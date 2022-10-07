/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.h								作成日：2000.4.3

	１．クラス概要
	半径寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFRADIUSDIM_CHECKC_H__1C2F3FC7_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFRADIUSDIM_CHECKC_H__1C2F3FC7_0971_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFLine_checkC.h"
#include "SXFText_String_checkC.h"

class SXFTableManagerC;
class SXFComInfoC;

class SXFRadiusDim_checkC  : public SXFLine_checkC ,
							public SXFProj_checkC ,
							public SXFArrow_checkC,
							public SXFText_String_checkC
{
public:
	int str_rule_check(RadiusDim_Struct* IN_radiusdim_str);
	int Feature_rule_check(RadiusDim_Struct* IN_radiusdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	int attr_rule_check(RadiusDim_Struct* IN_radiusdim_str);
	SXFRadiusDim_checkC();
	virtual ~SXFRadiusDim_checkC();
};

#endif // !defined(AFX_SXFRADIUSDIM_CHECKC_H__1C2F3FC7_0971_11D4_A76E_00000EB03267__INCLUDED_)
