/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp					作成日：2000.03.29

	１．クラス概要
	ユーザ定義色フィーチャのルールチェックを行うクラス
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFUserdefined_color_checkC.h"
#include "SXFErrorMsgC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		コンストラクタ
		
	２．インターフェイス
		void	SXFUserdefined_color_checkC::SXFUserdefined_color_checkC()
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFUserdefined_color_checkC::SXFUserdefined_color_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		デストラクタ
		
	２．インターフェイス
		void	SXFUserdefined_color_checkC::~SXFUserdefined_color_checkC ()
			
	引数	：	型						引数名					内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
SXFUserdefined_color_checkC::~SXFUserdefined_color_checkC ()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		ユーザ定義色フィーチャの属性以外のルールチェック
		
	２．インターフェイス
		int		SXFUserdefined_color_checkC::str_rule_check (
					Userdefined_Colour_Struct IN_Userdefined_color_str)

	引数	：	型						引数名						内容
			Userdefined_Colour_Struct	IN_Userdefined_color_str	構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFUserdefined_color_checkC::str_rule_check (Userdefined_Colour_Struct* IN_Userdefined_color_str) 
{
	//R値が0から255でないとき
	if ((IN_Userdefined_color_str->red < 0) 
		|| (IN_Userdefined_color_str->red > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->red);
		return SXFRGBERROR;
	}
	//G値が0から255でないとき
	if ((IN_Userdefined_color_str->green < 0) 
		|| (IN_Userdefined_color_str->green > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->green);
		return SXFRGBERROR;
	}
	//B値が0から255でないとき
	if ((IN_Userdefined_color_str->blue < 0) 
		|| (IN_Userdefined_color_str->blue > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->blue);
		return SXFRGBERROR;
	}

	return 0 ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	作成日：2000.03.29

	１．機能概要 
		ユーザ定義色フィーチャのルールチェック
		
	２．インターフェイス
		int		SXFUserdefined_color_checkC::Feature_rule_check(
					Userdefined_Colour_Struct IN_Userdefined_color_str)
		
	引数	：	型						引数名						内容
			Userdefined_Colour_Struct	IN_Userdefined_color_str

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.29	諌山(FQS)	なし。
**/
int SXFUserdefined_color_checkC::Feature_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str)
{
	int ret ;

	m_feature_name = DEF_USERDEFINED_COLOR;

	ret  = str_rule_check(IN_Userdefined_color_str) ;
	return ret ;
}
