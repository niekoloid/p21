/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_POINTMARKERC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�_�}�[�J�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_POINTMARKERC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_POINTMARKERC::SXFMapF_POINTMARKERC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_POINTMARKERC::SXFMapF_POINTMARKERC()
{
	m_start_x = 0.0;	    //�z�u�ʒuX���W
	m_start_y = 0.0;		//�z�u�ʒuY���W
	m_marker_code;			//�}�[�J�R�[�h
	m_rotate_angle = 0.0;	//��]�p
	m_scale = 0.0;			//�ړx
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_POINTMARKERC::~SXFMapF_POINTMARKERC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_POINTMARKERC::~SXFMapF_POINTMARKERC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_POINTMARKERC::GetStructData()

	���� �F	�^						������				���e
			Point_Marker_Struct* 	INOUT_Struct 	   �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_POINTMARKERC::GetStructData( Point_Marker_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h

	INOUT_Struct->start_x       = m_start_x     ;	//�z�u�ʒuX���W
	INOUT_Struct->start_y       = m_start_y     ;	//�z�u�ʒuY���W
	INOUT_Struct->marker_code = m_marker_code;		//�}�[�J�R�[�h
	INOUT_Struct->rotate_angle  = m_rotate_angle;	//��]�p
	INOUT_Struct->scale         = m_scale       ;	//�ړx

	return TRUE;
}
