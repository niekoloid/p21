// SXFGroupAssemblyC.cpp: SXFGroupAssemblyC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFGroupAssemblyC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFGroupAssemblyC::SXFGroupAssemblyC()
{
	GroupStruct = NULL;
	AssemblyCode = -1;
}

SXFGroupAssemblyC::~SXFGroupAssemblyC()
{

}

SXFGroupAssemblyC& SXFGroupAssemblyC::operator=(const SXFGroupAssemblyC& IN_GroupAssembly){
	GroupStruct = IN_GroupAssembly.GroupStruct;
	for(int i = 0; i < IN_GroupAssembly.ChildList.GetSize(); i++)
		ChildList.Add(IN_GroupAssembly.ChildList.GetAt(i));
	AssemblyCode = IN_GroupAssembly.AssemblyCode;
	return *this;
}
