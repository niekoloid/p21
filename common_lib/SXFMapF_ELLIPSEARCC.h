/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEARCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�ȉ~�ʃt�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_ELLIPSEARCC_CLASS_
#define _SXFMapF_ELLIPSEARCC_CLASS_

class SXFMapF_ELLIPSEARCC : public SXFMapFeatureBaseC,
	  public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_ELLIPSEARCC( );
	~SXFMapF_ELLIPSEARCC( );

	BOOL GetStructData( Ellipse_Arc_Struct* INOUT_Struct );

public:
/*
typedef struct Ellipse_Arc_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius_x ;			//X�������a
	double	radius_y ;			//Y�������a
	int direction;				//�����t���O
	double rotation_angle;		//��]�p
	double start_angle;			//�n�p
	double end_angle;			//�I�p
} Ellipse_Arc_Struct;
*/
	double	m_center_x ;			//���S�w���W
	double	m_center_y ;			//���S�x���W
	double	m_radius_x ;			//X�������a
	double	m_radius_y ;			//Y�������a
	int		m_direction;			//�����t���O
	double	m_rotation_angle;		//��]�p
	double	m_start_angle;			//�n�p
	double	m_end_angle;			//�I�p
};
#endif
