/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								作成日：2000.4.14

	１．クラス概要
		文字フォントフィーチャのルールチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFTextFont_checkC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								作成日：2000.4.14

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFTextFont_checkC::SXFTextFont_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFTextFont_checkC::SXFTextFont_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								作成日：2000.4.14

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFTextFont_checkC::~SXFTextFont_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFTextFont_checkC::~SXFTextFont_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								作成日：2000.4.14

	１．機能概要
		文字フォントフィーチャのルールチェック

	２．インターフェース
	int SXFTextFont_checkC::Feature_rule_checkC(Text_Font_Struct *IN_Struct, 
												SXFTableManagerC *IN_TableManager,
												SXFComInfoC* IN_ComInfo)
		
	引数	：	型					引数名				内容
				Text_Font_Struct*	IN_Struct			文字フォント構造体	
				SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
				SXFComInfoC*		IN_ComInfo			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
int SXFTextFont_checkC::Feature_rule_checkC(Text_Font_Struct *IN_Struct, 
											SXFTableManagerC *IN_TableManager,
											SXFComInfoC* IN_ComInfo)
{
	int ret = 0;
	m_feature_name = DEF_TEXT_FONT;
	m_TableManager = IN_TableManager;
	//RW_FLAG
	int RW_Flag = -1;
	IN_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Readではすでにﾁｪｯｸ済み)
	if (RW_Flag == 1){
		//フォント名称長が０のときはエラー
		CString TextfontName = IN_Struct->name;
		if (TextfontName.GetLength() <= 0){
			SXFErrorMsgC::RecordError(SXFFONTNAMEERROR,m_feature_name,0);
			return SXFFONTNAMEERROR;
		}
		m_UniqueName = IN_Struct->name;
		ret = NameUniqueCheck(7);
	}
	return ret;
}
