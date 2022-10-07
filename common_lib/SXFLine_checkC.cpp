/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．クラス概要
	線分フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFLine_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFLine_checkC::SXFLine_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFLine_checkC::SXFLine_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFLine_checkC::~SXFLine_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFLine_checkC::~SXFLine_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．機能概要
		線分フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Line_Struct IN_line_str,
						   SXFTableManagerC* IN_TableManager,
						   CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	引数:	型					引数名			内容
			Line_Struct			IN_line_str		線分構造体
		    SXFTableManagerC*	IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
            CString				IN_InstanceID	インスタンスID
			SXFComInfoC*		IN_Info			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFLine_checkC::Feature_rule_check(Line_Struct* IN_line_str,
									   SXFTableManagerC* IN_TableManager,
									   CString IN_InstanceID,
									   SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_LINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_line_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = linestr_rule_check(IN_line_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．機能概要
		線分フィーチャの属性以外のルールチェック

	２．インターフェース
	int linestr_rule_check(Line_Struct IN_line_str)

	引数:	型					引数名				内容
			Line_Struct			IN_line_str			線分構造体
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFLine_checkC::linestr_rule_check(Line_Struct* IN_line_str)
{
	/////////////////////////////
	//許容誤差の取得
	/////////////////////////////
	double tolerance1,tolerance2;
	m_ComInfo->Get_Tolerance(tolerance1,tolerance2);

	double length = calc_length(IN_line_str->start_x,
								IN_line_str->start_y,
								IN_line_str->end_x,
								IN_line_str->end_y);
	if (length < tolerance1){
		SXFErrorMsgC::RecordError(
			SXFLENGTHZERO,//エラーメッセージNO
			m_feature_name,//フィーチャ名
			3,//メッセージの引数の個数
			m_InstanceID,//インスタンスID
			length,//線分の長さ
			m_feature_name//メッセージ用フィーチャ名
			);
		return SXFLENGTHZERO;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								作成日：2000.3.27

	１．機能概要
		線分フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Line_Struct IN_line_str);
	引数:	型					引数名				内容
			Line_Struct			IN_line_str			線分構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFLine_checkC::attr_rule_check(Line_Struct* IN_line_str)
{
	//テーブルルールチェック
	m_layer = IN_line_str->layer;
	m_color = IN_line_str->color;
	m_type = IN_line_str->type;
	m_line_width = IN_line_str->line_width;
	int ret = LineFeature_Check();
	return ret;
}
