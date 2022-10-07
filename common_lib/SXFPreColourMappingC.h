/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	����`�F��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_StrC;
class SXFD_RealC;
class SXFPart21FileC;
class SXFPreDefColorC;

class SXFPreColourMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(SXFPreDefColorC IN_Struct);
	SXFPreColourMappingC();
	virtual ~SXFPreColourMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str;
};

#endif // !defined(AFX_SXFPRECOLOURMAPPINGC_H__88F71822_1075_11D4_A76E_00000EB03267__INCLUDED_)
