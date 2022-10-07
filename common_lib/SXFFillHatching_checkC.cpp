/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．クラス概要
	ハッチング（ユーザ定義）フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFFillHatching_checkC.h"
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
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFFillHatching_checkC::SXFFillHatching_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillHatching_checkC::SXFFillHatching_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFFillHatching_checkC::~SXFFillHatching_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillHatching_checkC::~SXFFillHatching_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャのルールチェック

	２．インターフェース
	int Feature_rule_check(FillHatching_Struct IN_fillhatching_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadFeatureManagerC* IN_ReadFeatureManager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	引数:型						引数名					内容
		FillHatching_Struct		IN_fillhatching_str	ユーザハッチ構造体
		SXFTableManagerC*		IN_TableManager		定義ﾃｰﾌﾞﾙ要素管理ｵﾌﾞｼﾞｪｸﾄ
		SXFReadFeatureManagerC* IN_ReadFeatureManager	Read管理ｵﾌﾞｼﾞｪｸﾄ
		SXFWriteManagerC* 		IN_WriteManager		Write管理ｵﾌﾞｼﾞｪｸﾄ
		CString					IN_InstanceID		インスタンスID
		SXFComInfoC*			IN_Info				共通情報ｵﾌﾞｼﾞｪｸﾄ

  復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillHatching_checkC::Feature_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str,
											   	SXFTableManagerC* IN_TableManager,
												SXFReadAP202ManagerC* IN_ReadAP202Manager,
												SXFWriteManagerC* IN_WriteManager,
											  	CString IN_InstanceID,
											  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_HATCHING;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;

	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_fillhatching_str);
	if (ret < 0)
		return ret;

	/** 属性以外のルールチェック **/
	ret = StructCheck(IN_fillhatching_str);
	if (ret < 0)
		return ret;

	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		ret = ReadAP202_Check(IN_fillhatching_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		ret = str_rule_check(IN_fillhatching_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(FillHatching_Struct IN_fillhatching_str)
	
	引数:	型					引数名				内容
			FillHatching_Struct	IN_fillhatching_str	ユーザハッチ構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillHatching_checkC::attr_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str)
{
	int ret,num;
	m_layer = IN_fillhatching_str->layer;
	/* ﾊｯﾁﾝｸﾞﾊﾟﾀｰﾝ数 */
	/* ﾊﾟﾀｰﾝ数が5より大きい場合、*/
	/* その数だけ属性のﾁｪｯｸを行うのでそれを回避する */
	num = IN_fillhatching_str->hatch_number;
	if (num > 4)
		num = 4;
	for (int i = 0; i < num ; i++){
		m_color = IN_fillhatching_str->hatch_color[i];
		m_type = IN_fillhatching_str->hatch_type[i];
		m_line_width = IN_fillhatching_str->hatch_line_width[i];
		ret = LineFeature_Check();
		if (ret < 0)
			return ret;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャの属性以外のルールチェック(write)

	２．インターフェース
	int str_rule_check(FillHatching_Struct IN_fillhatching_str);
	
	引数:	型					引数名				内容
			FillHatching_Struct	IN_fillhatching_str	ユーザハッチ構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillHatching_checkC::str_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str)
{
	if (IN_fillhatching_str->number > IN_fillhatching_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}
	//外形のフィーチャコードが定義されていない値のとき
	if (!m_WriteManager->CheckHatchID(IN_fillhatching_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//中抜きの閉領域数が0未満のとき
	if (IN_fillhatching_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	//中抜きのフィーチャコードが定義されていない値のとき
	for (int i = 0; i < IN_fillhatching_str->number; i++){
		if (IN_fillhatching_str->in_id[i] == IN_fillhatching_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillhatching_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_fillhatching_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillhatching_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャの属性以外のルールチェック(read)

	２．インターフェース
	int ReadFeature_Check(FillHatching_Struct* IN_Struct);
	
	引数:	型						引数名		内容
			FillHatching_Struct*	IN_Struct	ユーザハッチ構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillHatching_checkC::ReadAP202_Check(Fill_area_style_hatching_Struct *IN_Struct)
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
		/* 外形と中抜きのIDが同じ時 */
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

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャの属性以外のルールチェック

	２．インターフェース
	int StructCheck(FillHatching_Struct* IN_Struct);
	
	引数:	型						引数名				内容
			FillHatching_Struct*	IN_Struct	ユーザハッチ構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillHatching_checkC::StructCheck(Fill_area_style_hatching_Struct *IN_Struct) 
{
	/* ハッチング線のパターン数が範囲外の値のとき 1 <= 数 <= 4*/
	if (IN_Struct->hatch_number < 1 
		|| IN_Struct->hatch_number > 4){
		SXFErrorMsgC::RecordError(SXFERRORPATTERN,
								m_feature_name,
								3,
								m_InstanceID,
								IN_Struct->hatch_number,
								m_feature_name);
		return SXFERRORPATTERN;
	}

	for (int i = 0; i < IN_Struct->hatch_number; i++){
		if (double_check(IN_Struct->hatch_spacing[i]) < 0){
			SXFErrorMsgC::RecordError(SXFSPACING,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->hatch_spacing[i],
										m_feature_name) ;
			return SXFSPACING ;
		}
		if (angle_check(IN_Struct->hatch_angle[i]) < 0){
			SXFErrorMsgC::RecordError(SXFERRORANGLE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->hatch_angle[i],
										m_feature_name);
			return SXFERRORANGLE;
		}
	}
	return 0;

}
