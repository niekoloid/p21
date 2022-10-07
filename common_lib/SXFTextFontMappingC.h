/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.h								作成日：2000.4.14

	１．クラス概要
	文字フォントのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_TypeC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFTextFontMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Text_Font_Struct* IN_Struct);
	SXFTextFontMappingC();
	virtual ~SXFTextFontMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str1;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[2];
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type1;
};

#endif // !defined(AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_)
