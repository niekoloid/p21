/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.h						作成日：2000.04.17

	１．クラス概要
		直径寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_DIMETERDIMC_CLASS_
#define _SXFMapF_DIMETERDIMC_CLASS_

class SXFMapF_DIMETERDIMC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_DIMETERDIMC( );
	~SXFMapF_DIMETERDIMC( );

	BOOL GetStructData( DiameterDim_Struct* INOUT_Struct );

	BOOL SetArrFlag(  
				int IN_term1,	//矢印１の有り無しフラグ
				int IN_term2,	//矢印２の有り無しフラグ
				double IN_sun_x1,	//寸法線の始点
				double IN_sun_y1,	//寸法線の終点
				double IN_sun_x2,	//寸法線の始点
				double IN_sun_y2,	//寸法線の終点
				double IN_tmvec_x1,	//矢印１のベクトルX
				double IN_tmvec_y1,	//矢印１のベクトルY
				double IN_tmvec_x2,	//矢印２のベクトルX
				double IN_tmvec_y2	//矢印２のベクトルY	
				);


public:
/*
typedef struct DiameterDim_StructDF{

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
} DiameterDim_Struct;
*/
	double m_sun_x1;
	double m_sun_y1;
	double m_sun_x2;
	double m_sun_y2;
//
	int m_arr1_code1;
	int m_arr1_code2;
	double m_arr1_x;
	double m_arr1_y;
	double m_arr1_r;
//
	int m_arr2_code1;
	int m_arr2_code2;
	double m_arr2_x;
	double m_arr2_y;
	double m_arr2_r;

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
