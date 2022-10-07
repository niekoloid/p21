/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.h							作成日：2000.4.14

	１．クラス概要
	ユーザ定義線種のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFD_StrC.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_ListAggrC;
class SXFPart21FileC;

class SXFUserTypeMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Userdefined_Linetype_Struct* IN_Struct);
	SXFUserTypeMappingC();
	virtual ~SXFUserTypeMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[5];
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr;
	SXFD_ListAggrC* m_list_aggr;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real1;
};

#endif // !defined(AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_)
