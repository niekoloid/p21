/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.h								作成日：2000.4.20

	１．クラス概要
	引き出し線のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.20			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFPolylineMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_BoolC;

class SXFLabelMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC *IN_File);
	BOOL MappingStruct(Label_Struct *IN_Struct,int IN_AssemType);
	SXFLabelMappingC();
	SXFLabelMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFLabelMappingC();

private:
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
	SXFD_InstC* m_inst[3];
	SXFD_InstC* m_term_inst;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//折線フィーチャMappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFPolylineMappingC* m_PolylineMapping;
	//////////////////////////////////////
	//文字要素フィーチャMappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//矢印Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
};

#endif // !defined(AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_)
