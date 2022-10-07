/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINERDIMC.h						作成日：2000.04.17

	１．クラス概要
		直線寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_LINERDIMC_CLASS_
#define _SXFMapF_LINERDIMC_CLASS_

class SXFMapF_LINERDIMC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_LINERDIMC( );
	~SXFMapF_LINERDIMC( );

	BOOL GetStructData( LinearDim_Struct* INOUT_Struct );

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
//------------------------------------------------
//	直線寸法
//------------------------------------------------
typedef struct LinearDim_StructDF{
	int		layer ;			//レイヤコード
	int		color ;			//色コード
	int		type ;			//線種コード
	int		line_width ;	//線幅コード

	double	sun_x1 ;		//寸法線始点Ｘ座標
	double	sun_y1 ;		//寸法線始点Ｙ座標
	double	sun_x2 ;		//寸法線終点Ｘ座標
	double	sun_y2 ;		//寸法線終点Ｙ座標

	int		flg2 ;			//補助線１の有無フラグ(０：無、１：有)
	double	ho1_x0 ;		//補助線１基点Ｘ座標
	double	ho1_y0 ;		//補助線１基点Ｙ座標
	double	ho1_x1 ;		//補助線１基点Ｘ座標
	double	ho1_y1 ;		//補助線１基点Ｙ座標
	double	ho1_x2 ;		//補助線１基点Ｘ座標
	double	ho1_y2 ;		//補助線１基点Ｙ座標

	int		flg3 ;			//補助線２の有無フラグ(０：無、１：有)
	double	ho2_x0 ;		//補助線２基点Ｘ座標
	double	ho2_y0 ;		//補助線２基点Ｙ座標
	double	ho2_x1 ;		//補助線２基点Ｘ座標
	double	ho2_y1 ;		//補助線２基点Ｙ座標
	double	ho2_x2 ;		//補助線２基点Ｘ座標
	double	ho2_y2 ;		//補助線２基点Ｙ座標

	int		arr1_code1 ;	//矢印１コード
	int		arr1_code2 ;	//矢印１内外コード(０：なし、１：外向き、２：内向き)
	double	arr1_x ;		//矢印１配置始点Ｘ座標
	double	arr1_y ;		//矢印１配置始点Ｙ座標
	double	arr1_r ;		//矢印１配置倍率

	int		arr2_code1 ;	//矢印２コード
	int		arr2_code2 ;	//矢印２内外コード(０：なし、１：外向き、２：内向き)
	double	arr2_x ;		//矢印２配置始点Ｘ座標
	double	arr2_y ;		//矢印２配置始点Ｙ座標
	double	arr2_r ;		//矢印２配置倍率

	int		flg4 ;			//寸法値の有無フラグ(０：無、１：有)
	int		font ;			//文字フォントコード
	char	str[MAXTEXT] ;	//文字列
	double	text_x ;		//文字列配置基点Ｘ座標
	double	text_y ;		//文字列配置基点Ｙ座標
	double	height ;		//文字範囲高
	double	width ;			//文字範囲幅
	double	spc ;			//文字間隔
	double	angle ;			//文字列回転角
	double	slant ;			//スラント角度
	int		b_pnt ;			//文字配置基点(１：左下、２：中下、３：右下、４：左中、５：中中、６：右中、７：左上、８：中上、９右上：)
	int		direct ;		//文字書出し方向(１：横書き、２：縦書き)
} LinearDim_Struct;

*/

	double	m_sun_x1 ;		//寸法線始点Ｘ座標
	double	m_sun_y1 ;		//寸法線始点Ｙ座標
	double	m_sun_x2 ;		//寸法線終点Ｘ座標
	double	m_sun_y2 ;		//寸法線終点Ｙ座標
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
