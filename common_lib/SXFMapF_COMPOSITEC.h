/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����Ȑ��t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_COMPOSITEC_CLASS_
#define _SXFMapF_COMPOSITEC_CLASS_

class SXFMapF_COMPOSITEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_COMPOSITEC( );
	~SXFMapF_COMPOSITEC( );

	BOOL GetStructData( Ccurve_Org_Struct* INOUT_Struct );

public:
/*
//------------------------------------------------
//	�����Ȑ�
//------------------------------------------------
typedef struct Ccurve_Org_StructDF{
	int color;			//�F�R�[�h
	int type;			//����R�[�h
	int line_width;		//�����R�[�h
	int flag;			//�\��/��\���t���O
} Ccurve_Org_Struct;

*/

	int m_flag;			//�\��/��\���t���O

};
#endif
