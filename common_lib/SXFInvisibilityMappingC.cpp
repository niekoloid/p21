/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								�쐬���F2000.4.16

	�P�D�N���X�T�v
	Invisibility��Mapping
	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFInvisibilityMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_invisibilityC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								�쐬���F2000.4.16

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFInvisibilityMappingC::SXFInvisibilityMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/
SXFInvisibilityMappingC::SXFInvisibilityMappingC()
{
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_aggr = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								�쐬���F2000.4.16

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFInvisibilityMappingC::~SXFInvisibilityMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/
SXFInvisibilityMappingC::~SXFInvisibilityMappingC()
{
	if (m_inst2 != NULL)
		delete m_inst2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								�쐬���F2000.4.16

	�P�D�@�\�T�v
	Invisibility��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL SXFInvisibilityMappingC::MappingStruct(CUIntArray* IN_Invisibility)
	����:	�^				������				���e
			CUIntArray* 	IN_Invisibility				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/
BOOL SXFInvisibilityMappingC::MappingStruct(CUIntArray* IN_Invisibility)
{
	m_aggr = new SXFD_AggrC();
	for (int i = 0; i < IN_Invisibility->GetSize(); i++){
		m_inst1 = new SXFD_InstC(IN_Invisibility->GetAt(i));
		m_aggr->AddElem(m_inst1);
	}
	m_inst2 = new SXFE_invisibilityC(m_aggr);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								�쐬���F2000.4.16

	�P�D�@�\�T�v
	�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL SXFInvisibilityMappingC::WriteAP202(SXFPart21FileC *IN_File)
	����:	�^				������				���e
			SXFPart21FileC 	*IN_File		�t�@�C���I�u�W�F�N�g�̃A�h���X	

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.16			�{��(FQS)			�Ȃ��B

**/
BOOL SXFInvisibilityMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst2->WriteP21(IN_File);
	return TRUE;
}
