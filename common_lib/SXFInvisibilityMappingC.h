/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.h								ì¬“úF2000.4.16

	‚PDƒNƒ‰ƒXŠT—v

	‚QD—š—ð
	—š—ð”Ô†		“ú•t‚¯				’S“–ŽÒ				ŠT—v
	ì¬			2000.4.16			‹{‰€(FQS)			‚È‚µB

**/

#if !defined(AFX_SXFINVISIBILITYMAPPINGC_H__F88E18A4_12F0_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFINVISIBILITYMAPPINGC_H__F88E18A4_12F0_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>

class SXFPart21FileC;
class SXFD_InstC;
class SXFD_AggrC;

class SXFInvisibilityMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(CUIntArray* IN_Invisibility);
	SXFInvisibilityMappingC();
	virtual ~SXFInvisibilityMappingC();

private:
	SXFD_AggrC* m_aggr;
	SXFD_InstC* m_inst2;
	SXFD_InstC* m_inst1;
};

#endif // !defined(AFX_SXFINVISIBILITYMAPPINGC_H__F88E18A4_12F0_11D4_A76E_00000EB03267__INCLUDED_)
