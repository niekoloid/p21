/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_LINEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_LINEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LINEC::SXFMapF_LINEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_LINEC::SXFMapF_LINEC()
{
//	<������>

	m_Type = line_feature ;
	m_TypeName = "line_feature";

	m_start_x=0.;		//�n�_�w���W
	m_start_y=0.;		//�n�_�x���W
	m_end_x=0.;			//�I�_�w���W
	m_end_y=0.;			//�I�_�x���W

//------------------------------------------------
//	PROJECTION LINE �ŗL
//------------------------------------------------
	m_flag=0;			//�[�_�P�Q�t���O�i0:�����l,1:�[�_�P��, 2:�[�_�Q��)
	m_org_x=0.;			//��_�w���W
	m_org_y=0.;			//��_�x���W

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LINEC::~SXFMapF_LINEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_LINEC::~SXFMapF_LINEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						�쐬���F2000.05.13

	�P�D�@�\�T�v
		�⏕���̃t���O�ݒ�
	�Q�D�C���^�[�t�F�C�X
		BOOL SXFMapF_LINEC::Set12flg(
			CString& IN_name )		//	BODY �� NAME�p�����^ 


	����  �F	�^			������				���e
				CString& 	IN_name

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.05.13	�呺(FQS)
**/

//	<�⏕���̒[�_�P�C�Q�ǂ��炩�H��\�킷�t���O�ݒ�>
BOOL SXFMapF_LINEC::Set12flg(CString& IN_name)
{

	CStringArray pojflg;
	CString a1(" ");
	CString a2("$$SXF_prj_1");
	CString a3("$$SXF_prj_2");
	pojflg.Add((LPCTSTR)a1);
	pojflg.Add((LPCTSTR)a2);
	pojflg.Add((LPCTSTR)a3);

//�[�_�P�Q�t���O�i0:�����l,1:�[�_�P��, 2:�[�_�Q��)
	m_flag = 0;
	for(int i=1;i<=2;i++){
		if( IN_name==pojflg.GetAt(i)){
			m_flag=i;
			break;
		}
	}
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̎擾

	�Q�D�C���^�[�t�F�C�X
    BOOL GetStructData( Line_Struct* INOUT_Struct );

	����  �F	�^				������				���e
				Line_Struct* 	INOUT_Struct

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_LINEC::GetStructData( Line_Struct* INOUT_Struct )

{

//	<1. �G���e�B�e�B�p�����^�̐ݒ�>
	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->start_x	=	m_start_x;		//�n�_�w���W
	INOUT_Struct->start_y	=	m_start_y;		//�n�_�x���W
	INOUT_Struct->end_x		=	m_end_x;		//�I�_�w���W
	INOUT_Struct->end_y		=	m_end_y;		//�I�_�x���W

	return TRUE;
}
