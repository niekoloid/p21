/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．クラス概要
		AP202エンティティからフィーチャへのマッピングを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2001.06.21	

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapE_DRAWING_SHEET_REVISION_USAGEC.h" 
#include "SXFMapE_SYMBOL_REPRESENTATION_MAPC.h" 
#include "SXFMapE_COMPOSITE_CURVEC.h" 
#include "SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h" 
#include "SXFMapE_PLANAR_BOXC.h"
#include "SXFMapE_STYLED_ITEMC.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapF_SHEETC.h" 
#include "SXFMapF_SFIGORGC.h" 
#include "SXFMapF_COMPOSITEC.h" 
#include "SXFMapAssemblyC.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntCConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
	
/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapAssemblyC::SXFMapAssemblyC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
SXFMapAssemblyC::SXFMapAssemblyC()
{
//
//	<初期化>
//
//	<BODY種別> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:不明
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerCへのポインタ>
	m_TableManager=NULL;
	m_ComInfoC=NULL;

//	<アセンブリ要素のエンティティへのポインタ>
	m_AssmP = NULL ;
//	<フィーチャタイプ>
	m_Type  = NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class = NULL;
//	<フィーチャ名>
//  char m_TypeName[30];
//	<フィーチャ構造体へのポインタ>
	m_StructData = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapAssemblyC::SXFMapAssemblyC(
					SXFInstanceIDC* IN_InstanceIDManeger, 
					SXFTableManagerC* IN_TableManager,
					SXFComInfoC* IN_ComInfoC )
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	引数：	型					引数名					内容
			SXFInstanceIDC* 	IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC* 	IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			SXFComInfoC*		IN_ComInfoC				共通情報管理ｵﾌﾞｼﾞｪｸﾄ		

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapAssemblyC::SXFMapAssemblyC(
		SXFInstanceIDC* IN_InstanceIDManeger, 
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC )
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
//	<BODY種別> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:不明
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerCへのポインタ>
	m_TableManager=IN_TableManager;
//	<SXFComInfoCへのポインタ>
	m_ComInfoC = IN_ComInfoC;

//	<アセンブリ要素のエンティティへのポインタ>
	m_AssmP = NULL ;
//	<フィーチャタイプ>
	m_Type = NONFEATURE;
//	<フィーチャクラスへのポインタ>
	m_Class = NULL;
//	<フィーチャ名>
//  char m_TypeName[30];
//	<フィーチャ構造体へのポインタ>
	m_StructData = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapAssemblyC::~SXFMapAssemblyC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
SXFMapAssemblyC::~SXFMapAssemblyC()
{
	if (m_Class !=NULL ){
		if (m_Type == drawing_sheet_feature)
			delete (SXFMapF_SHEETC*)m_Class;
		if (m_Type == sfig_org_feature)
			delete (SXFMapF_SFIGORGC*)m_Class;
		if (m_Type == composite_curve_org_feature)
			delete (SXFMapF_COMPOSITEC*)m_Class;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		一般要素フィーチャ構造体の作成

	２．インターフェイス
		int		SXFMapAssemblyC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	引数  ：	型			引数名				内容
				int		OUT_type,	//アセンブリ種別
									1:用紙
									2:複合図形
									3:複合曲線
				void*	OUT_Class)	//フィーチャクラスへのポインタ


	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
int	SXFMapAssemblyC::	SetFeatureParameter(
					int		&OUT_Type,	//アセンブリ種別	
					LPVOID	&OUT_Class)	//フィーチャクラスへのポインタ

{
//
//	<初期化>
//
//	DEL(S)	チューニング対応	K.Naono	03.07.10
/*
	CStringArray type,orient;
	//用紙サイズ種別
	CString a0("A0");
	CString a1("A1");
	CString a2("A2");
	CString a3("A3");
	CString a4("A4");
	type.Add((LPCTSTR)a0);
	type.Add((LPCTSTR)a1);
	type.Add((LPCTSTR)a2);
	type.Add((LPCTSTR)a3);
	type.Add((LPCTSTR)a4);
	//縦/横区分
	CString a10(DEF_vertical);
	CString a11(DEF_horizontal);
	orient.Add((LPCTSTR)a10);
	orient.Add((LPCTSTR)a11);
	CString BodyData, BodyName;
*/
//	DEL(E)	チューニング対応	K.Naono	03.07.10
	//親玉の種別判定と親玉に合わせたBODYクラス作成

//	<BODY種別> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:不明
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

// #1400 = DRAWING_SHEET_REVISION_USAGE(#1412, #1402, '01');
// #1040 = SYMBOL_REPRESENTATION_MAP(#1046, #1047);
// #1121 = COMPOSITE_CURVE('composite_curve3', (#1100), .F.);

//	<Bodyの判定>

//	用紙 ///////////////////////////////////////////////////////// 
	if (m_EntityName == DEF_DRAWING_SHEET_REVISION_USAGE) {
//	ADD(S)	チューニング対応	K.Naono	03.07.10
		CStringArray	type, orient;
		type.Add(DEF_A0) ;
		type.Add(DEF_A1) ;
		type.Add(DEF_A2) ;
		type.Add(DEF_A3) ;
		type.Add(DEF_A4) ;
		//縦/横区分
		orient.Add(DEF_vertical) ;
		orient.Add(DEF_horizontal) ;
//	ADD(E)	チューニング対応	K.Naono	03.07.10

	/** drawing_sheet **/
/*		#1409 = CARTESIAN_POINT('cartesian_point168', (0., 0.));
		#1410 = AXIS2_PLACEMENT_2D('axis2_placement_2d54', #1409, $);
		#1411 = PLANAR_BOX('planar_box1', 594., 840., #1410);
		#1412 = DRAWING_SHEET_REVISION('A1_vertical', (#1060, #1080, #1120, #1180, #1200, #1220, #1260, #1280, #1320, #1340, #1380, #1411), #1408, 'revision_identifier01');
		#1400 = DRAWING_SHEET_REVISION_USAGE(#1412, #1402, '01');
		#1413 = PRESENTATION_SIZE(#1412, #1411);*/

		m_AsmKind = 1;

		SXFMapE_DRAWING_SHEET_REVISION_USAGEC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_SHEETC* sheet;
		sheet = new SXFMapF_SHEETC;
		m_TableManager->GetSheetTitle(m_AssmP.m_InSet_Inst,sheet->m_name);

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
		//	DRAUGHTING_DRAWING_REVISIONのインスタンスIDを登録
		m_TableManager->SetDraughtingDrawingRevID(m_AssmP.m_InSet_Inst) ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

		// 縦横フラグ ,用紙サイズ の設定 ////////////////////////////
		sheet->m_int_x	= 0;
		sheet->m_int_y	= 0;

		sheet->m_type = -1;
//		for(int i=0;i<=4;i++){
		for(int i = 0;i < type.GetSize(); i++) {
			if(m_AssmP.m_Area_p->m_Name.Find(type[i]) != -1) {
				sheet->m_type	= i ;
				sheet->m_int_x	= 0 ;
				sheet->m_int_y	= 0 ;
				break;
			}
			if ( m_AssmP.m_Area_p->m_Name.Find(DEF_FREE) != -1) {
				sheet->m_type	= 9 ;
				break;
			}
		}
		sheet->m_orient = -1;
		if (sheet->m_type != 9) {
//			for(int i=0;i<=1;i++){
			for(int i = 0; i < orient.GetSize(); i++) {
				if( m_AssmP.m_Area_p->m_Name.Find(orient[i]) != -1) {
					sheet->m_orient = i ;
					break;
				}
			}
		}
		
		int PlanarBoxID = m_TableManager->GetPlanarBoxID(m_AssmP.m_Area_Inst);
		CStringArray tmparray;
		
		SXFMapE_PLANAR_BOXC planar(m_InstanceIDManager);
		planar.SetRootID(PlanarBoxID);
		planar.SetEntity();
		planar.SetParameter();

		switch(sheet->m_type){
		case 0:
			sheet->m_int_x = DEF_A0_SIZE_X ;
			sheet->m_int_y = DEF_A0_SIZE_Y ;
			break;
		case 1:
			sheet->m_int_x = DEF_A1_SIZE_X ;
			sheet->m_int_y = DEF_A1_SIZE_Y ;
			break;
		case 2:
			sheet->m_int_x = DEF_A2_SIZE_X ;
			sheet->m_int_y = DEF_A2_SIZE_Y ;
			break;
		case 3:
			sheet->m_int_x = DEF_A3_SIZE_X ;
			sheet->m_int_y = DEF_A3_SIZE_Y ;
			break;
		case 4:
			sheet->m_int_x = DEF_A4_SIZE_X ;
			sheet->m_int_y = DEF_A4_SIZE_Y ;
			break;
		case 9:
			sheet->m_int_x = (int)planar.m_Size_x ;
			sheet->m_int_y = (int)planar.m_Size_y ;
			break;
		default:
			break;
		}
		
		// 用紙サイズ種別が０～４ならば、
		//PLANAR_BOXから読込んだ値が用紙サイズと異なればエラーを出力する。
		//但し０はOK
		if ( sheet->m_type >= 0 && sheet->m_type <= 4) {
			if (sheet->m_orient == 1 ){
				if ( (int)planar.m_Size_x != sheet->m_int_x && (int)planar.m_Size_x != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//errメッセージ番号
						m_EntityName,				//エンティティ名
						1,							//パラメタの個数
						(int)planar.m_Size_x		//パラメタ
						);
				}
				if ( (int)planar.m_Size_y != sheet->m_int_y && (int)planar.m_Size_y != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//errメッセージ番号
						m_EntityName,				//エンティティ名
						1,							//パラメタの個数
						(int)planar.m_Size_y		//パラメタ
						);
				}
			}
			else{
				if ( (int)planar.m_Size_y != sheet->m_int_x && (int)planar.m_Size_y != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//errメッセージ番号
						m_EntityName,				//エンティティ名
						1,							//パラメタの個数
						(int)planar.m_Size_y		//パラメタ
						);
				}
				if ( (int)planar.m_Size_x != sheet->m_int_y && (int)planar.m_Size_x != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//errメッセージ番号
						m_EntityName,				//エンティティ名
						1,							//パラメタの個数
						(int)planar.m_Size_x		//パラメタ
						);
				}
			}
		}
		
		// 用紙の抱える要素群へのインスタンスＩＤ
		m_Type  = drawing_sheet_feature;
		m_Class = sheet;
	}
	//	複合図形 ///////////////////////////////////////////////////// 
	else if ( m_EntityName == DEF_SYMBOL_REPRESENTATION_MAP ){

		m_AsmKind = 2;

		SXFMapE_SYMBOL_REPRESENTATION_MAPC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_SFIGORGC* sfigorg;
		sfigorg = new SXFMapF_SFIGORGC;

		/*sfigorg->m_flag,sfigorg->m_name の設定*/
		sfigorg->SetSubName(m_AssmP.m_subfig_rep_P->m_Name);

		m_Type  = sfig_org_feature;
		m_Class = sfigorg;

	}
	//	複合曲線  ///////////////////////////////////////////////////// 
	else if ( m_EntityName == DEF_COMPOSITE_CURVE){
		int CurveID = 0;
		m_AsmKind = 3;

		SXFMapE_COMPOSITE_CURVEC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_COMPOSITEC* composite;
		composite = new SXFMapF_COMPOSITEC;

		////////////////////////////////////////////////////////////////////////////////
		//  見え方のID取得   ////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////
//	MOD(S)	チューニング対応	K.Naono	03.07.10
//		CArray<int,int>* IDarray;
		CList<int,int>* IDarray;
//	MOD(E)	チューニング対応	K.Naono	03.07.10
		CString IN_InstanceName;
		int AppeID;

		// STYLED_ITEMのＩＤ取得
		IN_InstanceName = DEF_SXF_COMPLEX_INSTANCE;
//	MOD(S)	チューニング対応	K.Naono	03.07.10
/*
		if ( GetIDArray(IN_InstanceName) == NULL ) {
			return -10000;
		}
		else{
			IDarray = GetIDArray(IN_InstanceName); 
		}
		for (int i=0;i<(IDarray->GetSize());i++){
*/
		IDarray = GetIDArray(IN_InstanceName) ;
		if( IDarray == NULL ) {
			return -10000 ;
		}
//	MOD(E)	チューニング対応	K.Naono	03.07.10
		for(POSITION pos = IDarray->GetHeadPosition(); pos; ) {
			// SXF_COMPLEX_INSTANCEのSTYLED_ITEMのＩＤ取得
			// STYLED_ITEMが参照しているインスタンスをチェック
			SXFMapEntityBaseC body(m_InstanceIDManager);
//			body.SetRootID((*IDarray)[i]);
			body.SetRootID(IDarray->GetNext(pos));
			body.SetEntity();
			
			if ( (body.m_EntityData).Find( DEF_STYLED_ITEM ) != -1 ){

				// COMPLEXエンティティのデータを取り出す
				SXFMapEntCConvC convert(body.m_EntityArray);
				//	STYLED_ITEM のパラメタを取り出す
				convert.SplitComplex(DEF_STYLED_ITEM);
				CArray<int, int> intarray;
				int tmpInstID,OUT_Num;
				convert.GetSetInst(0,OUT_Num,intarray);
				convert.GetInst(1,tmpInstID);
				//	STYLED_ITEMのもつインスタンスへのＩＤが
				//	このCOMPOSITE_CURVE_SEGMENTのもつ
				//	m_parent_curve_Inst と同じか？のチェック
				if (tmpInstID == m_RootID ){
					AppeID = intarray[0];
					CurveID = body.GetRootID();
					break;
				}
			}
		}

		if (AppeID == 0){
			// STYLED_ITEMのＩＤ取得
			IN_InstanceName = DEF_STYLED_ITEM;
//	MOD(S)	チューニング対応	K.Naono	03.07.10
/*
			if ( GetIDArray(IN_InstanceName) == NULL ) {
				return -10000;
			}
			else{
				IDarray = GetIDArray(IN_InstanceName);
			}
			for (i=0;i<IDarray->GetSize();i++){
*/
			IDarray = GetIDArray(IN_InstanceName) ;
			if( IDarray == NULL ) {
				return -10000 ;
			}
			for(pos = IDarray->GetHeadPosition(); pos; ) {
//	MOD(E)	チューニング対応	K.Naono	03.07.10
				// STYLED_ITEMのもつインスタンスＩＤ取得
				SXFMapE_STYLED_ITEMC styled(m_InstanceIDManager);
//				styled.SetRootID((*IDarray)[i]);
				styled.SetRootID(IDarray->GetNext(pos));
				styled.SetEntity();
				styled.SetParameter();
				//	STYLED_ITEMのもつインスタンスへのＩＤが
				//	このCOMPOSITE_CURVE_SEGMENTのもつ
				//	m_parent_curve_Inst と同じか？のチェック
				if (styled.m_InstID == m_RootID ){
					AppeID = styled.m_AppeID;
					CurveID = styled.GetRootID();
					break;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		//  見え方へのＩＤの参照先エンティティを取得し、Stylesを作成する。//////////////
		////////////////////////////////////////////////////////////////////////////////
		SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC AppeP(m_InstanceIDManager);
		AppeP.SetRootID(AppeID);
		if ( AppeP.SetParameter() < 0 ) {
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

		//stylesのチェック
		int colorID,fontID,widthID;
		colorID =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_colour_Inst;
		fontID  =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_font_Inst;
		widthID =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_width_Inst;
		int OUT_Type;
	//	OUT_Type = 2or3; 
		composite->m_color = m_TableManager->GetTableCode(colorID, OUT_Type);
		if (OUT_Type != 2 && OUT_Type != 3)
			composite->m_color = -1;
	//	OUT_Type = 4or5; 
		composite->m_type  = m_TableManager->GetTableCode(fontID, OUT_Type);
		if (OUT_Type != 4 && OUT_Type != 5)
			composite->m_type = -1;
	//	OUT_Type = 6; 
		composite->m_line_width = m_TableManager->GetTableCode(widthID, OUT_Type);
		if (OUT_Type != 6)
			composite->m_line_width = -1;
		//  表示・非表示フラグの設定 /////////////////////////////////////////
		if (m_TableManager->GetInvisibilityFlag(CurveID))
			composite->m_flag = 0;
		else
			composite->m_flag = 1;
		m_Type  = composite_curve_org_feature;
		m_Class = composite;

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

	OUT_Type  = m_Type;		//アセンブリ種別	
	OUT_Class = m_Class;	//フィーチャクラスへのポインタ
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		フィーチャ構造体に値を設定

	２．インターフェイス
	int		SXFMapAssemblyC::SetStructData(
				E_type	IN_Type,
				LPVOID	IN_Class);

	引数  ：	型			引数名				内容
				E_type	IN_Type,	//フィーチャタイプ
				LPVOID	IN_Class	//フィーチャクラスへのポインタ
			
	復帰値：フィーチャＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
int SXFMapAssemblyC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class)

{
	m_Type 	= (E_type)IN_Type;
	m_Class	= IN_Class;
	if(m_Type == drawing_sheet_feature ){//1

		//構造体ﾃﾞｰﾀ作成
		Sheet_Struct* sheet = new Sheet_Struct;
		((SXFMapF_SHEETC*)m_Class)->GetStructData(sheet);
		//構造体ﾃﾞｰﾀの保存
		m_StructData = sheet;

	}else if(m_Type == sfig_org_feature){//11

		//構造体ﾃﾞｰﾀの作成
		Sfigorg_Struct* sfigorg = new Sfigorg_Struct;
		((SXFMapF_SFIGORGC*)m_Class)->GetStructData(sfigorg);
		//構造体ﾃﾞｰﾀの保存
		m_StructData = sfigorg;

	}else if(m_Type == composite_curve_org_feature ){//24

		//構造体ﾃﾞｰﾀの作成
		Ccurve_Org_Struct* curveorg = new Ccurve_Org_Struct;
		((SXFMapF_COMPOSITEC*)m_Class)->GetStructData(curveorg);
		//構造体ﾃﾞｰﾀの保存
		m_StructData = curveorg;

	}else{//feature comment name error
		return FALSE;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						作成日：2001.06.21

	１．機能概要
		フィーチャ構造体を取得する

	２．インターフェイス
	int		SXFMapAssemblyC::GetStructData(
				char*&	OUT_TypeName,
				void*		Out_Struct)

	引数  ：	型			引数名				内容
			char*			OUT_TypeName	構造体のType Name
			LPVOID			OUT_Struct		フィーチャ構造体
			
	復帰値：フィーチャＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.21	
**/
int SXFMapAssemblyC::GetStructData(
		LPVOID&		OUT_Struct)
{
	OUT_Struct 	= m_StructData;
	return (m_RootID) ;
}
