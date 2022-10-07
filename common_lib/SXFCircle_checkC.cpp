/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp					作成日：2000.03.29

	１．クラス概要
	円フィーチャのルールチェックを行うクラス
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFCircle_checkC.h"
#include "SXFErrorMsgC.h"
#include "max.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp					 	作成日：2000.03.29

	１．機能概要 
		コンストラクタ
		
	２．インターフェイス
		void	 SXFCircle_checkC::SXFCircle_checkC()
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFCircle_checkC::SXFCircle_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						作成日：2000.03.29

	１．機能概要
		デストラクタ
		
	２．インターフェイス
		void 	SXFCircle_checkC::~SXFCircle_checkC ()
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFCircle_checkC::~SXFCircle_checkC ()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						作成日：2000.03.29

	１．機能概要
		円フィーチャの属性のルールチェック
		
	２．インターフェイス
		int 	SXFCircle_checkC::attr_rule_check (Circle_Struct IN_circle_str)
		
	引数：	型				引数名				内容
			Circle_Struct	IN_circle_str		円の構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFCircle_checkC::attr_rule_check (Circle_Struct* IN_circle_str)
{
	m_layer = IN_circle_str->layer ;
	m_color = IN_circle_str->color ;
	m_type = IN_circle_str->type ;
	m_line_width = IN_circle_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						作成日：2000.03.29

	１．機能概要
		円フィーチャの属性以外のルールチェック
		
	２．インターフェイス
		int SXFCircle_checkC::circlestr_rule_check (Circle_Struct IN_circle_str)
		
	引数：	型				引数名				内容
			Circle_Struct	IN_circle_str		円の構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFCircle_checkC::circlestr_rule_check (Circle_Struct* IN_circle_str)
{
	//半径が０以下の時
	if (double_check(IN_circle_str->radius) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_circle_str->radius,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	return 0 ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						作成日：2000.03.29

	１．機能概要
		円フィーチャのルールチェック
		
	２．インターフェイス
		int SXFCircle_checkC::Feature_rule_check(
										Circle_Struct IN_circle_str,
										SXFTableManagerC* IN_TableManager,
										CString IN_InstanceID)
		
	引数：	型					引数名				内容
			Circle_Struct		IN_circle_str		円の構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFCircle_checkC::Feature_rule_check(Circle_Struct* IN_circle_str,
										 SXFTableManagerC* IN_TableManager,
										 CString IN_InstanceID)
{
	int ret ;

	m_feature_name = DEF_CIRCLE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 属性のルールチェック **/
	ret  = attr_rule_check(IN_circle_str) ;
	if (ret < 0)
		return ret ;
	/** 属性以外のルールチェック **/
	ret  = circlestr_rule_check(IN_circle_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;
}
