/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.h								�쐬���F2007.1.30

	�P�D�N���X�T�v
	�N���\�C�h��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.30			����				�Ȃ��B

**/

#if !defined(AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_RealC;
class SXFD_BoolC;
class SXFD_EnumC;
class SXFD_TypeC;
class SXFD_IntC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_ListAggrC;

class SXFClothoidMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Clothoid_Struct* IN_Struct);
	SXFClothoidMappingC();
	SXFClothoidMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFClothoidMappingC();
private:
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { INST_NUM = 11 };
	SXFD_InstC* m_inst[INST_NUM];
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { AGGR_NUM = 6 };
	SXFD_AggrC* m_aggr[AGGR_NUM];
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { STR_NUM = 7 };
	SXFD_StrC* m_str[STR_NUM];
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { REAL_NUM = 7 };
	SXFD_RealC* m_real[REAL_NUM];
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { ENUM_NUM = 2 };
	SXFD_EnumC* m_enum[ENUM_NUM];
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { TYPE_NUM = 2 };
	SXFD_TypeC* m_type[TYPE_NUM];
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	enum { BOOL_NUM = 2 };
	SXFD_BoolC* m_bool[BOOL_NUM];
	//////////////////////////////////////
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
};

#endif // !defined(AFX_SXFCLOTHOIDMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
