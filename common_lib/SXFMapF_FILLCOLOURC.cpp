/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i�h��j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_FILLCOLOURC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLCOLOURC::SXFMapF_FILLCOLOURC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLCOLOURC::SXFMapF_FILLCOLOURC()
{
	m_out_id = 0;
	m_number = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLCOLOURC::~SXFMapF_FILLCOLOURC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLCOLOURC::~SXFMapF_FILLCOLOURC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLCOLOURC::GetStructData(Fill_area_style_colour_Struct* INOUT_Struct)

	���� �F	�^								������			���e
			Fill_area_style_colour_Struct* 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_FILLCOLOURC::GetStructData( Fill_area_style_colour_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h

	INOUT_Struct->out_id    = m_out_id;
	INOUT_Struct->number    = m_number;

	INOUT_Struct->in_id.Copy( m_in_id );

	return TRUE;
}
