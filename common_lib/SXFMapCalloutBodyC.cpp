/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．クラス概要
		DRAUGHTING_CALLOUT系のBODYを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/

#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapEntCConvC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapF_LINEC.h" 
#include "SXFMapAnnoBodyC.h"
#include "SXFMapF_CURVEDIMC.h" 
#include "SXFMapF_ANGULARDIMC.h" 
#include "SXFMapF_ARCC.h" 
#include "SXFMapF_BALLOONC.h" 
#include "SXFMapF_CIRCLEC.h" 
#include "SXFMapF_DIMETERDIMC.h" 
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
#include "SXFMapCalloutBodyC.h"	
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapCalloutBodyC::SXFMapCalloutBodyC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapCalloutBodyC::SXFMapCalloutBodyC( )
{
//
//	<初期化>
//
//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
	m_CalloutKind =0;
//		0:不明
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION系 >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER系 >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON
//

	m_ContentsNum = 0;
//	<コンテンツへのＩＤ>
	m_ContentsID.RemoveAll() ;
//	<コンテンツへのポインタ>
	m_ContentsP.RemoveAll();

//	<SXFTableManagerCへのポインタ>
	m_TableManager=NULL;
//	<SXFReadAP202ManagerCへのポインタ>
	m_ReadManager=NULL;

//	<レイヤコード>
	m_layer=0;
//	<フィーチャタイプ>
	m_Type=NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class=NULL;

// DIMENSION LINE フラグ
	 m_dimline=0;
//DIMENSION ARC フラグ
	 m_dimarc=0;
// DIMENSION TEXT フラグ
	 m_dimtext=0;
// PROJECTION LINE1 フラグ
	 m_prjline1=0;
// PROJECTION LINE2 フラグ
	 m_prjline2=0;
// LEADER CURVE フラグ
	 m_leader=0;
// TERM1 フラグ
	 m_term1=0;
// TERM2 フラグ
	 m_term2=0;
// CIRCLE フラグ
	 m_balloon =0;

// DIMENSION LINE へのポインタ
	m_dimlineP=NULL;

// DIMENSION ARCへのポインタ
	m_dimarcP=NULL;

// DIMENSION TEXT へのポインタ
	m_dimtextP=NULL;

// PROJECTION LINE1 へのポインタ
	m_prjline1P=NULL;

// PROJECTION LINE2 へのポインタ
	m_prjline2P=NULL;

// LEADER CURVEへのポインタ
	m_leader=NULL;

// TERM1 へのポインタ
	m_term1P=NULL;

// TERM2 へのポインタ
	m_term2P=NULL;

// CIRCLE へのポインタ
	m_balloonP=NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapCalloutBodyC::SXFMapCalloutBodyC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型						引数名					内容
			SXFInstanceIDC* 		IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC* 		IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			SXFReadAP202ManagerC* 	IN_ReadManager			Read管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

//	<インスタンスＩＤへのポインタを登録し生成する>
		
SXFMapCalloutBodyC::SXFMapCalloutBodyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	
//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
	m_CalloutKind =0;
//		0:不明
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION系 >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER系 >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON
//
//	<コンテンツへのＩＤ>
	m_ContentsID.RemoveAll() ;
//	<コンテンツへのポインタ>
	m_ContentsP.RemoveAll();

//	<レイヤコード>
	m_layer=0;
//	<フィーチャタイプ>
	m_Type=NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class=NULL;

// DIMENSION LINE フラグ
	 m_dimline=0;
//DIMENSION ARC フラグ
	 m_dimarc=0;
// DIMENSION TEXT フラグ
	 m_dimtext=0;
// PROJECTION LINE1 フラグ
	 m_prjline1=0;
// PROJECTION LINE2 フラグ
	 m_prjline2=0;
// LEADER CURVE フラグ
	 m_leader=0;
// TERM1 フラグ
	 m_term1=0;
// TERM2 フラグ
	 m_term2=0;
// CIRCLE フラグ
	 m_balloon =0;

// DIMENSION LINE へのポインタ
	m_dimlineP=NULL;

// DIMENSION ARCへのポインタ
	m_dimarcP=NULL;

// DIMENSION TEXT へのポインタ
	m_dimtextP=NULL;

// PROJECTION LINE1 へのポインタ
	m_prjline1P=NULL;

// PROJECTION LINE2 へのポインタ
	m_prjline2P=NULL;

// LEADER CURVEへのポインタ
	m_leader=NULL;

// TERM1 へのポインタ
	m_term1P=NULL;

// TERM2 へのポインタ
	m_term2P=NULL;  

// CIRCLE へのポインタ
	m_balloonP=NULL;
	
//	<SXFTableManagerCへのポインタ>
    m_TableManager = IN_TableManager;
//	<SXFReadAP202ManagerC>
	m_ReadManager= IN_ReadManager;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapCalloutBodyC::~SXFMapCalloutBodyC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapCalloutBodyC::~SXFMapCalloutBodyC()
{

	if (m_Class!=NULL){
		if ( m_Type == linear_dim_feature )
		 delete (SXFMapF_LINERDIMC*)m_Class;
		if ( m_Type == curve_dim_feature )
		 delete (SXFMapF_CURVEDIMC*)m_Class;
		if ( m_Type == angular_dim_feature )
		 delete (SXFMapF_ANGULARDIMC*)m_Class;
		if ( m_Type == radius_dim_feature )
		 delete (SXFMapF_RADIUSDIMC*)m_Class;
		if ( m_Type == diameter_dim_feature )
		 delete (SXFMapF_DIMETERDIMC*)m_Class;
		if ( m_Type == label_feature )
		 delete (SXFMapF_LABELC*)m_Class;
		if ( m_Type == balloon_feature )
		 delete (SXFMapF_BALLOONC*)m_Class;
	}

	for(int i=0;i<m_ContentsP.GetSize();i++){
		if( m_ContentsP[i] != NULL)
			delete m_ContentsP[i];
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．機能概要
		DRAUGHTING_CALLOUT系フィーチャパラメタ設定

	２．インターフェイス
		void	SXFMapCalloutBodyC::	SetFeatureParameter()


	引数  ：	型			引数名				内容
			なし

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
int	SXFMapCalloutBodyC::	SetFeatureParameter()
{
//
//	<初期化>
//
	int ircode =0;

	// DIMENSION LINE フラグ
	 m_dimline=0;
	//DIMENSION ARC フラグ
	 m_dimarc=0;
	// DIMENSION TEXT フラグ
	 m_dimtext=0;
	// PROJECTION LINE1 フラグ
	 m_prjline1=0;
	// PROJECTION LINE2 フラグ
	 m_prjline2=0;
	// LEADER CURVE フラグ
	 m_leader=0;
	// TERM1 フラグ
	 m_term1=0;
	// TERM2 フラグ
	 m_term2=0;
	// CIRCLE フラグ
	 m_balloon =0;

	//親玉の種別判定と親玉に合わせたBODYクラス作成
	ircode = CheckBodyKind();
	if ( ircode <0 )return ircode;

	////////////////////////////////////////////////////////////////////////////////
	// コンテンツのＩＤを取り出す
	////////////////////////////////////////////////////////////////////////////////

//  DRAUGHTING_CALLOUT((#1968, #1974, #1983, #1993))

	// COMPLEXエンティティのデータを取り出す
	SXFMapEntCConvC convert(m_EntityArray);

	//	STYLED_ITEM のパラメタを取り出す
	convert.SplitComplex(DEF_DRAUGHTING_CALLOUT);
	convert.GetSetInst(0,m_ContentsNum,m_ContentsID);			

	////////////////////////////////////////////////////////////////////////////////
	// コンテンツ数の図形インスタンス（SXFMapAnnoBodyC）を作成する
	////////////////////////////////////////////////////////////////////////////////

	// ANNOTATION_OCCURRENCE系のBODYクラス作成

	for ( int i=0; i<m_ContentsNum;i++){

		SXFMapAnnoBodyC* annobody =
			new SXFMapAnnoBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
		m_ContentsP.Add(annobody);
		ircode = annobody->SetRootID(m_ContentsID[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = annobody->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		//DIMENSION_CURVE
		if(annobody->m_Type == line_feature){
			//	DIMENSION_CURVE,	//2:寸法線（狭義）
			if (annobody->m_CurveKind ==2 ){
				m_dimline  = 1;
				m_dimlineP = ((SXFMapF_LINEC*)(annobody->m_Class));
			}
			//	PROJECTION_CURVE	//3:寸法補助線
			else if (annobody->m_CurveKind ==3 ){
				if ( ((SXFMapF_LINEC*)(annobody->m_Class))->m_flag ==1 ){
					m_prjline1  =1;
					m_prjline1P = ((SXFMapF_LINEC*)(annobody->m_Class));
				}
				else if ( ((SXFMapF_LINEC*)(annobody->m_Class))->m_flag ==2) {
					m_prjline2  =1;
					m_prjline2P = ((SXFMapF_LINEC*)(annobody->m_Class) );
				}
				else{
					m_prjline1  =1;
					m_prjline1P = ((SXFMapF_LINEC*)(annobody->m_Class));
					
				}
			}
			else{
				//err
			}
		}
		//DIMENSION ARC
		else if(annobody->m_Type == arc_feature ){
			m_dimarc  = 1;
			m_dimarcP = ((SXFMapF_ARCC*)(annobody->m_Class ));

		}
		//LIEADER_CURVE
		else if(annobody->m_Type == polyline_feature){
			m_leader  = 1;
			m_leaderP = ((SXFMapF_POLYLINEC*)(annobody->m_Class));

		}
		//DIMTEXT
		else if(annobody->m_Type == text_string_feature){
			m_dimtext  =1;
			m_dimtextP = ((SXFMapF_TEXTSTRINGC*)(annobody->m_Class));

		}
		//ARRAW
		else if(annobody->m_Type == dimension_terminator_symbol){
			//半径寸法は矢印一つ
			//	4:RADIUS_DIMENSION///////////////////////////////////////
			if (m_DimensionKind == 4){
				if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==2 ){
					((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag = 1;
				}
			}
			if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==1 ){
				m_term1  = 1;
				m_term1P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
			else if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==2 ){
				m_term2  = 1;
				m_term2P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
			else{
				m_term1  = 1;
				m_term1P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
		}
		//CIRCLE
		else if(annobody->m_Type == circle_feature){
			m_balloon  =1;
			m_balloonP = ((SXFMapF_CIRCLEC*)(annobody->m_Class));

		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// コンテンツ＝寸法要素のチェック
	////////////////////////////////////////////////////////////////////////////////
	// DIMENSION LINE または、DIMENSION ARC はあるか？
	if ( m_dimline==0 && m_dimarc==0 && m_leader == 0 ) {
		//DRAUGHTING_CALLOUT の構成データに異常があります。
		return -10000;	
	}

	//	1:DIMENSION_CURVE_DIRECTED_CALLOUT系///////////////////////////////////////
	if ( m_CalloutKind == 1 ){

		//	1:LINEAR_DIMENSION系///////////////////////////////////////
		if (m_DimensionKind == 1){
			if ( m_ContentsNum > 6 ){
				//err
			}
		}
		//	2:ANGULAR_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 2){

		}
		//	3:DIAMETER_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 3){

		}
		//	4:RADIUS_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 4){

		}
		//	5:CURVE_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 5){

		}
	
	}
	//	2:LEADER_DIRECTED_CALLOUT系////////////////////////////////////////////////
	else if ( m_CalloutKind == 2 ){
		if ( m_balloon == 1 ){
			m_DimensionKind = 2;
		}
		else{
			m_DimensionKind = 1;
		}
		//	1:LABEL 系///////////////////////////////////////
		if (m_DimensionKind == 1){

		}
		//	2:BALLOON 系///////////////////////////////////////
		else if (m_DimensionKind == 2){

		}

	}

	////////////////////////////////////////////////////////////////////////////////
	// コンテンツの要素から必要な情報を取り出す。
	////////////////////////////////////////////////////////////////////////////////

	//	1:DIMENSION_CURVE_DIRECTED_CALLOUT系///////////////////////////////////////
	if ( m_CalloutKind == 1 ){

		//	1:LINEAR_DIMENSION系///////////////////////////////////////
		if (m_DimensionKind == 1){
			SXFMapF_LINERDIMC* linedim;
			linedim = new SXFMapF_LINERDIMC;

			linedim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;			//レイヤコード
			linedim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;			//色コード
			linedim->m_type  = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//線種コード
			linedim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//線幅コード
			
			linedim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;	
			linedim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			linedim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			linedim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;
			if ( m_prjline1 == 0 ) {   
				linedim->m_flg2 =0 ;
			}
			else {
				linedim->m_flg2 =1 ;
				linedim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;	
				linedim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y;
				linedim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				linedim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				linedim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				linedim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}
			if ( m_prjline2 == 0 ) {   
				linedim->m_flg3 =0;
			}
			else{
				linedim->m_flg3 =1;
				linedim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				linedim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				linedim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				linedim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				linedim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				linedim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;
			if ( m_term1 == 0 ) { 
				linedim->m_arr1_code2 = 0;
			}
			else{
				linedim->m_arr1_code2= 1 ;
				linedim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				linedim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				linedim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				linedim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				linedim->m_arr2_code2 = 0;
			}
			else{
				linedim->m_arr2_code2=1 ;
				linedim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				linedim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				linedim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				linedim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}

			linedim->SetArrFlag(
				m_term1, m_term2,
				linedim->m_sun_x1, linedim->m_sun_y1,	//寸法線の始点
				linedim->m_sun_x2, linedim->m_sun_y2,	//寸法線の終点
				tmvec_x1,	tmvec_y1,					//矢印１のベクトルXY
				tmvec_x2,	tmvec_y2					//矢印２のベクトルXY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty() ){
					linedim->m_flg4 = 0;
				}
				else{
					linedim->m_flg4 = 1;
				}

				linedim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

 				linedim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;   

				linedim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				linedim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				linedim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				linedim->m_width  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				linedim->m_spc    = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				linedim->m_angle  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				linedim->m_slant  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				linedim->m_b_pnt  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				linedim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = linear_dim_feature;
			m_Class = linedim;
		}
		//	5:CURVE_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 5){
			SXFMapF_CURVEDIMC* curvedim;
			curvedim = new SXFMapF_CURVEDIMC;

			curvedim->m_layer = ((SXFMapF_ARCC*)m_dimarcP)->m_layer ;			//レイヤコード
			curvedim->m_color = ((SXFMapF_ARCC*)m_dimarcP)->m_color ;			//色コード
			curvedim->m_type  = ((SXFMapF_ARCC*)m_dimarcP)->m_type ;			//線種コード
			curvedim->m_line_width = ((SXFMapF_ARCC*)m_dimarcP)->m_line_width ;	//線幅コード

			curvedim->m_sun_x = ((SXFMapF_ARCC*)m_dimarcP)->m_center_x ;
			curvedim->m_sun_y = ((SXFMapF_ARCC*)m_dimarcP)->m_center_y ;                 
			curvedim->m_sun_radius = ((SXFMapF_ARCC*)m_dimarcP)->m_radius ;
			curvedim->m_sun_angle0 = ((SXFMapF_ARCC*)m_dimarcP)->m_start_angle ;
			curvedim->m_sun_angle1 = ((SXFMapF_ARCC*)m_dimarcP)->m_end_angle ;

			if ( m_prjline1 == 0 ) {
	    		curvedim->m_flg2=0 ;
			}
			else{
				curvedim->m_flg2=1 ;
				curvedim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;
				curvedim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y ;
				curvedim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				curvedim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				curvedim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				curvedim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}

			if ( m_prjline2 == 0 ) {
				curvedim->m_flg3=0 ;
			}
			else{
				curvedim->m_flg3=1 ;
				curvedim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				curvedim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				curvedim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				curvedim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				curvedim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				curvedim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;

			if ( m_term1 == 0 ) { 
				curvedim->m_arr1_code2 =0 ;
			}
			else{
				curvedim->m_arr1_code2 =1 ;
				curvedim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				curvedim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				curvedim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				curvedim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				curvedim->m_arr2_code2 =0;
			}
			else{
				curvedim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				curvedim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				curvedim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				curvedim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			curvedim->SetArrFlag(
				m_term1, m_term2,
				curvedim->m_sun_x, curvedim->m_sun_y,	//寸法線の原点（中心）
				curvedim->m_arr1_x,	//矢印１配置点X
				curvedim->m_arr1_y,	//矢印１配置点Y
				curvedim->m_arr2_x,	//矢印２配置点X
				curvedim->m_arr2_y,	//矢印２配置点Y				
				tmvec_x1,	tmvec_y1,					//矢印１のベクトルXY
				tmvec_x2,	tmvec_y2					//矢印２のベクトルXY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					curvedim->m_flg4 = 0;
				}
				else{
					curvedim->m_flg4 = 1;
				}
				curvedim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				curvedim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				curvedim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				curvedim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				curvedim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				curvedim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				curvedim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				curvedim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				curvedim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				curvedim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				curvedim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = curve_dim_feature;
			m_Class = curvedim;

		}
		//	2:ANGULAR_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 2){
			SXFMapF_ANGULARDIMC* angledim;
			angledim = new SXFMapF_ANGULARDIMC;

			angledim->m_layer = ((SXFMapF_ARCC*)m_dimarcP)->m_layer ;			//レイヤコード
			angledim->m_color = ((SXFMapF_ARCC*)m_dimarcP)->m_color ;			//色コード
			angledim->m_type  = ((SXFMapF_ARCC*)m_dimarcP)->m_type ;			//線種コード
			angledim->m_line_width = ((SXFMapF_ARCC*)m_dimarcP)->m_line_width ;	//線幅コード

			angledim->m_sun_x = ((SXFMapF_ARCC*)m_dimarcP)->m_center_x ;
			angledim->m_sun_y = ((SXFMapF_ARCC*)m_dimarcP)->m_center_y ;                 
			angledim->m_sun_radius = ((SXFMapF_ARCC*)m_dimarcP)->m_radius ;
			angledim->m_sun_angle0 = ((SXFMapF_ARCC*)m_dimarcP)->m_start_angle ;
			angledim->m_sun_angle1 = ((SXFMapF_ARCC*)m_dimarcP)->m_end_angle ;

			if ( m_prjline1 == 0 ) {
	    		angledim->m_flg2=0 ;
			}
			else{
				angledim->m_flg2=1 ;
				angledim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;
				angledim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y ;
				angledim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				angledim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				angledim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				angledim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}

			if ( m_prjline2 == 0 ) {
				angledim->m_flg3=0 ;
			}
			else{
				angledim->m_flg3=1 ;
				angledim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				angledim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				angledim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				angledim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				angledim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				angledim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;

			if ( m_term1 == 0 ) { 
				angledim->m_arr1_code2 =0 ;
			}
			else{
				angledim->m_arr1_code2 =1 ;
				angledim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				angledim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				angledim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				angledim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				angledim->m_arr2_code2 =0;
			}
			else{
				angledim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				angledim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				angledim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				angledim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			angledim->SetArrFlag(
				m_term1, m_term2,
				angledim->m_sun_x, angledim->m_sun_y,	//寸法線の原点（中心）
				angledim->m_arr1_x,	//矢印１配置点X
				angledim->m_arr1_y,	//矢印１配置点Y
				angledim->m_arr2_x,	//矢印２配置点X
				angledim->m_arr2_y,	//矢印２配置点Y				
				tmvec_x1,	tmvec_y1,					//矢印１のベクトルXY
				tmvec_x2,	tmvec_y2					//矢印２のベクトルXY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					angledim->m_flg4 = 0;
				}
				else{
					angledim->m_flg4 = 1;
				}
				angledim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				angledim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				angledim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				angledim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				angledim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				angledim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				angledim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				angledim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				angledim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				angledim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				angledim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = angular_dim_feature;
			m_Class = angledim;

		}
		//	3:DIAMETER_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 3){

			SXFMapF_DIMETERDIMC* dimeterdim;
			dimeterdim = new SXFMapF_DIMETERDIMC;	

			dimeterdim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;		//レイヤコード
			dimeterdim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;		//色コード
			dimeterdim->m_type = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//線種コード
			dimeterdim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//線幅コード

			dimeterdim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;
			dimeterdim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			dimeterdim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			dimeterdim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;

			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;
			if ( m_term1 == 0 ) { 
				dimeterdim->m_arr1_code2=0 ;
			}
			else{
				dimeterdim->m_arr1_code2=1 ;
				dimeterdim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				dimeterdim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				dimeterdim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				dimeterdim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}
			if ( m_term2 == 0 ) { 
				dimeterdim->m_arr2_code2 = 0 ;
			}
			else{
				dimeterdim->m_arr2_code2 = 1 ;
				dimeterdim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				dimeterdim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				dimeterdim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				dimeterdim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			
			dimeterdim->SetArrFlag(
				m_term1, m_term2,
				dimeterdim->m_sun_x1, dimeterdim->m_sun_y1,	//寸法線の始点
				dimeterdim->m_sun_x2, dimeterdim->m_sun_y2,	//寸法線の終点
				tmvec_x1,	tmvec_y1,					//矢印１のベクトルXY
				tmvec_x2,	tmvec_y2					//矢印２のベクトルXY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					dimeterdim->m_flg = 0;
				}
				else{
					dimeterdim->m_flg = 1;
				}
				dimeterdim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				dimeterdim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				dimeterdim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				dimeterdim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				dimeterdim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				dimeterdim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				dimeterdim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				dimeterdim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				dimeterdim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				dimeterdim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				dimeterdim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = diameter_dim_feature;
			m_Class = dimeterdim;
		}
		//	4:RADIUS_DIMENSION系///////////////////////////////////////
		else if (m_DimensionKind == 4){
			SXFMapF_RADIUSDIMC* radiusdim;
			radiusdim = new SXFMapF_RADIUSDIMC;

			radiusdim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;		//レイヤコード
			radiusdim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;		//色コード
			radiusdim->m_type = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//線種コード
			radiusdim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//線幅コード

			radiusdim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;
			radiusdim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			radiusdim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			radiusdim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;

			double tmvec_x,tmvec_y;
			tmvec_x =tmvec_y =0.;
			if ( m_term1 == 0 ) { 
				radiusdim->m_arr_code2 = 0 ;
			}
			else{
				radiusdim->m_arr_code2 = 1 ;
				radiusdim->m_arr_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				radiusdim->m_arr_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				radiusdim->m_arr_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				radiusdim->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			radiusdim->SetArrFlag(
				m_term1, 	//矢印の有り無しフラグ
				radiusdim->m_sun_x1, radiusdim->m_sun_y1,	//寸法線の始点
				radiusdim->m_sun_x2, radiusdim->m_sun_y2,	//寸法線の終点
				tmvec_x,	tmvec_y								//矢印１のベクトルXY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					radiusdim->m_flg = 0;
				}
				else{
					radiusdim->m_flg = 1;
				}
				radiusdim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				radiusdim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				radiusdim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				radiusdim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				radiusdim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				radiusdim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				radiusdim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				radiusdim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				radiusdim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				radiusdim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				radiusdim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = radius_dim_feature;
			m_Class = radiusdim;
		}
	}
	//	2:LEADER_DIRECTED_CALLOUT系////////////////////////////////////////////////
	else if ( m_CalloutKind == 2 ){
		
		//	1:LABEL 系///////////////////////////////////////
		if (m_DimensionKind == 1){
			SXFMapF_LABELC* label;
			label = new SXFMapF_LABELC;

			label->m_layer = ((SXFMapF_POLYLINEC*)m_leaderP)->m_layer ;		//レイヤコード
			label->m_color = ((SXFMapF_POLYLINEC*)m_leaderP)->m_color ;		//色コード
			label->m_type = ((SXFMapF_POLYLINEC*)m_leaderP)->m_type ;			//線種コード
			label->m_line_width = ((SXFMapF_POLYLINEC*)m_leaderP)->m_line_width ;	//線幅コード

    		label->m_vertex_number = ((SXFMapF_POLYLINEC*)m_leaderP)->m_number ;
			label->m_vertex_x.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_x );
			label->m_vertex_y.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_y );

			if ( m_term1 == 1 ) { 
				//	折れ線の入れ替えをする
				label->SetVertex(
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x,
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_number,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_x,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_y	);

				label->m_arr_code = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				label->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
			}
			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()) {
					label->m_flg = 0;
				}
				else{
					label->m_flg = 1;
				}
				label->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;
				label->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;
	    		label->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				label->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				label->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				label->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				label->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				label->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				label->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				label->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				label->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = label_feature;
			m_Class = label;

		}
		//	2:BALLOON 系///////////////////////////////////////
		else if (m_DimensionKind == 2){
			SXFMapF_BALLOONC* balloon;
			balloon = new SXFMapF_BALLOONC;

			balloon->m_layer = ((SXFMapF_POLYLINEC*)m_leaderP)->m_layer ;		//レイヤコード
			balloon->m_color = ((SXFMapF_POLYLINEC*)m_leaderP)->m_color ;		//色コード
			balloon->m_type = ((SXFMapF_POLYLINEC*)m_leaderP)->m_type ;		//線種コード
			balloon->m_line_width = ((SXFMapF_POLYLINEC*)m_leaderP)->m_line_width ;	//線幅コード

			balloon->m_vertex_number = ((SXFMapF_POLYLINEC*)m_leaderP)->m_number ;

			balloon->m_vertex_x.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_x );
			balloon->m_vertex_y.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_y );

			balloon->m_center_x = ((SXFMapF_CIRCLEC*)m_balloonP)->m_center_x ;
			balloon->m_center_y = ((SXFMapF_CIRCLEC*)m_balloonP)->m_center_y ;
			balloon->m_radius = ((SXFMapF_CIRCLEC*)m_balloonP)->m_radius ;

			if ( m_term1 == 1 ) { 
				//	折れ線の入れ替えをする
				balloon->SetVertex(
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x,
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_number,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_x,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_y	);
				balloon->m_arr_code = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				balloon->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
			}

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty() ){
					balloon->m_flg = 0;
				}
				else{
					balloon->m_flg = 1;
				}

				balloon->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;
				balloon->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;
	    		balloon->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				balloon->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				balloon->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				balloon->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				balloon->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				balloon->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				balloon->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				balloon->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				balloon->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = balloon_feature;
			m_Class = balloon;
		}
	}

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						作成日：2000.04.21

	１．機能概要
		Bodyの種別判定

	２．インターフェイス
		int		SXFMapCalloutBodyC::CheckBodyKind()
					

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

int SXFMapCalloutBodyC::CheckBodyKind()
{

//< DRAUGHTING_CALLOUT系 >/////////////////////////////////////
	m_CalloutKind =0;
//		0:不明
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION系 >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER系 >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON


//	<親玉の判定>


	//要素のチェック
	if (m_EntityData.Find(DEF_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_GEOMETRIC_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_DRAUGHTING_ELEMENTS) == -1){
		//err
	}

	//<DRAUGHTING_CALLOUTの判定>
	//<寸法線系>
	if (m_EntityData.Find(DEF_DIMENSION_CURVE_DIRECTED_CALLOUT) != -1){
		m_CalloutKind = 1;

		// 直線寸法 ////////////////////////////////////////////////////////
		if (m_EntityData.Find(DEF_LINEAR_DIMENSION) != -1){
			m_DimensionKind =1;
		}
		// 弧長寸法 ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_CURVE_DIMENSION) != -1){
			m_DimensionKind =5;
		}
		// 角度寸法 ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_ANGULAR_DIMENSION) != -1){
			m_DimensionKind =2;
		}
		// 直径寸法 ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_DIAMETER_DIMENSION) != -1){
			m_DimensionKind =3;
		}
		// 半径寸法 ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_RADIUS_DIMENSION) != -1){
			m_DimensionKind =4;
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
	
	//<引出線系>
	else if (m_EntityData.Find(DEF_LEADER_DIRECTED_CALLOUT) != -1){
		m_CalloutKind = 2;
		
	}
	else {
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
