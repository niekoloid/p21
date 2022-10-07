/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.h						作成日：2000.04.21

	１．クラス概要
		DRAUGHTING_CALLOUT系のBODYを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapCalloutBodyC_CLASS_
#define _SXFMapCalloutBodyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"

class SXFInstanceIDC;
class SXFTableManagerC;
class SXFReadAP202ManagerC;

class SXFMapAnnoBodyC;
class SXFMapF_LINEC;
class SXFMapF_ARCC;
class SXFMapF_POLYLINEC;
class SXFMapF_CIRCLEC;
class SXFMapF_TERMSYMBOLC;
class SXFMapF_TEXTSTRINGC;

class SXFMapCalloutBodyC: public SXFMapEntityBaseC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapCalloutBodyC( );

//	<インスタンスＩＤへのポインタを登録し生成する>
//	SXFMapCalloutBodyC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapCalloutBodyC(SXFInstanceIDC* IN_InstanceIDManeger, SXFTableManagerC* IN_TableManager) ;
	SXFMapCalloutBodyC(
			SXFInstanceIDC* IN_InstanceIDManeger, 
			SXFTableManagerC* IN_TableManager,
			SXFReadAP202ManagerC* IN_ReadManager);

//
//	<デストラクタ>
	virtual	~SXFMapCalloutBodyC() ;

//
//	<フィーチャ構造体への値の設定>
//	int	SetFeatureParameter(E_type OUT_Type,	LPVOID	OUT_Class);
	int	SetFeatureParameter( );

//
//	<Body種別判定>
	int	CheckBodyKind() ;

//	<レイヤコード>
	int 	m_layer;
//	<フィーチャタイプ>
	E_type	m_Type;
//	<フィーチャクラスへのポインタ>
	void*	m_Class;

private :

protected :

//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
	int		m_CalloutKind;
//		0:不明
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT

//< DIMENSION系 >/////////////////////////////////////
	int	m_DimensionKind;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER系 >/////////////////////////////////////
	int	m_LavelKind;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON

//	<コンテンツへのＩＤ>
	CArray<int,int>		m_ContentsID ;
//	<コンテンツへ数>
	int		m_ContentsNum;

//	<コンテンツへのポインタ>
	CArray<SXFMapAnnoBodyC*,SXFMapAnnoBodyC*>	m_ContentsP ;

//	<SXFTableManagerCへのポインタ>
	SXFTableManagerC* m_TableManager;

//	<SXFReadAP202ManagerCへのポインタ>
	SXFReadAP202ManagerC* m_ReadManager;

// DIMENSION LINE フラグ
	int m_dimline;
//DIMENSION ARC フラグ
	int m_dimarc;
// DIMENSION TEXT フラグ
	int m_dimtext;
// PROJECTION LINE1 フラグ
	int m_prjline1;
// PROJECTION LINE2 フラグ
	int m_prjline2;
// LEADER CURVE フラグ
	int m_leader;
// TERM1 フラグ
	int m_term1;
// TERM2 フラグ
	int m_term2;
// CIRCLE フラグ
	int	m_balloon;

// DIMENSION LINE へのポインタ
	SXFMapF_LINEC* m_dimlineP;

//DIMENSION ARC へのポインタ
	SXFMapF_ARCC* m_dimarcP;

// DIMENSION TEXT へのポインタ
	SXFMapF_TEXTSTRINGC* m_dimtextP;

// PROJECTION LINE1 へのポインタ
	SXFMapF_LINEC* m_prjline1P;

// PROJECTION LINE2 へのポインタ
	SXFMapF_LINEC* m_prjline2P;

// LEADER CURVEへのポインタ
	SXFMapF_POLYLINEC* m_leaderP;

// TERM1 へのポインタ
	SXFMapF_TERMSYMBOLC* m_term1P;

// TERM2 へのポインタ
	SXFMapF_TERMSYMBOLC* m_term2P;

// CIRCLE へのポインタ
	SXFMapF_CIRCLEC*	m_balloonP;

} ;
#endif
