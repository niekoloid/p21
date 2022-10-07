// SXFE_calendar_dateC.cpp: SXFE_calendar_dateC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFE_calendar_dateC.h"
#include "SXFD_IntC.h"
#include "SXF_EXT.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFE_calendar_dateC::SXFE_calendar_dateC(SXFD_IntC *yy,SXFD_IntC *dd,SXFD_IntC *mm)
{
	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = "CALENDAR_DATE";

	m_Data.AddTail(yy);
	m_Data.AddTail(dd);
	m_Data.AddTail(mm);
}

SXFE_calendar_dateC::~SXFE_calendar_dateC()
{

}
