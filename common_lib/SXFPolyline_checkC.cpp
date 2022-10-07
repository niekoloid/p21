/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．クラス概要
	折線フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "SXFPolyline_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFPolyline_checkC::SXFPolyline_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFPolyline_checkC::SXFPolyline_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFPolyline_checkC::~SXFPolyline_checkC()
		
	引数	：	型						引数名						内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
SXFPolyline_checkC::~SXFPolyline_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		折線フィーチャのルールチェック

	２．インターフェース
	int attr_rule_check(Polyline_Struct IN_polyline_str);

	引数:	型					引数名				内容
			Polyline_Struct		IN_polyline_str		折線構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFPolyline_checkC::attr_rule_check(Polyline_Struct* IN_polyline_str)
{
	//属性ルールチェック
	m_layer = IN_polyline_str->layer;
	m_color = IN_polyline_str->color;
	m_type = IN_polyline_str->type;
	m_line_width = IN_polyline_str->line_width;
	int ret = LineFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		折線フィーチャの属性以外のルールチェック

	２．インターフェース
	int polystr_rule_check(Polyline_Struct IN_polyline_str)

	引数:	型					引数名				内容
			Polyline_Struct		IN_polyline_str		折線構造体

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFPolyline_checkC::polystr_rule_check(Polyline_Struct* IN_polyline_str)
{
	///////////////////////////////////////
	//許容誤差の取得
	///////////////////////////////////////
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	int number = IN_polyline_str->number;

	//頂点数が２未満のときの時
	if (number < 2){
		SXFErrorMsgC::RecordError(SXFVERTEXERROR,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFVERTEXERROR;
	}
	//頂点数より座標の配列数が少ない場合はエラー
	if (number > IN_polyline_str->x.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	if (number > IN_polyline_str->y.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}


	// 2010.08

	for (int i = 0; i < number - 1; i++) {
		int j= i + 1;
		while ((j < number - 1) &&
		       (fabs(IN_polyline_str->x[i] - IN_polyline_str->x[j]) < eps) &&
			   (fabs(IN_polyline_str->y[i] - IN_polyline_str->y[j]) < eps)) {
			IN_polyline_str->x.RemoveAt(j);
			IN_polyline_str->y.RemoveAt(j);
			number--;
		}
	}

	int n1 = number - 1;
	int n2 = number - 2;
	if ((2 < number) &&
		(fabs(IN_polyline_str->x[n2] - IN_polyline_str->x[n1]) < eps) &&
		(fabs(IN_polyline_str->y[n2] - IN_polyline_str->y[n1]) < eps)) {
		IN_polyline_str->x.RemoveAt(n2);
		IN_polyline_str->y.RemoveAt(n2);
		number--;
	}
	IN_polyline_str->number = number;

	//隣り合う二点（始点と終点）が同じ座標だったら
	if (IN_polyline_str->number == 2) {
		if ((fabs(IN_polyline_str->x[0] - IN_polyline_str->x[1]) < eps) &&
		    (fabs(IN_polyline_str->y[0] - IN_polyline_str->y[1]) < eps)) {
			SXFErrorMsgC::RecordError(SXFSAMECOORD,
									m_feature_name,
									4,
									m_InstanceID,
									IN_polyline_str->x[0],
									IN_polyline_str->y[0],
									m_feature_name);
			return SXFSAMECOORD;
		}
	}
	//

	/*
	//隣り合う二点が同じ座標だったら
	for (int i = 0; i < number-1; i++){
		if ((fabs(IN_polyline_str->x[i] - IN_polyline_str->x[i+1]) < eps) 
			&& (fabs(IN_polyline_str->y[i] - IN_polyline_str->y[i+1]) < eps)){
			SXFErrorMsgC::RecordError(SXFSAMECOORD,
									m_feature_name,
									4,
									m_InstanceID,
									IN_polyline_str->x[i],
									IN_polyline_str->y[i],
									m_feature_name);
			return SXFSAMECOORD;
		}
	}
	*/
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								作成日：2000.4.3

	１．機能概要
		折線フィーチャの属性のルールチェック

	２．インターフェース
	int Feature_rule_check(Polyline_Struct IN_polyline_str,
						   SXFTableManagerC* IN_TableManager,
						   int IN_AssemType,
						   CString IN_InstanceID,
						   SXFComInfoC* IN_Info);

	引数:	型					引数名			内容
			Polyline_Struct		IN_polyline_str	折線構造体
		    SXFTableManagerC*	IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
			int					IN_AssemType	アセンブリ型
			CString				IN_InstanceID	インスタンスID
			SXFComInfoC*		IN_Info			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.3			宮園(FQS)			なし。

**/
int SXFPolyline_checkC::Feature_rule_check(Polyline_Struct* IN_polyline_str,
										   SXFTableManagerC* IN_TableManager,
										   int IN_AssemType,
										   CString IN_InstanceID,
										   SXFComInfoC* IN_Info)
{
	int ret;
	m_feature_name = DEF_POLYLINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** 複合曲線上以外の要素のとき **/
	if (IN_AssemType != 3){
		/** 属性のルールチェック **/
		ret  = attr_rule_check(IN_polyline_str) ;
		if (ret < 0)
			return ret ;
	}
	/** 属性以外のルールチェック **/
	ret  = polystr_rule_check(IN_polyline_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;

}