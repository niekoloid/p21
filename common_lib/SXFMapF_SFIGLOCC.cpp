/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SFIGLOCC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����}�`�z�u�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_SFIGLOCC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGLOCC::SXFMapF_SFIGLOCC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SFIGLOCC::SXFMapF_SFIGLOCC()
{
	m_start_x = 0.0;	    //�z�u�ʒuX���W
	m_start_y = 0.0;		//�z�u�ʒuY���W
	m_angle   = 0.0;		//��]�p
	m_ratio_x = 0.0;		//X�����ړx
	m_ratio_y = 0.0;		//Y�����ړx
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGLOCC::~SXFMapF_SFIGLOCC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SFIGLOCC::~SXFMapF_SFIGLOCC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGLOCC::GetStructData(Sfigloc_StructDF* INOUT_Struct)

	���� �F	�^					������			���e
			Sfigloc_StructDF* 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_SFIGLOCC::GetStructData( Sfigloc_StructDF* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->name, m_name );			//�����}�`��

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

	INOUT_Struct->x      = m_start_x     ;			//�z�u�ʒuX���W
	INOUT_Struct->y      = m_start_y     ;			//�z�u�ʒuY���W
	INOUT_Struct->angle      = m_angle   ;			//��]�p
	INOUT_Struct->ratio_x    = m_ratio_x ;			//X�����ړx
	INOUT_Struct->ratio_y    = m_ratio_y ;			//y�����ړx

	return TRUE;
}
