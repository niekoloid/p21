/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.h							�쐬���F2000.4.14

	�P�D�N���X�T�v
	���[�U��`�����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFD_StrC.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_ListAggrC;
class SXFPart21FileC;

class SXFUserTypeMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Userdefined_Linetype_Struct* IN_Struct);
	SXFUserTypeMappingC();
	virtual ~SXFUserTypeMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[5];
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr;
	SXFD_ListAggrC* m_list_aggr;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real1;
};

#endif // !defined(AFX_SXFUSERTYPEMAPPINGC_H__279A9282_1095_11D4_A76E_00000EB03267__INCLUDED_)
