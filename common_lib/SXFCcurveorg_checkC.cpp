/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	複合曲線定義フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFCcurveorg_checkC.h"
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
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFCcurveorg_checkC::SXFCcurveorg_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

SXFCcurveorg_checkC::SXFCcurveorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFCcurveorg_checkC::~SXFCcurveorg_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFCcurveorg_checkC::~SXFCcurveorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合曲線定義フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(Ccurveorg_Struct IN_ccurveorg_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	引数:	型				引数名			内容
			Ccurveorg_Struct	IN_ccurveorg_str	複合曲線定義構造体
			SXFTableManagerC*	IN_TableManager		定義テーブル要素管理オブジェクト
			CString				IN_InstanceID		インスタンスID

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFCcurveorg_checkC::Feature_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_COMPOSITE_CURVE_ORG;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_ccurveorg_str);
	if (ret < 0)
		return ret;
	/** 属性以外のルールチェック **/
	ret = str_rule_check(IN_ccurveorg_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合曲線定義フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(Ccurveorg_Struct IN_ccurveorg_str);
	
	引数:	型					引数名				内容
			Ccurveorg_Struct	IN_ccurveorg_str	複合曲線定義構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFCcurveorg_checkC::attr_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str)
{
	m_color = IN_ccurveorg_str->color;
	m_type = IN_ccurveorg_str->type;
	m_line_width = IN_ccurveorg_str->line_width;
	int ret = CompCurveFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								作成日：2000.4.3

	１．機能概要
		複合曲線定義フィーチャの属性以外のルールチェック

	２．インターフェース
	int str_rule_check(Ccurveorg_Struct IN_ccurveorg_str);
	
	引数:	型					引数名				内容
			Ccurveorg_Struct	IN_ccurveorg_str	複合曲線定義構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFCcurveorg_checkC::str_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str)
{
	//表示／非表示フラグが０または１以外のとき
	if ((IN_ccurveorg_str->flag < 0) || (IN_ccurveorg_str->flag > 1)){
		SXFErrorMsgC::RecordError(SXFCURVEFLAG,
								m_feature_name,
								1,
								IN_ccurveorg_str->flag);
		return SXFCURVEFLAG;
	}
	return 0;
}
