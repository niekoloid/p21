/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.h								作成日：2000.4.14

	１．クラス概要
	文字フィーチャのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;
class SXFD_TypeC;
class SXFTableManagerC;
class SXFPart21FileC;

class SXFTextStringMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Text_Struct IN_Struct);
	SXFTextStringMappingC();
	SXFTextStringMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag);
	virtual ~SXFTextStringMappingC();

private:
	//////////////////////////////////////
	//寸法線フラグ
	//寸法線の寸法値：１、文字要素：０
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//CStringListのオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[9];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
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
	SXFD_RealC* m_real9;
	SXFD_RealC* m_real10;
	SXFD_RealC* m_real11;
	SXFD_RealC* m_real12;
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
	SXFD_TypeC* m_type6;

};

#endif // !defined(AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_)
