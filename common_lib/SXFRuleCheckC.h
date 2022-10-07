/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.h								作成日：2001.06.19

	１．クラス概要
	フィーチャのルールチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/

#if !defined(AFX_SXFRULECHECKC_H__266DAF61_1152_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFRULECHECKC_H__266DAF61_1152_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFFillColour_checkC.h"	// ClassView によって追加されました。
#include "SXFPolyline_checkC.h"	// ClassView によって追加されました。
#include "SXFTextFont_checkC.h"	// ClassView によって追加されました。
#include "SXFLine_checkC.h"	// ClassView によって追加されました。
#include "SXFSheet_checkC.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFUserdefined_color_checkC.h"
#include "SXFLayer_checkC.h"
#include "SXFUsertype_checkC.h"	// ClassView によって追加されました。
#include "SXFWidth_checkC.h"	// ClassView によって追加されました。
#include "SXFSfigorg_checkC.h"	// ClassView によって追加されました。
#include "SXFCcurveorg_checkC.h"	// ClassView によって追加されました。
#include "SXFText_String_checkC.h"	// ClassView によって追加されました。
#include "SXFPreColour_checkC.h"	// ClassView によって追加されました。
#include "SXFPreType_checkC.h"	// ClassView によって追加されました。
#include "SXFArc_checkC.h"	// ClassView によって追加されました。
#include "SXFEllipse_checkC.h"	// ClassView によって追加されました。
#include "SXFEllipse_Arc_checkC.h"	// ClassView によって追加されました。
#include "SXFCircle_checkC.h"	// ClassView によって追加されました。
#include "SXFLinearDim_checkC.h"
#include "SXFPoint_Marker_checkC.h"	// ClassView によって追加されました。
#include "SXFSpline_checkC.h"	// ClassView によって追加されました。
#include "SXFClothoid_checkC.h"	// ClassView によって追加されました。
#include "SXFCurveDim_checkC.h"	// ClassView によって追加されました。
#include "SXFAngularDim_checkC.h"	// ClassView によって追加されました。
#include "SXFDiameterDim_checkC.h"	// ClassView によって追加されました。
#include "SXFRadiusDim_checkC.h"	// ClassView によって追加されました。
#include "SXFLabel_checkC.h"	// ClassView によって追加されました。
#include "SXFBalloon_checkC.h"	// ClassView によって追加されました。
#include "SXFExSymbol_checkC.h"	// ClassView によって追加されました。
#include "SXFSfigloc_checkC.h"	// ClassView によって追加されました。
#include "SXFExhatch_checkC.h"	// ClassView によって追加されました。
#include "SXFFillHatching_checkC.h"	// ClassView によって追加されました。
#include "SXFFillTiles_checkC.h"	// ClassView によって追加されました。
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
#include "SXFAttribute_checkC.h"	// ClassView によって追加されました。
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

class SXFTableManagerC;
class SXFWriteManagerC;
class SXFComInfoC;
class SXFReadAP202ManagerC;

class SXFRuleCheckC  
{
public:
	CString m_InstanceID;
	SXFReadAP202ManagerC* m_ReadAP202Manager;
	SXFWriteManagerC* m_WriteManager;
	SXFTableManagerC* m_TableManager;
	SXFComInfoC* m_ComInfo;

	int FeatureRuleCheck(int IN_AssemType,char* IN_Type,LPVOID IN_Struct);
	int AssemblyRuleCheck(int IN_Type,LPVOID IN_Struct);
	int TableRuleCheck(int IN_Type,LPVOID IN_Struct);
	SXFRuleCheckC();
	virtual ~SXFRuleCheckC();

private:
	int m_SfigFlag;
	SXFFillTiles_checkC m_FillTiles_check;
	SXFFillHatching_checkC m_FillHatching_check;
	SXFFillColour_checkC m_FillColour_check;
	SXFExhatch_checkC m_Exhatch_check;
	SXFSfigloc_checkC m_Sfigloc_check;
	SXFExSymbol_checkC m_ExSymbol_check;
	SXFBalloon_checkC m_Balloon_check;
	SXFLabel_checkC m_Label_check;
	SXFRadiusDim_checkC m_RadiusDim_check;
	SXFDiameterDim_checkC m_DiameterDim_check;
	SXFCurveDim_checkC m_CurveDim_check;
	SXFAngularDim_checkC m_AngularDim_check;
	SXFSpline_checkC m_Spline_check;
	SXFClothoid_checkC m_Clothoid_check;
	SXFPolyline_checkC m_Polyline_check;
	SXFPoint_Marker_checkC m_Point_Marker_check;
	SXFLinearDim_checkC m_LinearDim_check;
	SXFCircle_checkC m_Circle_check;
	SXFEllipse_Arc_checkC m_Ellipse_Arc_check;
	SXFEllipse_checkC m_Ellipse_check;
	SXFArc_checkC m_Arc_check;
	SXFTextFont_checkC m_TextFont_check;
	SXFPreType_checkC m_PreType_check;
	SXFPreColour_checkC m_PreColour_check;
	SXFText_String_checkC m_Text_String_check;
	SXFLine_checkC m_Line_check;
	SXFCcurveorg_checkC m_Ccurveorg_check;
	SXFSfigorg_checkC m_Sfigorg_check;
	SXFSheet_checkC m_Sheet_check;
	SXFWidth_checkC m_Width_check;
	SXFUsertype_checkC m_Usertype_check;
	SXFUserdefined_color_checkC m_Usercolor_check;
	SXFLayer_checkC m_Layer_check;
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	SXFAttribute_checkC		m_Attribute_check;		/* 図面表題欄ﾙｰﾙﾁｪｯｸｵﾌﾞｼﾞｪｸﾄ */
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
};

#endif // !defined(AFX_SXFRULECHECKC_H__266DAF61_1152_11D4_A76E_00000EB03267__INCLUDED_)
