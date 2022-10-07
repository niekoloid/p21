// SXFE_organizationC.cpp: SXFE_organizationC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_organizationC.h"
#include "SXFD_StrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_organizationC::SXFE_organizationC(SXFD_StrC* str1, SXFD_StrC* str2, SXFD_StrC* str3)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "ORGANIZATION";

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
	m_Data.AddTail(str3);
}

SXFE_organizationC::SXFE_organizationC(SXFD_StrC* str1, SXFD_StrC* str2)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "ORGANIZATION";

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
}

SXFE_organizationC::~SXFE_organizationC()
{

}
