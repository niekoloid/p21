/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	���C����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFLayerMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFLayerC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_presentation_layer_assignmentC.h"
#include "SXFE_presentation_layer_usageC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLayerMappingC::SXFLayerMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFLayerMappingC::SXFLayerMappingC()
{
	for (int i = 0; i < 2; i++){
		m_inst[i] = NULL;
	}
	m_aggr1 = NULL;
	m_elem1 = NULL;
	m_sheet = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLayerMappingC::~SXFLayerMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFLayerMappingC::~SXFLayerMappingC()
{
	if (m_inst[1] != NULL)
		delete m_inst[1];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	���C����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(SXFLayerC* IN_Layer)
	����:	�^				������				���e
			SXFLayerC*		IN_Layer			SXFLayerC�I�u�W�F�N�g�̃|�C���^

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFLayerMappingC::MappingStruct(SXFLayerC *IN_Layer)
{
	m_str1 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Layer->m_Name);
	m_str2 = new SXFD_StrC(" ");
	m_aggr1 = new SXFD_AggrC();
	for (int i = 0; i < IN_Layer->m_Element.GetSize(); i++){
		m_elem1 = new SXFD_InstC(IN_Layer->m_Element[i]);
		m_aggr1->AddElem(m_elem1);
	}
	m_inst[0]=new SXFE_presentation_layer_assignmentC(m_str1,m_str2,m_aggr1);
	m_ID = m_inst[0]->GetInsID();

	m_sheet = new SXFD_InstC(IN_Layer->m_SheetID);
	m_inst[1]=new SXFE_presentation_layer_usageC(m_inst[0],m_sheet);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X

	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFLayerMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[1]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�C���X�^���XID��ԋp����

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFLayerMappingC::GetID()
{
	return m_ID;
}
