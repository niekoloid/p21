//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.h				   ì¬“úF2001.06.20
//
//	‚PDƒNƒ‰ƒXŠT—v
//		Feature Assembly‚ÌeŽqŠÖŒW‚ðŠÇ—‚·‚é
//		
//	‚QD—š—ð
//		—š—ð”Ô†	“ú•t‚¯		   ’S“–ŽÒ	 ŠT—v
//		ì¬		2001.06.20	   ²X–Ø		 ‚È‚µ
//
//------------------------------------------------------------

#if !defined(AFX_SXFFEATUREASSEMBLYC_H__7A7CDA82_1A22_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFFEATUREASSEMBLYC_H__7A7CDA82_1A22_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

#include "SXFFeatureChildC.h"

typedef CTypedPtrList<CPtrList,SXFFeatureChildC*> SXFCHILDLIST;

class SXFFeatureAssemblyC  
{
public:
	int AssemCurveFlag;
	int AssemSheetX;
	int AssemSheetY;
	int AssemSheetOrient;
	int AssemSheetType;
	int AssemSymbolType;
	SXFFeatureAssemblyC();
	virtual ~SXFFeatureAssemblyC();
	int AssemblyID;
	int AssemblyCode;
	CString AssemblyName;

	SXFCHILDLIST* ChildList;
	int m_CurveColour;
	int m_CurveType;
	int m_CurveWidth;

	int m_SfigLocateFlag;
};

#endif // !defined(AFX_SXFFEATUREASSEMBLYC_H__7A7CDA82_1A22_11D4_A76E_00000EB03267__INCLUDED_)
