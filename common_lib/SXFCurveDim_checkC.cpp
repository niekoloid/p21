/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．クラス概要
	弧長寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/

#include "stdafx.h"
#include "SXFCurveDim_checkC.h"
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
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFCurveDim_checkC::SXFCurveDim_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
SXFCurveDim_checkC::SXFCurveDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFCurveDim_checkC::~SXFCurveDim_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
SXFCurveDim_checkC::~SXFCurveDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．機能概要
		弧長寸法フィーチャのルールチェックを行う

	２．インターフェース
	int Feature_rule_check(CurveDim_Struct IN_curvedim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	引数:	型				引数名			内容
			CurveDim_Struct		IN_curvedim_str		弧長寸法構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト
			CString				IN_InstanceID		インスタンスID
			SXFComInfoC*		IN_Info				共通情報

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFCurveDim_checkC::Feature_rule_check(CurveDim_Struct* IN_curvedim_str,
											 SXFTableManagerC* IN_TableManager,
											 CString IN_InstanceID,
											 SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_CURVE_DIM;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret  = attr_rule_check(IN_curvedim_str) ;
	if (ret < 0)
		return ret ;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_curvedim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．機能概要
		弧長寸法フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(CurveDim_Struct IN_curvedim_str);

	引数:	型					引数名				内容
			CurveDim_Struct		IN_curvedim_str		弧長寸法構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFCurveDim_checkC::attr_rule_check(CurveDim_Struct* IN_curvedim_str)
{
	m_layer = IN_curvedim_str->layer ;
	m_color = IN_curvedim_str->color ;
	m_type = IN_curvedim_str->type ;
	m_line_width = IN_curvedim_str->line_width ;
	m_font = IN_curvedim_str->font ;

	int ret = DimFeature_Check(IN_curvedim_str->flg4) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDim_checkC.cpp								作成日：2007.1.29

	１．機能概要
		弧長寸法フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(CurveDim_Struct IN_curvedim_str)

	引数:	型					引数名				内容
			CurveDim_Struct		IN_curvedim_str		弧長寸法構造体
	
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFCurveDim_checkC::str_rule_check(CurveDim_Struct* IN_curvedim_str)
{
	int ret;
//寸法線
	Arc_Struct Arc_str;

	Arc_str.layer = IN_curvedim_str->layer;
	Arc_str.color = IN_curvedim_str->color;
	Arc_str.type = IN_curvedim_str->type;
	Arc_str.line_width = IN_curvedim_str->line_width;
	Arc_str.center_x = IN_curvedim_str->sun_x;
	Arc_str.center_y = IN_curvedim_str->sun_y;
	Arc_str.radius = IN_curvedim_str->sun_radius;
	Arc_str.direction = 1;
	Arc_str.start_angle = IN_curvedim_str->sun_angle0;
	Arc_str.end_angle = IN_curvedim_str->sun_angle1;
	ret = arcstr_rule_check(&Arc_str, false);
	if (ret < 0)
		return ret;
//補助線１
	ret = proj_check(IN_curvedim_str->flg2,
					IN_curvedim_str->ho1_x0,
					IN_curvedim_str->ho1_y0,
					IN_curvedim_str->ho1_x1,
					IN_curvedim_str->ho1_y1,
					IN_curvedim_str->ho1_x2,
					IN_curvedim_str->ho1_y2) ;
	if (ret < 0) 
		return ret ;

//補助線２
	ret = proj_check(IN_curvedim_str->flg3,
					IN_curvedim_str->ho2_x0,
					IN_curvedim_str->ho2_y0,
					IN_curvedim_str->ho2_x1,
					IN_curvedim_str->ho2_y1,
					IN_curvedim_str->ho2_x2,
					IN_curvedim_str->ho2_y2) ;
	if (ret < 0) 
		return ret ;
//矢印１
	ret = arr_check(IN_curvedim_str->arr1_code1,
					IN_curvedim_str->arr1_code2,
					IN_curvedim_str->arr1_r) ;
	if (ret < 0) 
		return ret ;

//矢印２
	ret = arr_check(IN_curvedim_str->arr2_code1,
					IN_curvedim_str->arr2_code2,
					IN_curvedim_str->arr2_r) ;
	if (ret < 0) 
		return ret ;

//文字要素
	Text_Struct Text_str;

	Text_str.layer = IN_curvedim_str->layer ;
	Text_str.color = IN_curvedim_str->color ;
	Text_str.font = IN_curvedim_str->font ;
	Text_str.text_x = IN_curvedim_str->text_x ;
	Text_str.text_y = IN_curvedim_str->text_y ;
	Text_str.height = IN_curvedim_str->height ;
	Text_str.width = IN_curvedim_str->width ;
	Text_str.spc = IN_curvedim_str->spc ;
	Text_str.angle = IN_curvedim_str->angle ;
	Text_str.slant = IN_curvedim_str->slant ;
	Text_str.b_pnt = IN_curvedim_str->b_pnt ;
	Text_str.direct = IN_curvedim_str->direct ;

	//寸法値の有無フラグが0または1ではないとき
	if ((IN_curvedim_str->flg4 < 0) || (IN_curvedim_str->flg4 > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_curvedim_str->flg4,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_curvedim_str->flg4 != 0){
		ret	= textstr_rule_check (&Text_str);
		if (ret < 0)
			return ret ;
	}
	return 0 ;

}
