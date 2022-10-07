/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	�����t�B�[�`����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;
class SXFD_TypeC;
class SXFTableManagerC;
class SXFPart21FileC;

class SXFTextStringMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Text_Struct IN_Struct);
	SXFTextStringMappingC();
	SXFTextStringMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag);
	virtual ~SXFTextStringMappingC();

private:
	//////////////////////////////////////
	//���@���t���O
	//���@���̐��@�l�F�P�A�����v�f�F�O
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//CStringList�̃I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[9];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
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
	SXFD_StrC* m_str9;
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
	SXFD_RealC* m_real8;
	SXFD_RealC* m_real9;
	SXFD_RealC* m_real10;
	SXFD_RealC* m_real11;
	SXFD_RealC* m_real12;
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
	SXFD_TypeC* m_type6;

};

#endif // !defined(AFX_SXFTEXTSTRINGMAPPINGC_H__2E711DE0_12B6_11D4_A76E_00000EB03267__INCLUDED_)
