/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	����`�����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFPreTypeMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Predefined_Linetype_Struct* IN_Struct);
	SXFPreTypeMappingC();
	virtual ~SXFPreTypeMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[1];
};

#endif // !defined(AFX_SXFPRETYPEMAPPINGC_H__BFD53180_1082_11D4_A76E_00000EB03267__INCLUDED_)
