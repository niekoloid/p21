/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.h						作成日：2000.04.17

	１．クラス概要
		点マーカフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_POINTMARKERC_CLASS_
#define _SXFMapF_POINTMARKERC_CLASS_

class SXFMapF_POINTMARKERC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_POINTMARKERC( );
	~SXFMapF_POINTMARKERC( );

	BOOL GetStructData( Point_Marker_Struct* INOUT_Struct );

public:
/*
//------------------------------------------------
//	点マーカ
//------------------------------------------------
typedef struct Point_Marker_StructDF{
	int layer;				//レイヤコード
	int color;				//色コード
	double start_x;			//配置位置X座標
	double start_y;			//配置位置Y座標
	int marker_code;		//マーカコード
	double rotate_angle;	//回転角
	double scale;			//尺度
} Point_Marker_Struct;
*/
//	マーカシンボル固有
	int    m_marker_code;			//マーカコード

//	マーカシンボル、外部定義シンボル共通
	double m_rotate_angle;			//回転角

//	マーカシンボル、外部定義シンボル、寸法端点シンボル共通
	double m_start_x;				//配置位置X座標
	double m_start_y;				//配置位置Y座標
	double m_scale;					//尺度

};
#endif
