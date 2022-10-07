/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_TEXTSTRINGC_CLASS_
#define _SXFMapF_TEXTSTRINGC_CLASS_

class SXFMapF_TEXTSTRINGC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC
 {
public :
	SXFMapF_TEXTSTRINGC( );
	~SXFMapF_TEXTSTRINGC( );

	BOOL GetStructData( Text_Struct* INOUT_Struct );

//	<�����z�u��_�t���O�̐ݒ�>
	BOOL SetBasePoint( CString& IN_name , CString& IN_Alignment );	

//	<���������o�������̐ݒ�>
	BOOL SetDirect( CString& IN_Path );	

//	<�����z�u�ʒu�̎Z�o�Ɛݒ�>
	BOOL  SetXYPoint(double IN_x, double IN_y, double IN_Ascent, double IN_Decent);

public:
/*
//------------------------------------------------
//	�����v�f
//------------------------------------------------
typedef struct Text_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	int font;				//�����t�H���g�R�[�h
	char str[MAXTEXT];		//������
	double text_x;			//�����z�u��_�w���W
	double text_y;			//�����z�u��_�x���W
	double height;			//�����͈͍�
	double width;			//�����͈͕�
	double spc;				//�����Ԋu
	double angle;			//������]�p
	double slant;			//�X�����g�p
	int b_pnt;				//�����z�u��_
	int direct;				//���������o������
} Text_Struct;

*/

	int m_font;
	CString m_str;
	double m_text_x;
	double m_text_y;
	double m_height;
	double m_width;
	double m_spc;
	double m_angle;
	double m_slant;
	int m_b_pnt;
	int m_direct;

};
#endif
