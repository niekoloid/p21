/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�~�ʃt�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ARCC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ARCC::SXFMapF_ARCC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_ARCC::SXFMapF_ARCC()
{
	m_center_x    = 0.0;
	m_center_y    = 0.0;
	m_radius      = 0.0;
	m_direction   = 0;
	m_start_angle = 0.0;
	m_end_angle   = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ARCC::~SXFMapF_ARCC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_ARCC::~SXFMapF_ARCC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ARCC::GetStructData()

	����  �F	�^				������				���e
				Arc_Struct* 	INOUT_Struct    	�\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_ARCC::GetStructData( Arc_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->center_x      = m_center_x;   		//���S�w���W
	INOUT_Struct->center_y   	= m_center_y;   		//���S�x���W
	INOUT_Struct->radius 		= m_radius;     	    //���a
	INOUT_Struct->direction  	= m_direction;  		//�����t���O
	INOUT_Struct->start_angle	= m_start_angle;		//�n�p
	INOUT_Struct->end_angle  	= m_end_angle;  		//�I�p

	return TRUE;
}
