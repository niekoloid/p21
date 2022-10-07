/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatchMappingC.cpp								作成日：2000.4.17

	１．クラス概要
	ハッチング(外部定義）フィーチャのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。
	更新			2001.09.18			K.Naono				ハッチング障害対応

**/

#if !defined(AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_InstC;
class SXFD_AggrC;
class SXFD_StrC;
class SXFD_TypeC;

class SXFExHatchMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Externally_Defined_Hatch_Struct* IN_Struct);
	SXFExHatchMappingC();
	SXFExHatchMappingC(
			SXFTableManagerC*	IN_TableManager,
			CUIntArray*			IN_AssemblyTable,
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//			CUIntArray*			IN_PointTable);
			CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable) ;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
	virtual ~SXFExHatchMappingC();

private:
	//////////////////////////////////////
	//CARTESIAN_POINT(ハッチング内部の点）のインスタンスIDの配列
	//////////////////////////////////////
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//	CUIntArray* m_PointTable;
	CArray<SXF_POINT,SXF_POINT&>*	m_PointTable;
	SXFD_InstC*						m_inst_point;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
	//////////////////////////////////////
	//複合曲線のIDの配列
	//////////////////////////////////////
	CUIntArray* m_AssemblyTable;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
	SXFD_TypeC* m_type6;
	SXFD_TypeC* m_type7;
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
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst1;
	SXFD_InstC* m_inst2;
	SXFD_InstC* m_inst3;
	SXFD_InstC* m_inst[5];
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
};

#endif // !defined(AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_)
