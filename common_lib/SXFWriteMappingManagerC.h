/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.h								作成日：2001.06.14

	１．クラス概要
	Write時のフィーチャオブジェクトとMappingオブジェクトの管理を行うクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。
	更新			2001.09.18			K.Naono				ハッチング障害対応

**/

#if !defined(AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFWriteManagerC.h"

class SXFSfigMappingC;
class SXFSheetMappingC;
class SXFCompCurveMappingC;
class SXFLineMappingC;
class SXFTextStringMappingC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFPointMarkerMappingC;
class SXFCircleMappingC;
class SXFArcMappingC;
class SXFEllipseMappingC;
class SXFEllipseArcMappingC;
class SXFPolylineMappingC;
class SXFSplineMappingC;
class SXFClothoidMappingC;
class SXFCirlceMappingC;
class SXFLinearDimMappingC;
class SXFCurveDimMappingC;
class SXFAngularDimMappingC;
class SXFDiameterDimMappingC;
class SXFRadiusDimMappingC;
class SXFLabelMappingC;
class SXFBalloonMappingC;
class SXFExSymbolMappingC;
class SXFSfiglocMappingC;
class SXFExHatchMappingC;
class SXFFillColourMappingC;
class SXFFillHatchingMappingC;
class SXFFillTilesMappingC;
class SXFInvisibilityMappingC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;
class SXFFeatureC;
class SXFAttrMappingC;

class SXFWriteMappingManagerC  
{
public:
	BOOL SetStructData(char* IN_FeatureType,LPVOID IN_Struct);
	int MappingFeature(
				char*	IN_FeatureType,
				LPVOID	IN_Struct,
				int&	OUT_Id1,
				int&	OUT_Id2,
				double&	INOUT_PointX,
				double&	INOUT_PointY,
				int &INOUT_PointN);
	void ClearData();
	BOOL MappingAssembly(
				CUIntArray*	IN_ChildrenID,
				int&		OUT_AssemblyID1,
				int&		OUT_AssemblyID2,
				int&		OUT_PointID,
				double		IN_PointX,
				double		IN_PointY);
	BOOL SetStructData(int IN_Asem_Type,LPVOID IN_Struct);
	SXFWriteMappingManagerC();
	SXFWriteMappingManagerC(
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
						SXFInstanceIDC*					IN_InstanceIDManager);
	SXFWriteMappingManagerC(SXFPart21FileC* IN_File);
	virtual ~SXFWriteMappingManagerC();

	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable);

//	MOD(S)	チューニング対応	K.Naono		03.07.08
//	SXFSFIGORGTABLE *m_SfigorgTable;
	CMapStringToPtr*	m_SfigorgTable ;
//	MOD(E)	チューニング対応	K.Naono		03.07.08

private:
	////////////////////////////////
	//アセンブリフィーチャオブジェクト
	////////////////////////////////
	SXFFeatureC* m_AsemFeature;
	////////////////////////////////
	//フィーチャオブジェクト
	////////////////////////////////
	SXFFeatureC* m_Feature;

	////////////////////////////////
	//ファイルオブジェクト
	////////////////////////////////
	SXFPart21FileC* m_Part21File;
	////////////////////////////////
	//ファイル出力オブジェクト
	////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;

	////////////////////////////////
	//共通情報管理オブジェクト
	////////////////////////////////
	SXFComInfoC* m_ComInfo;
	////////////////////////////////
	//インスタンスIDオブジェクト
	////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	////////////////////////////////
	//定義テーブル管理オブジェクト
	////////////////////////////////
	SXFTableManagerC* m_TableManager;

	////////////////////////////////
	//フィーチャ型
	////////////////////////////////
	char* m_FeatureType;
	////////////////////////////////
	//アセンブリ型
	////////////////////////////////
	int m_AssemType;

	////////////////////////////////
	//アセンブリテーブル
	////////////////////////////////
	CUIntArray *m_AssemblyTable;
	////////////////////////////////
	//ハッチング内部の点のテーブル
	////////////////////////////////
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//	CUIntArray *m_PointTable;
	CArray<SXF_POINT,SXF_POINT&>*	m_PointTable ;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18

	////////////////////////////////
	//用紙構造体
	////////////////////////////////
	Sheet_Struct m_Sheet_Str;
	////////////////////////////////
	//点マーカ構造体
	////////////////////////////////
	Point_Marker_Struct m_Point_Marker_Str;
	////////////////////////////////
	//線分構造体
	////////////////////////////////
	Line_Struct m_Line_Str;
	////////////////////////////////
	//折線構造体
	////////////////////////////////
	Polyline_Struct m_Polyline_Str;
	////////////////////////////////
	//円構造体
	////////////////////////////////
	Circle_Struct m_Circle_Str;
	////////////////////////////////
	//円弧構造体
	////////////////////////////////
	Arc_Struct m_Arc_Str;
	////////////////////////////////
	//楕円構造体
	////////////////////////////////
	Ellipse_Struct m_Ellipse_Str;
	////////////////////////////////
	//楕円弧構造体
	////////////////////////////////
	Ellipse_Arc_Struct m_Ellipse_Arc_Str;
	////////////////////////////////
	//文字要素構造体
	////////////////////////////////
	Text_Struct m_Text_String_Str;
	////////////////////////////////
	//スプライン構造体
	////////////////////////////////
	Spline_Struct m_Spline_Str;
	////////////////////////////////
	//クロソイド構造体
	////////////////////////////////
	Clothoid_Struct m_Clothoid_Str;
	////////////////////////////////
	//複合図形定義構造体
	////////////////////////////////
	Sfigorg_Struct m_Sfigorg_Str;
	////////////////////////////////
	//複合図形配置構造体
	////////////////////////////////
	Sfigloc_Struct m_Sfigloc_Str;
	////////////////////////////////
	//既定義シンボル構造体
	////////////////////////////////
	Externally_Defined_Symbol_Struct m_ExSymbol_Str;
	////////////////////////////////
	//直線寸法構造体
	////////////////////////////////
	LinearDim_Struct m_LinearDim_Str;
	////////////////////////////////
	//弧長寸法構造体
	////////////////////////////////
	CurveDim_Struct m_CurveDim_Str;
	////////////////////////////////
	//角度寸法構造体
	////////////////////////////////
	AngularDim_Struct m_AngularDim_Str;
	////////////////////////////////
	//半径寸法構造体
	////////////////////////////////
	RadiusDim_Struct m_RadiusDim_Str;
	////////////////////////////////
	//直径寸法構造体
	////////////////////////////////
	DiameterDim_Struct m_DiameterDim_Str;
	////////////////////////////////
	//引き出し線構造体
	////////////////////////////////
	Label_Struct m_Label_Str;
	////////////////////////////////
	//バルーン構造体
	////////////////////////////////
	Balloon_Struct m_Balloon_Str;
	////////////////////////////////
	//ハッチング（外部定義）構造体
	////////////////////////////////
	Externally_Defined_Hatch_Struct m_ExHatch_Str;
	////////////////////////////////
	//ハッチング（塗り)構造体
	////////////////////////////////
	Fill_area_style_colour_Struct m_FillColour_Str;
	////////////////////////////////
	//ハッチング（ユーザ定義）構造体
	////////////////////////////////
	Fill_area_style_hatching_Struct m_FillHatching_Str;
	////////////////////////////////
	//ハッチング(パターン)構造体
	////////////////////////////////
	Fill_area_style_tiles_Struct m_FillTiles_Str;
	////////////////////////////////
	//複合曲線構造体
	////////////////////////////////
	Ccurve_Org_Struct m_CompCurve_Str;

	////////////////////////////////
	//用紙Mappingオブジェクト
	////////////////////////////////
	SXFSheetMappingC* m_SheetMapping;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	//	図面表題欄Mappingオブジェクト
	SXFAttrMappingC* m_AttrMapping ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

	////////////////////////////////
	//点マーカMappingオブジェクト
	////////////////////////////////
	SXFPointMarkerMappingC* m_PointMarkerMapping;
	////////////////////////////////
	//線分Mappingオブジェクト
	////////////////////////////////
	SXFLineMappingC* m_LineMapping;
	////////////////////////////////
	//折線Mappingオブジェクト
	////////////////////////////////
	SXFPolylineMappingC* m_PolylineMapping;
	////////////////////////////////
	//円Mappingオブジェクト
	////////////////////////////////
	SXFCircleMappingC* m_CircleMapping;
	////////////////////////////////
	//円弧Mappingオブジェクト
	////////////////////////////////
	SXFArcMappingC* m_ArcMapping;
	////////////////////////////////
	//楕円Mappingオブジェクト
	////////////////////////////////
	SXFEllipseMappingC* m_EllipseMapping;
	////////////////////////////////
	//楕円弧Mappingオブジェクト
	////////////////////////////////
	SXFEllipseArcMappingC* m_EllipseArcMapping;
	////////////////////////////////
	//文字要素Mappingのオブジェクト
	////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	////////////////////////////////
	//スプラインMappingオブジェクト
	////////////////////////////////
	SXFSplineMappingC* m_SplineMapping;
	////////////////////////////////
	//クロソイドMappingオブジェクト
	////////////////////////////////
	SXFClothoidMappingC* m_ClothoidMapping;
	////////////////////////////////
	//複合図形定義Mappingオブジェクト
	////////////////////////////////
	SXFSfigMappingC* m_SfigMapping;
	////////////////////////////////
	//複合図形配置Mappingのオブジェクト
	////////////////////////////////
	SXFSfiglocMappingC* m_SfiglocMapping;
	////////////////////////////////
	//既定義シンボルMappingのオブジェクト
	////////////////////////////////
	SXFExSymbolMappingC* m_ExSymbolMapping;
	////////////////////////////////
	//直線寸法Mappingのオブジェクト
	////////////////////////////////
	SXFLinearDimMappingC* m_LinearDimMapping;
	////////////////////////////////
	//弧長寸法Mappingのオブジェクト
	////////////////////////////////
	SXFCurveDimMappingC* m_CurveDimMapping;
	////////////////////////////////
	//角度寸法Mappingのオブジェクト
	////////////////////////////////
	SXFAngularDimMappingC* m_AngularDimMapping;
	////////////////////////////////
	//半径寸法Mappingのオブジェクト
	////////////////////////////////
	SXFRadiusDimMappingC* m_RadiusDimMapping;
	////////////////////////////////
	//直径寸法Mappingオブジェクト
	////////////////////////////////
	SXFDiameterDimMappingC* m_DiameterDimMapping;
	////////////////////////////////
	//ハッチング(パターン）Mappingのオブジェクト
	////////////////////////////////
	SXFFillTilesMappingC* m_FillTilesMapping;
	////////////////////////////////
	//ハッチング（ユーザ定義）Mappingのオブジェクト
	////////////////////////////////
	SXFFillHatchingMappingC* m_FillHatchingMapping;
	////////////////////////////////
	//ハッチング（塗り）Mappingのオブジェクト
	////////////////////////////////
	SXFFillColourMappingC* m_FillColourMapping;
	////////////////////////////////
	//ハッチング(外部定義）Mappingのオブジェクト
	////////////////////////////////
	SXFExHatchMappingC* m_ExHatchMapping;
	////////////////////////////////
	//バルーンMappingのオブジェクト
	////////////////////////////////
	SXFBalloonMappingC* m_BalloonMapping;
	////////////////////////////////
	//引き出し線Mappingのオブジェクト
	////////////////////////////////
	SXFLabelMappingC* m_LabelMapping;
	////////////////////////////////
	//複合曲線Mappingオブジェクト
	////////////////////////////////
	SXFCompCurveMappingC* m_CompCurveMapping;

	////////////////////////////////
	//INVISIBILITY_Mappingオブジェクト
	////////////////////////////////
	SXFInvisibilityMappingC* m_InvisibilityMapping;

};

#endif // !defined(AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_)
