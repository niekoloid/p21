/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								�쐬���F2001.2.15

	�P�D�N���X�T�v
		���[���`�F�b�N�����Ǘ�����N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.15			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFCheckInfoC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								�쐬���F2001.2.15

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFCheckInfoC::SXFCheckInfoC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.15			�{��(FQS)			�Ȃ��B

**/
SXFCheckInfoC::SXFCheckInfoC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								�쐬���F2001.2.15

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFCheckInfoC::~SXFCheckInfoC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.15			�{��(FQS)			�Ȃ��B

**/
SXFCheckInfoC::~SXFCheckInfoC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								�쐬���F2001.2.15

	�P�D�@�\�T�v
		������

	�Q�D�C���^�[�t�F�[�X
		void	SXFTableCheckC::initialize()
		
	����	�F	�^			������			���e
				�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.15			�{��(FQS)			�Ȃ��B

**/
void SXFCheckInfoC::initialize()
{
	m_layer = -1;
	m_color = -1;
	m_type = -1;
	m_line_width = -1;
	m_font = -1;
}
