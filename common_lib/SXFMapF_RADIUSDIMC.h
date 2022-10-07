/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.h						作成日：2000.04.17

	１．クラス概要
		半径寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_RADIUSDIMC_CLASS_
#define _SXFMapF_RADIUSDIMC_CLASS_

class SXFMapF_RADIUSDIMC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_RADIUSDIMC( );
	~SXFMapF_RADIUSDIMC( );

    BOOL GetStructData( RadiusDim_Struct* INOUT_Struct );

	BOOL SetArrFlag(  
				int IN_term1,	//矢印の有り無しフラグ
				double IN_sun_x1,	//寸法線の始点
				double IN_sun_y1,	//寸法線の始点
				double IN_sun_x2,	//寸法線の終点
				double IN_sun_y2,	//寸法線の終点
				double IN_tmvec_x,	//矢印１のベクトルX
				double IN_tmvec_y	//矢印１のベクトルY
			);


public:
/*
typedef struct RadiusDim_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
//
	double sun_x1;
	double sun_y1;
	double sun_x2;
	double sun_y2;
//
	int arr_code1;
	int arr_code2;
	double arr_x;
	double arr_y;
	double arr_r;
//
	int flg;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;
} RadiusDim_Struct;
*/
	double m_sun_x1;
	double m_sun_y1;
	double m_sun_x2;
	double m_sun_y2;
//
	int m_arr_code1;
	int m_arr_code2;
	double m_arr_x;
	double m_arr_y;
	double m_arr_r;
//
	int m_flg;
	int m_font;
	CString m_str;
	double m_text_x;
	double m_text_y;
	double m_height;
	double m_width;
	double m_spc;
	double m_angle;
	double m_slant;
	int m_b_pnt;
	int m_direct;

};
#endif

