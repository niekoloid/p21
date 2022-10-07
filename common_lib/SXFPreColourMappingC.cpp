/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
	����`�F��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFPreColourMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFPart21FileC.h"
#include "SXFE_draughting_pre_defined_colourC.h"
#include "SXFE_colour_rgbC.h"
#include "SXFPreDefColorC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFPreColourMappingC::SXFPreColourMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreColourMappingC::SXFPreColourMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFPreColourMappingC::~SXFPreColourMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreColourMappingC::~SXFPreColourMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
	����`�F��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(SXFPreDefColorC IN_Struct)
	����:	�^					������				���e
			SXFPreDefColorC		IN_Struct			SXFPreDefColorC

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
BOOL SXFPreColourMappingC::MappingStruct(SXFPreDefColorC IN_Struct)
{
	//�R�[�h�F�P����W�@��DRAUGHTING_PRE_DEFINED_COLOUR
	//�R�[�h�F�X����P�U��COLOUR_RGB
	if (IN_Struct.m_Code <= 8){
		m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct.m_Name);
		m_inst[0] = new SXFE_draughting_pre_defined_colourC(m_str);
		m_ID = m_inst[0]->GetInsID();
		return TRUE;
	}
	else{
		char tmp_char[32];
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_");
		//strcat(tmp_char,IN_Struct.m_Name);
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_");
		strcat_s(tmp_char,_countof(tmp_char),IN_Struct.m_Name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		m_str = new SXFD_StrC(tmp_char);
		m_real1 = new SXFD_RealC((double)(IN_Struct.R/255.0));
		m_real2 = new SXFD_RealC((double)(IN_Struct.G/255.0));
		m_real3 = new SXFD_RealC((double)(IN_Struct.B/255.0));
		m_inst[0] = new SXFE_colour_rgbC(m_str,m_real1,m_real2,m_real3);
		m_ID = m_inst[0]->GetInsID();
		return TRUE;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

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
BOOL SXFPreColourMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								�쐬���F2000.4.14

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
int SXFPreColourMappingC::GetID()
{
	return m_ID;
}
