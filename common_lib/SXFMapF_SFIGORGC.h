/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.h						作成日：2000.04.17

	１．クラス概要
		複合図形定義フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
//	複合図形定義
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
