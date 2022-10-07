/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.h								作成日：2000.4.14

	１．クラス概要
	用紙のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_

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
class SXFTableManagerC;

class SXFSheetMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC *IN_File);
//	BOOL MappingStruct(Sheet_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	BOOL MappingStruct(
						Sheet_Struct		IN_Struct,
						CUIntArray*			IN_ChildrenID,
						Attribute_Struct*	IN_AttrStr) ;
	SXFSheetMappingC();
	SXFSheetMappingC(SXFTableManagerC* IN_TableManagerC);
	virtual ~SXFSheetMappingC();
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	//	DRAUGHTING_DRAWING_REVISIONのインスタンスIDを返却する
	int	GetDwgRevID() ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

private:
	BOOL MappingStruct(Sheet_Struct IN_Struct,CUIntArray* IN_ChildrenID);
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
	SXFD_InstC* m_inst[11];
	SXFD_InstC* m_elem_inst;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
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
	SXFD_StrC* m_str10;
	SXFD_StrC* m_str11;
	SXFD_StrC* m_str12;
	SXFD_StrC* m_str13;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	//	DRAUGHTING_DRAWING_REVISIONのインスタンスID
	int	m_nDwgRevID ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
};

#endif // !defined(AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_)
