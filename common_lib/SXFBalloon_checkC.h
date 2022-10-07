/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.h								作成日：2000.4.4

	１．クラス概要
	バルーンフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.4			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFBALLOON_CHECKC_H__6F7A9961_0A64_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFBALLOON_CHECKC_H__6F7A9961_0A64_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFText_String_checkC.h"
#include "SXFCircle_checkC.h"
#include "SXFPolyline_checkC.h"

class SXFBalloon_checkC  : public SXFArrow_checkC,
							public SXFPolyline_checkC,
							public SXFCircle_checkC,
							public SXFText_String_checkC
{
public:
	int str_rule_check(Balloon_Struct* IN_balloon_str);
	int attr_rule_check(Balloon_Struct* IN_balloon_str);
	int Feature_rule_check(Balloon_Struct* IN_balloon_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFBalloon_checkC();
	virtual ~SXFBalloon_checkC();
};

#endif // !defined(AFX_SXFBALLOON_CHECKC_H__6F7A9961_0A64_11D4_A76E_00000EB03267__INCLUDED_)
