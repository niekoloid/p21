/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.h								作成日：2000.4.17

	１．クラス概要
	折線のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFPOLYLINEMAPPINGC_H__E62A78C5_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPOLYLINEMAPPINGC_H__E62A78C5_130E_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_RealC;
class SXFD_BoolC;
class SXFD_EnumC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_ListAggrC;

class SXFPolylineMappingC  
{
public:
	int GetAssignID();
	BOOL MappingStructCurve(Polyline_Struct* IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Polyline_Struct* IN_Struct);
	SXFPolylineMappingC();
	SXFPolylineMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag);
	virtual ~SXFPolylineMappingC();

private:
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENTのインスタンスID
	//////////////////////////////////////
	int m_AssignID;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//ラベルフラグ
	//ラベルの文字要素：１、文字要素：０
	//////////////////////////////////////
	int m_LabelFlag;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList *m_slist;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_ListAggrC* m_list_aggr;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_elem1;
	SXFD_InstC* m_elem2;
	SXFD_InstC* m_elem3;
	SXFD_InstC* m_elem4;
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_ins4;
	SXFD_InstC* m_write_inst;
	//////////////////////////////////////
	//CObListオブジェクトのアドレス
	//////////////////////////////////////
	CObList m_list_elems;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;

};

#endif // !defined(AFX_SXFPOLYLINEMAPPINGC_H__E62A78C5_130E_11D4_A76E_00000EB03267__INCLUDED_)
