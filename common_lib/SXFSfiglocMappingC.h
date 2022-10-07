/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.h								作成日：2000.4.19

	１．クラス概要

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.19			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFSFIGLOCMAPPINGC_H__849FC6C0_1569_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGLOCMAPPINGC_H__849FC6C0_1569_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFWriteManagerC.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFLineMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_BoolC;
class SXFD_TypeC;
class SXFD_RealC;

class SXFSfiglocMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Sfigloc_Struct IN_Struct);
	SXFSfiglocMappingC();
//	MOD(S)	チューニング対応	K.Naono	03.07.08
//	SXFSfiglocMappingC(SXFTableManagerC* IN_TableManager,SXFSFIGORGTABLE* IN_SfigorgTable);
	SXFSfiglocMappingC(
				SXFTableManagerC*	IN_TableManager,
				CMapStringToPtr*	IN_SfigorgTable);
//	MOD(E)	チューニング対応	K.Naono	03.07.08
	virtual ~SXFSfiglocMappingC();

private:
//	MOD(S)	チューニング対応	K.Naono	03.07.08
//	SXFSFIGORGTABLE *m_SfigorgTable;
	CMapStringToPtr*	m_SfigorgTable ;
//	MOD(E)	チューニング対応	K.Naono	03.07.08

	SXFD_InstC* m_org_inst;
	SXFD_BoolC* m_bool1;
	SXFD_TypeC* m_type1;
	SXFD_InstC* m_inst[7];
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	CStringList *m_slist;
	int m_ID;
	SXFTableManagerC* m_TableManager;
};

#endif // !defined(AFX_SXFSFIGLOCMAPPINGC_H__849FC6C0_1569_11D4_A76E_00000EB03267__INCLUDED_)
