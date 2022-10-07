/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.h								作成日：2000.4.14

	１．クラス概要
	複合図形定義のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#if !defined(AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;

class SXFSfigMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	int GetID();
	BOOL MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	SXFSfigMappingC();
	virtual ~SXFSfigMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[5];
	SXFD_InstC* m_elem_inst;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
};

#endif // !defined(AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_)
