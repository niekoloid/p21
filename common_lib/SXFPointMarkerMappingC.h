/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								ì¬“úF2000.3.27

	‚PDƒNƒ‰ƒXŠT—v
	“_ƒ}[ƒJ‚ÌMapping

	‚QD—š—ð
	—š—ð”Ô†		“ú•t‚¯				’S“–ŽÒ				ŠT—v
	ì¬			2000.3.27			‹{‰€(FQS)			‚È‚µB

**/

#if !defined(AFX_SXFPOINTMARKERMAPPINGC_H__E62A78C7_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPOINTMARKERMAPPINGC_H__E62A78C7_130E_11D4_A76E_00000EB03267__INCLUDED_

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

class SXFPointMarkerMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	int GetID();
	BOOL MappingStruct(Point_Marker_Struct IN_Struct);
	SXFPointMarkerMappingC();
	SXFPointMarkerMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFPointMarkerMappingC();

private:
	SXFTableManagerC* m_TableManager;
	int m_ID;
	CStringList* m_slist;
	SXFD_InstC* m_inst[10];
	SXFD_InstC* m_ins1;
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	SXFD_StrC* m_str7;
	SXFD_StrC* m_str8;
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
};

#endif // !defined(AFX_SXFPOINTMARKERMAPPINGC_H__E62A78C7_130E_11D4_A76E_00000EB03267__INCLUDED_)
