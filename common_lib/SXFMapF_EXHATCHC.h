/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.h						作成日：2000.04.17

	１．クラス概要
		ハッチング（既定義）フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_EXHATCHC_CLASS_
#define _SXFMapF_EXHATCHC_CLASS_

class SXFMapF_EXHATCHC : 
	public SXFMapFeatureBaseC ,
	public SXFMapF_LayerBaseC{
public :
	SXFMapF_EXHATCHC( );
	~SXFMapF_EXHATCHC( );

	BOOL GetStructData( Externally_Defined_Hatch_Struct* INOUT_Struct );

public:
/*
typedef struct Externally_Defined_Hatch_StructDF{
	int layer;
	char name[MAXHATCHNAME];
	int out_id;
	int number;
	CArray<int, int> in_id;
} Externally_Defined_Hatch_Struct;
*/

	CString m_name;				  	//ハッチング名
	int m_out_id;
	int m_number;
	CArray<int,int> m_in_id;
};
#endif

