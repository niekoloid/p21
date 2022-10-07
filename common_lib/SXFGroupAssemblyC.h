// SXFGroupAssemblyC.h: SXFGroupAssemblyC クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SXFGROUPASSEMBLYC_H__790053E5_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
#define AFX_SXFGROUPASSEMBLYC_H__790053E5_2A42_11D4_A3A9_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include <afxtempl.h>
#include "SXFStruct.h"
#include "SXFChildFeatureC.h"

typedef CArray<SXFChildFeatureC,const SXFChildFeatureC&> SXFCHILD_FEATURELIST;

class SXFGroupAssemblyC  
{
public:
	SXFGroupAssemblyC();
	SXFGroupAssemblyC& operator=(const SXFGroupAssemblyC& IN_GroupAssembly);
	virtual ~SXFGroupAssemblyC();

	Sfigorg_Struct* GroupStruct;
	SXFCHILD_FEATURELIST ChildList;
	int AssemblyCode;

};

#endif // !defined(AFX_SXFGROUPASSEMBLYC_H__790053E5_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
