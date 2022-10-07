/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.h								�쐬���F2000.4.20

	�P�D�N���X�T�v
	�����o������Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.20			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFPolylineMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_BoolC;

class SXFLabelMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC *IN_File);
	BOOL MappingStruct(Label_Struct *IN_Struct,int IN_AssemType);
	SXFLabelMappingC();
	SXFLabelMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFLabelMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
	SXFD_InstC* m_inst[3];
	SXFD_InstC* m_term_inst;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//�ܐ��t�B�[�`��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFPolylineMappingC* m_PolylineMapping;
	//////////////////////////////////////
	//�����v�f�t�B�[�`��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//���Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
};

#endif // !defined(AFX_SXFLABELMAPPINGC_H__FA74CCE1_1507_11D4_A76E_00000EB03267__INCLUDED_)
