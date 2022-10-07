/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		����`�V���{���t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_EXSYMBOLC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_EXSYMBOLC::SXFMapF_EXSYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_EXSYMBOLC::SXFMapF_EXSYMBOLC()
{
	m_start_x = 0.0;	    //�z�u�ʒuX���W
	m_start_y = 0.0;		//�z�u�ʒuY���W
	m_rotate_angle = 0.0;	//��]�p
	m_scale = 0.0;			//�{��
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_EXSYMBOLC::~SXFMapF_EXSYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_EXSYMBOLC::~SXFMapF_EXSYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_EXSYMBOLC::GetStructData(Externally_Defined_Symbol_Struct* INOUT_Struct)

	�����F	�^									������			���e
			Externally_Defined_Symbol_Struct 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_EXSYMBOLC::GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color_flag  = m_color_flag ;		//�F�R�[�h�t���O
	INOUT_Struct->color       = m_color ;			//�F�R�[�h

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->name, m_name );	//�V���{����

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

	INOUT_Struct->start_x      = m_start_x     ;			//�z�u�ʒuX���W
	INOUT_Struct->start_y      = m_start_y     ;			//�z�u�ʒuY���W
	INOUT_Struct->rotate_angle = m_rotate_angle;			//��]�p
	INOUT_Struct->scale        = m_scale       ;			//�{��

	return TRUE;
}
