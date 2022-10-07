/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	�����}�`��`��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#if !defined(AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;

class SXFSfigMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	int GetID();
	BOOL MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	SXFSfigMappingC();
	virtual ~SXFSfigMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[5];
	SXFD_InstC* m_elem_inst;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
};

#endif // !defined(AFX_SXFSFIGMAPPINGC_H__16DFD9E2_1172_11D4_A76E_00000EB03267__INCLUDED_)
