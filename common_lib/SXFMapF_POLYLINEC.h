/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POLYLINEC.h						作成日：2000.04.17

	１．クラス概要
		折線フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_POLYLINEC_CLASS_
#define _SXFMapF_POLYLINEC_CLASS_

class SXFMapF_POLYLINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_POLYLINEC( );
	~SXFMapF_POLYLINEC( );

	BOOL GetStructData( Polyline_Struct* INOUT_Struct );

public:
/*
typedef struct Polyline_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	int number;					//頂点数
	CArray<double,double> x;	//X座標
	CArray<double, double> y;	//Y座標
} Polyline_Struct;
*/
	int m_number;					//頂点数
	CArray<double,double> m_x;	//X座標
	CArray<double, double> m_y;	//Y座標

};
#endif

