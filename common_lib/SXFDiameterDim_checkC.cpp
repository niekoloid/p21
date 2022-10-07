/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	直径寸法フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFDiameterDim_checkC.h"
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
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFDiameterDim_checkC::SXFDiameterDim_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFDiameterDim_checkC::SXFDiameterDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFDiameterDim_checkC::~SXFDiameterDim_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFDiameterDim_checkC::~SXFDiameterDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		直径寸法フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(DiameterDim_Struct IN_diameterdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	引数:	型					引数名			内容
			DiameterDim_Struct	IN_diameterdim_str	直径寸法構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト		
			CString				IN_InstanceID		インスタンスID
			SXFComInfoC*		IN_Info				共通情報

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFDiameterDim_checkC::Feature_rule_check(DiameterDim_Struct* IN_diameterdim_str,
											  SXFTableManagerC* IN_TableManager,
											  CString IN_InstanceID,
											  SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_DIAMETER_DIM;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret  = attr_rule_check(IN_diameterdim_str) ;
	if (ret < 0)
		return ret ;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_diameterdim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		直径寸法フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(DiameterDim_Struct IN_diameterdim_str);

	引数:	型					引数名				内容
			DiameterDim_Struct	IN_diameterdim_str	直径寸法構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFDiameterDim_checkC::attr_rule_check(DiameterDim_Struct* IN_diameterdim_str)
{
	m_layer = IN_diameterdim_str->layer ;
	m_color = IN_diameterdim_str->color ;
	m_type = IN_diameterdim_str->type ;
	m_line_width = IN_diameterdim_str->line_width ;
	m_font = IN_diameterdim_str->font ;
	
	int ret = DimFeature_Check(IN_diameterdim_str->flg) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								作成日：2000.4.3

	１．機能概要
		直径寸法フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(DiameterDim_Struct IN_diameterdim_str)

	引数:	型					引数名				内容
			DiameterDim_Struct	IN_diameterdim_str	直径寸法構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFDiameterDim_checkC::str_rule_check(DiameterDim_Struct* IN_diameterdim_str)
{
	int ret = 0 ;
//寸法線
	Line_Struct Line_str;

	Line_str.color = IN_diameterdim_str->color ;
	Line_str.end_x = IN_diameterdim_str->sun_x1 ;
	Line_str.end_y = IN_diameterdim_str->sun_y1 ;
	Line_str.layer = IN_diameterdim_str->layer ;
	Line_str.line_width = IN_diameterdim_str->line_width ;
	Line_str.start_x = IN_diameterdim_str->sun_x2 ;
	Line_str.start_y = IN_diameterdim_str->sun_y2 ;
	Line_str.type = IN_diameterdim_str->type ;

	ret = linestr_rule_check(&Line_str) ;
	if (ret < 0)
		return ret ;

//矢印１
	ret = arr_check(IN_diameterdim_str->arr1_code1,
					IN_diameterdim_str->arr1_code2,
					IN_diameterdim_str->arr1_r) ;
	if (ret < 0) 
		return ret ;

//矢印２
	ret = arr_check(IN_diameterdim_str->arr2_code1,
					IN_diameterdim_str->arr2_code2,
					IN_diameterdim_str->arr2_r) ;
	if (ret < 0) 
		return ret ;

//文字要素
	Text_Struct Text_str;
	int flg;

	flg = IN_diameterdim_str->flg ;
	Text_str.layer = IN_diameterdim_str->layer ;
	Text_str.color = IN_diameterdim_str->color ;
	Text_str.font = IN_diameterdim_str->font ;
	Text_str.text_x = IN_diameterdim_str->text_x ;
	Text_str.text_y = IN_diameterdim_str->text_y ;
	Text_str.height = IN_diameterdim_str->height ;
	Text_str.width = IN_diameterdim_str->width ;
	Text_str.spc = IN_diameterdim_str->spc ;
	Text_str.angle = IN_diameterdim_str->angle ;
	Text_str.slant = IN_diameterdim_str->slant ;
	Text_str.b_pnt = IN_diameterdim_str->b_pnt ;
	Text_str.direct = IN_diameterdim_str->direct ;

	//寸法値の有無フラグが0または1ではないとき
	if ((flg < 0) || (flg > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									flg,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (flg != 0){
		ret	= textstr_rule_check (&Text_str) ;
		if (ret < 0)
			return ret ;
	}
	return 0 ;

}
