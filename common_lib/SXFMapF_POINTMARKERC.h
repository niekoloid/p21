/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�_�}�[�J�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_POINTMARKERC_CLASS_
#define _SXFMapF_POINTMARKERC_CLASS_

class SXFMapF_POINTMARKERC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_POINTMARKERC( );
	~SXFMapF_POINTMARKERC( );

	BOOL GetStructData( Point_Marker_Struct* INOUT_Struct );

public:
/*
//------------------------------------------------
//	�_�}�[�J
//------------------------------------------------
typedef struct Point_Marker_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	double start_x;			//�z�u�ʒuX���W
	double start_y;			//�z�u�ʒuY���W
	int marker_code;		//�}�[�J�R�[�h
	double rotate_angle;	//��]�p
	double scale;			//�ړx
} Point_Marker_Struct;
*/
//	�}�[�J�V���{���ŗL
	int    m_marker_code;			//�}�[�J�R�[�h

//	�}�[�J�V���{���A�O����`�V���{������
	double m_rotate_angle;			//��]�p

//	�}�[�J�V���{���A�O����`�V���{���A���@�[�_�V���{������
	double m_start_x;				//�z�u�ʒuX���W
	double m_start_y;				//�z�u�ʒuY���W
	double m_scale;					//�ړx

};
#endif
