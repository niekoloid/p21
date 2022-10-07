/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_CURVEDIMC.cpp						�쐬���F2007.01.29

	�P�D�N���X�T�v
		CURVEDIM���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2007.01.29	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFutyFunctionC.h"
#include "SXFMapF_CURVEDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						�쐬���F2007.01.29

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CURVEDIMC::SXFMapF_CURVEDIMC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.29	
**/
SXFMapF_CURVEDIMC::SXFMapF_CURVEDIMC()
{
	m_sun_x = 0.0;
	m_sun_y = 0.0;
	m_sun_radius = 0.0;
	m_sun_angle0 = 0.0;
	m_sun_angle1 = 0.0;
//
	m_flg2 =0;
	m_ho1_x0 = 0.0;
	m_ho1_y0 = 0.0;
	m_ho1_x1 = 0.0;
	m_ho1_y1 = 0.0;
	m_ho1_x2 = 0.0;
	m_ho1_y2 = 0.0;
//
	m_flg3  = 0;
	m_ho2_x0 = 0.0;
	m_ho2_y0 = 0.0;
	m_ho2_x1 = 0.0;
	m_ho2_y1 = 0.0;
	m_ho2_x2 = 0.0;
	m_ho2_y2 = 0.0;
//
	m_arr1_code1 = 0;
	m_arr1_code2  = 0;
	m_arr1_x = 0.0;
	m_arr1_y = 0.0;
	m_arr1_r = 0.0;
//
	m_arr2_code1 = 0;
	m_arr2_code2 = 0;
	m_arr2_x  = 0.0;
	m_arr2_y = 0.0;
	m_arr2_r = 0.0;
//
	m_flg4  = 0;
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
	SXFMapF_CURVEDIMC.cpp						�쐬���F2007.01.29

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CURVEDIMC::~SXFMapF_CURVEDIMC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.29	
**/
SXFMapF_CURVEDIMC::~SXFMapF_CURVEDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						�쐬���F2007.01.29

	�P�D�@�\�T�v
		�\����Data�̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CURVEDIMC::GetStructData()

	���� �F	�^					������			���e
			CURVEDim_Struct* 	INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.29	
**/
BOOL SXFMapF_CURVEDIMC::GetStructData( CurveDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//���C���R�[�h
	INOUT_Struct->color       = m_color ;			//�F�R�[�h
	INOUT_Struct->type        = m_type ;			//����R�[�h
	INOUT_Struct->line_width  = m_line_width ;		//�����R�[�h

	INOUT_Struct->sun_x        = m_sun_x;
	INOUT_Struct->sun_y        = m_sun_y;
	INOUT_Struct->sun_radius   = m_sun_radius;
	INOUT_Struct->sun_angle0   = m_sun_angle0;
	INOUT_Struct->sun_angle1   = m_sun_angle1;

	INOUT_Struct->flg2         = m_flg2;
	INOUT_Struct->ho1_x0       = m_ho1_x0;
	INOUT_Struct->ho1_y0       = m_ho1_y0;
	INOUT_Struct->ho1_x1       = m_ho1_x1;
	INOUT_Struct->ho1_y1       = m_ho1_y1;
	INOUT_Struct->ho1_x2       = m_ho1_x2;
	INOUT_Struct->ho1_y2       = m_ho1_y2;

	INOUT_Struct->flg3         = m_flg3;
	INOUT_Struct->ho2_x0       = m_ho2_x0;
	INOUT_Struct->ho2_y0       = m_ho2_y0;
	INOUT_Struct->ho2_x1       = m_ho2_x1;
	INOUT_Struct->ho2_y1       = m_ho2_y1;
	INOUT_Struct->ho2_x2       = m_ho2_x2;
	INOUT_Struct->ho2_y2       = m_ho2_y2;

	INOUT_Struct->arr1_code1   = m_arr1_code1;
	INOUT_Struct->arr1_code2   = m_arr1_code2;
	INOUT_Struct->arr1_x       = m_arr1_x;
	INOUT_Struct->arr1_y       = m_arr1_y;
	INOUT_Struct->arr1_r       = m_arr1_r;

	INOUT_Struct->arr2_code1   = m_arr2_code1;
	INOUT_Struct->arr2_code2   = m_arr2_code2;
	INOUT_Struct->arr2_x	   = m_arr2_x;
	INOUT_Struct->arr2_y	   = m_arr2_y;
	INOUT_Struct->arr2_r	   = m_arr2_r;

	INOUT_Struct->flg4         = m_flg4;
	INOUT_Struct->font         = m_font;

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

	INOUT_Struct->text_x       = m_text_x;
	INOUT_Struct->text_y       = m_text_y;
	INOUT_Struct->height       = m_height;
	INOUT_Struct->width        = m_width;
	INOUT_Struct->spc          = m_spc;
	INOUT_Struct->angle        = m_angle;
	INOUT_Struct->slant        = m_slant;
	INOUT_Struct->b_pnt        = m_b_pnt;
	INOUT_Struct->direct       = m_direct;

	return TRUE;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						�쐬���F2007.01.29

	�P�D�@�\�T�v
		�����t���O��ݒ肷��

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_CURVEDIMC::SetArrFlag()

	���� �F	�^			������				���e
			int 		IN_term1		���P�̗L�薳���t���O
			int 		IN_term2		���Q�̗L�薳���t���O
			double 		IN_sun_x		���@���̌��_�i�~�ʒ��SX)
			double 		IN_sun_y		���@���̌��_�i�~�ʒ��SY�j
			double 		IN_arr1_x		���P�z�u�_X
			double 		IN_arr1_y		���P�z�u�_Y
			double 		IN_arr2_x		���Q�z�u�_X
			double 		IN_arr2_y		���Q�z�u�_Y				
			double 		IN_tmvec_x1		���P�̃x�N�g��X
			double 		IN_tmvec_y1		���P�̃x�N�g��Y
			double 		IN_tmvec_x2		���Q�̃x�N�g��X
			double 		IN_tmvec_y2		���Q�̃x�N�g��Y	

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2007.01.29	
**/
BOOL SXFMapF_CURVEDIMC::SetArrFlag(  
				int IN_term1,	//���P�̗L�薳���t���O
				int IN_term2,	//���Q�̗L�薳���t���O
				double IN_sun_x,	//���@���̌��_�i�~�ʒ��SX)
				double IN_sun_y,	//���@���̌��_�i�~�ʒ��SY�j
				double IN_arr1_x,	//���P�z�u�_X
				double IN_arr1_y,	//���P�z�u�_Y
				double IN_arr2_x,	//���Q�z�u�_X
				double IN_arr2_y,	//���Q�z�u�_Y				
				double IN_tmvec_x1,	//���P�̃x�N�g��X
				double IN_tmvec_y1,	//���P�̃x�N�g��Y
				double IN_tmvec_x2,	//���Q�̃x�N�g��X
				double IN_tmvec_y2	//���Q�̃x�N�g��Y	
				)

{
	double eps;
	eps = 0.0001;
	m_arr1_code2 = 0;
	m_arr2_code2 = 0;
	
	////���P�A�Q�̕����x�N�g�����v�Z
	double vector1_x,vector1_y,vector2_x,vector2_y;
	//���P�C�Q�Ɛ��@�����_�Ƃ̋���
	double L1,L2;

	double angle1_in,angle1_out,angle2_in,angle2_out,tm1_angle,tm2_angle;
	//��󂪂ӂ��̏ꍇ�B
	if ((IN_term1 != 0)&&(IN_term2 != 0)){

		//���P�C�Q�Ɛ��@�����_�Ƃ̋���
		L1 = fabs(sqrt(pow(IN_arr1_x - IN_sun_x, 2)+pow(IN_arr1_y - IN_sun_y, 2)));
		L2 = fabs(sqrt(pow(IN_arr2_x - IN_sun_x, 2)+pow(IN_arr2_y - IN_sun_y, 2)));
		//���@�����_�Ɩ��P�z�u�ʒu�̃x�N�g��
		vector1_x = (IN_arr1_x - IN_sun_x) / L1;
		vector1_y = (IN_arr1_y - IN_sun_y) / L1;
		//���@�����_�Ɩ��Q�z�u�ʒu�̃x�N�g��
		vector2_x = (IN_arr2_x - IN_sun_x) / L2;
		vector2_y = (IN_arr2_y - IN_sun_y) / L2;

		//���@�����_�Ɩ��P�z�u�ʒu�̃x�N�g���̂Ȃ��p
		angle1_in = SXFutyFunctionC::calc_angle(vector1_x,-vector1_y);
		angle1_out = SXFutyFunctionC::calc_angle(-vector1_x,vector1_y);
		//���@�����_�Ɩ��Q�z�u�ʒu�̃x�N�g���̂Ȃ��p
		angle2_out = SXFutyFunctionC::calc_angle(vector2_x,-vector2_y);
		angle2_in = SXFutyFunctionC::calc_angle(-vector2_x,vector2_y);
		//���P�x�N�g���̂Ȃ��p
		tm1_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y1,IN_tmvec_x1);
		//���Q�x�N�g���̂Ȃ��p
		tm2_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y2,IN_tmvec_x2);

		//���P�̓��O�R�[�h���Q(������)�̏ꍇ(-90)
		if (fabs(tm1_angle - angle1_in) < eps)
			m_arr1_code2 = 2;
		//���P�̓��O�R�[�h���P(�O�����j�̏ꍇ(+90)
		else if (fabs(tm1_angle - angle1_out) < eps)
			m_arr1_code2 = 1;
		//���Q�̓��O�R�[�h���Q�i�������j�̏ꍇ(90)
		if (fabs(tm2_angle - angle2_in) < eps)
			m_arr2_code2 = 2;
		//���Q�̓��O�R�[�h���P�i�O�����j�̏ꍇ(-90)
		else if (fabs(tm2_angle - angle2_out) < eps)
			m_arr2_code2 = 1;
	}
	//��󂪈�̏ꍇ
	////
	else if ((IN_term1 != 0)&&(IN_term2 == 0)){
		//���P�Ɛ��@�����_�Ƃ̋���
		L1 = fabs(sqrt(pow(IN_arr1_x - IN_sun_x, 2)+pow(IN_arr1_x - IN_sun_y, 2)));
		//���@�����_�Ɩ��P�z�u�ʒu�̃x�N�g��
		vector1_x = (IN_arr1_x - IN_sun_x) / L1;
		vector1_y = (IN_arr1_y - IN_sun_y) / L1;
		//���@�����_�Ɩ��P�z�u�ʒu�̃x�N�g���̂Ȃ��p
		angle1_in = SXFutyFunctionC::calc_angle(vector1_x,-vector1_y);
		angle1_out = SXFutyFunctionC::calc_angle(-vector1_x,vector1_y);
		//���P�x�N�g���̂Ȃ��p
		tm1_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y1,IN_tmvec_x1);
		//���P�̓��O�R�[�h���Q(������)�̏ꍇ(-90)
		if (fabs(tm1_angle - angle1_in) < eps)
			m_arr1_code2 = 2;
		//���P�̓��O�R�[�h���P(�O�����j�̏ꍇ(+90)
		else if (fabs(tm1_angle - angle1_out) < eps)
			m_arr1_code2 = 1;
	}

	////��󂪂ЂƂ̏ꍇ
	else if ((IN_term1 == 0)&&(IN_term2 != 0)){
		//���Q�Ɛ��@�����_�Ƃ̋���
		L2 = fabs(sqrt(pow(IN_arr2_x - IN_sun_x, 2)+pow(IN_arr2_x - IN_sun_y, 2)));
		//���@�����_�Ɩ��Q�z�u�ʒu�̃x�N�g��
		vector2_x = (IN_arr2_x - IN_sun_x) / L2;
		vector2_y = (IN_arr2_y - IN_sun_y) / L2;
		//���@�����_�Ɩ��Q�z�u�ʒu�̃x�N�g���̂Ȃ��p
		angle2_out = SXFutyFunctionC::calc_angle(vector2_x,-vector2_y);
		angle2_in = SXFutyFunctionC::calc_angle(-vector2_x,vector2_y);
		//���Q�x�N�g���̂Ȃ��p
		tm2_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y2,IN_tmvec_x2);
		//���Q�̓��O�R�[�h���Q�i�������j�̏ꍇ(90)
		if (fabs(tm2_angle - angle2_in) < eps)
			m_arr2_code2 = 2;
		//���Q�̓��O�R�[�h���P�i�O�����j�̏ꍇ(-90)
		else if (fabs(tm2_angle - angle2_out) < eps)
			m_arr2_code2 = 1;
	}
	return TRUE;
}
