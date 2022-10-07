/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.h								�쐬���F2000.4.17

	�P�D�N���X�T�v
	�⏕����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFPROJMAPPINGC_H__1A5803C1_13AE_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFPROJMAPPINGC_H__1A5803C1_13AE_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;

class SXFProjMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStructDim(ProjLine_Struct IN_Struct);
	SXFProjMappingC();
	SXFProjMappingC(int IN_Flag);
	virtual ~SXFProjMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�t���O
	//�P�F		�O�F
	//////////////////////////////////////
	int m_Flag;
	//////////////////////////////////////
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[8];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_ins4;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	SXFD_AggrC* m_aggr6;
	SXFD_AggrC* m_aggr7;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	SXFD_StrC* m_str7;
	SXFD_StrC* m_str8;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	SXFD_RealC* m_real7;
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
};

#endif // !defined(AFX_SXFPROJMAPPINGC_H__1A5803C1_13AE_11D4_A76E_00000EB03267__INCLUDED_)
