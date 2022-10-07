/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．クラス概要
	クロソイドフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/

#include "stdafx.h"
#include <math.h>
#include "SXFClothoid_checkC.h"
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
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFClothoid_checkC::SXFClothoid_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
SXFClothoid_checkC::SXFClothoid_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFClothoid_checkC::~SXFClothoid_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
SXFClothoid_checkC::~SXFClothoid_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．機能概要
		クロソイドフィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Clothoid_Struct IN_clothoid_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)

	引数:	型					引数名				内容
			Clothoid_Struct		IN_clothoid_str		スプライン構造体
			SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			int					IN_AssemType		アセンブリ型
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFClothoid_checkC::Feature_rule_check(Clothoid_Struct* IN_clothoid_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID,
										 SXFComInfoC* IN_Info)
{
	int ret;
	m_feature_name = DEF_CLOTHOID;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_clothoid_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = clothoidstr_rule_check(IN_clothoid_str);
	if (ret < 0)
		return ret;
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．機能概要
		クロソイドフィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Clothoid_Struct IN_clothoid_str);

	引数:	型				引数名				内容
			Clothoid_Struct	IN_clothoid_str		クロソイド構造体
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFClothoid_checkC::attr_rule_check(Clothoid_Struct* IN_clothoid_str)
{
	m_layer = IN_clothoid_str->layer ;
	m_color = IN_clothoid_str->color ;
	m_type = IN_clothoid_str->type ;
	m_line_width = IN_clothoid_str->line_width ;
	int ret = LineFeature_Check();
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								作成日：2007.1.29

	１．機能概要
		クロソイドフィーチャの属性以外のルールチェック

	２．インターフェース
	int clothoidstr_rule_check(Clothoid_Struct IN_clothoid_str)

	引数:	型						引数名				内容
			Clothoid_Struct			IN_clothoid_str		クロソイド構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
int SXFClothoid_checkC::clothoidstr_rule_check(Clothoid_Struct *IN_clothoid_str)
{
	///////////////////////////////////////
	//許容誤差の取得
	///////////////////////////////////////
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	//クロソイドパラメータが規定範囲外の時
	if (double_check(IN_clothoid_str->parameter) < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDPARA,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->parameter,
									m_feature_name) ;
		return SXFCLOTHOIDPARA ;
	}

	//向きフラグが０または１以外のとき
	if ((IN_clothoid_str->direction < 0) || (IN_clothoid_str->direction > 1)){
		SXFErrorMsgC::RecordError(SXFDIRECTIONERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->direction,
									m_feature_name);
		return SXFDIRECTIONERROR;
	}

	//回転角が０度から360度でないとき
	if (angle_check(IN_clothoid_str->angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->angle,
									m_feature_name);
		return SXFERRORANGLE;
	}

	//開始曲線長と終了曲線長が等しいとき
	double	length = fabs(IN_clothoid_str->end_length - IN_clothoid_str->start_length);
	if (length < eps){
		SXFErrorMsgC::RecordError(SXFLENGTHZERO,
									m_feature_name,
									3,
									m_InstanceID,
									length,
									m_feature_name);
		return SXFLENGTHZERO;
	}

	//開始曲線長が０未満のとき
	if (IN_clothoid_str->start_length < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDLEN,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->start_length,
									m_feature_name);
		return SXFCLOTHOIDLEN;
	}
	//終了曲線長が０未満のとき
	if (IN_clothoid_str->end_length < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDLEN,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->end_length,
									m_feature_name);
		return SXFCLOTHOIDLEN;
	}

	return 0 ;
}
