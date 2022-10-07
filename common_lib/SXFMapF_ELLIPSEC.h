/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ELLIPSEC.h						作成日：2000.04.17

	１．クラス概要
		楕円フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_ELLIPSEC_CLASS_
#define _SXFMapF_ELLIPSEC_CLASS_

class SXFMapF_ELLIPSEC :
	 public SXFMapFeatureBaseC,
	 public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_ELLIPSEC( );
	virtual ~SXFMapF_ELLIPSEC( );

	BOOL GetStructData( Ellipse_Struct* INOUT_Struct );

public:
/*
typedef struct Ellipse_StructDF{

	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	double	center_x ;			//中心Ｘ座標
	double	center_y ;			//中心Ｙ座標
	double	radius_x ;			//X方向半径
	double	radius_y ;			//Y方向半径
	double rotation_angle;		//回転角
} Ellipse_Struct;
*/
	double	m_center_x ;			//中心Ｘ座標
	double	m_center_y ;			//中心Ｙ座標
	double	m_radius_x ;			//X方向半径
	double	m_radius_y ;			//Y方向半径
	double	m_rotation_angle;		//回転角
};
#endif
