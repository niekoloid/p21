/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		����`�V���{���t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_EXSYMBOLC_CLASS_
#define _SXFMapF_EXSYMBOLC_CLASS_

class SXFMapF_EXSYMBOLC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_EXSYMBOLC( );
	~SXFMapF_EXSYMBOLC( );

	BOOL GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct );

public:
/*
typedef struct Externally_Defined_Symbol_StructDF{
	int layer;						//���C���R�[�h
	int color_flag;					//�F�R�[�h�t���O
	int color;						//�F�R�[�h
	char name[MAXSYMBOLNAME];		//�V���{����
	double start_x;					//�z�u�ʒuX���W
	double start_y;					//�z�u�ʒuY���W
	double rotate_angle;			//��]�p
	double scale;					//�{��
} Externally_Defined_Symbol_Struct;
*/
//	�O����`�V���{���ŗL
	int m_color_flag;					//�F�R�[�h�t���O
	CString m_name;				  	//�V���{����
	
//	�}�[�J�V���{���A�O����`�V���{������
	double m_rotate_angle;			//��]�p

//	�}�[�J�V���{���A�O����`�V���{���A���@�[�_�V���{������
	double m_start_x;				//�z�u�ʒuX���W
	double m_start_y;				//�z�u�ʒuY���W
	double m_scale;					//�{���i�X�P�[��X)
	double m_scale_y;				//�X�P�[��Y

};
#endif
