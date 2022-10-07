/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.h								作成日：2007.1.30

	１．クラス概要
	クロソイドのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/

#if !defined(AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_

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
class SXFD_TypeC;
class SXFD_IntC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_ListAggrC;

class SXFClothoidMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Clothoid_Struct* IN_Struct);
	SXFClothoidMappingC();
	SXFClothoidMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFClothoidMappingC();
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
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	enum { INST_NUM = 11 };
	SXFD_InstC* m_inst[INST_NUM];
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	enum { AGGR_NUM = 6 };
	SXFD_AggrC* m_aggr[AGGR_NUM];
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	enum { STR_NUM = 7 };
	SXFD_StrC* m_str[STR_NUM];
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	enum { REAL_NUM = 7 };
	SXFD_RealC* m_real[REAL_NUM];
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	enum { ENUM_NUM = 2 };
	SXFD_EnumC* m_enum[ENUM_NUM];
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	enum { TYPE_NUM = 2 };
	SXFD_TypeC* m_type[TYPE_NUM];
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	enum { BOOL_NUM = 2 };
	SXFD_BoolC* m_bool[BOOL_NUM];
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
};

#endif // !defined(AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
