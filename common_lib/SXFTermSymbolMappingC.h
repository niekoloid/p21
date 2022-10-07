/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.h								作成日：2000.4.17

	１．クラス概要
	矢印のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_EnumC;

class SXFTermSymbolMappingC  
{
public:
	int GetID();
	void SetTermID(int assignID);
	void GetTermID(int &OUT_assignID);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStructDim(TermSymbol_Struct IN_Struct);
	SXFTermSymbolMappingC();
	SXFTermSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_Flag,int IN_DimFlag);
	virtual ~SXFTermSymbolMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENTのインスタンスID
	//////////////////////////////////////
	int m_assignID;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//フラグ
	//１：	０：
	//////////////////////////////////////
	int m_Flag;
	//////////////////////////////////////
	//寸法線フラグ
	//寸法線の寸法値：１、文字要素：０
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[10];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
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
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
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

#endif // !defined(AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_)
