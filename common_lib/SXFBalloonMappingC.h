/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloonMappingC.h								作成日：2000.4.18

	１．クラス概要
	バルーンのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFBALLOONMAPPINGC_H__FA74CCE2_1507_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFBALLOONMAPPINGC_H__FA74CCE2_1507_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_BoolC;
class SXFD_TypeC;
class SXFPolylineMappingC;
class SXFCircleMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;

class SXFBalloonMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Balloon_Struct* IN_Struct,int IN_AssemType);
	SXFBalloonMappingC();
	SXFBalloonMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFBalloonMappingC();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_term_inst;
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_circle_inst;
	SXFD_InstC* m_ins_text;
	SXFD_InstC* m_inst[3];
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
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//折線Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFPolylineMappingC* m_PolylineMapping;
	//////////////////////////////////////
	//円Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFCircleMappingC* m_CircleMapping;
	//////////////////////////////////////
	//文字要素フィーチャMappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//矢印Mappingオブジェクトのアドレス
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping;
};

#endif // !defined(AFX_SXFBALLOONMAPPINGC_H__FA74CCE2_1507_11D4_A76E_00000EB03267__INCLUDED_)
