/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleC.h						作成日：2000.03.29

	１．クラス概要
	円フィーチャのルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/

#ifndef _SXFCIRCLEC_check_CLASS_
#define _SXFCIRCLEC_check_CLASS_

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;

class SXFCircle_checkC : virtual public SXFTableCheckC , public SXFComFunctionC
{
public :
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFCircle_checkC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFCircle_checkC() ;
//------------------------------------------------
//	属性ルールチェック
//------------------------------------------------
	int attr_rule_check(Circle_Struct* IN_circle_str);
//------------------------------------------------
//	属性以外のルールチェック
//------------------------------------------------
	int circlestr_rule_check(Circle_Struct* IN_circle_str);
//------------------------------------------------
//	構造体をチェックする
//------------------------------------------------
	int Feature_rule_check(Circle_Struct* IN_circle_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID) ;
} ;

#endif