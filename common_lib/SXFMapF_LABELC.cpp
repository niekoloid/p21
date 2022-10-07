/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���o�����t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_LABELC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LABELC::SXFMapF_LABELC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_LABELC::SXFMapF_LABELC()
{
	m_vertex_number = 0;
	m_arr_code = 0;
	m_arr_r = 0.0;

	m_flg = 0;
	m_font = 0;
	m_text_x = 0.0;
	m_text_y = 0.0;
	m_height = 0.0;
	m_width = 0.0;
	m_spc = 0.0;
	m_angle = 0.0;
	m_slant = 0.0;
	m_b_pnt = 0;
	m_direct = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LABELC::~SXFMapF_LABELC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_LABELC::~SXFMapF_LABELC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LABELC::GetStructData( Label_Struct* INOUT_Struct)

	����  �F	�^				������				���e
				Label_Struct 	INOUT_Struct   		�\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_LABELC::GetStructData( Label_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->vertex_number = m_vertex_number;

	INOUT_Struct->vertex_x.Copy( m_vertex_x );
	INOUT_Struct->vertex_y.Copy( m_vertex_y );

	INOUT_Struct->arr_code =  m_arr_code;
	INOUT_Struct->arr_r    =  m_arr_r;

	INOUT_Struct->flg  = m_flg;
	INOUT_Struct->font = m_font;

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->str, m_str );

	// �����v�f�Ɠ�����257�o�C�g�ȏ�̕������256�ɐ؂�l�߂�
	size_t ilen = strlen(m_str);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str );
	}
	else {
		/* ���b�Z�[�W���o�� */
		// ������ m_RootID = 0,m_TypeName == "" �����Ǖ����v�f�Ɠ��������ɂ��Ă���
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* �擪����256�o�C�g�؂��� */
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str.Left(256) );
	}
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

	INOUT_Struct->text_x =  m_text_x;
	INOUT_Struct->text_y =  m_text_y;
	INOUT_Struct->height =  m_height;
	INOUT_Struct->width  =  m_width;
	INOUT_Struct->spc    =  m_spc;
	INOUT_Struct->angle  =  m_angle;
	INOUT_Struct->slant  =  m_slant;
	INOUT_Struct->b_pnt  =  m_b_pnt;
	INOUT_Struct->direct =  m_direct;

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		���o���̍��W����ɋ߂������n�_�Ƃ��ăZ�b�g

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_LABELC::SetVertex()

	���� �F	�^			������				���e
			double		IN_arr_x		����X���W
			double		IN_arr_y		����Y���W
			int			IN_number		���
			CArray		IN_vertex_x		�܂����X���W
			CArray		IN_vertex_y		�܂����Y���W

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_LABELC::SetVertex(
	double IN_arr_x, double IN_arr_y,
	int		IN_number,
	CArray<double,double>& IN_vertex_x,
	CArray<double,double>& IN_vertex_y)
{

	if (IN_number>IN_vertex_x.GetSize() || IN_number>IN_vertex_y.GetSize() )
		return FALSE;

	double L1, L2;

//	���Ɛ܂���̎n�_�Ƃ̋����Z�o
	L1 = fabs(sqrt(pow(IN_arr_x - IN_vertex_x[0], 2)
					+pow(IN_arr_y - IN_vertex_y[0], 2)));
//	���Ɛ܂���̏I�_�Ƃ̋����Z�o
	L2 = fabs(sqrt	(pow(IN_arr_x - IN_vertex_x[IN_number-1], 2)
						+pow(IN_arr_y - IN_vertex_y[IN_number-1], 2)));

//	���肵�Z�b�g����B
	//�n�_�����Ƌ߂��ꍇ
	if (L1<L2){
		m_vertex_x.Copy( IN_vertex_x );
		m_vertex_y.Copy( IN_vertex_y );
	}
	//�I�_�����ɋ߂��ꍇ��������ւ���
	else{
		for (int i=0;i<IN_number;i++){
			m_vertex_x[i]=IN_vertex_x[IN_number-1-i];
			m_vertex_y[i]=IN_vertex_y[IN_number-1-i];
		}
	}
	return TRUE;
}
