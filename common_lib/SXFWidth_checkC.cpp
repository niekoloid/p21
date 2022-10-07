/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							作成日：2000.4.14

	１．クラス概要
		線幅フィーチャのルールチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFWidth_checkC.h"
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
	SXFWidth_checkC.cpp							作成日：2000.4.14

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFWidth_checkC::SXFWidth_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFWidth_checkC::SXFWidth_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							作成日：2000.4.14

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFWidth_checkC::~SXFWidth_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFWidth_checkC::~SXFWidth_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							作成日：2000.4.14

	１．機能概要
		線幅フィーチャのルールチェック

	２．インターフェース
	int SXFWidth_checkC::Feature_rule_check(Line_Width_Struct *IN_width_str,
											SXFTableManagerC* IN_TableManager,
											SXFComInfoC* IN_ComInfo)

	引数	：	型					引数名			内容
				Line_Width_Struct*	IN_width_str	線幅フィーチャ構造体	
				SXFTableManagerC*	IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
				SXFComInfoC*		IN_ComInfo		共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
int SXFWidth_checkC::Feature_rule_check(Line_Width_Struct *IN_width_str,
										SXFTableManagerC* IN_TableManager,
										SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_LINE_WIDTH;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//RW_FLAG
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Readではすでにﾁｪｯｸ済み)
	if (RW_Flag == 1){
		m_UniqueWidth = IN_width_str->width;
		ret = NameUniqueCheck(6);
		if (ret < 0)
			return ret;
	}
	ret = str_rule_check(IN_width_str);
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							作成日：2000.4.14

	１．機能概要
		線幅フィーチャの属性以外のルールチェック

	２．インターフェース
		void SXFWidth_checkC::str_rule_check(Line_Width_Struct *IN_width_str)
		
	引数	：	型					引数名			内容
				Line_Width_Struct*	IN_width_str	線幅フィーチャ構造体	

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
int SXFWidth_checkC::str_rule_check(Line_Width_Struct *IN_width_str)
{
	if (double_check(IN_width_str->width) < 0){
		SXFErrorMsgC::RecordError(SXFWIDTHERROR,
								m_feature_name,
								1,
								IN_width_str->width);
		return SXFWIDTHERROR;
	}
	return 0;
}
