/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i�h��j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_FILLCOLOURC_CLASS_
#define _SXFMapF_FILLCOLOURC_CLASS_

class SXFMapF_FILLCOLOURC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_FILLCOLOURC( );
	~SXFMapF_FILLCOLOURC( );

	BOOL GetStructData( Fill_area_style_colour_Struct* INOUT_Struct );


public:
/*
typedef struct Fill_area_style_colour_StructDF{
	int layer;
	int color;
	int out_id;
	int number;
	CArray<int,int> in_id;
} Fill_area_style_colour_Struct;
*/

	int m_out_id;
	int m_number;
	CArray<int,int> m_in_id;
};
#endif

