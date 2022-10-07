/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�ȉ~�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_ELLIPSEC_CLASS_
#define _SXFMapF_ELLIPSEC_CLASS_

class SXFMapF_ELLIPSEC :
	 public SXFMapFeatureBaseC,
	 public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_ELLIPSEC( );
	virtual ~SXFMapF_ELLIPSEC( );

	BOOL GetStructData( Ellipse_Struct* INOUT_Struct );

public:
/*
typedef struct Ellipse_StructDF{

	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius_x ;			//X�������a
	double	radius_y ;			//Y�������a
	double rotation_angle;		//��]�p
} Ellipse_Struct;
*/
	double	m_center_x ;			//���S�w���W
	double	m_center_y ;			//���S�x���W
	double	m_radius_x ;			//X�������a
	double	m_radius_y ;			//Y�������a
	double	m_rotation_angle;		//��]�p
};
#endif
