/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2000.04.15

	�P�D�N���X�T�v
	�����Ȑ���`��Mapping

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.15	�{��(FQS)	�Ȃ��B
**/

#if !defined(AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_BoolC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_RealC;
class SXFPart21FileC;
class SXFTableManagerC;

class SXFCompCurveMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2,int &OUT_PointID);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Ccurve_Org_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	SXFCompCurveMappingC();
	SXFCompCurveMappingC(SXFTableManagerC* IN_TableManager,double IN_PointX,double IN_PointY);
	virtual ~SXFCompCurveMappingC();
private:
	//////////////////////////////////////
	//�n�b�`���O�����̓_
	//////////////////////////////////////
	double m_PointX ;
	double m_PointY ;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID1;
	int m_ID2;
	//////////////////////////////////////
	//CARTESIAN_POINT�̃C���X�^���XID
	//////////////////////////////////////
	int m_pointID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[4];
	SXFD_InstC* m_elem_inst;
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	SXFD_InstC* m_inst_point;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
};

#endif // !defined(AFX_SXFCOMPCURVEMAPPINGC_H__35B221C0_11E0_11D4_A76E_00000EB03267__INCLUDED_)
