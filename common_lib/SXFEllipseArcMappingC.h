/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseArcMappingC.h								作成日：2001.06.15

	１．クラス概要
	楕円弧フィーチャのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.15			佐々木(FQS)			なし。

**/

#if !defined(AFX_SXFELLIPSEARCMAPPINGC_H__E62A78C4_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFELLIPSEARCMAPPINGC_H__E62A78C4_130E_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_EnumC;
class SXFD_BoolC;
class SXFD_TypeC;

class SXFEllipseArcMappingC  
{
public:
	BOOL WriteAP202Curve(SXFPart21FileC* IN_File);
	BOOL MappingStructCurve(Ellipse_Arc_Struct IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Ellipse_Arc_Struct IN_Struct);
	SXFEllipseArcMappingC(SXFTableManagerC* IN_TableManager);
	SXFEllipseArcMappingC();
	virtual ~SXFEllipseArcMappingC();

private:
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[8];
	SXFD_InstC* m_inst_curve[6];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	SXFD_AggrC* m_aggr6;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	SXFD_StrC* m_str7;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	SXFD_RealC* m_real7;
	SXFD_RealC* m_real8;
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	SXFD_BoolC* m_bool2;
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	SXFD_EnumC* m_enum2;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
};

#endif // !defined(AFX_SXFELLIPSEARCMAPPINGC_H__E62A78C4_130E_11D4_A76E_00000EB03267__INCLUDED_)
