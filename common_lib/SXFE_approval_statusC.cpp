// SXFE_approval_statusC.cpp: SXFE_approval_statusC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_approval_statusC.h"
#include "SXFD_StrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_approval_statusC::SXFE_approval_statusC(SXFD_StrC* str)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "APPROVAL_STATUS";

	m_Data.AddTail(str);
}

SXFE_approval_statusC::~SXFE_approval_statusC()
{

}
