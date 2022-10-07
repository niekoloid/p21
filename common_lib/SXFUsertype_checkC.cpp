/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	ユーザ定義線種フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFUsertype_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFUsertype_checkC::SXFUsertype_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFUsertype_checkC::SXFUsertype_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFUsertype_checkC::~SXFUsertype_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFUsertype_checkC::~SXFUsertype_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								作成日：2000.4.3

	１．機能概要
		ユーザ定義線種フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Userdefined_Linetype_Struct IN_usertype_str,
						   SXFTableManagerC* IN_TableManager,
						   SXFComInfoC* IN_ComInfo)

	引数:	型							引数名			内容
			Userdefined_Linetype_Struct	IN_usertype_str	ユーザ定義線種構造体
		    SXFTableManagerC*			IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			SXFComInfoC*				IN_ComInfo		共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFUsertype_checkC::Feature_rule_check(Userdefined_Linetype_Struct* IN_usertype_str,
										   SXFTableManagerC* IN_TableManager,
										   SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_USERDEFINED_LINETYPE;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//RW_FLAG
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Readではすでにﾁｪｯｸ済み)
	if (RW_Flag == 1){
		m_UniqueName = IN_usertype_str->name;
		ret = NameUniqueCheck(5);
		if (ret < 0)
			return ret;
	}
	ret = str_rule_check(IN_usertype_str);
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								作成日：2000.4.3

	１．機能概要
		ユーザ定義線種フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Userdefined_Linetype_Struct IN_usertype_str)

	引数:	型								引数名				内容
			Userdefined_Linetype_Struct		IN_usertype_str		ユーザ定義線種構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFUsertype_checkC::str_rule_check(Userdefined_Linetype_Struct* IN_usertype_str)
{
	//セグメント数が２の倍数でないとき
	if ((IN_usertype_str->segment % 2) != 0){
		SXFErrorMsgC::RecordError(SXFSEGMENTERROR,
									m_feature_name,
									1,
									IN_usertype_str->segment);
		return SXFSEGMENTERROR;
	}
	//セグメント数が２から８でないとき
	if ((IN_usertype_str->segment < MINSEGMENT) 
		|| (IN_usertype_str->segment > MAXSEGMENT)){
		SXFErrorMsgC::RecordError(SXFSEGMENTERROR,
									m_feature_name,
									1,
									IN_usertype_str->segment);
		return SXFSEGMENTERROR;
	}
	for (int i = 0; i < IN_usertype_str->segment ; i++){
		//ピッチが０以下の場合。
		if (double_check(IN_usertype_str->pitch[i]) < 0){
			SXFErrorMsgC::RecordError(SXFPITCHERROR,
										m_feature_name,
										1,
										IN_usertype_str->pitch[i]);
			return SXFPITCHERROR;
		}
	}
	return 0;
}
