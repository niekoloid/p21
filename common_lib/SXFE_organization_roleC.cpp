// SXFE_organization_roleC.cpp: SXFE_organization_roleC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_organization_roleC.h"
#include "SXFD_StrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_organization_roleC::SXFE_organization_roleC(SXFD_StrC* str)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "ORGANIZATION_ROLE";

	m_Data.AddTail(str);
}

SXFE_organization_roleC::~SXFE_organization_roleC()
{

}
