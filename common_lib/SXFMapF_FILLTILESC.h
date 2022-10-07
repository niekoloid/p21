/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i�p�^�[���j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_FILLTILESC_CLASS_
#define _SXFMapF_FILLTILESC_CLASS_

class SXFMapF_FILLTILESC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_FILLTILESC( );
	~SXFMapF_FILLTILESC( );

	BOOL GetStructData( Fill_area_style_tiles_Struct* INOUT_Struct );

public:
/*
typedef struct Fill_area_style_tiles_Struct{
	int layer;								//���C���R�[�h
	char name[MAXPRESYMBOLNAME];			//����`�V���{����
	int hatch_color;						//�n�b�`�p�^�[���̐F�R�[�h
	double hatch_pattern_x;					//�n�b�`�p�^�[���z�u�ʒuX���W
	double hatch_pattern_y;					//�n�b�`�p�^�[���z�u�ʒuY���W
	double hatch_pattern_vector1;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̑傫��
	double hatch_pattern_vector1_angle;		//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x
	double hatch_pattern_vector2;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̑傫��
	double hatch_pattern_vector2_angle;		//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̊p�x
	double hatch_pattern_scale_x;			//�n�b�`�p�^�[����X�ړx
	double hatch_pattern_scale_y;			//�n�b�`�p�^�[����Y�ړx
	double hatch_pattern_angle;				//�n�b�`�p�^�[���̌����̊p�x
	int out_id;								//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int number;								//�������̕̈搔
	CArray<int,int> in_id;					//�������̕����Ȑ��̃t�B�[�`���R�[�h
} Fill_area_style_tiles_Struct;

*/

	CString m_name;							//����`�V���{����
	int m_hatch_color;						//�n�b�`�p�^�[���̐F�R�[�h
	double m_hatch_pattern_x;				//�n�b�`�p�^�[���z�u�ʒuX���W
	double m_hatch_pattern_y;				//�n�b�`�p�^�[���z�u�ʒuY���W
	double m_hatch_pattern_vector1;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̑傫��
	double m_hatch_pattern_vector1_angle;	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x
	double m_hatch_pattern_vector2;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̑傫��
	double m_hatch_pattern_vector2_angle;	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̊p�x
	double m_hatch_pattern_scale_x;			//�n�b�`�p�^�[����X�ړx
	double m_hatch_pattern_scale_y;			//�n�b�`�p�^�[����Y�ړx
	double m_hatch_pattern_angle;			//�n�b�`�p�^�[���̌����̊p�x
	int m_out_id;							//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int m_number;							//�������̕̈搔
	CArray<int,int> m_in_id;				//�������̕����Ȑ��̃t�B�[�`���R�[�h

};
#endif
