/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.h						作成日：2000.04.17

	１．クラス概要
		ハッチング（ユーザ定義）フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_FILLHATCHINGC_CLASS_
#define _SXFMapF_FILLHATCHINGC_CLASS_

class SXFMapF_FILLHATCHINGC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_FILLHATCHINGC( );
	~SXFMapF_FILLHATCHINGC( );

	BOOL GetStructData( Fill_area_style_hatching_Struct* INOUT_Struct );


public:
/*
typedef struct Fill_area_style_hatching_StructDF{
	int layer;								//レイヤコード
	int hatch_number;						//ハッチング線のパターン数
	int hatch_color[MAXHATCHNUMBER];		//ハッチング線の色コード
	int hatch_type[MAXHATCHNUMBER];			//ハッチング線の線種コード
	int hatch_line_width[MAXHATCHNUMBER];	//ハッチング線の線幅コード
	double hatch_start_x[MAXHATCHNUMBER];	//ハッチング線のパターン開始点X座標
	double hatch_start_y[MAXHATCHNUMBER];	//ハッチング線のパターン開始点Y座標
	double hatch_spacing[MAXHATCHNUMBER];	//ハッチング間隔
	double hatch_angle[MAXHATCHNUMBER];		//ハッチング線の角度
	int out_id;								//外形の複合曲線のフィーチャコード
	int number;								//中抜きの領域数
	CArray<int,int> in_id;					//中抜きの複合曲線のフィーチャコード
} Fill_area_style_hatching_Struct;				
*/
	int m_hatch_number;						//ハッチング線のパターン数
	int m_hatch_color[MAXHATCHNUMBER];		//ハッチング線の色コード
	int m_hatch_type[MAXHATCHNUMBER];			//ハッチング線の線種コード
	int m_hatch_line_width[MAXHATCHNUMBER];	//ハッチング線の線幅コード
	double m_hatch_start_x[MAXHATCHNUMBER];	//ハッチング線のパターン開始点X座標
	double m_hatch_start_y[MAXHATCHNUMBER];	//ハッチング線のパターン開始点Y座標
	double m_hatch_spacing[MAXHATCHNUMBER];	//ハッチング間隔
	double m_hatch_angle[MAXHATCHNUMBER];		//ハッチング線の角度
	int m_out_id;								//外形の複合曲線のフィーチャコード
	int m_number;								//中抜きの領域数
	CArray<int,int> m_in_id;					//中抜きの複合曲線のフィーチャコード

};
#endif
