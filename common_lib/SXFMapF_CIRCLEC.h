/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�~�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_CIRCLEC_CLASS_
#define _SXFMapF_CIRCLEC_CLASS_

class SXFMapF_CIRCLEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_CIRCLEC( );
	~SXFMapF_CIRCLEC( );

	BOOL GetStructData( Circle_Struct* INOUT_Struct );

public:
/*
typedef struct Circle_StructDF{
	int		layer ;			//���C���R�[�h
	int		color ;			//�F�R�[�h
	int		type ;			//����R�[�h
	int		line_width ;	//�����R�[�h
	double	center_x ;		//���S�w���W
	double	center_y ;		//���S�x���W
	double	radius ;		//���a
} Circle_Struct;
*/
	double	m_center_x ;			//���S�w���W
	double	m_center_y ;			//���S�x���W
	double	m_radius ;				//���a
};
#endif
