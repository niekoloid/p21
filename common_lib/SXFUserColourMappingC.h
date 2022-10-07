/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	���[�U��`�F��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/


#if !defined(AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFUserColourMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Userdefined_Colour_Struct* IN_Struct);
	SXFUserColourMappingC();
	virtual ~SXFUserColourMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real1;
};

#endif // !defined(AFX_SXFUSERCOLOURMAPPINGC_H__279A9281_1095_11D4_A76E_00000EB03267__INCLUDED_)
