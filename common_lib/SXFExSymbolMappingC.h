/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.h								作成日：2000.4.19

	１．クラス概要
	既定義シンボルのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.19			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_

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

class SXFExSymbolMappingC  
{
public:
	int GetCartesianID();
	void SetSymbolScale(double IN_Scale);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Externally_Defined_Symbol_Struct IN_Struct);
	SXFExSymbolMappingC();
	SXFExSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_HatchFlag);
	virtual ~SXFExSymbolMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//CARTESIAN_POINTのインスタンスID
	//////////////////////////////////////
	int m_CartesianID;
	//////////////////////////////////////
	//スケール
	//////////////////////////////////////
	double m_Scale;
	//////////////////////////////////////
	//ハッチングフラグ
	//１：ハッチングの既定義シンボル　０：既定義シンボル
	//////////////////////////////////////
	int m_HatchFlag;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
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
	SXFD_StrC* m_str10;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_inst[11];
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
};

#endif // !defined(AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_)
