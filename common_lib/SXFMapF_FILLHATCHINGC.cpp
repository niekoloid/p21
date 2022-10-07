/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILLHATCHING�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_FILLHATCHINGC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLHATCHINGC::SXFMapF_FILLHATCHINGC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLHATCHINGC::SXFMapF_FILLHATCHINGC()
{
	int m_hatch_number = 0;
	for(int i=0;i<MAXHATCHNUMBER;i++){
		m_hatch_color[i] = 0;
		m_hatch_type[i] = 0;
		m_hatch_line_width[i] = 0;
		m_hatch_start_x[i] = 0.0;
		m_hatch_start_y[i] = 0.0;
		m_hatch_spacing[i] = 0.0;
		m_hatch_angle[i] = 0.0;
	}
	int m_out_id = 0;
	int m_number = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLHATCHINGC::~SXFMapF_FILLHATCHINGC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLHATCHINGC::~SXFMapF_FILLHATCHINGC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLHATCHINGC::GetStructData(Fill_area_style_hatching_Struct* INOUT_Struct)

	���� �F	�^									������			���e
			Fill_area_style_hatching_Struct* 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_FILLHATCHINGC::GetStructData( Fill_area_style_hatching_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h

	INOUT_Struct->hatch_number  = m_hatch_number;	//�n�b�`���O���̃p�^�[����

	for(int i=0;i<MAXHATCHNUMBER;i++){
		INOUT_Struct->hatch_color[i]      =  m_hatch_color[i];	
		INOUT_Struct->hatch_type[i]       =  m_hatch_type[i];	
		INOUT_Struct->hatch_line_width[i] = m_hatch_line_width[i];
		INOUT_Struct->hatch_start_x[i]    =  m_hatch_start_x[i];
		INOUT_Struct->hatch_start_y[i]    =  m_hatch_start_y[i];
		INOUT_Struct->hatch_spacing[i]    =  m_hatch_spacing[i];
		INOUT_Struct->hatch_angle[i]      =  m_hatch_angle[i];
	}

	INOUT_Struct->out_id = m_out_id;			//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	INOUT_Struct->number = m_number;			//�������̗̈搔

	INOUT_Struct->in_id.Copy( m_in_id);			//�������̕����Ȑ��̃t�B�[�`���R�[�h

	return TRUE;
}
