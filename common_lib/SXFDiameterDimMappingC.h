/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.h								ì¬“úF2000.4.18

	‚PDƒNƒ‰ƒXŠT—v

	‚QD—š—ð
	—š—ð”Ô†		“ú•t‚¯				’S“–ŽÒ				ŠT—v
	ì¬			2000.4.18			‹{‰€(FQS)			‚È‚µB

**/

#if !defined(AFX_SXFDIAMETERDIMMAPPINGC_H__1F88C681_149F_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFDIAMETERDIMMAPPINGC_H__1F88C681_149F_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFLineMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_BoolC;

class SXFDiameterDimMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(DiameterDim_Struct IN_Struct,int IN_AssemType);
	SXFDiameterDimMappingC();
	SXFDiameterDimMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFDiameterDimMappingC();
private:
	int m_DimFlag;
	SXFD_InstC* m_term2_inst;
	SXFD_InstC* m_term1_inst;
	SXFD_InstC* m_text_inst;
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	SXFD_BoolC* m_bool1;
	SXFD_TypeC* m_type1;
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	SXFTextStringMappingC* m_TextStringMapping;
	BOOL CalcArrowDir(DiameterDim_Struct IN_Struct,double &OUT_Arrow1_x,double &OUT_Arrow1_y,double &OUT_Arrow2_x,double &OUT_Arrow2_y);
	SXFTermSymbolMappingC* m_TermSymbolMapping1;
	SXFTermSymbolMappingC* m_TermSymbolMapping2;
	SXFLineMappingC* m_LineMapping;
	SXFTableManagerC* m_TableManager;
	int m_ID1;
	int m_ID2;
};

#endif // !defined(AFX_SXFDIAMETERDIMMAPPINGC_H__1F88C681_149F_11D4_A76E_00000EB03267__INCLUDED_)
