/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	複合図形配置フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFSfigloc_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFSfigloc_checkC::SXFSfigloc_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSfigloc_checkC::SXFSfigloc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFSfigloc_checkC::~SXFSfigloc_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSfigloc_checkC::~SXFSfigloc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合図形配置フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Sfigloc_Struct IN_sfigloc_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID)

	引数:	型					引数名				内容
			Sfigloc_Struct		IN_sfigloc_str		複合図形配置構造体
		    SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSfigloc_checkC::Feature_rule_check(Sfigloc_Struct* IN_sfigloc_str,
										  SXFTableManagerC* IN_TableManager,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SFIG_LOCATE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_sfigloc_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_sfigloc_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合図形配置フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Sfigloc_Struct IN_sfigloc_str);

	引数:	型					引数名			内容
			Sfigloc_Struct		IN_sfigloc_str	複合図形配置構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSfigloc_checkC::attr_rule_check(Sfigloc_Struct* IN_sfigloc_str)
{
	m_layer = IN_sfigloc_str->layer;
	int ret = SfiglocFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合図形配置フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Sfigloc_Struct IN_sfigloc_str);

	引数:	型					引数名			内容
			Sfigloc_Struct		IN_sfigloc_str	複合図形配置構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSfigloc_checkC::str_rule_check(Sfigloc_Struct* IN_sfigloc_str)
{
	//回転角が0度から360度でないとき
	if (angle_check(IN_sfigloc_str->angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//尺度が０以下または１０の１５乗以上のとき
	if (double_check(IN_sfigloc_str->ratio_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->ratio_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//尺度が０以下または１０の１５乗以上のとき
	if (double_check(IN_sfigloc_str->ratio_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->ratio_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	return 0;
}
