/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i�p�^�[���j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_FILLTILESC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLTILESC::SXFMapF_FILLTILESC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLTILESC::SXFMapF_FILLTILESC()
{              
	m_hatch_color = 0;
	m_hatch_pattern_x = 0.0;
	m_hatch_pattern_y = 0.0;
	m_hatch_pattern_vector1 = 0.0;
	m_hatch_pattern_vector1_angle = 0.0;
	m_hatch_pattern_vector2 = 0.0;
	m_hatch_pattern_vector2_angle = 0.0;
	m_hatch_pattern_scale_x = 0.0;
	m_hatch_pattern_scale_y = 0.0;
	m_hatch_pattern_angle = 0.0;
	m_out_id = 0;
	m_number = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLTILESC::~SXFMapF_FILLTILESC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_FILLTILESC::~SXFMapF_FILLTILESC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_FILLTILESC::GetStructData(Fill_area_style_tiles_Struct* INOUT_Struct)

	���� �F	�^								������			���e
			Fill_area_style_tiles_Struct 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_FILLTILESC::GetStructData( Fill_area_style_tiles_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->name, m_name);

	// �����v�f�Ɠ�����257�o�C�g�ȏ�̕������256�ɐ؂�l�߂�
	size_t ilen = strlen(m_name);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name );
	}
	else {
		/* ���b�Z�[�W���o�� */
		// ������ m_RootID = 0,m_TypeName == "" �����Ǖ����v�f�Ɠ��������ɂ��Ă���
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* �擪����256�o�C�g�؂��� */
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name.Left(256) );
	}
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

	INOUT_Struct->hatch_color                 = m_hatch_color;
	INOUT_Struct->hatch_pattern_x 			  = m_hatch_pattern_x;
	INOUT_Struct->hatch_pattern_y 			  = m_hatch_pattern_y;
	INOUT_Struct->hatch_pattern_vector1       = m_hatch_pattern_vector1;
	INOUT_Struct->hatch_pattern_vector1_angle = m_hatch_pattern_vector1_angle;
	INOUT_Struct->hatch_pattern_vector2       = m_hatch_pattern_vector2;
	INOUT_Struct->hatch_pattern_vector2_angle = m_hatch_pattern_vector2_angle;
	INOUT_Struct->hatch_pattern_scale_x       = m_hatch_pattern_scale_x;
	INOUT_Struct->hatch_pattern_scale_y       = m_hatch_pattern_scale_y;
	INOUT_Struct->hatch_pattern_angle         = m_hatch_pattern_angle;
	INOUT_Struct->out_id                      = m_out_id;
	INOUT_Struct->number 					  = m_number;

	INOUT_Struct->in_id.Copy( m_in_id );

	return TRUE;
}
