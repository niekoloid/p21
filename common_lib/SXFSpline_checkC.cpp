/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	スプラインフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFSpline_checkC.h"
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
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFSpline_checkC::SXFSpline_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSpline_checkC::SXFSpline_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFSpline_checkC::~SXFSpline_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSpline_checkC::~SXFSpline_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		スプラインフィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Spline_Struct IN_spline_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)

	引数:	型					引数名				内容
			Spline_Struct		IN_spline_str		スプライン構造体
			SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			int					IN_AssemType		アセンブリ型
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSpline_checkC::Feature_rule_check(Spline_Struct* IN_spline_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SPLINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 複合曲線上以外の要素のとき **/
	if (IN_AssemType != 3){
		/** 属性のルールチェック **/
		ret = attr_rule_check(IN_spline_str);
		if (ret < 0)
			return ret;
	}
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_spline_str);
	if (ret < 0)
		return ret;

	return 0;	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		スプラインフィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Spline_Struct IN_spline_str);

	引数:	型					引数名				内容
			Spline_Struct		IN_spline_str		スプライン構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSpline_checkC::attr_rule_check(Spline_Struct* IN_spline_str)
{
	m_layer = IN_spline_str->layer ;
	m_color = IN_spline_str->color ;
	m_type = IN_spline_str->type ;
	m_line_width = IN_spline_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		スプラインフィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Spline_Struct IN_spline_str);

	引数:	型					引数名				内容
			Spline_Struct		IN_spline_str		スプライン構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSpline_checkC::str_rule_check(Spline_Struct* IN_spline_str)
{
	//開閉区分が０、１以外
	if ((IN_spline_str->open_close < 0) || (IN_spline_str->open_close > 1)){
		SXFErrorMsgC::RecordError(SXFOPENCLOSEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->open_close,
									m_feature_name);
		return SXFOPENCLOSEERROR;
	}
	//頂点数が4未満
	if (IN_spline_str->number < 4){
		SXFErrorMsgC::RecordError(SXFVERTEXERRORSPLINE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFVERTEXERRORSPLINE;
	}
	//頂点数より座標の配列数が少ない場合はエラー
	if (IN_spline_str->number > IN_spline_str->x.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	if (IN_spline_str->number > IN_spline_str->y.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	return 0;
}
