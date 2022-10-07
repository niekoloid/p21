/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						作成日：2000.04.15

	１．クラス概要
	複合曲線定義のMapping

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/

#if !defined(AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_BoolC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_RealC;
class SXFPart21FileC;
class SXFTableManagerC;

class SXFCompCurveMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2,int &OUT_PointID);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Ccurve_Org_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	SXFCompCurveMappingC();
	SXFCompCurveMappingC(SXFTableManagerC* IN_TableManager,double IN_PointX,double IN_PointY);
	virtual ~SXFCompCurveMappingC();
private:
	//////////////////////////////////////
	//ハッチング内部の点
	//////////////////////////////////////
	double m_PointX ;
	double m_PointY ;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID1;
	int m_ID2;
	//////////////////////////////////////
	//CARTESIAN_POINTのインスタンスID
	//////////////////////////////////////
	int m_pointID;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[4];
	SXFD_InstC* m_elem_inst;
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_inst_point;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	//////////////////////////////////////
	//Bool型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
};

#endif // !defined(AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_)
