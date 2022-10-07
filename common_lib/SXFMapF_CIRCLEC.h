/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						作成日：2000.04.17

	１．クラス概要
		円フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_CIRCLEC_CLASS_
#define _SXFMapF_CIRCLEC_CLASS_

class SXFMapF_CIRCLEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_CIRCLEC( );
	~SXFMapF_CIRCLEC( );

	BOOL GetStructData( Circle_Struct* INOUT_Struct );

public:
/*
typedef struct Circle_StructDF{
	int		layer ;			//レイヤコード
	int		color ;			//色コード
	int		type ;			//線種コード
	int		line_width ;	//線幅コード
	double	center_x ;		//中心Ｘ座標
	double	center_y ;		//中心Ｙ座標
	double	radius ;		//半径
} Circle_Struct;
*/
	double	m_center_x ;			//中心Ｘ座標
	double	m_center_y ;			//中心Ｙ座標
	double	m_radius ;				//半径
};
#endif
