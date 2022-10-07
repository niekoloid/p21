/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�X�v���C���t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_SPLINEC_CLASS_
#define _SXFMapF_SPLINEC_CLASS_

class SXFMapF_SPLINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_SPLINEC( );
	~SXFMapF_SPLINEC( );

	BOOL GetStructData( Spline_Struct* INOUT_Struct );

public:
/*
typedef struct Spline_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	int open_close;				//�J�敪
	int number;					//���_��
	CArray<double,double> x;	//X���W
	CArray<double, double> y;	//Y���W
} Spline_Struct;
*/
	int m_open_close;			//�J�敪
	int m_number;				//���_��
	CArray<double,double> m_x;	//X���W
	CArray<double, double> m_y;	//Y���W

};
#endif
