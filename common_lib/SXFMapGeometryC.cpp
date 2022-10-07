/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．クラス概要
		AP202エンティティからフィーチャへのマッピングを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2001.07.21	佐々木(FQS)	

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapAnnoBodyC.h" 
#include "SXFMapCalloutBodyC.h" 
#include "SXFMapCompBodyC.h" 
#include "SXFMapGeometryC.h"
#include "SXFMapE_STYLED_ITEMC.h" 
#include "SXFMapF_LINEC.h" 
#include "SXFMapF_CURVEDIMC.h" 
#include "SXFMapF_ANGULARDIMC.h" 
#include "SXFMapF_ARCC.h" 
#include "SXFMapF_BALLOONC.h" 
#include "SXFMapF_CIRCLEC.h" 
#include "SXFMapF_DIMETERDIMC.h" 
#include "SXFMapF_ELLIPSEARCC.h" 
#include "SXFMapF_ELLIPSEC.h" 
#include "SXFMapF_EXHATCHC.h" 
#include "SXFMapF_EXSYMBOLC.h" 
#include "SXFMapF_FILLCOLOURC.h" 
#include "SXFMapF_FILLHATCHINGC.h" 
#include "SXFMapF_FILLTILESC.h" 
#include "SXFMapF_LABELC.h" 
#include "SXFMapF_LINERDIMC.h" 
#include "SXFMapF_POINTMARKERC.h" 
#include "SXFMapF_POLYLINEC.h" 
#include "SXFMapF_RADIUSDIMC.h"
#include "SXFMapF_SFIGLOCC.h"
#include "SXFMapF_SPLINEC.h"
#include "SXFMapF_CLOTHOIDC.h"
#include "SXFMapF_TERMSYMBOLC.h" 
#include "SXFMapF_TEXTSTRINGC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
	
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapGeometryC::SXFMapGeometryC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	佐々木(FQS)
**/
SXFMapGeometryC::SXFMapGeometryC()
{
//	<初期化>
//	<BODY種別> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:不明
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT

	//SXFTableManagerCへのポインタ
	m_TableManager=NULL;
	m_ComInfoC=NULL;
	m_ReadManager = NULL;
	m_StructData = NULL;
	m_calloutbody = NULL;
	m_annobody = NULL;
	m_compbody =NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapGeometryC::SXFMapGeometryC(
						SXFInstanceIDC* IN_InstanceIDManeger, 
						SXFTableManagerC* IN_TableManager,
						SXFComInfoC* IN_ComInfoC ,
						SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	引数 ：	型						引数名				内容
			SXFInstanceIDC* 		IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC* 		IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			SXFComInfoC* 			IN_ComInfoC				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
			SXFReadAP202ManagerC* 	IN_ReadManager			Read管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	
**/
//インスタンスＩＤへのポインタを登録し生成する
SXFMapGeometryC::SXFMapGeometryC(
		SXFInstanceIDC* IN_InstanceIDManeger, 
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC ,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	//	<BODY種別> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:不明
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT

	//SXFTableManagerCへのポインタ
	m_TableManager=IN_TableManager;
	//SXFComInfoCへのポインタ
	m_ComInfoC = IN_ComInfoC;
	m_ReadManager = IN_ReadManager;
	m_StructData = NULL;
	m_calloutbody = NULL;
	m_annobody = NULL;
	m_compbody =NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapGeometryC::~SXFMapGeometryC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	佐々木(FQS)
**/
SXFMapGeometryC::~SXFMapGeometryC()
{

	if(m_calloutbody != NULL)
		delete m_calloutbody;
	if(m_annobody != NULL)
		delete m_annobody;
	if (m_compbody !=NULL ) 
		delete m_compbody;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		一般要素フィーチャ構造体の作成

	２．インターフェイス
		int		SXFMapGeometryC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	引数  ：	型			引数名				内容
				int			OUT_type,	//定義テーブル種別	
				void*		OUT_Class	//定義テーブルフィーチャクラスへのポインタ


	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	佐々木(FQS)
**/
int	SXFMapGeometryC::	SetFeatureParameter(
					int		&OUT_Type,	//フィーチャ種別	
					LPVOID	&OUT_Class)	//フィーチャクラスへのポインタ

{
	//初期化
	int ircode;
	ircode = 0;
	//親玉の種別判定と親玉に合わせたBODYクラス作成
	//	<BODY種別> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:不明
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT
		
	//Bodyの判定
	//< COMPLEX > 
	if (m_EntityName == DEF_SXF_COMPLEX_INSTANCE ) {

		//< ANNOTATION_OCCURRENCE系 >/////////////////////////////////////
		if (m_EntityData.Find(DEF_ANNOTATION_OCCURRENCE) != -1){
			m_BodyKind = 1;

			// ANNOTATION_OCCURRENCE系のBODYクラス作成
			if (m_annobody) 
				delete m_annobody;
				m_annobody = new SXFMapAnnoBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_annobody->SetRootID(m_RootID);
				ircode = m_annobody->SetParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_annobody->m_Type;	//フィーチャタイプ	
					OUT_Class = m_annobody->m_Class;	//フィーチャクラスへのポインタ

		}
		//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
		else if ((m_EntityData.Find(DEF_DRAUGHTING_CALLOUT) != -1)&&
				(m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) == -1)){
				m_BodyKind = 2;

			// DRAUGHTING_CALLOUT系のBODYクラス作成
			if (m_calloutbody)
				delete m_calloutbody;
				m_calloutbody = new SXFMapCalloutBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_calloutbody->SetRootID(m_RootID);
				ircode = m_calloutbody->SetFeatureParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_calloutbody->m_Type;	//フィーチャタイプ	
					OUT_Class = m_calloutbody->m_Class;	//フィーチャクラスへのポインタ
		}
		else if (m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) != -1){
			return 0;
		}
		else{
		// SCADECの対象ではないENTITYです
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
			return SXFEXCEPT;
		}
	}
	//< STYLED_ITEM >
	else if ( m_EntityName == DEF_STYLED_ITEM){

		SXFMapE_STYLED_ITEMC styled(m_InstanceIDManager);
		styled.SetRootID(m_RootID);
		styled.SetEntity();
		styled.SetParameter();

		// STYLED_ITEMが参照しているインスタンスをチェック
		SXFMapEntityBaseC body(m_InstanceIDManager);
		body.SetRootID(styled.m_InstID);
		body.SetEntity();

		//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
		if ((body.m_EntityData.Find(DEF_DRAUGHTING_CALLOUT) != -1)&&
				(body.m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) == -1)){
				m_BodyKind = 2;

			// DRAUGHTING_CALLOUT系のBODYクラス作成
			if (m_calloutbody)
				delete m_calloutbody;
				m_calloutbody = new SXFMapCalloutBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_calloutbody->SetRootID(styled.m_InstID);
				ircode = m_calloutbody->SetFeatureParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_calloutbody->m_Type;		//フィーチャタイプ	
					OUT_Class = m_calloutbody->m_Class;	//フィーチャクラスへのポインタ
		}
		else if (body.m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) != -1){
			return 0;
		}
		else{
		// SCADECの対象ではないENTITYです
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,				//errメッセージ番号
				body.m_EntityName,		//エンティティ名
				2,						//パラメタの個数
				styled.m_InstID,		//パラメタ
				body.m_EntityName
				);
			return SXFEXCEPT;

		}

	}
	//////////////////////////////////////////////////////////////////////
	//	COMPOSITE_CURVE_SEGMENT  /////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	else if ( m_EntityName == DEF_COMPOSITE_CURVE_SEGMENT){
		m_BodyKind = 3;

		// ANNOTATION_OCCURRENCE系のBODYクラス作成
		if (m_compbody)
			delete m_compbody;
			m_compbody = new SXFMapCompBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
			m_compbody->SetRootID(m_RootID);
			ircode = m_compbody->SetParameter();
			if (ircode <0 )return ircode;

				OUT_Type  = m_compbody->m_Type;	//フィーチャタイプ	
				OUT_Class = m_compbody->m_Class;	//フィーチャクラスへのポインタ

	}
	else if (m_EntityName == DEF_AXIS2_PLACEMENT_2D ||
			m_EntityName == DEF_PLANAR_BOX){
		return 0;
	}

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	else if( m_EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ) {
		OUT_Type = attribute_feature ;
	}
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

	else{
		// SCADECの対象ではないENTITYです
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
			return SXFEXCEPT;
	}
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		フィーチャ構造体に値を設定

	２．インターフェイス
	int		SXFMapGeometryC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class);

	引数  ：	型			引数名				内容
				int			IN_Type,	//フィーチャタイプ
				LPVOID		IN_Class	//フィーチャクラスへのポインタ
			
	復帰値：フィーチャＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	佐々木(FQS)
**/
int SXFMapGeometryC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class)
{

	m_Type 	= (E_type)IN_Type;
	m_Class	= IN_Class;

/*
	NONFEATURE=0,
	drawing_sheet_feature,
	layer_feature,
	pre_defined_font_feature,
	user_defined_font_feature,
	pre_defined_colour_feature,
	user_defined_colour_feature,
	width_feature,
	text_font_feature,

	point_marker_feature,
	line_feature,
	polyline_feature,
	circle_feature,
	arc_feature,
	ellipse_feature,
	ellipse_arc_feature,
	text_string_feature,
	spline_feature,
	clothoid_feature,

	sfig_locate_feature,
	sfig_org_feature,
	externally_defined_symbol_feature,
	linear_dim_feature,
	curve_dim_feature,
	angular_dim_feature,
	radius_dim_feature,
	diameter_dim_feature,
	label_feature,
	balloon_feature,
	externally_defined_hatch_feature,
	fill_area_style_colour_feature,
	fill_area_style_hatching_feature,
	fill_area_style_tiles_feature,
	composite_curve_org_feature,

	projection_line,
	dimension_line,
	dimension_erminator_symbol
*/
	if(m_Type == drawing_sheet_feature ){//1

		//構造体データ作成
		Sheet_Struct* sheet = new Sheet_Struct;

		//構造体データの保存
		m_StructData = sheet;

		//フィーチャレベル
		m_Level = 1;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	} else if( m_Type == attribute_feature ) {

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ATTRIBUTE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ATTRIBUTE);

		//構造体データ作成
		Attribute_Struct*	attr = new Attribute_Struct ;
		m_TableManager->GetAttributeData(attr) ;

		//構造体データの保存
		m_StructData = attr ;

		//フィーチャレベル
		m_Level = 1 ;

//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

	}else if(m_Type == point_marker_feature ){//2

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_POINT_MARKER);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_POINT_MARKER);

		//構造体データ作成
		Point_Marker_Struct* pointmarker = new Point_Marker_Struct;
		((SXFMapF_POINTMARKERC*)m_Class)->GetStructData(pointmarker);
		//構造体データの保存
		m_StructData = pointmarker;

		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == line_feature ){//3
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LINE);
		//構造体データ作成
		Line_Struct* line = new Line_Struct;
		((SXFMapF_LINEC*)m_Class)->GetStructData(line);
		//構造体データの保存
		m_StructData = line;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == polyline_feature ){//4

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_POLYLINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_POLYLINE);
		//構造体データ作成
		Polyline_Struct* polyline = new Polyline_Struct;
		((SXFMapF_POLYLINEC*)m_Class)->GetStructData(polyline);
		//構造体データの保存
		m_StructData = polyline;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == circle_feature ){//5

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CIRCLE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CIRCLE);
		//構造体データ作成
		Circle_Struct* circle = new Circle_Struct;
		((SXFMapF_CIRCLEC*)m_Class)->GetStructData(circle);
		//構造体データの保存
		m_StructData = circle;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == arc_feature ){//6
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_ARC);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_ARC);
		//構造体データ作成
		Arc_Struct* arc = new Arc_Struct;
		((SXFMapF_ARCC*)m_Class)->GetStructData(arc);
		//構造体データの保存
		m_StructData = arc;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == ellipse_feature ){//7
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ELLIPSE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ELLIPSE);
		//構造体データ作成
		Ellipse_Struct* ellipse = new Ellipse_Struct;
		((SXFMapF_ELLIPSEC*)m_Class)->GetStructData(ellipse);
		//構造体データの保存
		m_StructData = ellipse;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == ellipse_arc_feature ){//8

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ELLIPSE_ARC);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ELLIPSE_ARC);
		//構造体データ作成
		Ellipse_Arc_Struct* ellipsearc = new Ellipse_Arc_Struct;
		((SXFMapF_ELLIPSEARCC*)m_Class)->GetStructData(ellipsearc);
		//構造体データの保存
		m_StructData = ellipsearc;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == text_string_feature ){//9

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_TEXT);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_TEXT);

		//構造体データ作成
		Text_Struct* textstring = new Text_Struct;
		((SXFMapF_TEXTSTRINGC*)m_Class)->GetStructData(textstring);
		//構造体データの保存
		m_StructData = textstring;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == spline_feature ){//10

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_SPLINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_SPLINE);

		//構造体データ作成
		Spline_Struct* spline = new Spline_Struct;
		((SXFMapF_SPLINEC*)m_Class)->GetStructData(spline);
		//構造体データの保存
		m_StructData = spline;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == clothoid_feature ){//10

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CLOTHOID);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CLOTHOID);

		//構造体データ作成
		Clothoid_Struct* clothoid = new Clothoid_Struct;
		((SXFMapF_CLOTHOIDC*)m_Class)->GetStructData(clothoid);
		//構造体データの保存
		m_StructData = clothoid;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == sfig_org_feature ){//11

		//構造体データ作成
		Sfigorg_Struct* sfigorg = new Sfigorg_Struct;
		//構造体データの保存
		m_StructData = sfigorg;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == sfig_locate_feature ){//12

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_SFIG_LOCATE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_SFIG_LOCATE);
		//構造体データ作成
		Sfigloc_Struct* sfiglocate = new Sfigloc_Struct;
		((SXFMapF_SFIGLOCC*)m_Class)->GetStructData(sfiglocate);
		//構造体データの保存
		m_StructData = sfiglocate;
		//フィーチャレベル
		m_Level = 1;

	}else if(m_Type == externally_defined_symbol_feature ){//13

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_EXTERNALLY_DEFINED_SYMBOL);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_EXTERNALLY_DEFINED_SYMBOL);
		//構造体データ作成
		Externally_Defined_Symbol_Struct* exsymbol = new Externally_Defined_Symbol_Struct;
		((SXFMapF_EXSYMBOLC*)m_Class)->GetStructData(exsymbol);
		//構造体データの保存
		m_StructData = exsymbol;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == linear_dim_feature ){//14

		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LINEAR_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LINEAR_DIMENSION);

		//構造体データ作成
		LinearDim_Struct* lineardim = new LinearDim_Struct;
		((SXFMapF_LINERDIMC*)m_Class)->GetStructData(lineardim);
		//構造体データの保存
		m_StructData = lineardim;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == curve_dim_feature ){//15
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CURVE_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CURVE_DIMENSION);
		//構造体データ作成
		CurveDim_Struct* curvedim = new CurveDim_Struct;
		((SXFMapF_CURVEDIMC*)m_Class)->GetStructData(curvedim);
		//構造体データの保存
		m_StructData = curvedim;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == angular_dim_feature ){//15
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ANGULAR_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ANGULAR_DIMENSION);
		//構造体データ作成
		AngularDim_Struct* angulardim = new AngularDim_Struct;
		((SXFMapF_ANGULARDIMC*)m_Class)->GetStructData(angulardim);
		//構造体データの保存
		m_StructData = angulardim;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == radius_dim_feature ){//16
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_RADIUS_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_RADIUS_DIMENSION);
		//構造体データ作成
		RadiusDim_Struct* radiusdim = new RadiusDim_Struct;
		((SXFMapF_RADIUSDIMC*)m_Class)->GetStructData(radiusdim);
		//構造体データの保存
		m_StructData = radiusdim;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == diameter_dim_feature ){//17
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_DIAMETER_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_DIAMETER_DIMENSION);
		//構造体データ作成
		DiameterDim_Struct* diameterdim = new DiameterDim_Struct;
		((SXFMapF_DIMETERDIMC*)m_Class)->GetStructData(diameterdim);
		//構造体データの保存
		m_StructData = diameterdim;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == label_feature ){//18
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LABEL);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LABEL);

		//構造体データ作成
		Label_Struct* label = new Label_Struct;
		((SXFMapF_LABELC*)m_Class)->GetStructData(label);
		//構造体データの保存
		m_StructData = label;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == balloon_feature ){//19
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_BALLOON);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_BALLOON);

		//構造体データ作成
		Balloon_Struct* balloon = new Balloon_Struct;
		((SXFMapF_BALLOONC*)m_Class)->GetStructData(balloon);
		//構造体データの保存
		m_StructData = balloon;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == externally_defined_hatch_feature ){//20
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_EXTERNALLY_DEFINED_HATCH);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_EXTERNALLY_DEFINED_HATCH);

		//構造体データ作成
		Externally_Defined_Hatch_Struct* externallyhatch = new Externally_Defined_Hatch_Struct;
		((SXFMapF_EXHATCHC*)m_Class)->GetStructData(externallyhatch);
		//構造体データの保存
		m_StructData = externallyhatch;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == fill_area_style_colour_feature ){//21
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_FILL_AREA_STYLE_COLOUR);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_FILL_AREA_STYLE_COLOUR);

		//構造体データ作成
		Fill_area_style_colour_Struct* fillcolor = new Fill_area_style_colour_Struct;
		((SXFMapF_FILLCOLOURC*)m_Class)->GetStructData(fillcolor);
		//構造体データの保存
		m_StructData = fillcolor;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == fill_area_style_hatching_feature ){//22
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_FILL_AREA_STYLE_HATCHING);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_FILL_AREA_STYLE_HATCHING);

		//構造体データ作成
		Fill_area_style_hatching_Struct* fillstyle = new Fill_area_style_hatching_Struct;
		((SXFMapF_FILLHATCHINGC*)m_Class)->GetStructData(fillstyle);
		//構造体データの保存
		m_StructData = fillstyle;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == fill_area_style_tiles_feature){//23
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_FILL_AREA_STYLE_TILES);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_FILL_AREA_STYLE_TILES);

		//構造体データ作成
		Fill_area_style_tiles_Struct* filltiles = new Fill_area_style_tiles_Struct;
		((SXFMapF_FILLTILESC*)m_Class)->GetStructData(filltiles);
		//構造体データの保存
		m_StructData = filltiles;
		//フィーチャレベル
		m_Level = 2;

	}else if(m_Type == composite_curve_org_feature ){//24

		//構造体データ作成
		Ccurve_Org_Struct* curveorg = new Ccurve_Org_Struct;

		//構造体データの保存
		m_StructData = curveorg;
		//フィーチャレベル
		m_Level = 2;

	}else{//feature comment name error
		return FALSE;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						作成日：2001.07.21

	１．機能概要
		フィーチャ構造体を取得

	２．インターフェイス
	int		SXFMapGeometryC::GetStructData(
				char*&		OUT_Name,
				size_t		NameSize,
				LPVOID		&Out_Struct)

	引数  ：	型			引数名			内容
				char*&		OUT_Name		フィーチャ名
				size_t		NameSize,		フィーチャ名バッファサイズ
				LPVOID		&OUT_Struct		フィーチャ構造体

	復帰値：フィーチャＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.21	佐々木(FQS)
	更新		2015.04.27	T.Matsushima	JPCERT/CC 指摘 脆弱性対応
**/
int SXFMapGeometryC::GetStructData(
		char*&		OUT_Name,
		size_t		NameSize,		// バッファサイズを渡すように変更
		LPVOID		&OUT_Struct)
{
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(OUT_Name, m_TypeName);
	strcpy_s(OUT_Name, NameSize, m_TypeName);
	OUT_Struct 	= m_StructData;

	return (m_RootID) ;
}
