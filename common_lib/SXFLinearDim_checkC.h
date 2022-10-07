/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.h						作成日：2000.03.21

	１．クラス概要
	直線寸法フィーチャのルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.21	諌山(FQS)	なし。
**/

#ifndef _SXFLINEARDIM_CLASS_
#define _SXFLINEARDIM_CLASS_

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFLine_checkC.h"
#include "SXFText_String_checkC.h"

class SXFComInfoC;

class SXFLinearDim_checkC : public SXFLine_checkC,
							public SXFProj_checkC ,
							public SXFArrow_checkC,
							public SXFText_String_checkC
{
public :
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFLinearDim_checkC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFLinearDim_checkC() ;
//------------------------------------------------
//	属性ルールチェック
//------------------------------------------------
	int attr_rule_check(LinearDim_Struct* IN_LinearDim_str); 
//------------------------------------------------
//	属性以外のルールチェック
//------------------------------------------------
	int lineardim_check(LinearDim_Struct* IN_LinearDim_str);
//------------------------------------------------
//	フューチャールールチェック
//------------------------------------------------
	int Feature_rule_check(LinearDim_Struct* IN_LinearDim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info) ;
} ;

#endif