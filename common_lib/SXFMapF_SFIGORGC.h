/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����}�`��`�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_SFIGORGC_CLASS_
#define _SXFMapF_SFIGORGC_CLASS_

class SXFMapF_SFIGORGC : 
	public SXFMapFeatureBaseC {
public :
	SXFMapF_SFIGORGC( );
	~SXFMapF_SFIGORGC( );

	BOOL GetStructData( Sfigorg_Struct* INOUT_Struct );

	BOOL SetSubName(CString IN_name);

public:
/*
//------------------------------------------------
//	�����}�`��`
//------------------------------------------------
typedef struct Sfigorg_StructDF{
	char name[MAXFIGURENAME];
	int flag;
} Sfigorg_Struct;

*/

	CString m_name;
	int m_flag;

};
#endif
