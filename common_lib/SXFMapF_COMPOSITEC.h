/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.h						作成日：2000.04.17

	１．クラス概要
		複合曲線フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
//	複合曲線
//------------------------------------------------
typedef struct Ccurve_Org_StructDF{
	int color;			//色コード
	int type;			//線種コード
	int line_width;		//線幅コード
	int flag;			//表示/非表示フラグ
} Ccurve_Org_Struct;

*/

	int m_flag;			//表示/非表示フラグ

};
#endif
