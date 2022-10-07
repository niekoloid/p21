/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	楕円弧フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include <math.h>
#include "SXFEllipse_Arc_checkC.h"
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
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFEllipse_Arc_checkC::SXFEllipse_Arc_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFEllipse_Arc_checkC::SXFEllipse_Arc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFEllipse_Arc_checkC::~SXFEllipse_Arc_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFEllipse_Arc_checkC::~SXFEllipse_Arc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円弧フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	引数:	型				引数名			内容
			Ellipse_Arc_Struct	IN_ellipse_arc_str	楕円弧構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト
			int					IN_AssemType		アセンブリ型
			CString				IN_InstanceID		インスタンスID
			SXFComInfoC*		IN_Info				共通情報

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_Arc_checkC::Feature_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str,
											  SXFTableManagerC* IN_TableManager,
											  int IN_AssemType,
											  CString IN_InstanceID,
											  SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_ELLIPSE_ARC;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 複合曲線上以外の要素のとき **/
	if (IN_AssemType != 3){
		/** 属性のルールチェック **/
		ret  = attr_rule_check(IN_ellipse_arc_str) ;
		if (ret < 0)
			return ret ;
	}
	/** 属性以外のルールチェック **/
	ret  = str_rule_check(IN_ellipse_arc_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円弧フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str);
	
	引数:	型					引数名				内容
			Ellipse_Arc_Struct	IN_ellipse_arc_str	楕円弧構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_Arc_checkC::attr_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str)
{
	m_layer = IN_ellipse_arc_str->layer ;
	m_color = IN_ellipse_arc_str->color ;
	m_type = IN_ellipse_arc_str->type ;
	m_line_width = IN_ellipse_arc_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		楕円弧フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str)

	引数:	型					引数名				内容
			Ellipse_Arc_Struct	IN_ellipse_arc_str	楕円弧構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFEllipse_Arc_checkC::str_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str)
{
	///////////////////////////////////////
	//許容誤差の取得
	///////////////////////////////////////
	double eps, angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	//X方向半径が０以下の時
	if (double_check(IN_ellipse_arc_str->radius_x) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->radius_x,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	//Y方向半径が０以下の時
	if (double_check(IN_ellipse_arc_str->radius_y) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->radius_y,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	//向きフラグが０または１以外のとき
	if ((IN_ellipse_arc_str->direction < 0) || (IN_ellipse_arc_str->direction > 1)){
		SXFErrorMsgC::RecordError(SXFDIRECTIONERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->direction,
									m_feature_name);
		return SXFDIRECTIONERROR;
	}
	//回転角が０度から360度でないとき
	if (angle_check(IN_ellipse_arc_str->rotation_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->rotation_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//始角と終角が等しいとき
	if (fabs(IN_ellipse_arc_str->end_angle - IN_ellipse_arc_str->start_angle) < angle_eps){
		SXFErrorMsgC::RecordError(SXFSAMEANGLE,
									m_feature_name,
									4,
									m_InstanceID,
									IN_ellipse_arc_str->start_angle,
									IN_ellipse_arc_str->end_angle,
									m_feature_name);
		return SXFSAMEANGLE;
	}
	//始角が０度から360度でないとき
	if (angle_check(IN_ellipse_arc_str->start_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->start_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//終角が0度から360度でないとき
	if (angle_check(IN_ellipse_arc_str->end_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->end_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	return 0 ;
}
