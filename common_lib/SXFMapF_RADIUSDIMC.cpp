/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���a���@�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_RADIUSDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_RADIUSDIMC::SXFMapF_RADIUSDIMC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_RADIUSDIMC::SXFMapF_RADIUSDIMC()
{
	m_sun_x1 = 0.0;
	m_sun_y1 = 0.0;
	m_sun_x2 = 0.0;
	m_sun_y2 = 0.0;
//
	m_arr_code1 = 0;
	m_arr_code2 = 0;
	m_arr_x = 0.0;
	m_arr_y = 0.0;
	m_arr_r = 0.0;
//
	m_flg = 0;
	m_font = 0;
	//CString m_str;
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
	SXFMapF_RADIUSDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_RADIUSDIMC::~SXFMapF_RADIUSDIMC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_RADIUSDIMC::~SXFMapF_RADIUSDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_RADIUSDIMC::GetStructData(RadiusDim_Struct* INOUT_Struct)

	����  �F	�^					������			���e
				RadiusDim_Struct 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_RADIUSDIMC::GetStructData( RadiusDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->sun_x1 = m_sun_x1;
	INOUT_Struct->sun_y1 = m_sun_y1;
	INOUT_Struct->sun_x2 = m_sun_x2;
	INOUT_Struct->sun_y2 = m_sun_y2;
//
	INOUT_Struct->arr_code1 = m_arr_code1;
	INOUT_Struct->arr_code2 = m_arr_code2;
	INOUT_Struct->arr_x     = m_arr_x;
	INOUT_Struct->arr_y     = m_arr_y;
	INOUT_Struct->arr_r     = m_arr_r;
//
	INOUT_Struct->flg  = m_flg;
	INOUT_Struct->font = m_font;

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->str, m_str);

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

	INOUT_Struct->text_x = m_text_x;
	INOUT_Struct->text_y = m_text_y;
	INOUT_Struct->height = m_height;
	INOUT_Struct->width  = m_width;
	INOUT_Struct->spc    = m_spc;
	INOUT_Struct->angle  = m_angle;
	INOUT_Struct->slant  = m_slant;
	INOUT_Struct->b_pnt  = m_b_pnt;
	INOUT_Struct->direct = m_direct;

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		���̌����t���O�ݒ�

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_ANGULARDIMC::SetArrFlag(
				int IN_term1,	//���̗L�薳���t���O
				double IN_sun_x1,	//���@���̎n�_
				double IN_sun_y1,	//���@���̎n�_
				double IN_sun_x2,	//���@���̏I�_
				double IN_sun_y2,	//���@���̏I�_
				double IN_tmvec_x,	//���P�̃x�N�g��X
				double IN_tmvec_y	//���P�̃x�N�g��Y)

	���� �F	�^			������				���e
			int 		IN_term1		//���̗L�薳���t���O
			double		 IN_sun_x1		//���@���̎n�_
			double		 IN_sun_y1		//���@���̎n�_
			double		 IN_sun_x2		//���@���̏I�_
			double		 IN_sun_y2		//���@���̏I�_
			double		 IN_tmvec_x		//���P�̃x�N�g��X
			double		 IN_tmvec_y		//���P�̃x�N�g��Y	

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_RADIUSDIMC::SetArrFlag(  
				int IN_term1,	//���̗L�薳���t���O
				double IN_sun_x1,	//���@���̎n�_
				double IN_sun_y1,	//���@���̎n�_
				double IN_sun_x2,	//���@���̏I�_
				double IN_sun_y2,	//���@���̏I�_
				double IN_tmvec_x,	//���P�̃x�N�g��X
				double IN_tmvec_y	//���P�̃x�N�g��Y
			)
{
	double eps;
	double L1;
	double Dim_x,Dim_y;
	double tmvec_x,tmvec_y;
	double tm_L;

	eps = 0.000001;
	m_arr_code2 = 0;

	if (IN_term1 != 0){
		//���̕����x�N�g��������O�R�[�h���v�Z����
		//���@���̕����x�N�g�����v�Z����
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = ( IN_sun_x2 - IN_sun_x1 )/L1;
		Dim_y = ( IN_sun_y2 - IN_sun_y1 )/L1;
		//���x�N�g���̒P�ʃx�N�g�������߂�B
		tm_L = fabs(sqrt(pow(IN_tmvec_x, 2)+pow(IN_tmvec_y, 2)));
		tmvec_x = IN_tmvec_x / tm_L;
		tmvec_y = IN_tmvec_y / tm_L;
		//���̓��O�R�[�h��ݒ肷��
		//���̕����x�N�g�������@���̕����x�N�g���Ɠ������̂Ƃ��A�Q�i�������j�ɐݒ肷��
		if((fabs(tmvec_x - Dim_x) < eps) && (fabs(tmvec_y - Dim_y) < eps)){
			m_arr_code2 = 2;
			m_arr_code2 = 1;
		}
		//���P�̕����x�N�g�������@���̕����x�N�g���Ɣ��Ε����̂Ƃ��A�P�i�O�����j�ɐݒ肷��
		else if((fabs(tmvec_x + Dim_x) < eps) && (fabs(tmvec_y + Dim_y) < eps)){
			m_arr_code2 = 1;
			m_arr_code2 = 2;
		}
	}
	return TRUE;
}

