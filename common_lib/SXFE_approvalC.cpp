// SXFE_approvalC.cpp: SXFE_approvalC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_approvalC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_approvalC::SXFE_approvalC(SXFD_InstC* inst,SXFD_StrC* str)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "APPROVAL";

	m_Data.AddTail(inst);
	m_Data.AddTail(str);
}

SXFE_approvalC::~SXFE_approvalC()
{

}
