/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．クラス概要
		定義テーブル要素のルールチェック

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFTableCheckC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFTableCheckC::SXFTableCheckC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFTableCheckC::SXFTableCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFTableCheckC::~SXFTableCheckC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFTableCheckC::~SXFTableCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		文字要素の属性ルールチェック

	２．インターフェース
		int	SXFTableCheckC::TextFeature_Check()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：0
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::TextFeature_Check()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Font
	error_code = FontCheck();
	if (error_code < 0)
		return error_code;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		線分の属性ルールチェック

	２．インターフェース
		int	SXFTableCheckC::LineFeature_Check()
		
	引数	：	型			引数名			内容
				なし
				
	復帰値	正常時：0
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::LineFeature_Check()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		レイヤのルールチェック

	２．インターフェース
		int	SXFTableCheckC::LayerCheck()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::LayerCheck()
{
	if (m_TableManager->GetID(1,m_layer) < 0){
		SXFErrorMsgC::RecordError(SXFEUNSETLAYER,
									m_feature_name,
									3,
									m_InstanceID,
									m_layer,
									m_feature_name);
		return SXFEUNSETLAYER;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		色のルールチェック

	２．インターフェース
		int	SXFTableCheckC::ColorCheck()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::ColorCheck()
{
	int table_type;
	if (m_color < 17)
		table_type = 2;
	else
		table_type = 3;
	if (m_TableManager->GetID(table_type,m_color) < 0){
		SXFErrorMsgC::RecordError(SXFERRORCOLOUR,
									m_feature_name,
									3,
									m_InstanceID,
									m_color,
									m_feature_name);
		return SXFERRORCOLOUR;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		線種のルールチェック

	２．インターフェース
		int	SXFTableCheckC::TypeCheck()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::TypeCheck()
{
	int table_type;
	if (m_type < 17)
		table_type = 4;
	else
		table_type = 5;
	if (m_TableManager->GetID(table_type,m_type) < 0){
		SXFErrorMsgC::RecordError(SXFERRORFONT,
									m_feature_name,
									3,
									m_InstanceID,
									m_type,
									m_feature_name);
		return SXFERRORFONT;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		線幅のルールチェック

	２．インターフェース
		int	SXFTableCheckC::WidthCheck()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::WidthCheck()
{
	if (m_TableManager->GetID(6,m_line_width) < 0){
		SXFErrorMsgC::RecordError(SXFERRORWIDTH,
									m_feature_name,
									3,
									m_InstanceID,
									m_line_width,
									m_feature_name);
		return SXFERRORWIDTH;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		文字フォントのルールチェック

	２．インターフェース
		int	SXFTableCheckC::FontCheck()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::FontCheck()
{
	if (m_TableManager->GetID(7,m_font) < 0){
		SXFErrorMsgC::RecordError(SXFTEXTFONTERROR,
									m_feature_name,
									3,
									m_InstanceID,
									m_font,
									m_feature_name);
		return SXFTEXTFONTERROR;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		複合曲線の属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::CompCurveFeature_Check()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::CompCurveFeature_Check()
{
	int error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		寸法線の属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::DimFeature_Check(int IN_TextFlag)
		
	引数	：	型			引数名			内容
				int			IN_TextFlag		寸法値有無フラグ(0:無1:有)

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::DimFeature_Check(int IN_TextFlag)
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	//Font
	if (IN_TextFlag == 1){
		error_code = FontCheck();
		if (error_code < 0)
			return error_code;
	}
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		点マーカの属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::PointMarkerFeature_CheckC()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::PointMarkerFeature_CheckC()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	return 0;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		既定義シンボルの属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::ExSymbol_Check(int IN_ColorFlag)
		
	引数	：	型			引数名			内容
				int			IN_ColorFlag	色コードフラグ(0:無効1:有効)

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::ExSymbol_Check( int IN_ColorFlag)
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	if (IN_ColorFlag != 0){
		error_code = ColorCheck();
		if (error_code < 0)
			return error_code;
	}
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		複合図形配置の属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::SfiglocFeature_Check()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::SfiglocFeature_Check()
{
	//Layer
	if (m_layer != 0){
		int layer_error = LayerCheck();
		if (layer_error < 0)
			return layer_error;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								作成日：2000.4.17

	１．機能概要
		既定義ハッチングの属性のルールチェック

	２．インターフェース
		int	SXFTableCheckC::ExHatchFeature_Check()
		
	引数	：	型			引数名			内容
				なし

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableCheckC::ExHatchFeature_Check()
{
	//Layer
	int layer_error = LayerCheck();
	if (layer_error < 0)
		return layer_error;
	return 0;

}
