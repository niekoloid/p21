/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	�����t�H���g��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFTextFontMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_externally_defined_text_fontC.h"
#include "SXFE_External_sourceC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTextFontMappingC::SXFTextFontMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFTextFontMappingC::SXFTextFontMappingC()
:	m_ID(-1),
	m_str1(NULL),
	m_str2(NULL),
	m_type1(NULL),
	m_type2(NULL)
{
	for(int i=0; i<2; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTextFontMappingC::~SXFTextFontMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFTextFontMappingC::~SXFTextFontMappingC()
{
	if (m_inst[1] != NULL)
		delete m_inst[1];
	if (m_str1 != NULL)
		delete m_str1;
	if (m_str2 != NULL)
		delete m_str2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�����t�H���g��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Text_Font_Struct* IN_Struct)
	����:	�^					������				���e
			Text_Font_Struct*	IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFTextFontMappingC::MappingStruct(Text_Font_Struct *IN_Struct)
{

	m_type1 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_str1 = new SXFD_StrC("scadec");
	m_type1->SetNext(m_str1);
	m_inst[0] = new SXFE_external_sourceC(m_type1) ;

	m_type2 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_str2 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_type2->SetNext(m_str2);
	m_inst[1] = new SXFE_externally_defined_text_fontC(m_type2,m_inst[0]) ;

	m_ID = m_inst[1]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�����t�H���g�C���X�^���X�̃t�@�C���ւ̏o��

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
BOOL SXFTextFontMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[1]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								�쐬���F2000.4.14

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
int SXFTextFontMappingC::GetID()
{
	return m_ID;
}
