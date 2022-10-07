/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	既定義シンボルフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFExSymbol_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFExSymbol_checkC::SXFExSymbol_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFExSymbol_checkC::SXFExSymbol_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFExSymbol_checkC::~SXFExSymbol_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFExSymbol_checkC::~SXFExSymbol_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．機能概要
		既定義シンボルフィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Externally_Defined_Symbol_Struct IN_exsymbol_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	引数:	型									引数名				内容
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		既定義シンボル構造体
			SXFTableManagerC*					IN_TableManager		定義テーブル要素管理オブジェクト
			CString								IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFExSymbol_checkC::Feature_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_EXTERNALLY_DEFINED_SYMBOL;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	ret = attr_rule_check(IN_exsymbol_str);
	if (ret < 0)
		return ret;

	ret = str_rule_check(IN_exsymbol_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．機能概要
		既定義シンボルフィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Externally_Defined_Symbol IN_exsymbol_str);
	
	引数:	型									引数名				内容
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		既定義シンボル構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFExSymbol_checkC::attr_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str)
{
	//色コードフラグが0または１ではないとき
	if ((IN_exsymbol_str->color_flag < 0) || (IN_exsymbol_str->color_flag > 1)){
		SXFErrorMsgC::RecordError(SXFCOLORFLAG,
								m_feature_name,
								3,
								m_InstanceID,
								IN_exsymbol_str->color_flag,
								m_feature_name);
		return SXFCOLORFLAG;
	}
	m_layer = IN_exsymbol_str->layer;
	m_color = IN_exsymbol_str->color;
	int ret = ExSymbol_Check(IN_exsymbol_str->color_flag) ;
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								作成日：2000.4.3

	１．機能概要
		既定義シンボルフィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Externally_Defined_Symbol_Struct IN_exsymbol_str);

	引数:	型									引数名				内容
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		既定義シンボル構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFExSymbol_checkC::str_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str)
{
	//回転角が０度から360度でないとき
	if (angle_check(IN_exsymbol_str->rotate_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exsymbol_str->rotate_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//尺度が０以下のとき
	if (double_check(IN_exsymbol_str->scale) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exsymbol_str->scale,
									m_feature_name);
		return SXFERRORSCALE;
	}
	return 0;
}
