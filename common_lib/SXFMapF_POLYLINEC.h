/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POLYLINEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�ܐ��t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_POLYLINEC_CLASS_
#define _SXFMapF_POLYLINEC_CLASS_

class SXFMapF_POLYLINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_POLYLINEC( );
	~SXFMapF_POLYLINEC( );

	BOOL GetStructData( Polyline_Struct* INOUT_Struct );

public:
/*
typedef struct Polyline_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	int number;					//���_��
	CArray<double,double> x;	//X���W
	CArray<double, double> y;	//Y���W
} Polyline_Struct;
*/
	int m_number;					//���_��
	CArray<double,double> m_x;	//X���W
	CArray<double, double> m_y;	//Y���W

};
#endif

