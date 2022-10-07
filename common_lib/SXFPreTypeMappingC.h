/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.h								作成日：2000.4.14

	１．クラス概要
	既定義線種のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFPreTypeMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Predefined_Linetype_Struct* IN_Struct);
	SXFPreTypeMappingC();
	virtual ~SXFPreTypeMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
};

#endif // !defined(AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_)
