/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	レイヤフィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFLayer_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFLayer_checkC::SXFLayer_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFLayer_checkC::SXFLayer_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFLayer_checkC::~SXFLayer_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFLayer_checkC::~SXFLayer_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								作成日：2000.4.3

	１．機能概要
		レイヤフィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Layer_Struct IN_layer_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo)

	引数:	型					引数名				内容
			Layer_Struct		IN_layer_str		用紙構造体
			SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			SXFComInfoC*		IN_ComInfo			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFLayer_checkC::Feature_rule_check(Layer_Struct* IN_layer_str,
										SXFTableManagerC* IN_TableManager,
										SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_LAYER;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//Read or Write フラグ
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Readではすでにﾁｪｯｸ済み)
	if (RW_Flag == 1){
		m_UniqueName = IN_layer_str->name;
		ret = NameUniqueCheck(1);
		if (ret < 0)
			return ret;
	}

	ret = str_rule_check(IN_layer_str);
	if (ret < 0)
		return ret;
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								作成日：2000.4.3

	１．機能概要
		レイヤフィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Layer_Struct IN_layer_str);

	引数:	型					引数名				内容
			Layer_Struct		IN_layer_str		用紙構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFLayer_checkC::str_rule_check(Layer_Struct* IN_layer_str)
{
	//レイヤ名が指定されていないとき
	if (strlen(IN_layer_str->name) == 0){
		SXFErrorMsgC::RecordError(SXFNOTSETLNAME,m_feature_name,0);
		return SXFNOTSETLNAME;
	}
	//表示/非表示フラグが０または１でないとき
	if ((IN_layer_str->lflag < 0) || (IN_layer_str->lflag > 1)){
		SXFErrorMsgC::RecordError(SXFLAYERFLAG,
									m_feature_name,
									1,
									IN_layer_str->lflag);
		return SXFLAYERFLAG;
	}
	return 0;
}
