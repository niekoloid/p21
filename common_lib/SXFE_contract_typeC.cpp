// SXFE_contract_typeC.cpp: SXFE_contract_typeC �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_contract_typeC.h"
#include "SXFD_StrC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

SXFE_contract_typeC::SXFE_contract_typeC(SXFD_StrC* str)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "CONTRACT_TYPE";

	m_Data.AddTail(str);
}

SXFE_contract_typeC::~SXFE_contract_typeC()
{

}
