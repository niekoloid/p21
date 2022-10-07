/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．クラス概要
	ハッチング（塗り）フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFFillColour_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFFillColour_checkC::SXFFillColour_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillColour_checkC::SXFFillColour_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFFillColour_checkC::~SXFFillColour_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillColour_checkC::~SXFFillColour_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(塗り)フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(FillColour_Struct IN_fillcolour_str);
								SXFTableManagerC* IN_TableManager,
								SXFReadFeatureManagerC* IN_ReadFeatureManager,
								SXFWriteManagerC* IN_WriteManager,
								CString IN_InstanceID,
								SXFComInfoC* IN_Info);

	引数:	型						引数名					内容
			FillColour_Struct		IN_fillcolour_str		ハッチ（塗り）構造体
			SXFTableManagerC*		IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			SXFReadFeatureManagerC* IN_ReadFeatureManager	Read管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			SXFWriteManagerC* 		IN_WriteManager			Write管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			CString					IN_InstanceID			インスタンスID
			SXFComInfoC*			IN_Info					共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillColour_checkC::Feature_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str,
											SXFTableManagerC* IN_TableManager,
											SXFReadAP202ManagerC* IN_ReadAP202Manager,
											SXFWriteManagerC* IN_WriteManager,
										  	CString IN_InstanceID,
										  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_COLOUR;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_fillcolour_str);
	if (ret < 0)
		return ret;
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		/** 属性以外のルールチェック **/
		ret = ReadAP202_Check(IN_fillcolour_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		/** 属性以外のルールチェック **/
		ret = str_rule_check(IN_fillcolour_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(塗り)フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(FillColour_Struct IN_fillcolour_str)
	
	引数:	型					引数名				内容
			FillColour_Struct	IN_fillcolour_str	ハッチング（塗り）構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillColour_checkC::attr_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str)
{
	m_color = IN_fillcolour_str->color;
	m_layer = IN_fillcolour_str->layer;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(塗り)フィーチャの属性以外のルールチェック(write)

	２．インターフェース
	int str_rule_check(FillColour_Struct IN_fillcolour_str)
	
	引数:	型					引数名				内容
			FillColour_Struct	IN_fillcolour_str	ハッチング（塗り）構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillColour_checkC::str_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str)
{
	if (IN_fillcolour_str->number > IN_fillcolour_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}
	//外形のフィーチャコードが定義されていない値のとき
	if (!m_WriteManager->CheckHatchID(IN_fillcolour_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//中抜きの閉領域数が0未満のとき
	if (IN_fillcolour_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	//中抜きのフィーチャコードが定義されていない値のとき
	for (int i = 0; i < IN_fillcolour_str->number; i++){
		if (IN_fillcolour_str->in_id[i] == IN_fillcolour_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillcolour_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_fillcolour_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillcolour_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(塗り)フィーチャの属性以外のルールチェック(read)

	２．インターフェース
	int ReadFeature_Check(FillColour_Struct* IN_Struct)
	
	引数:	型					引数名		内容
			FillColour_Struct*	IN_Struct	ハッチング（塗り）構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillColour_checkC::ReadAP202_Check(Fill_area_style_colour_Struct *IN_Struct)
{
	//外形のフィーチャコードが定義されていない値のとき
	if (!m_ReadAP202Manager->SymbolCodeCheck(IN_Struct->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_Struct->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//中抜きの閉領域数が0未満のとき
	if (IN_Struct->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_Struct->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	for (int i = 0; i < IN_Struct->number; i++){
		/* 中抜きと外形のID同じ時 */
		if (IN_Struct->in_id[i] == IN_Struct->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		//中抜きのフィーチャコードが定義されていない値のとき
		if (!m_ReadAP202Manager->SymbolCodeCheck(IN_Struct->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}

	return 0;
}
