/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.h								作成日：2000.4.14

	１．クラス概要
	既定義色のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_StrC;
class SXFD_RealC;
class SXFPart21FileC;
class SXFPreDefColorC;

class SXFPreColourMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(SXFPreDefColorC IN_Struct);
	SXFPreColourMappingC();
	virtual ~SXFPreColourMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str;
};

#endif // !defined(AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_)
