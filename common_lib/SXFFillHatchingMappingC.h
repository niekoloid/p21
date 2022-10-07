/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2000.4.20

	１．クラス概要
	ハッチング（ユーザ定義）のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.20			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFFILLHATCHINGMAPPINGC_H__6ACDA8A4_15D4_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFFILLHATCHINGMAPPINGC_H__6ACDA8A4_15D4_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_InstC;
class SXFD_AggrC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_RealC;

class SXFFillHatchingMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_FileC);
	BOOL MappingStruct(Fill_area_style_hatching_Struct* IN_Struct);
	SXFFillHatchingMappingC();
	SXFFillHatchingMappingC(SXFTableManagerC* IN_TableManager,CUIntArray* IN_AssemblyTable);
	virtual ~SXFFillHatchingMappingC();

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
	//複合曲線のIDの配列
	//////////////////////////////////////
	CUIntArray* m_AssemblyTable;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
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
	SXFD_StrC* m_str8;
	SXFD_StrC* m_str9;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst1;
	SXFD_InstC* m_inst2;
	SXFD_InstC* m_inst3;
	SXFD_InstC* m_inst4;
	SXFD_InstC* m_inst5;
	SXFD_InstC* m_inst[28];
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	SXFD_AggrC* m_aggr6;
	SXFD_AggrC* m_aggr7;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;

};

#endif // !defined(AFX_SXFFILLHATCHINGMAPPINGC_H__6ACDA8A4_15D4_11D4_A76E_00000EB03267__INCLUDED_)
