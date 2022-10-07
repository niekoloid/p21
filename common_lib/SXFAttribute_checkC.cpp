// SXFAttribute_checkC.cpp: SXFAttribute_checkC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．クラス概要
	図面表題欄フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/

#include "stdafx.h"
#include "SXFAttribute_checkC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFAttribute_checkC::SXFAttribute_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/
SXFAttribute_checkC::SXFAttribute_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFAttribute_checkC::~SXFAttribute_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/
SXFAttribute_checkC::~SXFAttribute_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．機能概要
		図面表題欄フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(
							Attribute_Struct*	IN_attribute_str,
							SXFTableManagerC*	IN_TableManager,
							CString				IN_InstanceID)

	引数:	型					引数名				内容
			Attribute_Struct*	IN_attribute_str	図面表題欄構造体
  		    SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
		    CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/
int SXFAttribute_checkC::Feature_rule_check(
						Attribute_Struct*	IN_attribute_str,
						SXFTableManagerC*	IN_TableManager,
						CString				IN_InstanceID)
{
	m_feature_name	= "ATTRIBUTE";
	m_TableManager	= IN_TableManager;
	m_InstanceID	= IN_InstanceID;

	int	ret = 0 ;

	/** 属性のルールチェック **/
	if( (ret = attr_rule_check(IN_attribute_str)) < 0 ) {
		return ret;
	}

	/** 属性以外のルールチェック **/
	if( (ret = str_rule_check(IN_attribute_str)) < 0 ) {
		return ret;
	}

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．機能概要
		図面表題欄フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(
						Attribute_Struct*	IN_attribute_str)

	引数:	型					引数名				内容
			Attribute_Struct*	IN_attribute_str	図面表題欄構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/
int SXFAttribute_checkC::attr_rule_check(
						Attribute_Struct*	IN_attribute_str)
{
	if( IN_attribute_str->d_month < 1 || IN_attribute_str->d_month > 12 ) {
		SXFErrorMsgC::RecordError(SXFDATEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_attribute_str->d_month,
									m_feature_name);
		return SXFDATEERROR;
	}
	if( IN_attribute_str->d_day < 1 || IN_attribute_str->d_day > 31 ) {
		SXFErrorMsgC::RecordError(SXFDATEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_attribute_str->d_day,
									m_feature_name);
		return SXFDATEERROR;
	}

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							作成日：2002.12.03

	１．機能概要
		図面表題欄フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(
						Attribute_Struct*	IN_attribute_str)

	引数:	型					引数名				内容
			Attribute_Struct*	IN_attribute_str	図面表題欄構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/
int SXFAttribute_checkC::str_rule_check(
						Attribute_Struct*	IN_attribute_str)
{
	return 0 ;
}
