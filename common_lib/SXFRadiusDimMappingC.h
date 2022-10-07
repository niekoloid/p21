/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.h								�쐬���F2000.4.17

	�P�D�N���X�T�v
	���a���@��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFRADIUSDIMMAPPINGC_H__FA74CCE0_1507_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFRADIUSDIMMAPPINGC_H__FA74CCE0_1507_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFLineMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_BoolC;
class SXFD_TypeC;

class SXFRadiusDimMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(RadiusDim_Struct IN_Struct,int IN_AssemType);
	SXFRadiusDimMappingC();
	SXFRadiusDimMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFRadiusDimMappingC();
private:
	//////////////////////////////////////
	//���@���t���O
	//���@���̐��@�l�F�P�A�����v�f�F�O
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_text_inst;
	SXFD_InstC* m_term_inst;
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
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
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//�����v�f�t�B�[�`��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//���Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping;
	//////////////////////////////////////
	//���@��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFLineMappingC* m_LineMapping;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//���DIRECTION�v�Z�p���\�b�h
	//////////////////////////////////////
	int CalcArrowDir(RadiusDim_Struct IN_Struct,double &OUT_Arrow_x,double &OUT_Arrow_y);
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID1;
	int m_ID2;

};

#endif // !defined(AFX_SXFRADIUSDIMMAPPINGC_H__FA74CCE0_1507_11D4_A76E_00000EB03267__INCLUDED_)
