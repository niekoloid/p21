/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.h								作成日：2000.4.14

	１．クラス概要
	レイヤのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFLayerC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_AggrC;

class SXFLayerMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(SXFLayerC* IN_Layer);
	SXFLayerMappingC();
	virtual ~SXFLayerMappingC();
	int GetID();

private:
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_elem1;
	SXFD_InstC* m_sheet;
	SXFD_InstC* m_inst[2];
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str1;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
};

#endif // !defined(AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_)
