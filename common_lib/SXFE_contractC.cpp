// SXFE_contractC.cpp: SXFE_contractC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_contractC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_contractC::SXFE_contractC(SXFD_StrC* str1,SXFD_StrC* str2,SXFD_InstC* inst)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "CONTRACT";

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
	m_Data.AddTail(inst);
}

SXFE_contractC::~SXFE_contractC()
{

}
