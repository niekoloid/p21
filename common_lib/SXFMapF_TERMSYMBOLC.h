/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.h						作成日：2000.04.17

	１．クラス概要
		フィーチャの矢印を管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_TERMSYMBOLC_CLASS_
#define _SXFMapF_TERMSYMBOLC_CLASS_

class SXFMapF_TERMSYMBOLC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_TERMSYMBOLC( );
	~SXFMapF_TERMSYMBOLC( );

//    BOOL GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct );

//	<補助線の端点１，２どちらか？を表わすフラグ設定>
	BOOL Set12flg(CString& IN_name);

public:
/*
//------------------------------------------------
//	寸法端点シンボル
//------------------------------------------------
//＜直線寸法の場合＞
	int		arr1_code1 ;	//矢印１コード
	int		arr1_code2 ;	//矢印１内外コード(０：なし、１：外向き、２：内向き)
	double	arr1_x ;		//矢印１配置始点Ｘ座標
	double	arr1_y ;		//矢印１配置始点Ｙ座標
	double	arr1_r ;		//矢印１配置倍率
*/
//	寸法端点シンボル固有
	int    m_flag;				//矢印１２フラグ（０：初期値,１：端点１側, ２：端点２側)
	int    m_arr_code;			//矢印コード

//	マーカシンボル、外部定義シンボル、寸法端点シンボル共通
	double m_start_x;			//配置位置X座標
	double m_start_y;			//配置位置Y座標
	double m_scale;				//矢印配置倍率

	double m_vecter_x;			//矢印のベクトルX
	double m_vecter_y;			//矢印のベクトルY

};
#endif
