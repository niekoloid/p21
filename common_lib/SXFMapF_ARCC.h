/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�~�ʃt�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_ARCC_CLASS_
#define _SXFMapF_ARCC_CLASS_

class SXFMapF_ARCC 
	: public SXFMapFeatureBaseC,
	  public SXFMapF_CurveStyleBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_ARCC( );
//	<�f�X�g���N�^>
	virtual	~SXFMapF_ARCC( );
	
//	<�t�B�[�`���\���̂̎擾>
	BOOL GetStructData( Arc_Struct* INOUT_Struct );

public:
/*
typedef struct Arc_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius ;			//���a
	int direction;				//�����t���O
	double start_angle;			//�n�p
	double end_angle;			//�I�p
} Arc_Struct;
*/
	double	m_center_x ;			//���S�w���W
	double	m_center_y ;			//���S�x���W
	double	m_radius ;				//���a
	int		m_direction;			//�����t���O
	double	m_start_angle;			//�n�p
	double	m_end_angle;			//�I�p
};
#endif

