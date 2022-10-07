/**
	All Rights Reserved,(c) JACIC 2001
	SXFSplineMappingC.h								�쐬���F2000.4.17

	�P�D�N���X�T�v
	�X�v���C����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSPLINEMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSPLINEMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_

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
class SXFD_IntC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_ListAggrC;

class SXFSplineMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Spline_Struct* IN_Struct);
	BOOL MappingStructCurve(Spline_Struct* IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN);
	SXFSplineMappingC();
	SXFSplineMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFSplineMappingC();
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
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList *m_slist;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_IntC* m_int1;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_ListAggrC* m_list_aggr;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_elem1;
	SXFD_InstC* m_elem2;
	SXFD_InstC* m_elem3;
	SXFD_InstC* m_elem4;
	SXFD_InstC* m_elem5;
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_write_inst;
	//////////////////////////////////////
	//CObList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CObList m_list_elems;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	SXFD_BoolC* m_bool2;
	SXFD_BoolC* m_bool3;
	SXFD_BoolC* m_bool4;

};

#endif // !defined(AFX_SXFSPLINEMAPPINGC_H__E62A78C6_130E_11D4_A76E_00000EB03267__INCLUDED_)
