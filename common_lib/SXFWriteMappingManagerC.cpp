/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．クラス概要
	Write時のフィーチャオブジェクトとMappingオブジェクトの管理を行うクラス。

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。
	更新			2001.09.18			K.Naono				ハッチング障害対応

**/
#include "stdafx.h"
#include "SXFWriteMappingManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFSfigMappingC.h"
#include "SXFSheetMappingC.h"
#include "SXFCompCurveMappingC.h"
#include "SXFLineMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFCircleMappingC.h"
#include "SXFPolylineMappingC.h"
#include "SXFArcMappingC.h"
#include "SXFEllipseMappingC.h"
#include "SXFEllipseArcMappingC.h"
#include "SXFSplineMappingC.h"
#include "SXFClothoidMappingC.h"
#include "SXFPointMarkerMappingC.h"
#include "SXFLinearDimMappingC.h"
#include "SXFCurveDimMappingC.h"
#include "SXFAngularDimMappingC.h"
#include "SXFDiameterDimMappingC.h"
#include "SXFRadiusDimMappingC.h"
#include "SXFLabelMappingC.h"
#include "SXFBalloonMappingC.h"
#include "SXFExSymbolMappingC.h"
#include "SXFSfiglocMappingC.h"
#include "SXFExHatchMappingC.h"
#include "SXFFillColourMappingC.h"
#include "SXFFillHatchingMappingC.h"
#include "SXFFillTilesMappingC.h"
#include "SXFInvisibilityMappingC.h"
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//#include "SXFFeatureC.h"
//	DEL(E)	チューニング対応	K.Naono	03.07.03
#include "SXFComInfoC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFInstanceIDC.h"
#include "SXFComndef.h"
#include "SXFAttrMappingC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFWriteMappingManagerC::SXFWriteMappingManagerC()
	引数:	型								引数名				内容
			なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFWriteMappingManagerC::SXFWriteMappingManagerC()
{
	m_CompCurveMapping = NULL;
	m_SheetMapping = NULL;
	m_SfigMapping = NULL;
	m_PointMarkerMapping = NULL;
	m_CircleMapping = NULL;
	m_ArcMapping = NULL;
	m_EllipseMapping = NULL;
	m_EllipseArcMapping = NULL;
	m_PolylineMapping = NULL;
	m_SplineMapping = NULL;
	m_ClothoidMapping = NULL;
	m_TextStringMapping = NULL;
	m_LineMapping = NULL;
	m_FillTilesMapping = NULL;
	m_FillHatchingMapping = NULL;
	m_FillColourMapping = NULL;
	m_ExHatchMapping = NULL;
	m_SfiglocMapping = NULL;
	m_ExSymbolMapping = NULL;
	m_BalloonMapping = NULL;
	m_LabelMapping = NULL;
	m_RadiusDimMapping = NULL;
	m_CurveDimMapping = NULL;
	m_AngularDimMapping = NULL;
	m_LinearDimMapping = NULL;
	m_DiameterDimMapping = NULL;
	m_InvisibilityMapping = NULL;
	m_AssemType = -1;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_Feature = NULL;
//	m_AsemFeature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	m_TableManager = NULL;
	m_Part21File = NULL;
	m_AssemblyTable = NULL;
	m_WriteFile = NULL;
	m_PointTable = NULL;
	m_InstanceIDManager = NULL;
	m_InvisibilityMapping = NULL;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_AttrMapping = NULL ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFWriteMappingManagerC(SXFPart21FileC* IN_File)
	引数:	型								引数名				内容
			SXFPart21FileC* 				IN_File				ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ			

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFWriteMappingManagerC::SXFWriteMappingManagerC(SXFPart21FileC* IN_File)
{
	m_WriteFile = NULL;
	m_PointTable = NULL;
	m_InstanceIDManager = NULL;
	m_Part21File = IN_File;
	m_TableManager = NULL;
	m_AssemType = -1;
	m_AssemblyTable = NULL;
	m_CompCurveMapping = NULL;
	m_SheetMapping = NULL;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_AsemFeature = NULL;
//	m_Feature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	m_SfigMapping = NULL;
	m_PointMarkerMapping = NULL;
	m_CircleMapping = NULL;
	m_ArcMapping = NULL;
	m_EllipseMapping = NULL;
	m_EllipseArcMapping = NULL;
	m_PolylineMapping = NULL;
	m_SplineMapping = NULL;
	m_ClothoidMapping = NULL;
	m_TextStringMapping = NULL;
	m_LineMapping = NULL;
	m_FillTilesMapping = NULL;
	m_FillHatchingMapping = NULL;
	m_FillColourMapping = NULL;
	m_ExHatchMapping = NULL;
	m_SfiglocMapping = NULL;
	m_ExSymbolMapping = NULL;
	m_BalloonMapping = NULL;
	m_LabelMapping = NULL;
	m_RadiusDimMapping = NULL;
	m_CurveDimMapping = NULL;
	m_AngularDimMapping = NULL;
	m_LinearDimMapping = NULL;
	m_DiameterDimMapping = NULL;
	m_InvisibilityMapping = NULL;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_AttrMapping = NULL ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFWriteMappingManagerC(SXFPart21FileC* IN_File,
									SXFTableManagerC* IN_TableManager,
									int IN_AssemType,
									CUIntArray *IN_AssemblyTable,
									CUIntArray *IN_PointTable,
									SXFSFIGORGTABLE* IN_SfigorgTable,
									SXFComInfoC* IN_ComInfo,
									SXFPart21FileWriteC* IN_WriteFile,
									SXFInstanceIDC* IN_InstanceIDManager)
	
	引数:	型								引数名				内容
			SXFPart21FileC*					IN_File					ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC* 				IN_TableManager			ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			int 							IN_AssemType			ｱｾﾝﾌﾞﾘ型
			CUIntArray 						*IN_AssemblyTable		ｱｾﾝﾌﾞﾘﾃｰﾌﾞﾙ
			CUIntArray 						*IN_PointTable			ﾎﾟｲﾝﾄﾃｰﾌﾞﾙ
			SXFSFIGORGTABLE* 				IN_SfigorgTable			複合図形ﾃｰﾌﾞﾙ
			SXFComInfoC* 					IN_ComInfo				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
			SXFPart21FileWriteC* 			IN_WriteFile			ﾌｧｲﾙ出力ｵﾌﾞｼﾞｪｸﾄ
			SXFInstanceIDC* 				IN_InstanceIDManager	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。
	更新			2001.09.18			K.Naono			ハッチング障害対応

**/
SXFWriteMappingManagerC::SXFWriteMappingManagerC(
						SXFPart21FileC*					IN_File,
						SXFTableManagerC*				IN_TableManager,
						int								IN_AssemType,
						CUIntArray*						IN_AssemblyTable,
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//						CUIntArray*						IN_PointTable,
						CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable,
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
//	MOD(S)	チューニング対応	K.Naono		03.07.08
//						SXFSFIGORGTABLE*				IN_SfigorgTable,
						CMapStringToPtr*				IN_SfigorgTable,
//	MOD(E)	チューニング対応	K.Naono		03.07.08
						SXFComInfoC*					IN_ComInfo,
						SXFPart21FileWriteC*			IN_WriteFile,
						SXFInstanceIDC*					IN_InstanceIDManager)
{

	m_Part21File = IN_File;
	m_TableManager = IN_TableManager;
	m_AssemType = IN_AssemType;
	m_AssemblyTable = IN_AssemblyTable;
	m_PointTable = IN_PointTable;
	m_SfigorgTable = IN_SfigorgTable;
	m_WriteFile = IN_WriteFile;
	m_ComInfo = IN_ComInfo;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_CompCurveMapping = NULL;
	m_SheetMapping = NULL;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_AsemFeature = NULL;
//	m_Feature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	m_SfigMapping = NULL;
	m_PointMarkerMapping = NULL;
	m_CircleMapping = NULL;
	m_ArcMapping = NULL;
	m_EllipseMapping = NULL;
	m_EllipseArcMapping = NULL;
	m_PolylineMapping = NULL;
	m_SplineMapping = NULL;
	m_ClothoidMapping = NULL;
	m_TextStringMapping = NULL;
	m_LineMapping = NULL;
	m_FillTilesMapping = NULL;
	m_FillHatchingMapping = NULL;
	m_FillColourMapping = NULL;
	m_ExHatchMapping = NULL;
	m_SfiglocMapping = NULL;
	m_ExSymbolMapping = NULL;
	m_BalloonMapping = NULL;
	m_LabelMapping = NULL;
	m_RadiusDimMapping = NULL;
	m_CurveDimMapping = NULL;
	m_AngularDimMapping = NULL;
	m_LinearDimMapping = NULL;
	m_DiameterDimMapping = NULL;
	m_InvisibilityMapping = NULL;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_AttrMapping = NULL ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFWriteMappingManagerC::~SXFWriteMappingManagerC()
	引数:	型								引数名				内容
			なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFWriteMappingManagerC::~SXFWriteMappingManagerC()
{
	if (m_CompCurveMapping != NULL)
		delete m_CompCurveMapping;
	if (m_SheetMapping != NULL)
		delete m_SheetMapping;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	if (m_AsemFeature != NULL)
//		delete m_AsemFeature;
//	if (m_Feature != NULL)
//		delete 	m_Feature;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	if (m_SfiglocMapping != NULL)
		delete m_SfiglocMapping;
	if (m_SfigMapping != NULL)
		delete m_SfigMapping;
	if (m_PointMarkerMapping != NULL)
		delete m_PointMarkerMapping;
	if (m_CircleMapping != NULL)
		delete m_CircleMapping;
	if (m_ArcMapping != NULL)
		delete m_ArcMapping;
	if (m_EllipseMapping != NULL)
		delete m_EllipseMapping;
	if (m_EllipseArcMapping != NULL)
		delete m_EllipseArcMapping;
	if (m_PolylineMapping != NULL)
		delete m_PolylineMapping;
	if (m_SplineMapping != NULL)
		delete m_SplineMapping;
	if (m_ClothoidMapping != NULL)
		delete m_ClothoidMapping;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_LineMapping != NULL)
		delete m_LineMapping;
	if (m_FillTilesMapping != NULL)
		delete m_FillTilesMapping;
	if (m_FillHatchingMapping != NULL)
		delete m_FillHatchingMapping;
	if (m_FillColourMapping != NULL)
		delete m_FillColourMapping;
	if (m_ExHatchMapping != NULL)
		delete m_ExHatchMapping;
	if (m_ExSymbolMapping != NULL)
		delete m_ExSymbolMapping;
	if (m_BalloonMapping != NULL)
		delete m_BalloonMapping;
	if (m_LabelMapping != NULL)
		delete m_LabelMapping;
	if (m_RadiusDimMapping != NULL)
		delete m_RadiusDimMapping;
	if (m_CurveDimMapping != NULL)
		delete m_CurveDimMapping;
	if (m_AngularDimMapping != NULL)
		delete m_AngularDimMapping;
	if (m_LinearDimMapping != NULL)
		delete m_LinearDimMapping;
	if (m_DiameterDimMapping != NULL)
		delete m_DiameterDimMapping;
	if (m_InvisibilityMapping != NULL)
		delete m_InvisibilityMapping;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	if( m_AttrMapping != NULL )
		delete m_AttrMapping ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	構造体をSETする

	２．インターフェース
	BOOL SetStructData(int IN_Asem_Type, LPVOID IN_Struct)
	引数:	型				引数名				内容
			int				IN_Asem_Type		アセンブリ型
			LPVOID			IN_Struct			構造体
	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFWriteMappingManagerC::SetStructData(int IN_Asem_Type, LPVOID IN_Struct)
{
	switch(IN_Asem_Type){
	case 1://SHEET
		//アセンブリタイプのセット
		m_AssemType = IN_Asem_Type;
		//構造体のセット
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Sheet_Str.name,((Sheet_Struct*)IN_Struct)->name);
		strcpy_s(m_Sheet_Str.name, _countof(m_Sheet_Str.name),((Sheet_Struct*)IN_Struct)->name);
		m_Sheet_Str.orient = ((Sheet_Struct*)IN_Struct)->orient;
		m_Sheet_Str.type = ((Sheet_Struct*)IN_Struct)->type;
		m_Sheet_Str.x = ((Sheet_Struct*)IN_Struct)->x;
		m_Sheet_Str.y = ((Sheet_Struct*)IN_Struct)->y;
		break;
	case 2://subfigure
		//アセンブリタイプのセット
		m_AssemType = IN_Asem_Type;
		//構造体のセット
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Sfigorg_Str.name,((Sfigorg_Struct*)IN_Struct)->name);
		strcpy_s(m_Sfigorg_Str.name,_countof(m_Sfigorg_Str.name),((Sfigorg_Struct*)IN_Struct)->name);
		m_Sfigorg_Str.flag = ((Sfigorg_Struct*)IN_Struct)->flag;

		break;
	case 3://composite_curve
		//アセンブリタイプのセット
		m_AssemType = IN_Asem_Type;
		//構造体のセット
		m_CompCurve_Str.color = ((Ccurve_Org_Struct*)IN_Struct)->color;
		m_CompCurve_Str.type = ((Ccurve_Org_Struct*)IN_Struct)->type;
		m_CompCurve_Str.line_width = ((Ccurve_Org_Struct*)IN_Struct)->line_width;
		m_CompCurve_Str.flag = ((Ccurve_Org_Struct*)IN_Struct)->flag;
		break;
	default:
		break;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	アセンブリ要素のMapping依頼

	２．インターフェース
	BOOL MappingAssembly(CUIntArray* IN_ChildrenID,int &OUT_AssemblyID1,int &OUT_AssemblyID2,int &OUT_PointID,double IN_PointX,double IN_PointY)
	引数:	型				引数名				内容
			CUIntArray		IN_ChildrenID		アセンブリ要素がもつ一般要素のインスタンスIDの配列
			int&			OUT_AssemblyID1		アセンブリ要素のインスタンスID
			int&			OUT_AssemblyID2		アセンブリ要素のインスタンスID
			int&			OUT_PointID			ハッチング内部の点のインスタンスID
			double			IN_PointX			ハッチング内部の点X
			double			IN_PointY			ハッチング内部の点Y

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFWriteMappingManagerC::MappingAssembly(
								CUIntArray*	IN_ChildrenID,
								int&		OUT_AssemblyID1,
								int&		OUT_AssemblyID2,
								int&		OUT_PointID,
								double		IN_PointX,
								double		IN_PointY)
{
	OUT_AssemblyID1 = -1;
	OUT_AssemblyID2 = -1;
	switch(m_AssemType){
	/** 用紙 **/
	case 1:
		/* ｱｾﾝﾌﾞﾘ構造体ｾｯﾄ */
		m_SheetMapping = new SXFSheetMappingC(m_TableManager);
//	MOD(S)	Ver3.0対応	K.Naono	04.01.30
//		if (m_SheetMapping->MappingStruct(m_Sheet_Str,IN_ChildrenID)){
//			m_SheetMapping->WriteAP202(m_Part21File);
//			OUT_AssemblyID1 = m_SheetMapping->GetID();
//			return TRUE;
//		}
//		else 
//			return FALSE;
		if( !m_SheetMapping->MappingStruct(
								m_Sheet_Str,
								IN_ChildrenID,
								m_TableManager->GetAttributeStruct()) ) {
			return FALSE ;
		}
		m_SheetMapping->WriteAP202(m_Part21File) ;
		OUT_AssemblyID1 = m_SheetMapping->GetID() ;

		if( m_TableManager->GetAttributeStruct() == NULL ) {
			return TRUE ;
		}

		m_AttrMapping = new SXFAttrMappingC(m_SheetMapping) ;
		if( !m_AttrMapping->MappingStruct(m_TableManager->GetAttributeStruct()) ) {
			return FALSE ;
		}
		m_AttrMapping->WriteAP202(m_Part21File) ;
//	MOD(E)	Ver3.0対応	K.Naono	04.01.30

		break;
	/** 複合図形 **/
	case 2:
		/* ｱｾﾝﾌﾞﾘ構造体ｾｯﾄ */
		m_SfigMapping = new SXFSfigMappingC();
		if (m_SfigMapping->MappingStruct(m_Sfigorg_Str,IN_ChildrenID)){
			m_SfigMapping->WriteAP202(m_Part21File);
			OUT_AssemblyID1 = m_SfigMapping->GetID();
			return TRUE;
		}
		else 
			return FALSE;
		break;
	/** 複合曲線 **/
	case 3:
		/* ｱｾﾝﾌﾞﾘ構造体ｾｯﾄ */
		m_CompCurveMapping = new SXFCompCurveMappingC(m_TableManager,IN_PointX,IN_PointY);
		if (m_CompCurveMapping->MappingStruct(m_CompCurve_Str,IN_ChildrenID)){
			m_CompCurveMapping->WriteAP202(m_Part21File);
			m_CompCurveMapping->GetID(OUT_AssemblyID1,OUT_AssemblyID2,OUT_PointID);
			return TRUE;
		}
		else 
			return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	メンバのデータクリア。

	２．インターフェース
	void ClearData()
	引数:	型				引数名				内容
			なし。
	復帰値	なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
void SXFWriteMappingManagerC::ClearData()
{
	//////////////////
	//data clear
	//////////////////
	if (m_CompCurveMapping != NULL)
		delete m_CompCurveMapping;
	if (m_SheetMapping != NULL)
		delete m_SheetMapping;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	if (m_AsemFeature != NULL)
//		delete m_AsemFeature;
//	if (m_Feature != NULL)
//		delete 	m_Feature;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	if (m_SfiglocMapping != NULL)
		delete m_SfiglocMapping;
	if (m_SfigMapping != NULL)
		delete m_SfigMapping;
	if (m_PointMarkerMapping != NULL)
		delete m_PointMarkerMapping;
	if (m_CircleMapping != NULL)
		delete m_CircleMapping;
	if (m_ArcMapping != NULL)
		delete m_ArcMapping;
	if (m_EllipseMapping != NULL)
		delete m_EllipseMapping;
	if (m_EllipseArcMapping != NULL)
		delete m_EllipseArcMapping;
	if (m_PolylineMapping != NULL)
		delete m_PolylineMapping;
	if (m_SplineMapping != NULL)
		delete m_SplineMapping;
	if (m_ClothoidMapping != NULL)
		delete m_ClothoidMapping;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_LineMapping != NULL)
		delete m_LineMapping;
	if (m_FillTilesMapping != NULL)
		delete m_FillTilesMapping;
	if (m_FillHatchingMapping != NULL)
		delete m_FillHatchingMapping;
	if (m_FillColourMapping != NULL)
		delete m_FillColourMapping;
	if (m_ExHatchMapping != NULL)
		delete m_ExHatchMapping;
	if (m_ExSymbolMapping != NULL)
		delete m_ExSymbolMapping;
	if (m_BalloonMapping != NULL)
		delete m_BalloonMapping;
	if (m_LabelMapping != NULL)
		delete m_LabelMapping;
	if (m_RadiusDimMapping != NULL)
		delete m_RadiusDimMapping;
	if (m_CurveDimMapping != NULL)
		delete m_CurveDimMapping;
	if (m_AngularDimMapping != NULL)
		delete m_AngularDimMapping;
	if (m_LinearDimMapping != NULL)
		delete m_LinearDimMapping;
	if (m_DiameterDimMapping != NULL)
		delete m_DiameterDimMapping;
	if (m_InvisibilityMapping != NULL)
		delete m_InvisibilityMapping;

	//Assemtype
	m_AssemType = -1;
	m_FeatureType = "";
	m_CompCurveMapping = NULL;
	m_SheetMapping = NULL;
	m_SfigMapping = NULL;
	m_PointMarkerMapping = NULL;
	m_CircleMapping = NULL;
	m_ArcMapping = NULL;
	m_EllipseMapping = NULL;
	m_EllipseArcMapping = NULL;
	m_PolylineMapping = NULL;
	m_SplineMapping = NULL;
	m_ClothoidMapping = NULL;
	m_TextStringMapping = NULL;
	m_LineMapping = NULL;
	m_FillTilesMapping = NULL;
	m_FillHatchingMapping = NULL;
	m_FillColourMapping = NULL;
	m_ExHatchMapping = NULL;
	m_SfiglocMapping = NULL;
	m_ExSymbolMapping = NULL;
	m_BalloonMapping = NULL;
	m_LabelMapping = NULL;
	m_RadiusDimMapping = NULL;
	m_CurveDimMapping = NULL;
	m_AngularDimMapping = NULL;
	m_LinearDimMapping = NULL;
	m_DiameterDimMapping = NULL;
	m_InvisibilityMapping = NULL;
	m_AssemType = -1;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_AsemFeature = NULL;
//	m_Feature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	if( m_AttrMapping != NULL )
		delete m_AttrMapping ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	Mappingを行う

	２．インターフェース
	int MappingFeature(int &OUT_Id1,int &OUT_Id2,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN)
	引数:	型				引数名				内容
			int&			OUT_Id1				アセンブリ要素のインスタンスID
			int&			OUT_Id2				アセンブリ要素のインスタンスID
			double&			INOUT_PointX		ハッチング内部の点X
			double&			INOUT_PointY		ハッチング内部の点Y
			int&			INOUT_PointN		ハッチング内部の点の個数

	復帰値	正常時：1
			異常時：-1

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
int SXFWriteMappingManagerC::MappingFeature(
								char*	IN_FeatureType,
								LPVOID	IN_Struct,
								int&	OUT_Id1,
								int&	OUT_Id2,
								double&	INOUT_PointX,
								double&	INOUT_PointY,
								int&	INOUT_PointN)
{
	OUT_Id1 = -1;
	OUT_Id2 = -1;
	m_FeatureType = IN_FeatureType;
	/*線分*/
	if (strcmp(m_FeatureType,DEF_LINE) == 0){
		m_Line_Str.layer = ((Line_Struct*)IN_Struct)->layer;
		m_Line_Str.color = ((Line_Struct*)IN_Struct)->color;
		m_Line_Str.type = ((Line_Struct*)IN_Struct)->type;
		m_Line_Str.line_width = ((Line_Struct*)IN_Struct)->line_width;
		m_Line_Str.start_x = ((Line_Struct*)IN_Struct)->start_x;
		m_Line_Str.start_y = ((Line_Struct*)IN_Struct)->start_y;
		m_Line_Str.end_x = ((Line_Struct*)IN_Struct)->end_x;
		m_Line_Str.end_y = ((Line_Struct*)IN_Struct)->end_y;
		m_LineMapping = new SXFLineMappingC(m_TableManager,0);
		if (m_LineMapping->MappingStruct(m_Line_Str)){
			m_LineMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_LineMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	/** 図面表題欄 **/
	else if (strcmp(m_FeatureType,"ATTRIBUTE") == 0) {
		if( m_TableManager->SetAttributeStruct(IN_Struct) ) {
			OUT_Id1 = 0 ;
			return 1 ;
		}
		return -1 ;
	}
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

	/*文字要素*/
	else if (strcmp(m_FeatureType,DEF_TEXT) == 0){
		m_Text_String_Str.layer = ((Text_Struct*)IN_Struct)->layer;
		m_Text_String_Str.color = ((Text_Struct*)IN_Struct)->color;
		m_Text_String_Str.font = ((Text_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Text_String_Str.str,((Text_Struct*)IN_Struct)->str);
		strcpy_s(m_Text_String_Str.str,_countof(m_Text_String_Str.str),((Text_Struct*)IN_Struct)->str);
		m_Text_String_Str.text_x = ((Text_Struct*)IN_Struct)->text_x;
		m_Text_String_Str.text_y = ((Text_Struct*)IN_Struct)->text_y;
		m_Text_String_Str.height = ((Text_Struct*)IN_Struct)->height;
		m_Text_String_Str.width = ((Text_Struct*)IN_Struct)->width;
		m_Text_String_Str.spc = ((Text_Struct*)IN_Struct)->spc;
		m_Text_String_Str.angle = ((Text_Struct*)IN_Struct)->angle;
		m_Text_String_Str.slant = ((Text_Struct*)IN_Struct)->slant;
		m_Text_String_Str.b_pnt = ((Text_Struct*)IN_Struct)->b_pnt;
		m_Text_String_Str.direct = ((Text_Struct*)IN_Struct)->direct;

		m_TextStringMapping = new SXFTextStringMappingC(m_TableManager,0);
		if (m_TextStringMapping->MappingStruct(m_Text_String_Str)){
			m_TextStringMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_TextStringMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
	/*円*/
	else if (strcmp(m_FeatureType,DEF_CIRCLE) == 0){
		m_Circle_Str.layer = ((Circle_Struct*)IN_Struct)->layer;
		m_Circle_Str.color = ((Circle_Struct*)IN_Struct)->color;
		m_Circle_Str.type = ((Circle_Struct*)IN_Struct)->type;
		m_Circle_Str.line_width = ((Circle_Struct*)IN_Struct)->line_width;
		m_Circle_Str.center_x = ((Circle_Struct*)IN_Struct)->center_x;
		m_Circle_Str.center_y = ((Circle_Struct*)IN_Struct)->center_y;
		m_Circle_Str.radius = ((Circle_Struct*)IN_Struct)->radius;

		m_CircleMapping = new SXFCircleMappingC(m_TableManager,0);
		if (m_CircleMapping->MappingStruct(m_Circle_Str)){
			m_CircleMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_CircleMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
	/*点マーカ*/
	else if (strcmp(m_FeatureType,DEF_POINT_MARKER) == 0){
		m_Point_Marker_Str.layer = ((Point_Marker_Struct*)IN_Struct)->layer;
		m_Point_Marker_Str.color = ((Point_Marker_Struct*)IN_Struct)->color;
		m_Point_Marker_Str.start_x = ((Point_Marker_Struct*)IN_Struct)->start_x;
		m_Point_Marker_Str.start_y = ((Point_Marker_Struct*)IN_Struct)->start_y;
		m_Point_Marker_Str.marker_code = ((Point_Marker_Struct*)IN_Struct)->marker_code;
		m_Point_Marker_Str.rotate_angle = ((Point_Marker_Struct*)IN_Struct)->rotate_angle;
		m_Point_Marker_Str.scale = ((Point_Marker_Struct*)IN_Struct)->scale;

		m_PointMarkerMapping = new SXFPointMarkerMappingC(m_TableManager);
		if (m_PointMarkerMapping->MappingStruct(m_Point_Marker_Str)){
			m_PointMarkerMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_PointMarkerMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
	/*円弧*/
	else if (strcmp(m_FeatureType,DEF_ARC) == 0){
		m_Arc_Str.layer = ((Arc_Struct*)IN_Struct)->layer;
		m_Arc_Str.color = ((Arc_Struct*)IN_Struct)->color;
		m_Arc_Str.type = ((Arc_Struct*)IN_Struct)->type;
		m_Arc_Str.line_width = ((Arc_Struct*)IN_Struct)->line_width;
		m_Arc_Str.center_x = ((Arc_Struct*)IN_Struct)->center_x;
		m_Arc_Str.center_y = ((Arc_Struct*)IN_Struct)->center_y;
		m_Arc_Str.radius = ((Arc_Struct*)IN_Struct)->radius;
		m_Arc_Str.direction = ((Arc_Struct*)IN_Struct)->direction;
		m_Arc_Str.start_angle = ((Arc_Struct*)IN_Struct)->start_angle;
		m_Arc_Str.end_angle = ((Arc_Struct*)IN_Struct)->end_angle;

		m_ArcMapping = new SXFArcMappingC(m_TableManager,0);
		//composite_curve
		if (m_AssemType == 3 ){
			if (m_ArcMapping->MappingStructCurve(m_Arc_Str,INOUT_PointX,INOUT_PointY,INOUT_PointN)){
				m_ArcMapping->WriteAP202Curve(m_Part21File);
				OUT_Id1 = m_ArcMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
		else{
			if (m_ArcMapping->MappingStruct(m_Arc_Str)){
				m_ArcMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_ArcMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
	}
	/*楕円*/
	else if (strcmp(m_FeatureType,DEF_ELLIPSE) == 0){
		m_Ellipse_Str.layer = ((Ellipse_Struct*)IN_Struct)->layer;
		m_Ellipse_Str.color = ((Ellipse_Struct*)IN_Struct)->color;
		m_Ellipse_Str.type = ((Ellipse_Struct*)IN_Struct)->type;
		m_Ellipse_Str.line_width = ((Ellipse_Struct*)IN_Struct)->line_width;
		m_Ellipse_Str.center_x = ((Ellipse_Struct*)IN_Struct)->center_x;
		m_Ellipse_Str.center_y = ((Ellipse_Struct*)IN_Struct)->center_y;
		m_Ellipse_Str.radius_x = ((Ellipse_Struct*)IN_Struct)->radius_x;
		m_Ellipse_Str.radius_y = ((Ellipse_Struct*)IN_Struct)->radius_y;
		m_Ellipse_Str.rotation_angle = ((Ellipse_Struct*)IN_Struct)->rotation_angle;

		m_EllipseMapping = new SXFEllipseMappingC(m_TableManager);
		if (m_EllipseMapping->MappingStruct(m_Ellipse_Str)){
			m_EllipseMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_EllipseMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
	/*楕円弧*/
	else if (strcmp(m_FeatureType,DEF_ELLIPSE_ARC) == 0){
		m_Ellipse_Arc_Str.layer = ((Ellipse_Arc_Struct*)IN_Struct)->layer;
		m_Ellipse_Arc_Str.color = ((Ellipse_Arc_Struct*)IN_Struct)->color;
		m_Ellipse_Arc_Str.type = ((Ellipse_Arc_Struct*)IN_Struct)->type;
		m_Ellipse_Arc_Str.line_width = ((Ellipse_Arc_Struct*)IN_Struct)->line_width;
		m_Ellipse_Arc_Str.center_x = ((Ellipse_Arc_Struct*)IN_Struct)->center_x;
		m_Ellipse_Arc_Str.center_y = ((Ellipse_Arc_Struct*)IN_Struct)->center_y;
		m_Ellipse_Arc_Str.radius_x = ((Ellipse_Arc_Struct*)IN_Struct)->radius_x;
		m_Ellipse_Arc_Str.radius_y = ((Ellipse_Arc_Struct*)IN_Struct)->radius_y;
		m_Ellipse_Arc_Str.direction = ((Ellipse_Arc_Struct*)IN_Struct)->direction;
		m_Ellipse_Arc_Str.rotation_angle = ((Ellipse_Arc_Struct*)IN_Struct)->rotation_angle;
		m_Ellipse_Arc_Str.start_angle = ((Ellipse_Arc_Struct*)IN_Struct)->start_angle;
		m_Ellipse_Arc_Str.end_angle = ((Ellipse_Arc_Struct*)IN_Struct)->end_angle;

		m_EllipseArcMapping = new SXFEllipseArcMappingC(m_TableManager);
		//composite_curve
		if (m_AssemType == 3 ){
			if (m_EllipseArcMapping->MappingStructCurve(m_Ellipse_Arc_Str,INOUT_PointX,INOUT_PointY,INOUT_PointN)){
				m_EllipseArcMapping->WriteAP202Curve(m_Part21File);
				OUT_Id1 = m_EllipseArcMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
		else{
			if (m_EllipseArcMapping->MappingStruct(m_Ellipse_Arc_Str)){
				m_EllipseArcMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_EllipseArcMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
	}
	/*折れ線*/
	else if (strcmp(m_FeatureType,DEF_POLYLINE) == 0){
		m_Polyline_Str.layer = ((Polyline_Struct*)IN_Struct)->layer;
		m_Polyline_Str.color = ((Polyline_Struct*)IN_Struct)->color;
		m_Polyline_Str.type = ((Polyline_Struct*)IN_Struct)->type;
		m_Polyline_Str.line_width = ((Polyline_Struct*)IN_Struct)->line_width;
		m_Polyline_Str.number = ((Polyline_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_Polyline_Str.number;i++){
			m_Polyline_Str.x.Add(((Polyline_Struct*)IN_Struct)->x[i]);
			m_Polyline_Str.y.Add(((Polyline_Struct*)IN_Struct)->y[i]);
		}

		m_PolylineMapping = new SXFPolylineMappingC(m_TableManager,0);
		//composite_curve
		if (m_AssemType == 3 ){
			if (m_PolylineMapping->MappingStructCurve(&m_Polyline_Str,INOUT_PointX,INOUT_PointY,INOUT_PointN)){
				m_PolylineMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_PolylineMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
		else{
			if (m_PolylineMapping->MappingStruct(&m_Polyline_Str)){
				m_PolylineMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_PolylineMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
	}
	/*スプライン*/
	else if (strcmp(m_FeatureType,DEF_SPLINE) == 0){
		m_Spline_Str.layer = ((Spline_Struct*)IN_Struct)->layer;
		m_Spline_Str.color = ((Spline_Struct*)IN_Struct)->color;
		m_Spline_Str.type = ((Spline_Struct*)IN_Struct)->type;
		m_Spline_Str.line_width = ((Spline_Struct*)IN_Struct)->line_width;
		m_Spline_Str.open_close = ((Spline_Struct*)IN_Struct)->open_close;
		m_Spline_Str.number = ((Spline_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_Spline_Str.number;i++){
			m_Spline_Str.x.Add(((Spline_Struct*)IN_Struct)->x[i]);
			m_Spline_Str.y.Add(((Spline_Struct*)IN_Struct)->y[i]);
		}

		m_SplineMapping = new SXFSplineMappingC(m_TableManager);
		//composite_curve
		if (m_AssemType == 3 ){
			if (m_SplineMapping->MappingStructCurve(&m_Spline_Str,INOUT_PointX,INOUT_PointY,INOUT_PointN)){
				m_SplineMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_SplineMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
		else{
			if (m_SplineMapping->MappingStruct(&m_Spline_Str)){
				m_SplineMapping->WriteAP202(m_Part21File);
				OUT_Id1 = m_SplineMapping->GetID();
				return 1;
			}
			else 
				return -1;
		}
	}
	/*クロソイド*/
	else if (strcmp(m_FeatureType,DEF_CLOTHOID) == 0){
		m_Clothoid_Str.layer = ((Clothoid_Struct*)IN_Struct)->layer;
		m_Clothoid_Str.color = ((Clothoid_Struct*)IN_Struct)->color;
		m_Clothoid_Str.type = ((Clothoid_Struct*)IN_Struct)->type;
		m_Clothoid_Str.line_width = ((Clothoid_Struct*)IN_Struct)->line_width;
		m_Clothoid_Str.base_x = ((Clothoid_Struct*)IN_Struct)->base_x;
		m_Clothoid_Str.base_y = ((Clothoid_Struct*)IN_Struct)->base_y;
		m_Clothoid_Str.parameter = ((Clothoid_Struct*)IN_Struct)->parameter;
		m_Clothoid_Str.direction = ((Clothoid_Struct*)IN_Struct)->direction;
		m_Clothoid_Str.angle = ((Clothoid_Struct*)IN_Struct)->angle;
		m_Clothoid_Str.start_length = ((Clothoid_Struct*)IN_Struct)->start_length;
		m_Clothoid_Str.end_length = ((Clothoid_Struct*)IN_Struct)->end_length;

		m_ClothoidMapping = new SXFClothoidMappingC(m_TableManager);
		//composite_curve
		if (m_ClothoidMapping->MappingStruct(&m_Clothoid_Str)){
			m_ClothoidMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_ClothoidMapping->GetID();
			return 1;
		}
		else 
			return -1;
	}
	/*複合図形配置*/
	else if (strcmp(m_FeatureType,DEF_SFIG_LOCATE) == 0){
		m_Sfigloc_Str.layer = ((Sfigloc_Struct*)IN_Struct)->layer;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Sfigloc_Str.name,((Sfigloc_Struct*)IN_Struct)->name);
		strcpy_s(m_Sfigloc_Str.name,_countof(m_Sfigloc_Str.name),((Sfigloc_Struct*)IN_Struct)->name);
		m_Sfigloc_Str.x = ((Sfigloc_Struct*)IN_Struct)->x;
		m_Sfigloc_Str.y = ((Sfigloc_Struct*)IN_Struct)->y;
		m_Sfigloc_Str.angle = ((Sfigloc_Struct*)IN_Struct)->angle;
		m_Sfigloc_Str.ratio_x = ((Sfigloc_Struct*)IN_Struct)->ratio_x;
		m_Sfigloc_Str.ratio_y = ((Sfigloc_Struct*)IN_Struct)->ratio_y;

		m_SfiglocMapping = new SXFSfiglocMappingC(m_TableManager, m_SfigorgTable);
		if (m_SfiglocMapping->MappingStruct(m_Sfigloc_Str)){
			m_SfiglocMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_SfiglocMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*既定義シンボル*/
	else if (strcmp(m_FeatureType,DEF_EXTERNALLY_DEFINED_SYMBOL) == 0){
		m_ExSymbol_Str.layer = ((Externally_Defined_Symbol_Struct*)IN_Struct)->layer;
		m_ExSymbol_Str.color_flag = ((Externally_Defined_Symbol_Struct*)IN_Struct)->color_flag;
		m_ExSymbol_Str.color = ((Externally_Defined_Symbol_Struct*)IN_Struct)->color;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_ExSymbol_Str.name,((Externally_Defined_Symbol_Struct*)IN_Struct)->name);
		strcpy_s(m_ExSymbol_Str.name,_countof(m_ExSymbol_Str.name),((Externally_Defined_Symbol_Struct*)IN_Struct)->name);
		m_ExSymbol_Str.start_x = ((Externally_Defined_Symbol_Struct*)IN_Struct)->start_x;
		m_ExSymbol_Str.start_y = ((Externally_Defined_Symbol_Struct*)IN_Struct)->start_y;
		m_ExSymbol_Str.rotate_angle = ((Externally_Defined_Symbol_Struct*)IN_Struct)->rotate_angle;
		m_ExSymbol_Str.scale = ((Externally_Defined_Symbol_Struct*)IN_Struct)->scale;

		m_ExSymbolMapping = new SXFExSymbolMappingC(m_TableManager,0);
		if (m_ExSymbolMapping->MappingStruct(m_ExSymbol_Str)){
			m_ExSymbolMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_ExSymbolMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*直線寸法*/
	else if (strcmp(m_FeatureType,DEF_LINEAR_DIMENSION) == 0){
		m_LinearDim_Str.layer = ((LinearDim_Struct*)IN_Struct)->layer;
		m_LinearDim_Str.color = ((LinearDim_Struct*)IN_Struct)->color;
		m_LinearDim_Str.type = ((LinearDim_Struct*)IN_Struct)->type;
		m_LinearDim_Str.line_width = ((LinearDim_Struct*)IN_Struct)->line_width;
		m_LinearDim_Str.sun_x1 = ((LinearDim_Struct*)IN_Struct)->sun_x1;
		m_LinearDim_Str.sun_y1 = ((LinearDim_Struct*)IN_Struct)->sun_y1;
		m_LinearDim_Str.sun_x2 = ((LinearDim_Struct*)IN_Struct)->sun_x2;
		m_LinearDim_Str.sun_y2 = ((LinearDim_Struct*)IN_Struct)->sun_y2;
		m_LinearDim_Str.flg2 = ((LinearDim_Struct*)IN_Struct)->flg2;
		m_LinearDim_Str.ho1_x0 = ((LinearDim_Struct*)IN_Struct)->ho1_x0;
		m_LinearDim_Str.ho1_y0 = ((LinearDim_Struct*)IN_Struct)->ho1_y0;
		m_LinearDim_Str.ho1_x1 = ((LinearDim_Struct*)IN_Struct)->ho1_x1;
		m_LinearDim_Str.ho1_y1 = ((LinearDim_Struct*)IN_Struct)->ho1_y1;
		m_LinearDim_Str.ho1_x2 = ((LinearDim_Struct*)IN_Struct)->ho1_x2;
		m_LinearDim_Str.ho1_y2 = ((LinearDim_Struct*)IN_Struct)->ho1_y2;
		m_LinearDim_Str.flg3 = ((LinearDim_Struct*)IN_Struct)->flg3;
		m_LinearDim_Str.ho2_x0 = ((LinearDim_Struct*)IN_Struct)->ho2_x0;
		m_LinearDim_Str.ho2_y0 = ((LinearDim_Struct*)IN_Struct)->ho2_y0;
		m_LinearDim_Str.ho2_x1 = ((LinearDim_Struct*)IN_Struct)->ho2_x1;
		m_LinearDim_Str.ho2_y1 = ((LinearDim_Struct*)IN_Struct)->ho2_y1;
		m_LinearDim_Str.ho2_x2 = ((LinearDim_Struct*)IN_Struct)->ho2_x2;
		m_LinearDim_Str.ho2_y2 = ((LinearDim_Struct*)IN_Struct)->ho2_y2;
		m_LinearDim_Str.arr1_code1 = ((LinearDim_Struct*)IN_Struct)->arr1_code1;
		m_LinearDim_Str.arr1_code2 = ((LinearDim_Struct*)IN_Struct)->arr1_code2;
		m_LinearDim_Str.arr1_x = ((LinearDim_Struct*)IN_Struct)->arr1_x;
		m_LinearDim_Str.arr1_y = ((LinearDim_Struct*)IN_Struct)->arr1_y;
		m_LinearDim_Str.arr1_r = ((LinearDim_Struct*)IN_Struct)->arr1_r;
		m_LinearDim_Str.arr2_code1 = ((LinearDim_Struct*)IN_Struct)->arr2_code1;
		m_LinearDim_Str.arr2_code2 = ((LinearDim_Struct*)IN_Struct)->arr2_code2;
		m_LinearDim_Str.arr2_x = ((LinearDim_Struct*)IN_Struct)->arr2_x;
		m_LinearDim_Str.arr2_y = ((LinearDim_Struct*)IN_Struct)->arr2_y;
		m_LinearDim_Str.arr2_r = ((LinearDim_Struct*)IN_Struct)->arr2_r;
		m_LinearDim_Str.flg4 = ((LinearDim_Struct*)IN_Struct)->flg4;
		m_LinearDim_Str.font = ((LinearDim_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_LinearDim_Str.str,((LinearDim_Struct*)IN_Struct)->str);
		strcpy_s(m_LinearDim_Str.str,_countof(m_LinearDim_Str.str),((LinearDim_Struct*)IN_Struct)->str);
		m_LinearDim_Str.text_x = ((LinearDim_Struct*)IN_Struct)->text_x;
		m_LinearDim_Str.text_y = ((LinearDim_Struct*)IN_Struct)->text_y;
		m_LinearDim_Str.height = ((LinearDim_Struct*)IN_Struct)->height;
		m_LinearDim_Str.width = ((LinearDim_Struct*)IN_Struct)->width;
		m_LinearDim_Str.spc = ((LinearDim_Struct*)IN_Struct)->spc;
		m_LinearDim_Str.angle = ((LinearDim_Struct*)IN_Struct)->angle;
		m_LinearDim_Str.slant = ((LinearDim_Struct*)IN_Struct)->slant;
		m_LinearDim_Str.b_pnt = ((LinearDim_Struct*)IN_Struct)->b_pnt;
		m_LinearDim_Str.direct = ((LinearDim_Struct*)IN_Struct)->direct;

		m_LinearDimMapping = new SXFLinearDimMappingC(m_TableManager);
		if (m_LinearDimMapping->MappingStruct(m_LinearDim_Str,m_AssemType)){
			m_LinearDimMapping->WriteAP202(m_Part21File);
			m_LinearDimMapping->GetID(OUT_Id1,OUT_Id2);
			return 1;
		}
		else
			return -1;
	}
	/*弧長寸法*/
	else if (strcmp(m_FeatureType,DEF_CURVE_DIMENSION) == 0){
		m_CurveDim_Str.layer = ((CurveDim_Struct*)IN_Struct)->layer;
		m_CurveDim_Str.color = ((CurveDim_Struct*)IN_Struct)->color;
		m_CurveDim_Str.type = ((CurveDim_Struct*)IN_Struct)->type;
		m_CurveDim_Str.line_width = ((CurveDim_Struct*)IN_Struct)->line_width;
		m_CurveDim_Str.sun_x = ((CurveDim_Struct*)IN_Struct)->sun_x;
		m_CurveDim_Str.sun_y = ((CurveDim_Struct*)IN_Struct)->sun_y;
		m_CurveDim_Str.sun_radius = ((CurveDim_Struct*)IN_Struct)->sun_radius;
		m_CurveDim_Str.sun_angle0 = ((CurveDim_Struct*)IN_Struct)->sun_angle0;
		m_CurveDim_Str.sun_angle1 = ((CurveDim_Struct*)IN_Struct)->sun_angle1;
		m_CurveDim_Str.flg2 = ((CurveDim_Struct*)IN_Struct)->flg2;
		m_CurveDim_Str.ho1_x0 = ((CurveDim_Struct*)IN_Struct)->ho1_x0;
		m_CurveDim_Str.ho1_y0 = ((CurveDim_Struct*)IN_Struct)->ho1_y0;
		m_CurveDim_Str.ho1_x1 = ((CurveDim_Struct*)IN_Struct)->ho1_x1;
		m_CurveDim_Str.ho1_y1 = ((CurveDim_Struct*)IN_Struct)->ho1_y1;
		m_CurveDim_Str.ho1_x2 = ((CurveDim_Struct*)IN_Struct)->ho1_x2;
		m_CurveDim_Str.ho1_y2 = ((CurveDim_Struct*)IN_Struct)->ho1_y2;
		m_CurveDim_Str.flg3 = ((CurveDim_Struct*)IN_Struct)->flg3;
		m_CurveDim_Str.ho2_x0 = ((CurveDim_Struct*)IN_Struct)->ho2_x0;
		m_CurveDim_Str.ho2_y0 = ((CurveDim_Struct*)IN_Struct)->ho2_y0;
		m_CurveDim_Str.ho2_x1 = ((CurveDim_Struct*)IN_Struct)->ho2_x1;
		m_CurveDim_Str.ho2_y1 = ((CurveDim_Struct*)IN_Struct)->ho2_y1;
		m_CurveDim_Str.ho2_x2 = ((CurveDim_Struct*)IN_Struct)->ho2_x2;
		m_CurveDim_Str.ho2_y2 = ((CurveDim_Struct*)IN_Struct)->ho2_y2;
		m_CurveDim_Str.arr1_code1 = ((CurveDim_Struct*)IN_Struct)->arr1_code1;
		m_CurveDim_Str.arr1_code2 = ((CurveDim_Struct*)IN_Struct)->arr1_code2;
		m_CurveDim_Str.arr1_x = ((CurveDim_Struct*)IN_Struct)->arr1_x;
		m_CurveDim_Str.arr1_y = ((CurveDim_Struct*)IN_Struct)->arr1_y;
		m_CurveDim_Str.arr1_r = ((CurveDim_Struct*)IN_Struct)->arr1_r;
		m_CurveDim_Str.arr2_code1 = ((CurveDim_Struct*)IN_Struct)->arr2_code1;
		m_CurveDim_Str.arr2_code2 = ((CurveDim_Struct*)IN_Struct)->arr2_code2;
		m_CurveDim_Str.arr2_x = ((CurveDim_Struct*)IN_Struct)->arr2_x;
		m_CurveDim_Str.arr2_y = ((CurveDim_Struct*)IN_Struct)->arr2_y;
		m_CurveDim_Str.arr2_r = ((CurveDim_Struct*)IN_Struct)->arr2_r;
		m_CurveDim_Str.flg4 = ((CurveDim_Struct*)IN_Struct)->flg4;
		m_CurveDim_Str.font = ((CurveDim_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_CurveDim_Str.str,((CurveDim_Struct*)IN_Struct)->str);
		strcpy_s(m_CurveDim_Str.str,_countof(m_CurveDim_Str.str),((CurveDim_Struct*)IN_Struct)->str);
		m_CurveDim_Str.text_x = ((CurveDim_Struct*)IN_Struct)->text_x;
		m_CurveDim_Str.text_y = ((CurveDim_Struct*)IN_Struct)->text_y;
		m_CurveDim_Str.height = ((CurveDim_Struct*)IN_Struct)->height;
		m_CurveDim_Str.width = ((CurveDim_Struct*)IN_Struct)->width;
		m_CurveDim_Str.spc = ((CurveDim_Struct*)IN_Struct)->spc;
		m_CurveDim_Str.angle = ((CurveDim_Struct*)IN_Struct)->angle;
		m_CurveDim_Str.slant = ((CurveDim_Struct*)IN_Struct)->slant;
		m_CurveDim_Str.b_pnt = ((CurveDim_Struct*)IN_Struct)->b_pnt;
		m_CurveDim_Str.direct = ((CurveDim_Struct*)IN_Struct)->direct;

		m_CurveDimMapping = new SXFCurveDimMappingC(m_TableManager);
		int ret = m_CurveDimMapping->MappingStruct(m_CurveDim_Str,m_AssemType);
		if (ret > 0){
			m_CurveDimMapping->WriteAP202(m_Part21File);
			m_CurveDimMapping->GetID(OUT_Id1,OUT_Id2);
			return 1;
		}
		else
			return ret;
	}
	/*角度寸法*/
	else if (strcmp(m_FeatureType,DEF_ANGULAR_DIMENSION) == 0){
		m_AngularDim_Str.layer = ((AngularDim_Struct*)IN_Struct)->layer;
		m_AngularDim_Str.color = ((AngularDim_Struct*)IN_Struct)->color;
		m_AngularDim_Str.type = ((AngularDim_Struct*)IN_Struct)->type;
		m_AngularDim_Str.line_width = ((AngularDim_Struct*)IN_Struct)->line_width;
		m_AngularDim_Str.sun_x = ((AngularDim_Struct*)IN_Struct)->sun_x;
		m_AngularDim_Str.sun_y = ((AngularDim_Struct*)IN_Struct)->sun_y;
		m_AngularDim_Str.sun_radius = ((AngularDim_Struct*)IN_Struct)->sun_radius;
		m_AngularDim_Str.sun_angle0 = ((AngularDim_Struct*)IN_Struct)->sun_angle0;
		m_AngularDim_Str.sun_angle1 = ((AngularDim_Struct*)IN_Struct)->sun_angle1;
		m_AngularDim_Str.flg2 = ((AngularDim_Struct*)IN_Struct)->flg2;
		m_AngularDim_Str.ho1_x0 = ((AngularDim_Struct*)IN_Struct)->ho1_x0;
		m_AngularDim_Str.ho1_y0 = ((AngularDim_Struct*)IN_Struct)->ho1_y0;
		m_AngularDim_Str.ho1_x1 = ((AngularDim_Struct*)IN_Struct)->ho1_x1;
		m_AngularDim_Str.ho1_y1 = ((AngularDim_Struct*)IN_Struct)->ho1_y1;
		m_AngularDim_Str.ho1_x2 = ((AngularDim_Struct*)IN_Struct)->ho1_x2;
		m_AngularDim_Str.ho1_y2 = ((AngularDim_Struct*)IN_Struct)->ho1_y2;
		m_AngularDim_Str.flg3 = ((AngularDim_Struct*)IN_Struct)->flg3;
		m_AngularDim_Str.ho2_x0 = ((AngularDim_Struct*)IN_Struct)->ho2_x0;
		m_AngularDim_Str.ho2_y0 = ((AngularDim_Struct*)IN_Struct)->ho2_y0;
		m_AngularDim_Str.ho2_x1 = ((AngularDim_Struct*)IN_Struct)->ho2_x1;
		m_AngularDim_Str.ho2_y1 = ((AngularDim_Struct*)IN_Struct)->ho2_y1;
		m_AngularDim_Str.ho2_x2 = ((AngularDim_Struct*)IN_Struct)->ho2_x2;
		m_AngularDim_Str.ho2_y2 = ((AngularDim_Struct*)IN_Struct)->ho2_y2;
		m_AngularDim_Str.arr1_code1 = ((AngularDim_Struct*)IN_Struct)->arr1_code1;
		m_AngularDim_Str.arr1_code2 = ((AngularDim_Struct*)IN_Struct)->arr1_code2;
		m_AngularDim_Str.arr1_x = ((AngularDim_Struct*)IN_Struct)->arr1_x;
		m_AngularDim_Str.arr1_y = ((AngularDim_Struct*)IN_Struct)->arr1_y;
		m_AngularDim_Str.arr1_r = ((AngularDim_Struct*)IN_Struct)->arr1_r;
		m_AngularDim_Str.arr2_code1 = ((AngularDim_Struct*)IN_Struct)->arr2_code1;
		m_AngularDim_Str.arr2_code2 = ((AngularDim_Struct*)IN_Struct)->arr2_code2;
		m_AngularDim_Str.arr2_x = ((AngularDim_Struct*)IN_Struct)->arr2_x;
		m_AngularDim_Str.arr2_y = ((AngularDim_Struct*)IN_Struct)->arr2_y;
		m_AngularDim_Str.arr2_r = ((AngularDim_Struct*)IN_Struct)->arr2_r;
		m_AngularDim_Str.flg4 = ((AngularDim_Struct*)IN_Struct)->flg4;
		m_AngularDim_Str.font = ((AngularDim_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_AngularDim_Str.str,((AngularDim_Struct*)IN_Struct)->str);
		strcpy_s(m_AngularDim_Str.str,_countof(m_AngularDim_Str.str),((AngularDim_Struct*)IN_Struct)->str);
		m_AngularDim_Str.text_x = ((AngularDim_Struct*)IN_Struct)->text_x;
		m_AngularDim_Str.text_y = ((AngularDim_Struct*)IN_Struct)->text_y;
		m_AngularDim_Str.height = ((AngularDim_Struct*)IN_Struct)->height;
		m_AngularDim_Str.width = ((AngularDim_Struct*)IN_Struct)->width;
		m_AngularDim_Str.spc = ((AngularDim_Struct*)IN_Struct)->spc;
		m_AngularDim_Str.angle = ((AngularDim_Struct*)IN_Struct)->angle;
		m_AngularDim_Str.slant = ((AngularDim_Struct*)IN_Struct)->slant;
		m_AngularDim_Str.b_pnt = ((AngularDim_Struct*)IN_Struct)->b_pnt;
		m_AngularDim_Str.direct = ((AngularDim_Struct*)IN_Struct)->direct;

		m_AngularDimMapping = new SXFAngularDimMappingC(m_TableManager);
		int ret = m_AngularDimMapping->MappingStruct(m_AngularDim_Str,m_AssemType);
		if (ret > 0){
			m_AngularDimMapping->WriteAP202(m_Part21File);
			m_AngularDimMapping->GetID(OUT_Id1,OUT_Id2);
			return 1;
		}
		else
			return ret;
	}
	/*半径寸法*/
	else if (strcmp(m_FeatureType,DEF_RADIUS_DIMENSION) == 0){
		m_RadiusDim_Str.layer = ((RadiusDim_Struct*)IN_Struct)->layer;
		m_RadiusDim_Str.color = ((RadiusDim_Struct*)IN_Struct)->color;
		m_RadiusDim_Str.type = ((RadiusDim_Struct*)IN_Struct)->type;
		m_RadiusDim_Str.line_width = ((RadiusDim_Struct*)IN_Struct)->line_width;
		m_RadiusDim_Str.sun_x1 = ((RadiusDim_Struct*)IN_Struct)->sun_x1;
		m_RadiusDim_Str.sun_y1 = ((RadiusDim_Struct*)IN_Struct)->sun_y1;
		m_RadiusDim_Str.sun_x2 = ((RadiusDim_Struct*)IN_Struct)->sun_x2;
		m_RadiusDim_Str.sun_y2 = ((RadiusDim_Struct*)IN_Struct)->sun_y2;
		m_RadiusDim_Str.arr_code1 = ((RadiusDim_Struct*)IN_Struct)->arr_code1;
		m_RadiusDim_Str.arr_code2 = ((RadiusDim_Struct*)IN_Struct)->arr_code2;
		m_RadiusDim_Str.arr_x = ((RadiusDim_Struct*)IN_Struct)->arr_x;
		m_RadiusDim_Str.arr_y = ((RadiusDim_Struct*)IN_Struct)->arr_y;
		m_RadiusDim_Str.arr_r = ((RadiusDim_Struct*)IN_Struct)->arr_r;
		m_RadiusDim_Str.flg = ((RadiusDim_Struct*)IN_Struct)->flg;
		m_RadiusDim_Str.font = ((RadiusDim_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_RadiusDim_Str.str,((RadiusDim_Struct*)IN_Struct)->str);
		strcpy_s(m_RadiusDim_Str.str,_countof(m_RadiusDim_Str.str),((RadiusDim_Struct*)IN_Struct)->str);
		m_RadiusDim_Str.text_x = ((RadiusDim_Struct*)IN_Struct)->text_x;
		m_RadiusDim_Str.text_y = ((RadiusDim_Struct*)IN_Struct)->text_y;
		m_RadiusDim_Str.height = ((RadiusDim_Struct*)IN_Struct)->height;
		m_RadiusDim_Str.width = ((RadiusDim_Struct*)IN_Struct)->width;
		m_RadiusDim_Str.spc = ((RadiusDim_Struct*)IN_Struct)->spc;
		m_RadiusDim_Str.angle = ((RadiusDim_Struct*)IN_Struct)->angle;
		m_RadiusDim_Str.slant = ((RadiusDim_Struct*)IN_Struct)->slant;
		m_RadiusDim_Str.b_pnt = ((RadiusDim_Struct*)IN_Struct)->b_pnt;
		m_RadiusDim_Str.direct = ((RadiusDim_Struct*)IN_Struct)->direct;

		m_RadiusDimMapping = new SXFRadiusDimMappingC(m_TableManager);
		if (m_RadiusDimMapping->MappingStruct(m_RadiusDim_Str,m_AssemType)){
			m_RadiusDimMapping->WriteAP202(m_Part21File);
			m_RadiusDimMapping->GetID(OUT_Id1,OUT_Id2);
			return 1;
		}
		else
			return -1;
	}
	/*直径寸法*/
	else if (strcmp(m_FeatureType,DEF_DIAMETER_DIMENSION) == 0){
		m_DiameterDim_Str.layer = ((DiameterDim_Struct*)IN_Struct)->layer;
		m_DiameterDim_Str.color = ((DiameterDim_Struct*)IN_Struct)->color;
		m_DiameterDim_Str.type = ((DiameterDim_Struct*)IN_Struct)->type;
		m_DiameterDim_Str.line_width = ((DiameterDim_Struct*)IN_Struct)->line_width;
		m_DiameterDim_Str.sun_x1 = ((DiameterDim_Struct*)IN_Struct)->sun_x1;
		m_DiameterDim_Str.sun_y1 = ((DiameterDim_Struct*)IN_Struct)->sun_y1;
		m_DiameterDim_Str.sun_x2 = ((DiameterDim_Struct*)IN_Struct)->sun_x2;
		m_DiameterDim_Str.sun_y2 = ((DiameterDim_Struct*)IN_Struct)->sun_y2;
		m_DiameterDim_Str.arr1_code1 = ((DiameterDim_Struct*)IN_Struct)->arr1_code1;
		m_DiameterDim_Str.arr1_code2 = ((DiameterDim_Struct*)IN_Struct)->arr1_code2;
		m_DiameterDim_Str.arr1_x = ((DiameterDim_Struct*)IN_Struct)->arr1_x;
		m_DiameterDim_Str.arr1_y = ((DiameterDim_Struct*)IN_Struct)->arr1_y;
		m_DiameterDim_Str.arr1_r = ((DiameterDim_Struct*)IN_Struct)->arr1_r;
		m_DiameterDim_Str.arr2_code1 = ((DiameterDim_Struct*)IN_Struct)->arr2_code1;
		m_DiameterDim_Str.arr2_code2 = ((DiameterDim_Struct*)IN_Struct)->arr2_code2;
		m_DiameterDim_Str.arr2_x = ((DiameterDim_Struct*)IN_Struct)->arr2_x;
		m_DiameterDim_Str.arr2_y = ((DiameterDim_Struct*)IN_Struct)->arr2_y;
		m_DiameterDim_Str.arr2_r = ((DiameterDim_Struct*)IN_Struct)->arr2_r;
		m_DiameterDim_Str.flg = ((DiameterDim_Struct*)IN_Struct)->flg;
		m_DiameterDim_Str.font = ((DiameterDim_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_DiameterDim_Str.str,((DiameterDim_Struct*)IN_Struct)->str);
		strcpy_s(m_DiameterDim_Str.str,_countof(m_DiameterDim_Str.str),((DiameterDim_Struct*)IN_Struct)->str);
		m_DiameterDim_Str.text_x = ((DiameterDim_Struct*)IN_Struct)->text_x;
		m_DiameterDim_Str.text_y = ((DiameterDim_Struct*)IN_Struct)->text_y;
		m_DiameterDim_Str.height = ((DiameterDim_Struct*)IN_Struct)->height;
		m_DiameterDim_Str.width = ((DiameterDim_Struct*)IN_Struct)->width;
		m_DiameterDim_Str.spc = ((DiameterDim_Struct*)IN_Struct)->spc;
		m_DiameterDim_Str.angle = ((DiameterDim_Struct*)IN_Struct)->angle;
		m_DiameterDim_Str.slant = ((DiameterDim_Struct*)IN_Struct)->slant;
		m_DiameterDim_Str.b_pnt = ((DiameterDim_Struct*)IN_Struct)->b_pnt;
		m_DiameterDim_Str.direct = ((DiameterDim_Struct*)IN_Struct)->direct;

		m_DiameterDimMapping = new SXFDiameterDimMappingC(m_TableManager);
		if (m_DiameterDimMapping->MappingStruct(m_DiameterDim_Str,m_AssemType)){
			m_DiameterDimMapping->WriteAP202(m_Part21File);
			m_DiameterDimMapping->GetID(OUT_Id1,OUT_Id2);
			return 1;
		}
		else
			return -1;
	}
	/*引き出し線*/
	else if (strcmp(m_FeatureType,DEF_LABEL) == 0){
		m_Label_Str.layer = ((Label_Struct*)IN_Struct)->layer;
		m_Label_Str.color = ((Label_Struct*)IN_Struct)->color;
		m_Label_Str.type = ((Label_Struct*)IN_Struct)->type;
		m_Label_Str.line_width = ((Label_Struct*)IN_Struct)->line_width;
		m_Label_Str.vertex_number = ((Label_Struct*)IN_Struct)->vertex_number;
		for (int i = 0; i < m_Label_Str.vertex_number;i++){
			m_Label_Str.vertex_x.Add(((Label_Struct*)IN_Struct)->vertex_x[i]);
			m_Label_Str.vertex_y.Add(((Label_Struct*)IN_Struct)->vertex_y[i]);
		}
		m_Label_Str.arr_code = ((Label_Struct*)IN_Struct)->arr_code;
		m_Label_Str.arr_r = ((Label_Struct*)IN_Struct)->arr_r;
		m_Label_Str.flg = ((Label_Struct*)IN_Struct)->flg;
		m_Label_Str.font = ((Label_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Label_Str.str,((Label_Struct*)IN_Struct)->str);
		strcpy_s(m_Label_Str.str,_countof(m_Label_Str.str),((Label_Struct*)IN_Struct)->str);
		m_Label_Str.text_x = ((Label_Struct*)IN_Struct)->text_x;
		m_Label_Str.text_y = ((Label_Struct*)IN_Struct)->text_y;
		m_Label_Str.height = ((Label_Struct*)IN_Struct)->height;
		m_Label_Str.width = ((Label_Struct*)IN_Struct)->width;
		m_Label_Str.spc = ((Label_Struct*)IN_Struct)->spc;
		m_Label_Str.angle = ((Label_Struct*)IN_Struct)->angle;
		m_Label_Str.slant = ((Label_Struct*)IN_Struct)->slant;
		m_Label_Str.b_pnt = ((Label_Struct*)IN_Struct)->b_pnt;
		m_Label_Str.direct = ((Label_Struct*)IN_Struct)->direct;

		m_LabelMapping = new SXFLabelMappingC(m_TableManager);
		if (m_LabelMapping->MappingStruct(&m_Label_Str,m_AssemType)){
			m_LabelMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_LabelMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*バルーン*/
	else if (strcmp(m_FeatureType,DEF_BALLOON) == 0){
		m_Balloon_Str.layer = ((Balloon_Struct*)IN_Struct)->layer;
		m_Balloon_Str.color = ((Balloon_Struct*)IN_Struct)->color;
		m_Balloon_Str.type = ((Balloon_Struct*)IN_Struct)->type;
		m_Balloon_Str.line_width = ((Balloon_Struct*)IN_Struct)->line_width;
		m_Balloon_Str.vertex_number = ((Balloon_Struct*)IN_Struct)->vertex_number;
		for (int i = 0; i < m_Balloon_Str.vertex_number;i++){
			m_Balloon_Str.vertex_x.Add(((Balloon_Struct*)IN_Struct)->vertex_x[i]);
			m_Balloon_Str.vertex_y.Add(((Balloon_Struct*)IN_Struct)->vertex_y[i]);
		}
		m_Balloon_Str.center_x = ((Balloon_Struct*)IN_Struct)->center_x;
		m_Balloon_Str.center_y = ((Balloon_Struct*)IN_Struct)->center_y;
		m_Balloon_Str.radius = ((Balloon_Struct*)IN_Struct)->radius;
		m_Balloon_Str.arr_code = ((Balloon_Struct*)IN_Struct)->arr_code;
		m_Balloon_Str.arr_r = ((Balloon_Struct*)IN_Struct)->arr_r;
		m_Balloon_Str.flg = ((Balloon_Struct*)IN_Struct)->flg;
		m_Balloon_Str.font = ((Balloon_Struct*)IN_Struct)->font;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_Balloon_Str.str,((Balloon_Struct*)IN_Struct)->str);
		strcpy_s(m_Balloon_Str.str,_countof(m_Balloon_Str.str),((Balloon_Struct*)IN_Struct)->str);
		m_Balloon_Str.text_x = ((Balloon_Struct*)IN_Struct)->text_x;
		m_Balloon_Str.text_y = ((Balloon_Struct*)IN_Struct)->text_y;
		m_Balloon_Str.height = ((Balloon_Struct*)IN_Struct)->height;
		m_Balloon_Str.width = ((Balloon_Struct*)IN_Struct)->width;
		m_Balloon_Str.spc = ((Balloon_Struct*)IN_Struct)->spc;
		m_Balloon_Str.angle = ((Balloon_Struct*)IN_Struct)->angle;
		m_Balloon_Str.slant = ((Balloon_Struct*)IN_Struct)->slant;
		m_Balloon_Str.b_pnt = ((Balloon_Struct*)IN_Struct)->b_pnt;
		m_Balloon_Str.direct = ((Balloon_Struct*)IN_Struct)->direct;

		m_BalloonMapping = new SXFBalloonMappingC(m_TableManager);
		if (m_BalloonMapping->MappingStruct(&m_Balloon_Str,m_AssemType)){
			m_BalloonMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_BalloonMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*外部定義ハッチング*/
	else if (strcmp(m_FeatureType,DEF_EXTERNALLY_DEFINED_HATCH) == 0){
		m_ExHatch_Str.layer = ((Externally_Defined_Hatch_Struct*)IN_Struct)->layer;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_ExHatch_Str.name,((Externally_Defined_Hatch_Struct*)IN_Struct)->name);
		strcpy_s(m_ExHatch_Str.name,_countof(m_ExHatch_Str.name),((Externally_Defined_Hatch_Struct*)IN_Struct)->name);
		m_ExHatch_Str.out_id = ((Externally_Defined_Hatch_Struct*)IN_Struct)->out_id;
		m_ExHatch_Str.number = ((Externally_Defined_Hatch_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_ExHatch_Str.number; i++)
			m_ExHatch_Str.in_id.Add(((Externally_Defined_Hatch_Struct*)IN_Struct)->in_id[i]);

		m_ExHatchMapping = new SXFExHatchMappingC(m_TableManager,m_AssemblyTable,m_PointTable);
		if (m_ExHatchMapping->MappingStruct(&m_ExHatch_Str)){
			m_ExHatchMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_ExHatchMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*ハッチング（塗り）*/
	else if (strcmp(m_FeatureType,DEF_FILL_AREA_STYLE_COLOUR) == 0){
		m_FillColour_Str.layer = ((Fill_area_style_colour_Struct*)IN_Struct)->layer;
		m_FillColour_Str.color = ((Fill_area_style_colour_Struct*)IN_Struct)->color;
		m_FillColour_Str.out_id = ((Fill_area_style_colour_Struct*)IN_Struct)->out_id;
		m_FillColour_Str.number = ((Fill_area_style_colour_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_FillColour_Str.number; i++)
			m_FillColour_Str.in_id.Add(((Fill_area_style_colour_Struct*)IN_Struct)->in_id[i]);

		m_FillColourMapping = new SXFFillColourMappingC(m_TableManager,m_AssemblyTable,m_PointTable);
		if (m_FillColourMapping->MappingStruct(&m_FillColour_Str)){
			m_FillColourMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_FillColourMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*ハッチング（ユーザ定義）*/
	else if (strcmp(m_FeatureType,DEF_FILL_AREA_STYLE_HATCHING) == 0){
		m_FillHatching_Str.layer = ((Fill_area_style_hatching_Struct*)IN_Struct)->layer;
		m_FillHatching_Str.hatch_number = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_number;
		for (int j = 0; j < m_FillHatching_Str.hatch_number; j++){
			m_FillHatching_Str.hatch_color[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_color[j];
			m_FillHatching_Str.hatch_type[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_type[j];
			m_FillHatching_Str.hatch_line_width[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_line_width[j];
			m_FillHatching_Str.hatch_start_x[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_start_x[j];
			m_FillHatching_Str.hatch_start_y[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_start_y[j];
			m_FillHatching_Str.hatch_spacing[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_spacing[j];
			m_FillHatching_Str.hatch_angle[j] = ((Fill_area_style_hatching_Struct*)IN_Struct)->hatch_angle[j];
		}
		m_FillHatching_Str.out_id = ((Fill_area_style_hatching_Struct*)IN_Struct)->out_id;
		m_FillHatching_Str.number = ((Fill_area_style_hatching_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_FillHatching_Str.number; i++)
			m_FillHatching_Str.in_id.Add(((Fill_area_style_hatching_Struct*)IN_Struct)->in_id[i]);

		m_FillHatchingMapping = new SXFFillHatchingMappingC(m_TableManager,m_AssemblyTable);
		if (m_FillHatchingMapping->MappingStruct(&m_FillHatching_Str)){
			m_FillHatchingMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_FillHatchingMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	/*ハッチング（パターン）*/
	else if (strcmp(m_FeatureType,DEF_FILL_AREA_STYLE_TILES) == 0){
		m_FillTiles_Str.layer = ((Fill_area_style_tiles_Struct*)IN_Struct)->layer;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//		strcpy(m_FillTiles_Str.name,((Fill_area_style_tiles_Struct*)IN_Struct)->name);
		strcpy_s(m_FillTiles_Str.name,_countof(m_FillTiles_Str.name),((Fill_area_style_tiles_Struct*)IN_Struct)->name);
		m_FillTiles_Str.hatch_color = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_color;
		m_FillTiles_Str.hatch_pattern_x = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_x;
		m_FillTiles_Str.hatch_pattern_y = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_y;
		m_FillTiles_Str.hatch_pattern_vector1 = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_vector1;
		m_FillTiles_Str.hatch_pattern_vector1_angle = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_vector1_angle;
		m_FillTiles_Str.hatch_pattern_vector2 = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_vector2;
		m_FillTiles_Str.hatch_pattern_vector2_angle = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_vector2_angle;
		m_FillTiles_Str.hatch_pattern_scale_x = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_scale_x;
		m_FillTiles_Str.hatch_pattern_scale_y = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_scale_y;
		m_FillTiles_Str.hatch_pattern_angle = ((Fill_area_style_tiles_Struct*)IN_Struct)->hatch_pattern_angle;
		m_FillTiles_Str.out_id = ((Fill_area_style_tiles_Struct*)IN_Struct)->out_id;
		m_FillTiles_Str.number = ((Fill_area_style_tiles_Struct*)IN_Struct)->number;
		for (int i = 0; i < m_FillTiles_Str.number; i++)
			m_FillTiles_Str.in_id.Add(((Fill_area_style_tiles_Struct*)IN_Struct)->in_id[i]);

		m_FillTilesMapping = new SXFFillTilesMappingC(m_TableManager,m_AssemblyTable);
		if (m_FillTilesMapping->MappingStruct(&m_FillTiles_Str)){
			m_FillTilesMapping->WriteAP202(m_Part21File);
			OUT_Id1 = m_FillTilesMapping->GetID();
			return 1;
		}
		else
			return -1;
	}
	else{
		return -1;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	構造体をセットする

	２．インターフェース
	BOOL SXFWriteMappingManagerC::SetStructData(char *IN_FeatureType, LPVOID IN_Struct)
	引数:	型				引数名				内容
			char*			IN_FeatureType		フィーチャ型
			LPVOID			IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFWriteMappingManagerC::SetStructData(char *IN_FeatureType, LPVOID IN_Struct)
{
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.cpp								作成日：2001.06.14

	１．機能概要
	InvisibilityインスタンスをMappingする

	２．インターフェース
	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable)
	引数:	型				引数名					内容
			CUIntArray*		IN_InvisibilityTable	InvisibilityインスタンスがもつインスタンスIDの配列

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFWriteMappingManagerC::MappingInvisibility(CUIntArray* IN_InvisibilityTable)
{
	m_InvisibilityMapping = new SXFInvisibilityMappingC();
	if (m_InvisibilityMapping->MappingStruct(IN_InvisibilityTable)){
		m_InvisibilityMapping->WriteAP202(m_Part21File);
		return TRUE;
	}
	else
		return FALSE;
}
