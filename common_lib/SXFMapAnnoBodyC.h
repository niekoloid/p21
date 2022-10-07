/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.h						作成日：2000.04.21

	１．クラス概要
		ANNOTATION_OCCURRENCE系のBODYを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapAnnoBodyC_CLASS_
#define _SXFMapAnnoBodyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"

class SXFInstanceIDC;
class SXFTableManagerC;
class SXFReadAP202ManagerC;

class SXFMapAnnoBodyC: public SXFMapEntityBaseC{
public:
//
//	<デフォルトコンストラクタ>
	SXFMapAnnoBodyC( );

//	<インスタンスＩＤへのポインタを登録し生成する>
//	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger);
//	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger, SXFTableManagerC* IN_TableManager);
	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger, 
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager);

//
//	<デストラクタ>
	virtual	~SXFMapAnnoBodyC( );

//
//	<フィーチャ構造体への値の設定>
//	int	SetParameter(E_type OUT_Type,	LPVOID	OUT_Class);
	int	SetParameter();

	//	<Body種別判定>
	int	CheckBodyKind() ;

//	<レイヤコード>
	int 	m_layer;

//	<フィーチャタイプ>
	E_type	m_Type;
//	<フィーチャクラスへのポインタ>
	void*	m_Class;
		
//< ANNOTATION_OCCURRENCE系 >/////////////////////////////////////
	int	m_AnnoKind;
//	E_AnnoKindtype	m_AnnoKind;
//	NONSTYLE,		//0:不明
//	CURVESTYLE,		//1:
//	SYMBOLSTYLE,	//2:
//	FILLSTYLE,		//3:
//	TEXTSTYLE,		//4:
//	NULLSTYLE		//5:

//< ANNOTATION_CURVE_OCCURRENCEの種類 >////////////////////////////
	int	m_CurveKind;
//	E_CurveKindtype m_CurveKind;
//	NONCURVE,			//0:不明
//	CURVE,				//1:一般要素
//	DIMENSION_CURVE,	//2:寸法線（狭義）
//	PROJECTION_CURVE	//3:寸法補助線
//	LEADER_CURVE		//4:引出線分（狭義）


//< ANNOTATION_SYMBOL_OCCURRENCEの種類 >////////////////////////////
	int	m_SymbolKind;
//	E_SymbolKindtype m_SymbolKind;
//	NONSYMBOL,							//0:不明
//	SYMBOL,							//1:点マーカ、既定義（外部定義）、その他シンボル
//	DIM_CURVE_TERMINATOR,			//2:寸法端点矢印
//	LEADER_TERMINATOR,				//3:引き出し線、バルーン端点矢印
//	SUBFIGURE_OCCURRENCE			//4:複合図形配置（SUbfigure）

//	<親玉のnameパラメタ>
	CString m_namepara;

private :

protected :


//	<図形インスタンス部へのＩＤ>
	int		m_InstID ;
//	<図形見え方へのＩＤ>
	int		m_AppeID ;

//	<図形インスタンス部へのポインタ>
	void*	m_InstP ;
//	<図形見え方へのポインタ>
	void*	m_AppeP ;

//	<SXFTableManagerCへのポインタ>
	SXFTableManagerC* m_TableManager;

//	<SXFReadAP202ManagerCへのポインタ>
	SXFReadAP202ManagerC* m_ReadManager;

//	<SXFMapAnnoBodyCへのポインタ>
	SXFMapAnnoBodyC* m_tilebody;

};

#endif
