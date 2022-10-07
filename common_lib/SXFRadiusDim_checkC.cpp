/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	半径寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFRadiusDim_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFRadiusDim_checkC::SXFRadiusDim_checkC()		
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFRadiusDim_checkC::SXFRadiusDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFRadiusDim_checkC::~SXFRadiusDim_checkC()		
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFRadiusDim_checkC::~SXFRadiusDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		半径寸法フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(RadiusDim_Struct IN_radiusdim_str)

	引数:	型					引数名				内容
			RadiusDim_Struct	IN_radiusdim_str	半径寸法構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFRadiusDim_checkC::attr_rule_check(RadiusDim_Struct* IN_radiusdim_str)
{
	m_layer = IN_radiusdim_str->layer ;
	m_color = IN_radiusdim_str->color ;
	m_type = IN_radiusdim_str->type ;
	m_line_width = IN_radiusdim_str->line_width ;
	m_font = IN_radiusdim_str->font ;

	int ret = DimFeature_Check(IN_radiusdim_str->flg) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		半径寸法フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(RadiusDim_Struct IN_radiusdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	引数:	型				引数名			内容
			RadiusDim_Struct	IN_radiusdim_str	半径寸法構造体
			SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			CString				IN_InstanceID		インスタンスID
			SXFComInfoC*		IN_Info				共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFRadiusDim_checkC::Feature_rule_check(RadiusDim_Struct* IN_radiusdim_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID,
											SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = "RADIUS_DIM";
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret  = attr_rule_check(IN_radiusdim_str) ;
	if (ret < 0)
		return ret ;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_radiusdim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		半径寸法フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(RadiusDim_Struct IN_radiusdim_str);

	引数:	型					引数名				内容
			RadiusDim_Struct	IN_radiusdim_str	半径寸法構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFRadiusDim_checkC::str_rule_check(RadiusDim_Struct* IN_radiusdim_str)
{
	int ret = 0 ;
//寸法線
	Line_Struct Line_str;

	Line_str.color = IN_radiusdim_str->color ;
	Line_str.end_x = IN_radiusdim_str->sun_x1 ;
	Line_str.end_y = IN_radiusdim_str->sun_y1 ;
	Line_str.layer = IN_radiusdim_str->layer ;
	Line_str.line_width = IN_radiusdim_str->line_width ;
	Line_str.start_x = IN_radiusdim_str->sun_x2 ;
	Line_str.start_y = IN_radiusdim_str->sun_y2 ;
	Line_str.type = IN_radiusdim_str->type ;

	ret = linestr_rule_check(&Line_str);
	if (ret < 0)
		return ret ;
//矢印
	ret = arr_check(IN_radiusdim_str->arr_code1,
					IN_radiusdim_str->arr_code2,
					IN_radiusdim_str->arr_r) ;
	if (ret < 0) 
		return ret ;

//文字要素
	Text_Struct Text_str;

	Text_str.layer = IN_radiusdim_str->layer ;
	Text_str.color = IN_radiusdim_str->color ;
	Text_str.font = IN_radiusdim_str->font ;
	Text_str.text_x = IN_radiusdim_str->text_x ;
	Text_str.text_y = IN_radiusdim_str->text_y ;
	Text_str.height = IN_radiusdim_str->height ;
	Text_str.width = IN_radiusdim_str->width ;
	Text_str.spc = IN_radiusdim_str->spc ;
	Text_str.angle = IN_radiusdim_str->angle ;
	Text_str.slant = IN_radiusdim_str->slant ;
	Text_str.b_pnt = IN_radiusdim_str->b_pnt ;
	Text_str.direct = IN_radiusdim_str->direct ;

	//寸法値の有無フラグが0または1ではないとき
	if ((IN_radiusdim_str->flg < 0) || (IN_radiusdim_str->flg > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_radiusdim_str->flg,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_radiusdim_str->flg != 0){
		ret	= textstr_rule_check (&Text_str);
		if (ret < 0)
			return ret ;
	}
	return 0 ;

}
