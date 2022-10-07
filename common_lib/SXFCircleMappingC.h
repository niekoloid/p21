/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.h					作成日：2000.04.15

	１．クラス概要
	円フィーチャのMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/

#if !defined(AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;

class SXFCircleMappingC  
{
public:
	void SetAssignID(int IN_AssignID);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Circle_Struct IN_Struct);
	SXFCircleMappingC();
	SXFCircleMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag);
	virtual ~SXFCircleMappingC();

private:
	//////////////////////////////////////
	//ラベルフラグ
	//ラベルの文字要素：１、文字要素：０
	//////////////////////////////////////
	int m_LabelFlag;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENTのインスタンスID
	//////////////////////////////////////
	int m_AssignID;
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//定義テーブル管理オブジェクトのアドレス
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//CStringListオブジェクトのアドレス
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	//////////////////////////////////////
	//集合体型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	//////////////////////////////////////
	//文字列型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
};

#endif // !defined(AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_)
