/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	����`�����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFPreTypeMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_draughting_pre_defined_curve_fontC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFPreTypeMappingC::SXFPreTypeMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreTypeMappingC::SXFPreTypeMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFPreTypeMappingC::~SXFPreTypeMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreTypeMappingC::~SXFPreTypeMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	����`�����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Predefined_Linetype_Struct* IN_Struct)
	����:	�^								������				���e
			Predefined_Linetype_Struct*		IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFPreTypeMappingC::MappingStruct(Predefined_Linetype_Struct* IN_Struct)
{
	m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_inst[0] = new SXFE_draughting_pre_defined_curve_fontC(m_str) ;

	m_ID = m_inst[0]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	����`����C���X�^���X�̃t�@�C���ւ̏o��

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
BOOL SXFPreTypeMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								�쐬���F2000.4.14

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
int SXFPreTypeMappingC::GetID()
{
	return m_ID;
}
