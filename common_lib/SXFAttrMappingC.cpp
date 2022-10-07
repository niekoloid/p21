// SXFAttrMappingC.cpp: SXFAttrMappingC ÉNÉâÉXÇÃÉCÉìÉvÉäÉÅÉìÉeÅ[ÉVÉáÉì
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFAttrMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFSheetMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_IntC.h"
#include "SXFE_contract_typeC.h"
#include "SXFE_contractC.h"
#include "SXFE_draughting_contract_assignmentC.h"
#include "SXFE_calendar_dateC.h"
#include "SXFE_approval_statusC.h"
#include "SXFE_approvalC.h"
#include "SXFE_approval_date_timeC.h"
#include "SXFE_draughting_approval_assignmentC.h"
#include "SXFE_organizationC.h"
#include "SXFE_organization_roleC.h"
#include "SXFE_draughting_organization_assignmentC.h"

//////////////////////////////////////////////////////////////////////
// ç\íz/è¡ñ≈
//////////////////////////////////////////////////////////////////////

SXFAttrMappingC::SXFAttrMappingC()
{
	m_ID = -1 ;
	m_SheetMap = NULL ;

	initMember() ;
}

SXFAttrMappingC::SXFAttrMappingC(
					SXFSheetMappingC*	IN_Sheet)
{
	m_ID = -1 ;
	m_SheetMap = IN_Sheet ;

	initMember() ;
}

SXFAttrMappingC::~SXFAttrMappingC()
{
	m_SheetMap = NULL ;

	if( m_inst[2] != NULL ) {
		SXFInstanceC::AddDeleted(m_inst[2]);
		delete m_inst[2] ;
	}

	if( m_inst[6] != NULL ) {
		delete m_inst[6] ;
	}

	if( m_inst[7] != NULL ) {
		delete m_inst[7] ;
	}

	if( m_inst[10] != NULL ) {
		delete m_inst[10] ;
	}

	if( m_inst[13] != NULL ) {
		delete m_inst[13] ;
	}
	SXFInstanceC::EndDeleteMap();
}

void SXFAttrMappingC::initMember()
{
	for(int i = 0; i < 14; i++) {
		m_inst[i] = NULL ;
	}
	for(i = 0; i < 13; i++) {
		m_str[i] = NULL ;
	}
	for(i = 0; i < 4; i++) {
		m_aggr[i] = NULL ;
	}
	for(i = 0; i < 3; i++) {
		m_int[i] = NULL ;
	}
}

BOOL SXFAttrMappingC::MappingStruct(
					Attribute_Struct*	IN_Struct)
{
	//	å_ñÒãÊï™
	m_str[0] = new SXFD_StrC(IN_Struct->c_type) ;
	//	CONTRACT_TYPE
	m_inst[0] = new SXFE_contract_typeC(m_str[0]) ;

	//	CONTRACT
	//	çHéññº
	m_str[1] = new SXFD_StrC(IN_Struct->c_name) ;
	//	éñã∆ñº
	m_str[2] = new SXFD_StrC(IN_Struct->p_name) ;
	m_inst[1] = new SXFE_contractC(m_str[1], m_str[2], m_inst[0]) ;

	//	DRAUGHTING_CONTRACT_ASSIGNMENT
	m_aggr[0] = new SXFD_AggrC() ;
	if( m_SheetMap != NULL ) {
		m_aggr[0]->AddElem(new SXFD_InstC(m_SheetMap->GetDwgRevID())) ;
	}
	m_inst[2] = new SXFE_draughting_contract_assignmentC(m_inst[1], m_aggr[0]) ;

	//	APPROVAL_STATUS
	m_str[3] = new SXFD_StrC(" ") ;
	m_inst[3] = new SXFE_approval_statusC(m_str[3]) ;

	//	APPROVAL
	m_str[4] = new SXFD_StrC(" ") ;
	m_inst[4] = new SXFE_approvalC(m_inst[3], m_str[4]) ;

	//	CALENDAR_DATE
	//	ê}ñ çÏê¨îN(êºóÔ)
	m_int[0] = new SXFD_IntC(IN_Struct->d_year) ;
	//	ê}ñ çÏê¨åé(êºóÔ)
	m_int[1] = new SXFD_IntC(IN_Struct->d_month) ;
	//	ê}ñ çÏê¨ì˙(êºóÔ)
	m_int[2] = new SXFD_IntC(IN_Struct->d_day) ;
	m_inst[5] = new SXFE_calendar_dateC(m_int[0], m_int[2], m_int[1]) ;

	//	APPROVAL_DATE_TIME
	m_inst[6] = new SXFE_approval_date_timeC(m_inst[5], m_inst[4]) ;

	//	DRAUGHTING_APPROVAL_ASSIGNMENT
	m_aggr[1] = new SXFD_AggrC() ;
	if( m_SheetMap != NULL ) {
		m_aggr[1]->AddElem(new SXFD_InstC(m_SheetMap->GetDwgRevID())) ;
	}
	m_inst[7] = new SXFE_draughting_approval_assignmentC(new SXFD_InstC(m_inst[4]->GetInsID()), m_aggr[1]) ;

	//	ORGANIZATION_ROLE
	m_str[8] = new SXFD_StrC("creator") ;
	m_inst[8] = new SXFE_organization_roleC(m_str[8]) ;

	//	ORGANIZATION
	m_str[5] = new SXFD_StrC("$") ;
	//	éÛíçâÔé–ñº
	m_str[6] = new SXFD_StrC(IN_Struct->c_contractor) ;
	m_str[7] = new SXFD_StrC(" ") ;
	m_inst[9] = new SXFE_organizationC(m_str[5], m_str[6], m_str[7]) ;

	//	DRAUGHTING_ORGANIZATION_ASSIGNMENT
	m_aggr[2] = new SXFD_AggrC() ;
	if( m_SheetMap != NULL ) {
		m_aggr[2]->AddElem(new SXFD_InstC(m_SheetMap->GetDwgRevID())) ;
	}
	m_inst[10] = new SXFE_draughting_organization_assignmentC(m_inst[9], m_inst[8], m_aggr[2]) ;

	//	ORGANIZATION_ROLE
	m_str[12] = new SXFD_StrC("owner") ;
	m_inst[11] = new SXFE_organization_roleC(m_str[12]) ;

	//	ORGANIZATION
	m_str[9] = new SXFD_StrC("$") ;
	//	î≠íçéñã∆é“ñº
	m_str[10] = new SXFD_StrC(IN_Struct->c_owner) ;
	m_str[11] = new SXFD_StrC(" ") ;
	m_inst[12] = new SXFE_organizationC(m_str[9], m_str[10], m_str[11]) ;

	//	DRAUGHTING_ORGANIZATION_ASSIGNMENT
	m_aggr[3] = new SXFD_AggrC() ;
	if( m_SheetMap != NULL ) {
		m_aggr[3]->AddElem(new SXFD_InstC(m_SheetMap->GetDwgRevID())) ;
	}
	m_inst[13] = new SXFE_draughting_organization_assignmentC(m_inst[12], m_inst[11], m_aggr[3]) ;

	return TRUE ;
}

int SXFAttrMappingC::GetID()
{
	return m_ID ;
}

BOOL SXFAttrMappingC::WriteAP202(
					SXFPart21FileC*	IN_File)
{
	m_inst[ 2]->WriteP21(IN_File) ;
	m_inst[ 6]->WriteP21(IN_File) ;
	m_inst[ 7]->WriteP21(IN_File) ;
	m_inst[10]->WriteP21(IN_File) ;
	m_inst[13]->WriteP21(IN_File) ;

	return TRUE ;
}
