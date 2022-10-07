/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i���[�U��`�j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_FILLHATCHINGC_CLASS_
#define _SXFMapF_FILLHATCHINGC_CLASS_

class SXFMapF_FILLHATCHINGC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_FILLHATCHINGC( );
	~SXFMapF_FILLHATCHINGC( );

	BOOL GetStructData( Fill_area_style_hatching_Struct* INOUT_Struct );


public:
/*
typedef struct Fill_area_style_hatching_StructDF{
	int layer;								//���C���R�[�h
	int hatch_number;						//�n�b�`���O���̃p�^�[����
	int hatch_color[MAXHATCHNUMBER];		//�n�b�`���O���̐F�R�[�h
	int hatch_type[MAXHATCHNUMBER];			//�n�b�`���O���̐���R�[�h
	int hatch_line_width[MAXHATCHNUMBER];	//�n�b�`���O���̐����R�[�h
	double hatch_start_x[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_X���W
	double hatch_start_y[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_Y���W
	double hatch_spacing[MAXHATCHNUMBER];	//�n�b�`���O�Ԋu
	double hatch_angle[MAXHATCHNUMBER];		//�n�b�`���O���̊p�x
	int out_id;								//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int number;								//�������̗̈搔
	CArray<int,int> in_id;					//�������̕����Ȑ��̃t�B�[�`���R�[�h
} Fill_area_style_hatching_Struct;				
*/
	int m_hatch_number;						//�n�b�`���O���̃p�^�[����
	int m_hatch_color[MAXHATCHNUMBER];		//�n�b�`���O���̐F�R�[�h
	int m_hatch_type[MAXHATCHNUMBER];			//�n�b�`���O���̐���R�[�h
	int m_hatch_line_width[MAXHATCHNUMBER];	//�n�b�`���O���̐����R�[�h
	double m_hatch_start_x[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_X���W
	double m_hatch_start_y[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_Y���W
	double m_hatch_spacing[MAXHATCHNUMBER];	//�n�b�`���O�Ԋu
	double m_hatch_angle[MAXHATCHNUMBER];		//�n�b�`���O���̊p�x
	int m_out_id;								//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int m_number;								//�������̗̈搔
	CArray<int,int> m_in_id;					//�������̕����Ȑ��̃t�B�[�`���R�[�h

};
#endif
