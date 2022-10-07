// SXFE_approval_date_timeC.cpp: SXFE_approval_date_timeC �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_approval_date_timeC.h"
#include "SXFD_InstC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

SXFE_approval_date_timeC::SXFE_approval_date_timeC(SXFD_InstC *inst1,SXFD_InstC *inst2)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "APPROVAL_DATE_TIME";

	m_Data.AddTail(inst1);
	m_Data.AddTail(inst2);
}

SXFE_approval_date_timeC::~SXFE_approval_date_timeC()
{

}
