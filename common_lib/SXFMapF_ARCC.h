/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						作成日：2000.04.17

	１．クラス概要
		円弧フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_ARCC_CLASS_
#define _SXFMapF_ARCC_CLASS_

class SXFMapF_ARCC 
	: public SXFMapFeatureBaseC,
	  public SXFMapF_CurveStyleBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_ARCC( );
//	<デストラクタ>
	virtual	~SXFMapF_ARCC( );
	
//	<フィーチャ構造体の取得>
	BOOL GetStructData( Arc_Struct* INOUT_Struct );

public:
/*
typedef struct Arc_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	double	center_x ;			//中心Ｘ座標
	double	center_y ;			//中心Ｙ座標
	double	radius ;			//半径
	int direction;				//向きフラグ
	double start_angle;			//始角
	double end_angle;			//終角
} Arc_Struct;
*/
	double	m_center_x ;			//中心Ｘ座標
	double	m_center_y ;			//中心Ｙ座標
	double	m_radius ;				//半径
	int		m_direction;			//向きフラグ
	double	m_start_angle;			//始角
	double	m_end_angle;			//終角
};
#endif

