/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						�쐬���F2007.01.30

	�P�D�N���X�T�v
		�N���\�C�h�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2007.01.30	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_CLOTHOIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						�쐬���F2007.01.30

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CLOTHOIDC::SXFMapF_CLOTHOIDC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.30	
**/
SXFMapF_CLOTHOIDC::SXFMapF_CLOTHOIDC()
{
	base_x = 0.0;
	base_y = 0.0;
	parameter = 0.0;
	direction = 0;
	angle = 0.0;
	start_length = 0.0;
	end_length = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						�쐬���F2007.01.30

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CLOTHOIDC::~SXFMapF_CLOTHOIDC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.30	
**/
SXFMapF_CLOTHOIDC::~SXFMapF_CLOTHOIDC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						�쐬���F2007.01.30

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CLOTHOIDC::GetStructData(Clothoid_Struct* INOUT_Struct)

	����  �F	�^				������				���e
				Clothoid_Struct* 	INOUT_Struct    	�\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.30	
**/
BOOL SXFMapF_CLOTHOIDC::GetStructData( Clothoid_Struct* INOUT_Struct )
{
#include "SXFMapF_CurveStyleBaseC.h"

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->base_x = base_x;
	INOUT_Struct->base_y = base_y;
	INOUT_Struct->parameter = parameter;
	INOUT_Struct->direction = direction;
	INOUT_Struct->angle = angle;
	INOUT_Struct->start_length = start_length;
	INOUT_Struct->end_length = end_length;

	return TRUE;
}
