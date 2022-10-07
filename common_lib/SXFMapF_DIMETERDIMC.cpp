/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.h						�쐬���F2000.04.17

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
#include "SXFMapF_DIMETERDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_DIMETERDIMC::SXFMapF_DIMETERDIMC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_DIMETERDIMC::SXFMapF_DIMETERDIMC()
{
	m_sun_x1 = 0.0;
	m_sun_y1 = 0.0;
	m_sun_x2 = 0.0;
	m_sun_y2 = 0.0;
//
	m_arr1_code1 = 0;
	m_arr1_code2 = 0;
	m_arr1_x = 0.0;
	m_arr1_y = 0.0;
	m_arr1_r = 0.0;
//
	m_arr2_code1 = 0;
	m_arr2_code2 = 0;
	m_arr2_x = 0.0;
	m_arr2_y = 0.0;
	m_arr2_r = 0.0;

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
	SXFMapF_DIMETERDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_DIMETERDIMC::~SXFMapF_DIMETERDIMC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_DIMETERDIMC::~SXFMapF_DIMETERDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_DIMETERDIMC::GetStructData()

	���� �F	�^					������			���e
			DiameterDim_Struct	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_DIMETERDIMC::GetStructData( DiameterDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->sun_x1 = m_sun_x1;
	INOUT_Struct->sun_y1 = m_sun_y1;
	INOUT_Struct->sun_x2 = m_sun_x2;
	INOUT_Struct->sun_y2 = m_sun_y2;
////
	INOUT_Struct->arr1_code1	= m_arr1_code1;
	INOUT_Struct->arr1_code2	= m_arr1_code2;
	INOUT_Struct->arr1_x 	    = m_arr1_x;
	INOUT_Struct->arr1_y	    = m_arr1_y;
	INOUT_Struct->arr1_r 	    = m_arr1_r;
////
	INOUT_Struct->arr2_code1	= m_arr2_code1;
	INOUT_Struct->arr2_code2	= m_arr2_code2;
	INOUT_Struct->arr2_x 	    = m_arr2_x;
	INOUT_Struct->arr2_y        = m_arr2_y;
	INOUT_Struct->arr2_r	    = m_arr2_r;

	INOUT_Struct->flg    = m_flg;
	INOUT_Struct->font   = m_font;

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->str,  m_str);

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

	INOUT_Struct->text_x   = m_text_x;
	INOUT_Struct->text_y   = m_text_y;
	INOUT_Struct->height   = m_height;
	INOUT_Struct->width    = m_width;
	INOUT_Struct->spc      = m_spc;
	INOUT_Struct->angle    = m_angle;
	INOUT_Struct->slant    = m_slant;
	INOUT_Struct->b_pnt	   = m_b_pnt;
	INOUT_Struct->direct   = m_direct;

	return TRUE;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�����t���O�̐ݒ�

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_DIMETERDIMC::SetArrFlag()

	���� �F	�^		������				���e
			int		IN_term1	���P�̗L�薳���t���O
			int		IN_term2	���Q�̗L�薳���t���O
			double	IN_sun_x1	���@���̎n�_
			double	IN_sun_y1	���@���̎n�_
			double	IN_sun_x2	���@���̏I�_
			double	IN_sun_y2	���@���̏I�_
			double	IN_tmvec_x1	���P�̃x�N�g��X
			double	IN_tmvec_y1	���P�̃x�N�g��Y
			double	IN_tmvec_x2	���Q�̃x�N�g��X
			double	IN_tmvec_y2	���Q�̃x�N�g��Y
	
	  ���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_DIMETERDIMC::SetArrFlag(  
				int IN_term1,	//���P�̗L�薳���t���O
				int IN_term2,	//���Q�̗L�薳���t���O
				double IN_sun_x1,	//���@���̎n�_
				double IN_sun_y1,	//���@���̎n�_
				double IN_sun_x2,	//���@���̏I�_
				double IN_sun_y2,	//���@���̏I�_
				double IN_tmvec_x1,	//���P�̃x�N�g��X
				double IN_tmvec_y1,	//���P�̃x�N�g��Y
				double IN_tmvec_x2,	//���Q�̃x�N�g��X
				double IN_tmvec_y2	//���Q�̃x�N�g��Y				
			)

{

	double eps;
	double L1;
	double Dim_x,Dim_y;
	double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
	double tm1_L,tm2_L;

	eps = 0.000001;
	m_arr1_code2 = 0;
	m_arr2_code2 = 0;

	//��󂪂Q�̏ꍇ
	if ((IN_term1 != 0)&&(IN_term2 != 0)){
		//���P�A�Q�̕����x�N�g��������O�R�[�h���v�Z����
		//���@���̕����x�N�g�����v�Z����
		//���@���̎n�_����I�_�܂ł̒���
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//���x�N�g���̒P�ʃx�N�g�������߂�B
		tm1_L = fabs(sqrt(pow(IN_tmvec_x1, 2)+pow(IN_tmvec_y1, 2)));
		tmvec_x1 = IN_tmvec_x1 / tm1_L;
		tmvec_y1 = IN_tmvec_y1 / tm1_L;
		tm2_L = fabs(sqrt(pow(IN_tmvec_x2, 2)+pow(IN_tmvec_y2, 2)));
		tmvec_x2 = IN_tmvec_x2 / tm2_L;
		tmvec_y2 = IN_tmvec_y2 / tm2_L;
		//���P�̓��O�R�[�h��ݒ肷��
		//���P�̕����x�N�g�������@���̕����x�N�g���Ɠ������̂Ƃ��A�Q�i�������j�ɐݒ肷��
		if((fabs(tmvec_x1 - Dim_x) < eps )&&( fabs(tmvec_y1 - Dim_y) < eps)){
			m_arr1_code2 = 2;
		}
		//���P�̕����x�N�g�������@���̕����x�N�g���Ɣ��Ε����̂Ƃ��A�P�i�O�����j�ɐݒ肷��
		else if((fabs(tmvec_x1 + Dim_x) < eps) && (fabs(tmvec_y1 + Dim_y) < eps)){
			m_arr1_code2 = 1;
		}

		//���Q�̓��O�R�[�h��ݒ肷��
		//���Q�̕����x�N�g�������@���̕����x�N�g���Ɣ��Ε����̂Ƃ��A�Q�i�������j�ɐݒ肷��
		if((fabs(tmvec_x2 + Dim_x) < eps) && (fabs(tmvec_y2 + Dim_y) < eps)){
			m_arr2_code2 = 2;
		}
		//���Q�̕����x�N�g�������@���̕����x�N�g���Ɠ������̂Ƃ��A�P�i�O�����j�ɐݒ肷��
		else if((fabs(tmvec_x2 - Dim_x) < eps) && (fabs(tmvec_y2 - Dim_y) < eps)){
			m_arr2_code2 = 1;
		}
	}
	//��󂪂ЂƂ̏ꍇ
	else if ((IN_term1 != 0)&&(IN_term2 == 0)){
		//���P�̕����x�N�g��������O�R�[�h���v�Z����
		//���@���̕����x�N�g�����v�Z����
		//���@���̎n�_����I�_�܂ł̒���
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//���x�N�g���̒P�ʃx�N�g�������߂�B
		tm1_L = fabs(sqrt(pow(IN_tmvec_x1, 2)+pow(IN_tmvec_y1, 2)));
		tmvec_x1 = IN_tmvec_x1 / tm1_L;
		tmvec_y1 = IN_tmvec_y1 / tm1_L;
		//���P�̓��O�R�[�h��ݒ肷��
		//���P�̕����x�N�g�������@���̕����x�N�g���Ɠ������̂Ƃ��A�Q�i�������j�ɐݒ肷��
		if((fabs(tmvec_x1 - Dim_x) < eps) && (fabs(tmvec_y1 - Dim_y) < eps)){
			m_arr1_code2 = 2;
		}
		//���P�̕����x�N�g�������@���̕����x�N�g���Ɣ��Ε����̂Ƃ��A�P�i�O�����j�ɐݒ肷��
		else if((fabs(tmvec_x1 + Dim_x) < eps) && (fabs(tmvec_y1 + Dim_y) < eps)){
			m_arr1_code2 = 1;
		}
	}
	else if ((IN_term1 == 0)&&(IN_term2 != 0)){
		//���P�A�Q�̕����x�N�g��������O�R�[�h���v�Z����
		//���@���̕����x�N�g�����v�Z����
		//���@���̎n�_����I�_�܂ł̒���
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//���x�N�g���̒P�ʃx�N�g�������߂�B
		tm2_L = fabs(sqrt(pow(IN_tmvec_x2, 2)+pow(IN_tmvec_y2, 2)));
		tmvec_x2 = IN_tmvec_x2 / tm2_L;
		tmvec_y2 = IN_tmvec_y2 / tm2_L;
		//���Q�̓��O�R�[�h��ݒ肷��
		//���Q�̕����x�N�g�������@���̕����x�N�g���Ɣ��Ε����̂Ƃ��A�Q�i�������j�ɐݒ肷��
		if((fabs(tmvec_x2 + Dim_x) < eps) && (fabs(tmvec_y2 + Dim_y) < eps)){
			m_arr2_code2 = 2;
		}
		//���Q�̕����x�N�g�������@���̕����x�N�g���Ɠ������̂Ƃ��A�P�i�O�����j�ɐݒ肷��
		else if((fabs(tmvec_x2 - Dim_x) < eps) && (fabs(tmvec_y2 - Dim_y) < eps)){
			m_arr2_code2 = 1;
		}
	}

	return TRUE;
}
