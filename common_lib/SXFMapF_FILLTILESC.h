/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLTILESC.h						作成日：2000.04.17

	１．クラス概要
		ハッチング（パターン）フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_FILLTILESC_CLASS_
#define _SXFMapF_FILLTILESC_CLASS_

class SXFMapF_FILLTILESC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_FILLTILESC( );
	~SXFMapF_FILLTILESC( );

	BOOL GetStructData( Fill_area_style_tiles_Struct* INOUT_Struct );

public:
/*
typedef struct Fill_area_style_tiles_Struct{
	int layer;								//レイヤコード
	char name[MAXPRESYMBOLNAME];			//既定義シンボル名
	int hatch_color;						//ハッチパターンの色コード
	double hatch_pattern_x;					//ハッチパターン配置位置X座標
	double hatch_pattern_y;					//ハッチパターン配置位置Y座標
	double hatch_pattern_vector1;			//ハッチパターンの繰り返しベクトル１の大きさ
	double hatch_pattern_vector1_angle;		//ハッチパターンの繰り返しベクトル１の角度
	double hatch_pattern_vector2;			//ハッチパターンの繰り返しベクトル２の大きさ
	double hatch_pattern_vector2_angle;		//ハッチパターンの繰り返しベクトル２の角度
	double hatch_pattern_scale_x;			//ハッチパターンのX尺度
	double hatch_pattern_scale_y;			//ハッチパターンのY尺度
	double hatch_pattern_angle;				//ハッチパターンの向きの角度
	int out_id;								//外形の複合曲線のフィーチャコード
	int number;								//中抜きの閉領域数
	CArray<int,int> in_id;					//中抜きの複合曲線のフィーチャコード
} Fill_area_style_tiles_Struct;

*/

	CString m_name;							//既定義シンボル名
	int m_hatch_color;						//ハッチパターンの色コード
	double m_hatch_pattern_x;				//ハッチパターン配置位置X座標
	double m_hatch_pattern_y;				//ハッチパターン配置位置Y座標
	double m_hatch_pattern_vector1;			//ハッチパターンの繰り返しベクトル１の大きさ
	double m_hatch_pattern_vector1_angle;	//ハッチパターンの繰り返しベクトル１の角度
	double m_hatch_pattern_vector2;			//ハッチパターンの繰り返しベクトル２の大きさ
	double m_hatch_pattern_vector2_angle;	//ハッチパターンの繰り返しベクトル２の角度
	double m_hatch_pattern_scale_x;			//ハッチパターンのX尺度
	double m_hatch_pattern_scale_y;			//ハッチパターンのY尺度
	double m_hatch_pattern_angle;			//ハッチパターンの向きの角度
	int m_out_id;							//外形の複合曲線のフィーチャコード
	int m_number;							//中抜きの閉領域数
	CArray<int,int> m_in_id;				//中抜きの複合曲線のフィーチャコード

};
#endif
