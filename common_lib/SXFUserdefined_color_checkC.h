/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.h						作成日：2000.03.21

	１．クラス概要
	ユーザ定義色フィーチャのルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.21	諌山(FQS)	なし。
**/

#ifndef _SXFCIRCLEC_CLASS_
#define _SXFCIRCLEC_CLASS_

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFUserdefined_color_checkC :public SXFCheckInfoC
{
public :
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFUserdefined_color_checkC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFUserdefined_color_checkC() ;
//------------------------------------------------
//	ユーザ定義色フィーチャの属性以外のルールチェック
//------------------------------------------------
	int str_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str);
//------------------------------------------------
//	ユーザ定義色フィーチャのルールチェック
//------------------------------------------------
	int Feature_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str) ;
} ;

#endif