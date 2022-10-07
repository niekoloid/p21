/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEARCC.cpp					�쐬���F2000.04.17

	�P�D�N���X�T�v
		ELLIPSEARC�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ELLIPSEARCC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ELLIPSEARCC::SXFMapF_ELLIPSEARCC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_ELLIPSEARCC::SXFMapF_ELLIPSEARCC()
{
	double	m_center_x       = 0.0;
	double	m_center_y       = 0.0;
	double	m_radius_x       = 0.0;
	double	m_radius_y       = 0.0;
	int     m_direction      = 0;
	double  m_rotation_angle = 0.0;
	double  m_start_angle    = 0.0;
	double  m_end_angle      = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ELLIPSEARCC::~SXFMapF_ELLIPSEARCC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_ELLIPSEARCC::~SXFMapF_ELLIPSEARCC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEARCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ELLIPSEARCC::GetStructData()

	���� �F	�^					������				���e
			Ellipse_Arc_Struct* INOUT_Struct    	�\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_ELLIPSEARCC::GetStructData( Ellipse_Arc_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->center_x       =  m_center_x;      	//���S�w���W
	INOUT_Struct->center_y       =  m_center_y;      	//���S�x���W
	INOUT_Struct->radius_x       =  m_radius_x;      	//X�������a
	INOUT_Struct->radius_y       =  m_radius_y;      	//Y�������a
	INOUT_Struct->direction      =  m_direction;     	//�����t���O
	INOUT_Struct->rotation_angle =  m_rotation_angle;	//��]�p
	INOUT_Struct->start_angle    =  m_start_angle;   	//�n�p
	INOUT_Struct->end_angle      =	m_end_angle;     	//�I�p

	return TRUE;

}
