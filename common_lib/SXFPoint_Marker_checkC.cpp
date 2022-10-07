/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．クラス概要
	点マーカフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFPoint_Marker_checkC.h"
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
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFPoint_Marker_checkC::SXFPoint_Marker_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFPoint_Marker_checkC::SXFPoint_Marker_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFPoint_Marker_checkC::~SXFPoint_Marker_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFPoint_Marker_checkC::~SXFPoint_Marker_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．機能概要
		点マーカフィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Point_Marker_Struct IN_point_marker_str,
						   SXFTableManagerC* IN_TableManager,
						   CString IN_InstanceID)

	引数:	型					引数名				内容
			Point_Marker_Struct	IN_point_marker_str	点マーカ構造体
  		    SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
		    CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFPoint_Marker_checkC::Feature_rule_check(Point_Marker_Struct* IN_point_marker_str,
											   SXFTableManagerC* IN_TableManager,
											   CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_POINT_MARKER;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_point_marker_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_point_marker_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．機能概要
		点マーカフィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Point_Marker_Struct IN_point_marker_str)

	引数:	型					引数名				内容
			Point_Marker_Struct	IN_point_marker_str	点マーカ構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFPoint_Marker_checkC::str_rule_check(Point_Marker_Struct* IN_point_marker_str)
{
	//マーカコードが１から７でないとき
	if ((IN_point_marker_str->marker_code < 1) 
		|| (IN_point_marker_str->marker_code > 7)){
		SXFErrorMsgC::RecordError(SXFMARKERERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->marker_code,
									m_feature_name);
		return SXFMARKERERROR;
	}
	//回転角が0度から360度でないとき
	if (angle_check(IN_point_marker_str->rotate_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->rotate_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//尺度が０以下のとき
	if (double_check(IN_point_marker_str->scale) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->scale,
									m_feature_name);
		return SXFERRORSCALE;
	}

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								作成日：2000.3.27

	１．機能概要
		点マーカフィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Point_Marker_Struct IN_point_marker_str);

	引数:	型					引数名				内容
			Point_Marker_Struct	IN_point_marker_str	点マーカ構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFPoint_Marker_checkC::attr_rule_check(Point_Marker_Struct* IN_point_marker_str)
{
	//属性ルールチェック
	m_layer = IN_point_marker_str->layer;
	m_color = IN_point_marker_str->color;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}
