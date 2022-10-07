/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.h						作成日：2000.04.17

	１．クラス概要
		文字フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_TEXTSTRINGC_CLASS_
#define _SXFMapF_TEXTSTRINGC_CLASS_

class SXFMapF_TEXTSTRINGC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC
 {
public :
	SXFMapF_TEXTSTRINGC( );
	~SXFMapF_TEXTSTRINGC( );

	BOOL GetStructData( Text_Struct* INOUT_Struct );

//	<文字配置基点フラグの設定>
	BOOL SetBasePoint( CString& IN_name , CString& IN_Alignment );	

//	<文字書き出し方向の設定>
	BOOL SetDirect( CString& IN_Path );	

//	<文字配置位置の算出と設定>
	BOOL  SetXYPoint(double IN_x, double IN_y, double IN_Ascent, double IN_Decent);

public:
/*
//------------------------------------------------
//	文字要素
//------------------------------------------------
typedef struct Text_StructDF{
	int layer;				//レイヤコード
	int color;				//色コード
	int font;				//文字フォントコード
	char str[MAXTEXT];		//文字列
	double text_x;			//文字配置基点Ｘ座標
	double text_y;			//文字配置基点Ｙ座標
	double height;			//文字範囲高
	double width;			//文字範囲幅
	double spc;				//文字間隔
	double angle;			//文字回転角
	double slant;			//スラント角
	int b_pnt;				//文字配置基点
	int direct;				//文字書き出し方向
} Text_Struct;

*/

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
