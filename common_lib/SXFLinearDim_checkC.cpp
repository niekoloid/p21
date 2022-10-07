/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp					作成日：2000.03.29

	１．クラス概要
	直線寸法フィーチャのルールチェックを行うクラス
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFLinearDim_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		コンストラクタ
		
	２．インターフェイス
		void 	SXFLinearDim_checkC::SXFLinearDim_checkC()
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFLinearDim_checkC::SXFLinearDim_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		デストラクタ
		
	２．インターフェイス
		void 	SXFLinearDim_checkC::~SXFLinearDim_checkC ()
			
	引数	：	型						引数名					内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFLinearDim_checkC::~SXFLinearDim_checkC ()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		直線寸法フィーチャのルールチェック
		
	２．インターフェイス
		int		SXFLinearDim_checkC::Feature_rule_check(
								LinearDim_Struct IN_LinearDim_str,
								SXFTableManagerC* IN_TableManager,
								CString IN_InstanceID,
								SXFComInfoC* IN_Info)
		
	引数	：	型						引数名		内容
			LinearDim_Struct	IN_LinearDim_str	直線寸法フィーチャの構造体		
			SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			CString				IN_InstanceID		インスタンスID
			SXFComInfoC*		IN_Info				共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFLinearDim_checkC::Feature_rule_check(LinearDim_Struct* IN_LinearDim_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID,
											SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_LINEAR_DIM;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret  = attr_rule_check(IN_LinearDim_str) ;
	if (ret < 0)
		return ret ;
	/** 属性以外のルールチェック **/
	ret = lineardim_check(IN_LinearDim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		直線寸法フィーチャの属性のルールチェック
		
	２．インターフェイス
		int	 SXFLinearDim_checkC::attr_rule_check (
					LinearDim_Struct IN_LinearDim_str)
		
	引数	：	型				引数名				内容
			LinearDim_Struct	IN_LinearDim_str	構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFLinearDim_checkC::attr_rule_check (LinearDim_Struct* IN_LinearDim_str)
{
	m_layer = IN_LinearDim_str->layer ;
	m_color = IN_LinearDim_str->color ;
	m_type = IN_LinearDim_str->type ;
	m_line_width = IN_LinearDim_str->line_width ;
	m_font = IN_LinearDim_str->font ;
	
	int ret = DimFeature_Check(IN_LinearDim_str->flg4) ;
	return ret ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		直線寸法フィーチャの属性以外のルールチェック
		
	２．インターフェイス
		int 	SXFLinearDim_checkC::lineardim_check (
					LinearDim_Struct IN_LinearDim_str)

	引数	：	型				引数名				内容
			LinearDim_Struct	IN_LinearDim_str	構造体
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFLinearDim_checkC::lineardim_check (LinearDim_Struct* IN_LinearDim_str)
{
	int ret = 0 ;
//寸法線
	Line_Struct Line_str ;

	Line_str.layer = IN_LinearDim_str->layer ;
	Line_str.color = IN_LinearDim_str->color ;
	Line_str.type = IN_LinearDim_str->type ;
	Line_str.line_width = IN_LinearDim_str->line_width ;
	Line_str.start_x = IN_LinearDim_str->sun_x1 ;
	Line_str.start_y = IN_LinearDim_str->sun_y1 ;
	Line_str.end_x = IN_LinearDim_str->sun_x2 ;
	Line_str.end_y = IN_LinearDim_str->sun_y2 ;
	ret = linestr_rule_check(&Line_str) ;
	if (ret < 0)
		return ret ;
//補助線１
	ret = proj_check(IN_LinearDim_str->flg2,
					IN_LinearDim_str->ho1_x0,
					IN_LinearDim_str->ho1_y0,
					IN_LinearDim_str->ho1_x1,
					IN_LinearDim_str->ho1_y1,
					IN_LinearDim_str->ho1_x2,
					IN_LinearDim_str->ho1_y2) ;
	if (ret < 0) 
		return ret ;

//補助線２
	ret = proj_check(IN_LinearDim_str->flg3,
					IN_LinearDim_str->ho2_x0,
					IN_LinearDim_str->ho2_y0,
					IN_LinearDim_str->ho2_x1,
					IN_LinearDim_str->ho2_y1,
					IN_LinearDim_str->ho2_x2,
					IN_LinearDim_str->ho2_y2) ;
	if (ret < 0) 
		return ret ;
//矢印１
	ret = arr_check(IN_LinearDim_str->arr1_code1,
					IN_LinearDim_str->arr1_code2,
					IN_LinearDim_str->arr1_r) ;
	if (ret < 0) 
		return ret ;

//矢印２
	ret = arr_check(IN_LinearDim_str->arr2_code1,
					IN_LinearDim_str->arr2_code2,
					IN_LinearDim_str->arr2_r) ;
	if (ret < 0) 
		return ret ;

//文字要素
	//寸法値の有無フラグが0または1ではないとき
	if ((IN_LinearDim_str->flg4 < 0) 
			|| (IN_LinearDim_str->flg4 > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_LinearDim_str->flg4,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_LinearDim_str->flg4 != 0){
		Text_Struct Text_str ;
		Text_str.layer = IN_LinearDim_str->layer ;
		Text_str.color = IN_LinearDim_str->color ;
		Text_str.font = IN_LinearDim_str->font ;
		Text_str.text_x = IN_LinearDim_str->text_x ;
		Text_str.text_y = IN_LinearDim_str->text_y ;
		Text_str.height = IN_LinearDim_str->height ;
		Text_str.width = IN_LinearDim_str->width ;
		Text_str.spc = IN_LinearDim_str->spc ;
		Text_str.angle = IN_LinearDim_str->angle ;
		Text_str.slant = IN_LinearDim_str->slant ;
		Text_str.b_pnt = IN_LinearDim_str->b_pnt ;
		Text_str.direct = IN_LinearDim_str->direct ;
		ret	= textstr_rule_check (&Text_str) ;
		if (ret < 0)
			return ret ;
	}
	return 0 ;
}
