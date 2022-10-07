/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	���[�U��`�F��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFUserColourMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_colour_rgbC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFUserColourMappingC::SXFUserColourMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFUserColourMappingC::SXFUserColourMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFUserColourMappingC::~SXFUserColourMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFUserColourMappingC::~SXFUserColourMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	���[�U��`�F��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Userdefined_Colour_Struct* IN_Struct)
	����:	�^							������				���e
			Userdefined_Colour_Struct*	IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFUserColourMappingC::MappingStruct(Userdefined_Colour_Struct *IN_Struct)
{
	m_str = new SXFD_StrC("");
	m_real1 = new SXFD_RealC((double)(IN_Struct->red/255.0));
	m_real2 = new SXFD_RealC((double)(IN_Struct->green/255.0));
	m_real3 = new SXFD_RealC((double)(IN_Struct->blue/255.0));

	m_inst[0] = new SXFE_colour_rgbC(m_str,m_real1,m_real2,m_real3);

	m_ID = m_inst[0]->GetInsID();

	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�n�b�`���O(�p�^�[���j�C���X�^���X�̃t�@�C���ւ̏o��

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
BOOL SXFUserColourMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								�쐬���F2000.4.14

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
int SXFUserColourMappingC::GetID()
{
	return m_ID;
}
