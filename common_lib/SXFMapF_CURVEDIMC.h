/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.h						作成日：2000.04.17

	１．クラス概要
		弧長寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_CURVEDIMC_CLASS_
#define _SXFMapF_CURVEDIMC_CLASS_

class SXFMapF_CURVEDIMC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC	{
public :
	SXFMapF_CURVEDIMC( );
	~SXFMapF_CURVEDIMC( );

	BOOL GetStructData( CurveDim_Struct* INOUT_Struct );

// 弧長寸法の向きフラグを設定する
	BOOL SetArrFlag(  
				int IN_term1,	//矢印１の有り無しフラグ
				int IN_term2,	//矢印２の有り無しフラグ
				double IN_sun_x,	//寸法線の原点（円弧中心X)
				double IN_sun_y,	//寸法線の原点（円弧中心Y）
				double IN_arr1_x,	//矢印１配置点X
				double IN_arr1_y,	//矢印１配置点Y
				double IN_arr2_x,	//矢印２配置点X
				double IN_arr2_y,	//矢印２配置点Y				
				double IN_tmvec_x1,	//矢印１のベクトルX
				double IN_tmvec_y1,	//矢印１のベクトルY
				double IN_tmvec_x2,	//矢印２のベクトルX
				double IN_tmvec_y2	//矢印２のベクトルY	
				);

public:
/*
typedef struct CurveDim_StructDF{

	int layer;
	int color;
	int type;
	int line_width;

	double sun_x;
	double sun_y;
	double sun_radius;
	double sun_angle0;
	double sun_angle1;
//
	int flg2;
	double ho1_x0;
	double ho1_y0;
	double ho1_x1;
	double ho1_y1;
	double ho1_x2;
	double ho1_y2;
//

	int flg3;
	double ho2_x0;
	double ho2_y0;
	double ho2_x1;
	double ho2_y1;
	double ho2_x2;
	double ho2_y2;
//
	int arr1_code1;
	int arr1_code2;
	double arr1_x;
	double arr1_y;
	double arr1_r;
//
	int arr2_code1;
	int arr2_code2;
	double arr2_x;
	double arr2_y;
	double arr2_r;
//
	int flg4;
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

} CurveDim_Struct;
*/

	double m_sun_x;
	double m_sun_y;
	double m_sun_radius;
	double m_sun_angle0;
	double m_sun_angle1;
//
	int    m_flg2;
	double m_ho1_x0;
	double m_ho1_y0;
	double m_ho1_x1;
	double m_ho1_y1;
	double m_ho1_x2;
	double m_ho1_y2;
//

	int    m_flg3;
	double m_ho2_x0;
	double m_ho2_y0;
	double m_ho2_x1;
	double m_ho2_y1;
	double m_ho2_x2;
	double m_ho2_y2;
//
	int    m_arr1_code1;
	int    m_arr1_code2;
	double m_arr1_x;
	double m_arr1_y;
	double m_arr1_r;
//
	int    m_arr2_code1;
	int    m_arr2_code2;
	double m_arr2_x;
	double m_arr2_y;
	double m_arr2_r;
//
	int    m_flg4;
	int    m_font;
	CString m_str;
	double m_text_x;
	double m_text_y;
	double m_height;
	double m_width;
	double m_spc;
	double m_angle;
	double m_slant;
	int    m_b_pnt;
	int    m_direct;

};
#endif
