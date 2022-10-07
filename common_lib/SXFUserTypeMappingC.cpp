/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	���[�U��`�����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFUserTypeMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_curve_style_font_patternC.h"
#include "SXFE_curve_style_fontC.h"
#include "SXFD_ListAggrC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFUserTypeMappingC::SXFUserTypeMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFUserTypeMappingC::SXFUserTypeMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFUserTypeMappingC::~SXFUserTypeMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFUserTypeMappingC::~SXFUserTypeMappingC()
{
	if (m_inst[4] != NULL)
		delete m_inst[4];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�p�x���@��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Userdefined_Linetype_Struct* IN_Struct)
	����:	�^								������				���e
			Userdefined_Linetype_Struct*	IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFUserTypeMappingC::MappingStruct(Userdefined_Linetype_Struct *IN_Struct)
{
	for (int i = 0; i < IN_Struct->segment/2;i++){
		m_real1 = new SXFD_RealC(IN_Struct->pitch[2*i]);
		m_real2 = new SXFD_RealC(IN_Struct->pitch[2*i+1]);
		m_inst[i] = new SXFE_curve_style_font_patternC(m_real1,m_real2) ;
	}
	m_list_aggr = new SXFD_ListAggrC();
	for (i = 0; i < IN_Struct->segment/2; i++){
		m_list_aggr->AddElem(m_inst[i]);
	}
	m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_inst[4] = new SXFE_curve_style_fontC(m_str,m_list_aggr);

	m_ID = m_inst[4]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	���[�U��`����C���X�^���X�̃t�@�C���ւ̏o��

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
BOOL SXFUserTypeMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[4]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFUserTypeMappingC::GetID()
{
	return m_ID;
}
