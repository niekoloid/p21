/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINERDIMC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�������@�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_LINERDIMC_CLASS_
#define _SXFMapF_LINERDIMC_CLASS_

class SXFMapF_LINERDIMC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_LINERDIMC( );
	~SXFMapF_LINERDIMC( );

	BOOL GetStructData( LinearDim_Struct* INOUT_Struct );

	BOOL SetArrFlag(
				int IN_term1,	//���P�̗L�薳���t���O
				int IN_term2,	//���Q�̗L�薳���t���O
				double IN_sun_x1,	//���@���̎n�_
				double IN_sun_y1,	//���@���̏I�_
				double IN_sun_x2,	//���@���̎n�_
				double IN_sun_y2,	//���@���̏I�_
				double IN_tmvec_x1,	//���P�̃x�N�g��X
				double IN_tmvec_y1,	//���P�̃x�N�g��Y
				double IN_tmvec_x2,	//���Q�̃x�N�g��X
				double IN_tmvec_y2	//���Q�̃x�N�g��Y	
				);

public:
/*
//------------------------------------------------
//	�������@
//------------------------------------------------
typedef struct LinearDim_StructDF{
	int		layer ;			//���C���R�[�h
	int		color ;			//�F�R�[�h
	int		type ;			//����R�[�h
	int		line_width ;	//�����R�[�h

	double	sun_x1 ;		//���@���n�_�w���W
	double	sun_y1 ;		//���@���n�_�x���W
	double	sun_x2 ;		//���@���I�_�w���W
	double	sun_y2 ;		//���@���I�_�x���W

	int		flg2 ;			//�⏕���P�̗L���t���O(�O�F���A�P�F�L)
	double	ho1_x0 ;		//�⏕���P��_�w���W
	double	ho1_y0 ;		//�⏕���P��_�x���W
	double	ho1_x1 ;		//�⏕���P��_�w���W
	double	ho1_y1 ;		//�⏕���P��_�x���W
	double	ho1_x2 ;		//�⏕���P��_�w���W
	double	ho1_y2 ;		//�⏕���P��_�x���W

	int		flg3 ;			//�⏕���Q�̗L���t���O(�O�F���A�P�F�L)
	double	ho2_x0 ;		//�⏕���Q��_�w���W
	double	ho2_y0 ;		//�⏕���Q��_�x���W
	double	ho2_x1 ;		//�⏕���Q��_�w���W
	double	ho2_y1 ;		//�⏕���Q��_�x���W
	double	ho2_x2 ;		//�⏕���Q��_�w���W
	double	ho2_y2 ;		//�⏕���Q��_�x���W

	int		arr1_code1 ;	//���P�R�[�h
	int		arr1_code2 ;	//���P���O�R�[�h(�O�F�Ȃ��A�P�F�O�����A�Q�F������)
	double	arr1_x ;		//���P�z�u�n�_�w���W
	double	arr1_y ;		//���P�z�u�n�_�x���W
	double	arr1_r ;		//���P�z�u�{��

	int		arr2_code1 ;	//���Q�R�[�h
	int		arr2_code2 ;	//���Q���O�R�[�h(�O�F�Ȃ��A�P�F�O�����A�Q�F������)
	double	arr2_x ;		//���Q�z�u�n�_�w���W
	double	arr2_y ;		//���Q�z�u�n�_�x���W
	double	arr2_r ;		//���Q�z�u�{��

	int		flg4 ;			//���@�l�̗L���t���O(�O�F���A�P�F�L)
	int		font ;			//�����t�H���g�R�[�h
	char	str[MAXTEXT] ;	//������
	double	text_x ;		//������z�u��_�w���W
	double	text_y ;		//������z�u��_�x���W
	double	height ;		//�����͈͍�
	double	width ;			//�����͈͕�
	double	spc ;			//�����Ԋu
	double	angle ;			//�������]�p
	double	slant ;			//�X�����g�p�x
	int		b_pnt ;			//�����z�u��_(�P�F�����A�Q�F�����A�R�F�E���A�S�F�����A�T�F�����A�U�F�E���A�V�F����A�W�F����A�X�E��F)
	int		direct ;		//�������o������(�P�F�������A�Q�F�c����)
} LinearDim_Struct;

*/

	double	m_sun_x1 ;		//���@���n�_�w���W
	double	m_sun_y1 ;		//���@���n�_�x���W
	double	m_sun_x2 ;		//���@���I�_�w���W
	double	m_sun_y2 ;		//���@���I�_�x���W
//

	int    m_flg2;
	double m_ho1_x0;
	double m_ho1_y0;
	double m_ho1_x1;
	double m_ho1_y1;
	double m_ho1_x2;
	double m_ho1_y2;
//

	int    m_flg3;
	double m_ho2_x0;
	double m_ho2_y0;
	double m_ho2_x1;
	double m_ho2_y1;
	double m_ho2_x2;
	double m_ho2_y2;
//
	int    m_arr1_code1;
	int    m_arr1_code2;
	double m_arr1_x;
	double m_arr1_y;
	double m_arr1_r;
//
	int    m_arr2_code1;
	int    m_arr2_code2;
	double m_arr2_x;
	double m_arr2_y;
	double m_arr2_r;
//
	int    m_flg4;
	int    m_font;
	CString m_str;
	double m_text_x;
	double m_text_y;
	double m_height;
	double m_width;
	double m_spc;
	double m_angle;
	double m_slant;
	int    m_b_pnt;
	int    m_direct;

};
#endif
