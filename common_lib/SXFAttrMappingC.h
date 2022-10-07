/**
	All Rights Reserved,(c) JACIC 2001
	SXFAttrMappingC.h								ì¬“úF2000.4.16

	‚PDƒNƒ‰ƒXŠT—v
	}–Ê•\‘è—“‚ÌMapping

	‚QD—š—ð
	—š—ð”Ô†		“ú•t‚¯				’S“–ŽÒ				ŠT—v

**/
#if !defined(AFX_SXFATTRMAPPINGC_H__96C7B7D8_BCC2_41FA_ACE6_4F36893A4624__INCLUDED_)
#define AFX_SXFATTRMAPPINGC_H__96C7B7D8_BCC2_41FA_ACE6_4F36893A4624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFStruct.h"
class SXFD_InstC ;
class SXFD_StrC ;
class SXFD_IntC ;
class SXFD_AggrC ;
class SXFPart21FileC;
class SXFSheetMappingC;

class SXFAttrMappingC  
{
public:
	SXFAttrMappingC();
	SXFAttrMappingC(SXFSheetMappingC* IN_Sheet);
	virtual ~SXFAttrMappingC();

	int		GetID();
	BOOL	MappingStruct(Attribute_Struct* IN_Struct);
	BOOL	WriteAP202(SXFPart21FileC* IN_File);

private:
	void	initMember() ;

	int					m_ID ;
	SXFSheetMappingC*	m_SheetMap ;
	SXFD_InstC*			m_inst[14] ;
	SXFD_StrC*			m_str[13] ;
	SXFD_AggrC*			m_aggr[4] ;
	SXFD_IntC*			m_int[3] ;
};

#endif // !defined(AFX_SXFATTRMAPPINGC_H__96C7B7D8_BCC2_41FA_ACE6_4F36893A4624__INCLUDED_)
