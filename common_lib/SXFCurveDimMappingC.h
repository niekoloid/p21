/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDimMappingC.h								作成日：2007.1.29

	１．クラス概要
	弧長寸法のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/

#if !defined(AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFArcMappingC;
class SXFProjMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_BoolC;

class SXFCurveDimMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	int MappingStruct(CurveDim_Struct IN_Struct,int IN_AssemType);
	SXFCurveDimMappingC();
	SXFCurveDimMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFCurveDimMappingC();
private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID1;
	int m_ID2;
	//////////////////////////////////////
	//寸法線フラグ
	//寸法線の寸法値：１、文字要素：０
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_term2_inst;
	SXFD_InstC* m_term1_inst;
	SXFD_InstC* m_text_inst;
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins_proj1;
	SXFD_InstC* m_ins_proj2;
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	//////////////////////////////////////
	//文字要素フィーチャMappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//矢印Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping1;
	SXFTermSymbolMappingC* m_TermSymbolMapping2;
	//////////////////////////////////////
	//補助線Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFProjMappingC* m_ProjMapping1;
	SXFProjMappingC* m_ProjMapping2;
	//////////////////////////////////////
	//円弧フィーチャMappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFArcMappingC* m_ArcMapping;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//矢印DIRECTION計算用メソッド
	//////////////////////////////////////
	int CalcArrowDir(CurveDim_Struct IN_Struct,double& OUT_Arrow1_x,double& OUT_Arrow1_y,double& OUT_Arrow2_x,double& OUT_Arrow2_y);
	void CalcAngle(double IN_x1,double IN_y1,double IN_x2,double IN_y2,double& OUT_angle);
	void CalcAngleSub(double IN_angle1,double IN_angle2,double& OUT_angle);
	void CalcAngleSub2(double IN_angle1,double IN_angle2,double& OUT_angle);

/*	==>	Added by S.Kakizawa(KLS) on 2006/03/14	*/
	BOOL	AngleIsInside( const double& dbAngleStart, const double& dbAngleEnd, const double& dbAngleCheck, const double& dbEps ) const;
/*	<==	Added by S.Kakizawa(KLS) on 2006/03/14	*/
};

#endif // !defined(AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_)
