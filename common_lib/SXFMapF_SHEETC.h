/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SHEETC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�p���t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_SHEETC_CLASS_
#define _SXFMapF_SHEETC_CLASS_

class SXFMapF_SHEETC : 
	public SXFMapFeatureBaseC {
public :
	SXFMapF_SHEETC( );
	~SXFMapF_SHEETC( );

	BOOL GetStructData( Sheet_Struct* INOUT_Struct );

public:
/*

//------------------------------------------------
//	�p��
//------------------------------------------------
typedef struct Sheet_StructDF{
	char name[MAXSHEETNAME];
	int type;
	int orient;
	int x;
	int y;
} Sheet_Struct;

*/

	CString m_name;
	int m_type;
	int m_orient;
	int m_int_x;
	int m_int_y;

};
#endif
