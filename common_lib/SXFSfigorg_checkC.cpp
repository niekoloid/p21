/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	複合図形定義フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFSfigorg_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void SXFSfigorg_checkC::SXFSfigorg_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSfigorg_checkC::SXFSfigorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void SXFSfigorg_checkC::~SXFSfigorg_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFSfigorg_checkC::~SXFSfigorg_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合図形定義フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Sfigorg_Struct IN_sfigorg_str,
										  CString IN_InstanceID)

	引数:	型				引数名				内容
			Sfigorg_Struct	IN_sfigorg_str		複合図形定義構造体
		    CString			IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSfigorg_checkC::Feature_rule_check(Sfigorg_Struct* IN_sfigorg_str,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SFIG_ORG;
	m_InstanceID = IN_InstanceID;
	ret = str_rule_check(IN_sfigorg_str);
	return ret;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合図形定義フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Sfigorg_Struct IN_sfigorg_str);

	引数:	型					引数名				内容
			Sfigorg_Struct		IN_sfigorg_str		複合図形定義構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFSfigorg_checkC::str_rule_check(Sfigorg_Struct* IN_sfigorg_str)
{
	if ((IN_sfigorg_str->flag < 1) || (IN_sfigorg_str->flag > 4)){
		SXFErrorMsgC::RecordError(SXFSFIGFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigorg_str->flag,
									m_feature_name);
		return SXFSFIGFLAG;
	}
	return 0;
}
