/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.h								�쐬���F2000.4.19

	�P�D�N���X�T�v
	����`�V���{����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.19			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_

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

class SXFExSymbolMappingC  
{
public:
	int GetCartesianID();
	void SetSymbolScale(double IN_Scale);
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Externally_Defined_Symbol_Struct IN_Struct);
	SXFExSymbolMappingC();
	SXFExSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_HatchFlag);
	virtual ~SXFExSymbolMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//CARTESIAN_POINT�̃C���X�^���XID
	//////////////////////////////////////
	int m_CartesianID;
	//////////////////////////////////////
	//�X�P�[��
	//////////////////////////////////////
	double m_Scale;
	//////////////////////////////////////
	//�n�b�`���O�t���O
	//�P�F�n�b�`���O�̊���`�V���{���@�O�F����`�V���{��
	//////////////////////////////////////
	int m_HatchFlag;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
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
	SXFD_StrC* m_str10;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_inst[11];
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
};

#endif // !defined(AFX_SXFEXSYMBOLMAPPINGC_H__8AC12AC0_154C_11D4_A76E_00000EB03267__INCLUDED_)
