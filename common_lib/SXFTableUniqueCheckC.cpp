/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								作成日：2000.4.17

	１．クラス概要
		定義テーブル要素のユニークチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFTableUniqueCheckC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								作成日：2000.4.17

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFTableUniqueCheckC::SXFTableUniqueCheckC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFTableUniqueCheckC::SXFTableUniqueCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								作成日：2000.4.17

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFTableUniqueCheckC::~SXFTableUniqueCheckC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFTableUniqueCheckC::~SXFTableUniqueCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								作成日：2000.4.17

	１．機能概要
		定義テーブル要素のユニークチェック

	２．インターフェース
		void SXFTableUniqueCheckC::NameUniqueCheck(int IN_TableType)
		
	引数	：	型		引数名				内容
				int		IN_TableType		テーブル型

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFTableUniqueCheckC::NameUniqueCheck(int IN_TableType)
{
	int error_code = 0;

	//TableManagerのメソッドを呼び出す。
	switch(IN_TableType){
	case 1://layer
		if (!m_TableManager->CheckSameLayer(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 2://pre_color
		if (!m_TableManager->CheckSamePreDefColor(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 3://user_color
		break;
	case 4://pre_type
		if (!m_TableManager->CheckSamePreDefFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 5://user_type
		if (!m_TableManager->CheckSameUserDefFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 6://width
		if (!m_TableManager->CheckSameWidth(m_UniqueWidth)){
			SXFErrorMsgC::RecordError(SXFSAMEWIDTH,
										m_feature_name,
										1,
										m_UniqueWidth);
			return SXFSAMENAME;
		}
		break;
	case 7://text_font
		if (!m_TableManager->CheckSameTextFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	default:
		break;
	}
	return error_code;

}
