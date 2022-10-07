/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_EnumC.h						作成日：2000.04.21

	１．機能概要
		列挙型を定義する

	２．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

#ifndef _SXFMAPT_ENUMC_H_
#define	_SXFMAPT_ENUMC_H_

//#include "SXFErrorMsgC.h"

//< ANNOTATION_OCCURRENCE系 >/////////////////////////////////////
//		0:不明 1:Curve 2:Symbol 3:Fill 4:Text

typedef enum E_AnnoKindtype{
	NONSTYLE,		//		0:不明
	CURVESTYLE,
	SYMBOLSTYLE,
	FILLSTYLE,
	TEXTSTYLE,
	NULLSTYLE
}E_AnnoKind;

//< ANNOTATION_CURVE_OCCURRENCEの種類 >////////////////////////////
typedef enum E_CurveKindtype{
	NONCURVE,			//0:不明
	CURVE,				//1:一般要素
	DIMENSION_CURVE,	//2:寸法線（狭義）
	PROJECTION_CURVE,	//3:寸法補助線
	LEADER_CURVE		//4:引出線（狭義）
}E_CurveKind;

//< ANNOTATION_SYMBOL_OCCURRENCEの種類 >////////////////////////////
typedef enum E_SymbolKindtype{
	NONSYMBOL,							//0:不明
	SYMBOL,								//1:点マーカ、既定義（外部定義）、その他シンボル
	DIM_CURVE_TERMINATOR,				//2:寸法端点矢印
	LEADER_TERMINATOR,					//3:引き出し線、バルーン端点矢印
	SUBFIGURE_OCCURRENCE		//4:複合図形配置（SUbfigure）
}E_SymbolKind;

#endif

