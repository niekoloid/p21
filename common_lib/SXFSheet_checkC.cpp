/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	用紙フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFSheet_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFSheet_checkC::SXFSheet_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSheet_checkC::SXFSheet_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFSheet_checkC::~SXFSheet_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSheet_checkC::~SXFSheet_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								作成日：2000.4.3

	１．機能概要
		用紙フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Sheet_Struct IN_sheet_str);

	引数:	型					引数名				内容
			Sheet_Struct		IN_sheet_str		用紙構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSheet_checkC::str_rule_check(Sheet_Struct* in_sheet_str)
{
	//図面名が設定されていないとき
	//ログファイルに出力するのみの
	//ワーニングとする。
	if (strlen(in_sheet_str->name) == 0){
		SXFErrorMsgC::RecordError(SXFNOTSETZNAME,
									m_feature_name,
									0);
	}
	//用紙サイズ種別が０～４または９ではないとき
	if ( (in_sheet_str->type < 0) || (in_sheet_str->type > 4) ){
		if (in_sheet_str->type != 9){
			SXFErrorMsgC::RecordError(SXFSHEETSIZE,
										m_feature_name,
										1,
										in_sheet_str->type);
			return SXFSHEETSIZE;
		}
	}
	//用紙サイズ種別が９で自由用紙横長,縦長が設定されてないとき
	if (in_sheet_str->type == 9){
		if (in_sheet_str->x <= 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTH,
										m_feature_name,
										1,
										in_sheet_str->x);
			return SXFSHEETLENGTH;
		}
		if (in_sheet_str->y <= 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTH,
										m_feature_name,
										1,
										in_sheet_str->y);
			return SXFSHEETLENGTH;
		}
	}
	//用紙サイズ種別が０～４で自由用紙横長,縦長が設定されているとき
	//メッセージのみ。マイナスは返さない。（エラーではなくワーニングとする）
	if ((in_sheet_str->type >= 0) && (in_sheet_str->type <= 4)){
		if (in_sheet_str->x > 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTHWARNING,
										m_feature_name,
										1,
										in_sheet_str->x);
		}
		if (in_sheet_str->y > 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTHWARNING,
										m_feature_name,
										1,
										in_sheet_str->y);
		}
	}

	//用紙サイズ種別が９ではなく、縦/横区分が０または１ではないとき
	//用紙サイズ種別が９でないとき、縦/横区分は無効
	if (in_sheet_str->type != 9){
		if ((in_sheet_str->orient < 0) || (in_sheet_str->orient > 1)){
			SXFErrorMsgC::RecordError(SXFORIENTERROR,
										m_feature_name,
										1,
										in_sheet_str->orient);
			return SXFORIENTERROR;
		}
	}
	return 0;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								作成日：2000.4.3

	１．機能概要
		用紙フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Sheet_Struct IN_sheet_str);

	引数:	型				引数名				内容
			Sheet_Struct	IN_sheet_str		用紙構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSheet_checkC::Feature_rule_check(Sheet_Struct* IN_sheet_str)
{
	int ret;

	m_feature_name = DEF_SHEET;

	ret = str_rule_check(IN_sheet_str);
	return ret;

}
