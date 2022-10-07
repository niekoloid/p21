/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SPLINEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�X�v���C���t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_SPLINEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SPLINEC::SXFMapF_SPLINEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SPLINEC::SXFMapF_SPLINEC()
{
	m_open_close = 0;
	m_number = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SPLINEC::~SXFMapF_SPLINEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SPLINEC::~SXFMapF_SPLINEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SPLINEC::GetStructData(Spline_Struct* INOUT_Struct)

	����  �F	�^				������				���e
				Spline_Struct* 	INOUT_Struct    	�\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_SPLINEC::GetStructData( Spline_Struct* INOUT_Struct )
{
#include "SXFMapF_CurveStyleBaseC.h"

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->open_close = m_open_close;		//�J�敪
	INOUT_Struct->number     = m_number;			//���_��

    INOUT_Struct->x.Copy( m_x );	//X���W
	INOUT_Struct->y.Copy( m_y );	//Y���W

	return TRUE;
}
