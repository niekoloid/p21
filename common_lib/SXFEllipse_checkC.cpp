/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	楕円フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFEllipse_checkC.h"
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
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFEllipse_checkC::SXFEllipse_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFEllipse_checkC::SXFEllipse_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFEllipse_checkC::~SXFEllipse_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFEllipse_checkC::~SXFEllipse_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Ellipse_Struct IN_ellipse_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	引数:	型					引数名				内容
			Ellipse_Struct		IN_ellipse_str		楕円構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_checkC::Feature_rule_check(Ellipse_Struct* IN_ellipse_str,
										  SXFTableManagerC* IN_TableManager,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_ELLIPSE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_ellipse_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_ellipse_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円フィーチャのルールチェック

	２．インターフェース
	int attr_rule_check(Ellipse_Struct IN_ellipse_str);

	引数:	型					引数名				内容
			Ellipse_Struct		IN_ellipse_str		楕円構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_checkC::attr_rule_check(Ellipse_Struct* IN_ellipse_str)
{
	m_layer = IN_ellipse_str->layer ;
	m_color = IN_ellipse_str->color ;
	m_type = IN_ellipse_str->type ;
	m_line_width = IN_ellipse_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Ellipse_Struct IN_ellipse_str);
	
	引数:	型					引数名				内容
			Ellipse_Struct		IN_ellipse_str		楕円構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_checkC::str_rule_check(Ellipse_Struct* IN_ellipse_str)
{
	//X方向半径が０以下の時
	if (double_check(IN_ellipse_str->radius_x) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->radius_x,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}	
	//Y方向半径が０以下の時
	if (double_check(IN_ellipse_str->radius_y) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->radius_y,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}	
	//回転角が０度から360度でないとき
	if (angle_check(IN_ellipse_str->rotation_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->rotation_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	return 0 ;
}
