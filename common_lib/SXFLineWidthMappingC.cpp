/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�N���X�T�v
	������Mapping

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include "SXFLineWidthMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_TypeC.h"
#include "SXFPart21FileC.h"
#include "SXFE_length_measure_with_unitC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLineWidthMappingC::SXFLineWidthMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
SXFLineWidthMappingC::SXFLineWidthMappingC()
:	m_ID(-1),
	m_unit_inst(NULL),
	m_real(NULL),
	m_type(NULL)
{
	m_inst[0] = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLineWidthMappingC::~SXFLineWidthMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
SXFLineWidthMappingC::~SXFLineWidthMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
	if (m_real != NULL)
		delete m_real;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�@�\�T�v
	������Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Line_Width_Struct* IN_Struct)
	����:	�^							������				���e
			Line_Width_Struct*			IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
BOOL SXFLineWidthMappingC::MappingStruct(Line_Width_Struct *IN_Struct)
{
	m_type = new SXFD_TypeC(DEF_POSITIVE_LENGTH_MEASURE);
	m_real = new SXFD_RealC(IN_Struct->width);
	m_type->SetNext(m_real);

	//�P�ʂ̃C���X�^���XID���擾����K�v����B
	m_unit_inst = new SXFD_InstC(10);

	m_inst[0] = new SXFE_length_measure_with_unitC(m_type,m_unit_inst);

	m_ID = m_inst[0]->GetInsID();
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�@�\�T�v
	�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X
	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
BOOL SXFLineWidthMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					�쐬���F2000.04.14

	�P�D�@�\�T�v
	�C���X�^���XID��ԋp����

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.14	�{��(FQS)	�Ȃ��B
**/
int SXFLineWidthMappingC::GetID()
{
	return m_ID;
}
