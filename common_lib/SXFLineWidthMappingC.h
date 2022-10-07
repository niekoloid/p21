/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.h					作成日：2000.04.14

	１．クラス概要
	線幅フィーチャのMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/

#if !defined(AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_TypeC;
class SXFPart21FileC;

class SXFLineWidthMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Line_Width_Struct* IN_Struct);
	SXFLineWidthMappingC();
	virtual ~SXFLineWidthMappingC();
	int GetID();

private:
	//////////////////////////////////////
	//インスタンスID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//インスタンスオブジェクトのアドレス
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	SXFD_InstC* m_unit_inst;
	//////////////////////////////////////
	//実数型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_RealC* m_real;
	//////////////////////////////////////
	//TYPE型オブジェクトのアドレス
	//////////////////////////////////////
	SXFD_TypeC* m_type;
};

#endif // !defined(AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_)
