/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.h						作成日：2000.04.17

	１．クラス概要
		引出し線フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_LABELC_CLASS_
#define _SXFMapF_LABELC_CLASS_

class SXFMapF_LABELC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_LABELC( );
	~SXFMapF_LABELC( );

	BOOL GetStructData( Label_Struct* INOUT_Struct );

	BOOL SetVertex(
	double IN_arr_x, double IN_arr_y,
	int		IN_number,
	CArray<double,double>& IN_vertex_x,
	CArray<double,double>& IN_vertex_y);


public:
/*
typedef struct Label_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
	int vertex_number;

	CArray<double, double> vertex_x;
	CArray<double, double> vertex_y;
		
	int arr_code;
	double arr_r;
	
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
} Label_Struct;

*/

	int m_vertex_number;
	CArray<double,double> m_vertex_x;
	CArray<double,double> m_vertex_y;

	int m_arr_code;
	double m_arr_r;

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
