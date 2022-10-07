/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.h								�쐬���F2000.4.16

	�P�D�N���X�T�v
	�~�ʂ�Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFARCMAPPINGC_H__E62A78C3_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFARCMAPPINGC_H__E62A78C3_130E_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFTableManagerC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_EnumC;
class SXFD_BoolC;
class SXFD_TypeC;

class SXFArcMappingC  
{
public:
	int GetAssignID();
	BOOL WriteAP202Curve(SXFPart21FileC* IN_File);
	BOOL MappingStructCurve(Arc_Struct IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Arc_Struct IN_Struct);
	SXFArcMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag);
	SXFArcMappingC();
	virtual ~SXFArcMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENT�̃C���X�^���XID
	//////////////////////////////////////
	int m_assign_ID;
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
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[7];
	SXFD_InstC* m_inst_curve[5];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
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
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	SXFD_BoolC* m_bool2;
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	SXFD_EnumC* m_enum2;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
};

#endif // !defined(AFX_SXFARCMAPPINGC_H__E62A78C3_130E_11D4_A76E_00000EB03267__INCLUDED_)
