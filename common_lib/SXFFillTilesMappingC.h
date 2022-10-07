/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.h								�쐬���F2000.4.19

	�P�D�N���X�T�v
	�n�b�`���O(�p�^�[��)��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.19			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFFILLTILESMAPPINGC_H__6ACDA8A5_15D4_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFFILLTILESMAPPINGC_H__6ACDA8A5_15D4_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFExSymbolMappingC;
class SXFD_InstC;
class SXFD_AggrC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_RealC;

class SXFFillTilesMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Fill_area_style_tiles_Struct *IN_Struct);
	SXFFillTilesMappingC();
	SXFFillTilesMappingC(SXFTableManagerC* IN_TableManager,CUIntArray* IN_AssemblyTable);
	virtual ~SXFFillTilesMappingC();

private:
	//////////////////////////////////////
	//����`�V���{��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFExSymbolMappingC* m_ExSymbolMapping;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�����Ȑ���ID�̔z��
	//////////////////////////////////////
	CUIntArray* m_AssemblyTable;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
//	SXFD_TypeC* m_type1;//AP-01_000511_del
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
	SXFD_TypeC* m_type6;
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
	SXFD_InstC* m_inst1;
	SXFD_InstC* m_inst2;
	SXFD_InstC* m_inst3;
	SXFD_InstC* m_inst4;
	SXFD_InstC* m_inst[11];
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
	SXFD_AggrC* m_aggr8;
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
};

#endif // !defined(AFX_SXFFILLTILESMAPPINGC_H__6ACDA8A5_15D4_11D4_A76E_00000EB03267__INCLUDED_)
