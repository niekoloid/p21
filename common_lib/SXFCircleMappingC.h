/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.h					�쐬���F2000.04.15

	�P�D�N���X�T�v
	�~�t�B�[�`����Mapping
	
	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.15	�{��(FQS)	�Ȃ��B
**/

#if !defined(AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_

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

class SXFCircleMappingC  
{
public:
	void SetAssignID(int IN_AssignID);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Circle_Struct IN_Struct);
	SXFCircleMappingC();
	SXFCircleMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag);
	virtual ~SXFCircleMappingC();

private:
	//////////////////////////////////////
	//���x���t���O
	//���x���̕����v�f�F�P�A�����v�f�F�O
	//////////////////////////////////////
	int m_LabelFlag;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENT�̃C���X�^���XID
	//////////////////////////////////////
	int m_AssignID;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
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
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
};

#endif // !defined(AFX_SXFCIRCLEMAPPINGC_H__E62A78C1_130E_11D4_A76E_00000EB03267__INCLUDED_)
