/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.h					�쐬���F2000.04.14

	�P�D�N���X�T�v
	�����t�B�[�`����Mapping
	
	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/

#if !defined(AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_TypeC;
class SXFPart21FileC;

class SXFLineWidthMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Line_Width_Struct* IN_Struct);
	SXFLineWidthMappingC();
	virtual ~SXFLineWidthMappingC();
	int GetID();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	SXFD_InstC* m_unit_inst;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type;
};

#endif // !defined(AFX_SXFLINEWIDTHMAPPINGC_H__279A9283_1095_11D4_A76E_00000EB03267__INCLUDED_)
