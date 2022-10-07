/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．クラス概要
	ハッチング（パターン）フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFFillTiles_checkC.h"
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
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFFillTiles_checkC::SXFFillTiles_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillTiles_checkC::SXFFillTiles_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFFillTiles_checkC::~SXFFillTiles_checkC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
SXFFillTiles_checkC::~SXFFillTiles_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(ユーザ定義)フィーチャの属性以外のルールチェック

	２．インターフェース
	int Feature_rule_check(FillTiles_Struct IN_filltiles_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadFeatureManagerC* IN_ReadFeatureManager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
							
	引数:	型						引数名					内容
			FillTiles_Struct		IN_filltiles_str		ハッチング（パターン）構造体
			SXFTableManagerC*		IN_TableManager			定義ﾃｰﾌﾞﾙ要素管理ｵﾌﾞｼﾞｪｸﾄ
			SXFReadFeatureManagerC* IN_ReadFeatureManager	Read管理ｵﾌﾞｼﾞｪｸﾄ
			SXFWriteManagerC* 		IN_WriteManager			Write管理ｵﾌﾞｼﾞｪｸﾄ
			CString					IN_InstanceID			インスタンスID
			SXFComInfoC*			IN_Info					共通情報ｵﾌﾞｼﾞｪｸﾄ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillTiles_checkC::Feature_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str,
											   	SXFTableManagerC* IN_TableManager,
												SXFReadAP202ManagerC* IN_ReadAP202Manager,
												SXFWriteManagerC* IN_WriteManager,
											  	CString IN_InstanceID,
											  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_TILES;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 属性のルールチェック **/
	ret = attr_rule_check(IN_filltiles_str);
	if (ret < 0)
		return ret;
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		/** 属性以外のルールチェック **/
		ret = ReadAP202_Check(IN_filltiles_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		/** 属性以外のルールチェック **/
		ret = str_rule_check(IN_filltiles_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(パターン)フィーチャの属性のルールチェック

	２．インターフェース
	int attr_rule_check(FillTiles_Struct IN_filltiles_str);
	
	引数:	型					引数名				内容
			FillTiles_Struct	IN_filltiles_str	ハッチパターン構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillTiles_checkC::attr_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str)
{
	m_layer = IN_filltiles_str->layer;
	m_color = IN_filltiles_str->hatch_color;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(パターン)フィーチャの属性以外のルールチェック(write)

	２．インターフェース
	int str_rule_check(FillTiles_Struct IN_filltiles_str);
	
	引数:	型					引数名				内容
			FillTiles_Struct	IN_filltiles_str	ハッチング（パターン）構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillTiles_checkC::str_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str)
{
	//ハッチパターンの繰り返しベクトル1の大きさが範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_vector1) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//ハッチパターンの繰り返しベクトル１の角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_vector1_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//ハッチパターンの繰り返しベクトル２の大きさが範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_vector2) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//ハッチパターンの繰り返しベクトル１の角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_vector2_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//ハッチパターンの倍率が範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_scale_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//ハッチパターンの倍率が範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_scale_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//ハッチパターンの向きの角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_angle) < 0) {
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//外形のフィーチャコードが定義されていない値のとき
	if (!m_WriteManager->CheckHatchID(IN_filltiles_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//中抜きの閉領域数が0未満のとき
	if (IN_filltiles_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	if (IN_filltiles_str->number > IN_filltiles_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}

	//中抜きのフィーチャコードが定義されていない値のとき
	for (int i = 0; i < IN_filltiles_str->number; i++){
		if (IN_filltiles_str->in_id[i] == IN_filltiles_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_filltiles_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								作成日：2001.06.3

	１．機能概要
		ハッチング(パターン)フィーチャの属性以外のルールチェック(read)

	２．インターフェース
	int ReadFeature_Check(FillTiles_Struct IN_filltiles_str);
	
	引数:	型					引数名				内容
			FillTiles_Struct	IN_filltiles_str	ハッチパターン構造体
			
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.3			佐々木(FQS)			なし。

**/
int SXFFillTiles_checkC::ReadAP202_Check(Fill_area_style_tiles_Struct *IN_filltiles_str)
{
	//ハッチパターンの繰り返しベクトル1の大きさが範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_vector1) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//ハッチパターンの繰り返しベクトル１の角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_vector1_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//ハッチパターンの繰り返しベクトル２の大きさが範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_vector2) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//ハッチパターンの繰り返しベクトル１の角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_vector2_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//ハッチパターンの倍率が範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_scale_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//ハッチパターンの倍率が範囲外の値のとき
	if (double_check(IN_filltiles_str->hatch_pattern_scale_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//ハッチパターンの向きの角度が0～360でないとき
	if (angle_check(IN_filltiles_str->hatch_pattern_angle) < 0) {
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}

	//外形のフィーチャコードが定義されていない値のとき
	if (!m_ReadAP202Manager->SymbolCodeCheck(IN_filltiles_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//中抜きの閉領域数が0未満のとき
	if (IN_filltiles_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	for (int i = 0; i < IN_filltiles_str->number; i++){
		/* 外形と中抜きのIDが同じ時 */
		if (IN_filltiles_str->in_id[i] == IN_filltiles_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		//中抜きのフィーチャコードが定義されていない値のとき
		if (!m_ReadAP202Manager->SymbolCodeCheck(IN_filltiles_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}

	return 0;
}
