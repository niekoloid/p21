/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.h						作成日：2000.04.17

	１．クラス概要
		スプラインフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_SPLINEC_CLASS_
#define _SXFMapF_SPLINEC_CLASS_

class SXFMapF_SPLINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_SPLINEC( );
	~SXFMapF_SPLINEC( );

	BOOL GetStructData( Spline_Struct* INOUT_Struct );

public:
/*
typedef struct Spline_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	int open_close;				//開閉区分
	int number;					//頂点数
	CArray<double,double> x;	//X座標
	CArray<double, double> y;	//Y座標
} Spline_Struct;
*/
	int m_open_close;			//開閉区分
	int m_number;				//頂点数
	CArray<double,double> m_x;	//X座標
	CArray<double, double> m_y;	//Y座標

};
#endif
