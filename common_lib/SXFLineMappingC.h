/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.h					作成日：2000.04.15

	１．クラス概要
	線分フィーチャのMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/

#if !defined(AFX_SXFLINEMAPPINGC_H__4EA58E80_120B_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLINEMAPPINGC_H__4EA58E80_120B_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;
class SXFPart21FileC;
class SXFTableManagerC;

class SXFLineMappingC  
{
public:
	int GetAssignID();
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Line_Struct IN_Struct);
	SXFLineMappingC();
	SXFLineMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag);
	virtual ~SXFLineMappingC();

private:
	//////////////////////////////////////
	//寸法線フラグ
	//寸法線の寸法値：１、文字要素：０
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENTのインスタンスID
	//////////////////////////////////////
	int m_assign_ID;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[9];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_ins4;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	SXFD_AggrC* m_aggr6;
	SXFD_AggrC* m_aggr7;
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
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//列挙型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
};

#endif // !defined(AFX_SXFLINEMAPPINGC_H__4EA58E80_120B_11D4_A76E_00000EB03267__INCLUDED_)
