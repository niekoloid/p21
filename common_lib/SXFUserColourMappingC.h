/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.h								作成日：2000.4.14

	１．クラス概要
	ユーザ定義色のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFUserColourMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Userdefined_Colour_Struct* IN_Struct);
	SXFUserColourMappingC();
	virtual ~SXFUserColourMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real1;
};

#endif // !defined(AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_)
