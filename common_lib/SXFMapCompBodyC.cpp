/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapCompBodyC.cpp						作成日：2000.04.21

	１．クラス概要
		COMPOSITE_CURVE_SEGMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/

#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFutyFunctionC.h"
#include "SXFMapEntCConvC.h"
//#include "ComSplitStringC.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFMapE_STYLED_ITEMC.h" 
#include "SXFMapE_TRIMMED_CURVEC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_VECTORC.h"
#include "SXFMapE_DIRECTIONC.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapE_ELLIPSEC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_POLYLINEC.h"
#include "SXFMapE_SPLINEC.h"
#include "SXFMapE_CLOTHOIDC.h"
#include "SXFMapE_COMPOSITE_CURVE_SEGMENTC.h"
#include "SXFMapA_CURVE_STYLEC.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapF_ARCC.h"
#include "SXFMapF_ELLIPSEARCC.h"
#include "SXFMapF_POLYLINEC.h"
#include "SXFMapF_SPLINEC.h"
#include "SXFMapF_CLOTHOIDC.h"
#include "SXFMapF_ARCC.h" 
#include "SXFMapF_POLYLINEC.h" 
#include "SXFMapT_trimming_preferenceE.h"
#include "SXFMapCompBodyC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCompBodyC.cpp						作成日：2000.04.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		SXFMapCompBodyC::SXFMapCompBodyC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

SXFMapCompBodyC::SXFMapCompBodyC( )
{
//
//	<初期化>
//

	m_InstID = m_AppeID = 0;
	m_InstP  = m_AppeP = NULL;

//	<SXFTableManagerCへのポインタ>
	m_TableManager=NULL;
//	<SXFReadAP202ManagerCへのポインタ>
	m_ReadManager=NULL;

//	<レイヤコード>
	m_layer = 0;
	m_color = 0;
	m_font  = 0;
	m_width =0;

//	<フィーチャタイプ>
	m_Type   = NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class  = NULL;

//< ANNOTATION_OCCURRENCE系 >/////////////////////////////////////
	m_AnnoKind = CURVESTYLE;
//	NONSTYLE,		//		0:不明
//	CURVESTYLE,
//	SYMBOLSTYLE,
//	FILLSTYLE,
//	TEXTSTYLE,
//	NULLSTYLE

//< ANNOTATION_CURVE_OCCURRENCEの種類 >////////////////////////////
	m_CurveKind =CURVE;
//	NONCURVE,			//0:不明
//	CURVE,				//1:一般要素
//	DIMENSION_CURVE,	//2:寸法線（狭義）
//	PROJECTION_CURVE	//3:寸法補助線

//< ANNOTATION_SYMBOL_OCCURRENCEの種類 >////////////////////////////
	m_SymbolKind =0;
//	NONSYMBOL,							//0:不明
//	SYMBOL,								//1:点マーカ、既定義（外部定義）、その他シンボル
//	DIM_CURVE_TERMINATOR,				//2:寸法端点矢印
//	LEADER_TERMINATOR,					//3:引き出し線、バルーン端点矢印
//	SUBFIGURE_OCCURRENCE				//4:複合図形配置（SUbfigure）

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCompBodyC.cpp						作成日：2000.04.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapCompBodyC::SXFMapCompBodyC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	引数：	型						引数名					内容
			SXFInstanceIDC* 		IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC*	 	IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			SXFReadAP202ManagerC* 	IN_ReadManager			Read管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapCompBodyC::SXFMapCompBodyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{

	m_InstID = m_AppeID = 0;
	m_InstP  = m_AppeP = NULL;

//	<SXFTableManagerCへのポインタ>
	m_TableManager=IN_TableManager;
//	<SXFReadAP202ManagerC>
	m_ReadManager= IN_ReadManager;

//	<レイヤコード>
	m_layer = 0;
	m_color = 0;
	m_font  = 0;
	m_width =0;

//	<フィーチャタイプ>
	m_Type   = NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class  = NULL;

//< ANNOTATION_OCCURRENCE系 >/////////////////////////////////////
	m_AnnoKind =CURVESTYLE;
//	NONSTYLE,		//		0:不明
//	CURVESTYLE,
//	SYMBOLSTYLE,
//	FILLSTYLE,
//	TEXTSTYLE,
//	NULLSTYLE

//< ANNOTATION_CURVE_OCCURRENCEの種類 >////////////////////////////
	m_CurveKind =CURVE;
//	NONCURVE,			//0:不明
//	CURVE,				//1:一般要素
//	DIMENSION_CURVE,	//2:寸法線（狭義）
//	PROJECTION_CURVE	//3:寸法補助線

//< ANNOTATION_SYMBOL_OCCURRENCEの種類 >////////////////////////////
	m_SymbolKind =0;
//	NONSYMBOL,							//0:不明
//	SYMBOL,								//1:点マーカ、既定義（外部定義）、その他シンボル
//	DIM_CURVE_TERMINATOR,				//2:寸法端点矢印
//	LEADER_TERMINATOR,					//3:引き出し線、バルーン端点矢印
//	SUBFIGURE_OCCURRENCE				//4:複合図形配置（SUbfigure）

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCompBodyC.cpp						作成日：2000.04.21

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapCompBodyC::~SXFMapCompBodyC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapCompBodyC::~SXFMapCompBodyC()
{
	if (m_Class!=NULL) {
		if ( m_Type == arc_feature ){
			delete (SXFMapF_ARCC*)m_Class;
		}
		else if ( m_Type == ellipse_arc_feature ){
			delete (SXFMapF_ELLIPSEARCC*)m_Class;
		}
		else if ( m_Type == polyline_feature ){
			delete (SXFMapF_POLYLINEC*)m_Class;
		}
		else if ( m_Type == spline_feature ){
			delete (SXFMapF_SPLINEC*)m_Class;
		}
		else if ( m_Type == clothoid_feature ){
			delete (SXFMapF_CLOTHOIDC*)m_Class;
		}
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCompBodyC.cpp						作成日：2000.04.21

	１．機能概要
		パラメータの設定

	２．インターフェイス
		int		int SXFMapCompBodyC::SetParameter()


	引数  ：	型			引数名				内容
			なし

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
/*
SXFMapCompBodyC::	SetParameter(
					E_type	OUT_Type,	//フィーチャ種別	
					LPVOID	OUT_Class)	//フィーチャクラスへのポインタ*/

int SXFMapCompBodyC::SetParameter()

{
//
//	<初期化>
//

	////////////////////////////////////////////////////////////////////////////////
	//  COMPOSITE_CURVE_SEGMENT エンティティクラス作成 
	////////////////////////////////////////////////////////////////////////////////

	SXFMapE_COMPOSITE_CURVE_SEGMENTC composite(m_InstanceIDManager);
	composite.SetRootID(m_RootID);
	composite.SetEntity();
	composite.SetParameter();
	
	m_InstID = composite.m_parent_curve_Inst;

	////////////////////////////////////////////////////////////////////////////////
	// レイヤ、色、線種、線幅の値設定 
	////////////////////////////////////////////////////////////////////////////////
	//	※COMPOSITE_CURVE_SEGMENTから参照される要素の属性は、全て０とする。
	////////////////////////////////////////////////////////////////////////////////

	m_layer = 0;
	m_color = 0;
	m_font  = 0;
	m_width =0;

	////////////////////////////////////////////////////////////////////////////////
	//  インスタンス情報の取得   	//////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	
	CString InstEntityName;
	InstEntityName = SXFMapInstIDC::GetEntityName(m_InstID);

	//TRIMMED_CURVE
	if (InstEntityName == DEF_TRIMMED_CURVE){

		SXFMapE_TRIMMED_CURVEC m_InstP(m_InstanceIDManager);
		m_InstP.SetRootID(m_InstID);
		m_InstP.SetParameter();
		
		//ARC
		if ( m_InstP.m_basis_curve_Name == DEF_CIRCLE ){
			if ( m_InstP.m_e_rep == cartesian ) {

			}
			else if ( m_InstP.m_e_rep == parameter ) {

				SXFMapF_ARCC* arc;
				arc = new SXFMapF_ARCC;
				
				arc->m_layer	= m_layer;
				arc->m_color	= m_color;
				arc->m_type  	= m_font;
				arc->m_line_width	= m_width;

				//円弧の中心
				arc->m_center_x = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;	
				arc->m_center_y = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;	
				//円弧の半径
				arc->m_radius = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_radius;
				//向きフラグ（０：半時計回り、１：時計回り）
				if ( m_InstP.m_sense == FALSE     ){
					arc->m_direction = 1;
				}
				else{
					arc->m_direction = 0;
				}
				//円弧の始角、終角
				arc->m_start_angle = m_InstP.m_trim1_para * 180. /acos(-1.) ;
				arc->m_end_angle   = m_InstP.m_trim2_para * 180. /acos(-1.) ;
				m_Type  = arc_feature;
				m_Class = arc;
			}
		}
		//ELLIPSE ARC
		else if ( m_InstP.m_basis_curve_Name == DEF_ELLIPSE ){
			if ( m_InstP.m_e_rep == cartesian ) {

			}
			else if ( m_InstP.m_e_rep == parameter ) {

				SXFMapF_ELLIPSEARCC* ellipsarc;
				ellipsarc = new SXFMapF_ELLIPSEARCC;

				ellipsarc->m_layer	= m_layer;
				ellipsarc->m_color	= m_color;
				ellipsarc->m_type  	= m_font;
				ellipsarc->m_line_width	= m_width;

				//楕円弧の中心
				ellipsarc->m_center_x = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;	
				ellipsarc->m_center_y = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;	
				//楕円弧のｘ方向半径、ｙ方向半径
				ellipsarc->m_radius_x = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_semi_axis_1;
				ellipsarc->m_radius_y = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_semi_axis_2;
				//向きフラグ（０：半時計回り、１：時計回り）
				if ( m_InstP.m_sense == FALSE     ){
					ellipsarc->m_direction = 1;
				}
				else{
					ellipsarc->m_direction = 0;
				}
				//楕円弧の回転角
				ellipsarc->m_rotation_angle  =	SXFutyFunctionC::calc_angle(
					((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_y ,
					((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_x   );	
			
				//楕円弧の始角、終角
				ellipsarc->m_start_angle = m_InstP.m_trim1_para * 180. /acos(-1.) ;
				ellipsarc->m_end_angle   = m_InstP.m_trim2_para * 180. /acos(-1.) ;
				m_Type  = ellipse_arc_feature;
				m_Class = ellipsarc;
			}
			else{
			}
		}	
		//CLOTHOID
		else if (InstEntityName == DEF_CLOTHOID){
			SXFMapF_CLOTHOIDC* clothoid;
			clothoid = new SXFMapF_CLOTHOIDC;

			clothoid->m_layer	= m_layer;
			clothoid->m_color	= m_color;
			clothoid->m_type  	= m_font;
			clothoid->m_line_width	= m_width;
			clothoid->base_x = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;
			clothoid->base_y = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;
			clothoid->parameter = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_parameter;
			//向きフラグ（０：半時計回り、１：時計回り）
			if (((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_direction == _T("1")) {
				clothoid->direction = 1;
			} else {
				clothoid->direction = 0;
			}
			clothoid->angle = SXFutyFunctionC::calc_angle(
					((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_y,
					((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_x);
			clothoid->start_length = m_InstP.m_trim1_para;
			clothoid->end_length = m_InstP.m_trim2_para;
			int	split = m_InstP.m_name.Find(',');
			if (split != -1)
			{
				clothoid->start_length = atof(m_InstP.m_name.Left(split));
				clothoid->end_length = atof(m_InstP.m_name.Mid(split + 1));
			}

			m_Type  = clothoid_feature;
			m_Class = clothoid;
		}
		else{
		// SCADECの対象ではないENTITYです
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//errメッセージ番号
				InstEntityName,		//エンティティ名
				2,					//パラメタの個数
				m_InstID,			//パラメタ
				InstEntityName
				);
			return SXFEXCEPT;
		}
	}
	//POLYLINE
	else if (InstEntityName == DEF_POLYLINE){
		SXFMapE_POLYLINEC m_InstP(m_InstanceIDManager);
		m_InstP.SetRootID(m_InstID);
		m_InstP.SetParameter();

		SXFMapF_POLYLINEC* polyline;
		polyline = new SXFMapF_POLYLINEC;

		polyline->m_layer	= m_layer;
		polyline->m_color	= m_color;
		polyline->m_type  	= m_font;
		polyline->m_line_width	= m_width;

		polyline->m_number =m_InstP.m_PointCount;
		for ( int c_pnt=0;c_pnt<m_InstP.m_PointCount;c_pnt++){
			polyline->m_x.Add( m_InstP.m_PointArray_p[c_pnt]->m_x );
			polyline->m_y.Add( m_InstP.m_PointArray_p[c_pnt]->m_y );
		}
		m_Type  = polyline_feature;
		m_Class = polyline;
	}
	//BEZIER_CURVE
	else if (InstEntityName == DEF_BEZIER_CURVE){
		SXFMapE_SPLINEC m_InstP(m_InstanceIDManager);
		m_InstP.SetRootID(m_InstID);
		m_InstP.SetParameter();

		SXFMapF_SPLINEC* spline;
		spline = new SXFMapF_SPLINEC;

		spline->m_layer	= m_layer;
		spline->m_color	= m_color;
		spline->m_type			= m_font;
		spline->m_line_width	= m_width;

		spline->m_open_close = !(m_InstP.m_ClosedCurveFlg);
		spline->m_number =m_InstP.m_PointCount;
		for ( int c_pnt=0;c_pnt<m_InstP.m_PointCount;c_pnt++){
			spline->m_x.Add( m_InstP.m_PointArray_P[c_pnt]->m_x );
			spline->m_y.Add( m_InstP.m_PointArray_P[c_pnt]->m_y );
		}
		m_Type  = spline_feature;
		m_Class = spline;

	}
	else{
	// SCADECの対象ではないENTITYです
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//errメッセージ番号
			InstEntityName,		//エンティティ名
			2,					//パラメタの個数
			m_InstID,			//パラメタ
			InstEntityName
			);
		return SXFEXCEPT;
	}

	return 0;

}
