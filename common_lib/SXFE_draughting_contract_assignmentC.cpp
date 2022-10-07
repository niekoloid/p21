// SXFE_draughting_contract_assignmentC.cpp: SXFE_draughting_contract_assignmentC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_draughting_contract_assignmentC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_draughting_contract_assignmentC::SXFE_draughting_contract_assignmentC(SXFD_InstC* inst,SXFD_AggrC* aggr)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "DRAUGHTING_CONTRACT_ASSIGNMENT";

	m_Data.AddTail(inst);
	m_Data.AddTail(aggr);
}

SXFE_draughting_contract_assignmentC::~SXFE_draughting_contract_assignmentC()
{

}
