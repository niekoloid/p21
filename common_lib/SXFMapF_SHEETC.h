/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SHEETC.h						作成日：2000.04.17

	１．クラス概要
		用紙フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
//	用紙
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
