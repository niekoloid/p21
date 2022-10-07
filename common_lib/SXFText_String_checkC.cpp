/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．クラス概要
	文字要素フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFText_String_checkC.h"
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
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFText_String_checkC::SXFText_String_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFText_String_checkC::SXFText_String_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFText_String_checkC::~SXFText_String_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFText_String_checkC::~SXFText_String_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．機能概要
		文字要素フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Text_Struct IN_text_str,
						  SXFTableManagerC* IN_TableManager,
						  CString IN_InstanceID)

	引数:	型					引数名			内容
			Text_Struct			IN_text_str		文字要素構造体
		    SXFTableManagerC*	IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			CString				IN_InstanceID	インスタンスID
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFText_String_checkC::Feature_rule_check(Text_Struct* in_text_str,
											  SXFTableManagerC* IN_TableManager,
											  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_TEXT;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	ret = attr_rule_check(in_text_str);
	if (ret < 0)
		return ret;

	ret = textstr_rule_check(in_text_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．機能概要
		文字要素フィーチャのルールチェック

	２．インターフェース
	int attr_rule_check(Text_Struct IN_text_str);

	引数:	型					引数名				内容
			Text_Struct	IN_text_str			文字要素構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFText_String_checkC::attr_rule_check(Text_Struct* in_text_str)
{
	//テーブルのルールチェック
	m_layer = in_text_str->layer;
	m_color = in_text_str->color;
	m_font = in_text_str->font;
	int ret = TextFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								作成日：2000.3.27

	１．機能概要
		文字要素フィーチャの属性以外のルールチェック

	２．インターフェース
	int textstr_rule_check(Text_Struct IN_text_str)

	引数:	型			引数名				内容
			Text_Struct	IN_text_str			文字要素構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFText_String_checkC::textstr_rule_check(Text_Struct* in_text_str)
{
	//文字範囲高が規定範囲外のとき
	if (double_check(in_text_str->height) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTHEIGHT,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//メッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->height,//文字範囲高
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFTEXTHEIGHT;
	}
	//文字範囲幅が規定範囲外のとき
	if (double_check(in_text_str->width) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTWIDTH,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//エラーメッセージ引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->width,//文字範囲幅
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFTEXTWIDTH;
	}
	//文字間隔が規定範囲外のとき
	if (max_double_check(in_text_str->spc) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTSPACE,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//エラーメッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->spc,//文字間隔
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFTEXTSPACE;
	}
	//回転角が0度から360度でないとき
	if (angle_check(in_text_str->angle) < 0){
		SXFErrorMsgC::RecordError(
			SXFERRORANGLE,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//エラーメッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->angle,//回転角
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFERRORANGLE;
	}
	//スラント角度が-85度から85度でないとき
	if (slant_check(in_text_str->slant) < 0){
		SXFErrorMsgC::RecordError(
			SXFERRORANGLE,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//エラーメッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->slant,//スラント角
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFERRORANGLE;
	}
	//文字配置基点が１から９でないとき
	if ((in_text_str->b_pnt < 1) || (in_text_str->b_pnt > 9)){
		SXFErrorMsgC::RecordError(
			SXFBPNTERROR,//エラーメッセージNO
			m_feature_name,//フィーチャ名
			3,//エラーメッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->b_pnt,//文字配置基点
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFBPNTERROR;
	}
	//文字書き出し方向が１から２でないとき
	if ((in_text_str->direct < 1) || (in_text_str->direct > 2)){
		SXFErrorMsgC::RecordError(
			SXFDIRECTERROR,//エラーメッセージNo
			m_feature_name,//フィーチャ名
			3,//エラーメッセージの引数の個数
			m_InstanceID,//インスタンスID
			in_text_str->direct,//文字書き出し方向
			m_feature_name//エラーメッセージ用フィーチャ名
			);
		return SXFDIRECTERROR;
	}
	return 0;

}
