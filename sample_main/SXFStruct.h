//------------------------------------------------
//	構造体を定義
//------------------------------------------------
#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <afx.h>
#include <afxtempl.h>
#include "max.h"

//------------------------------------------------
//	用紙
//------------------------------------------------
typedef struct Sheet_StructDF{
	char name[MAXSHEETNAME];
	int type;
	int orient;
	int x;
	int y;
} Sheet_Struct;

//------------------------------------------------
//	レイヤ
//------------------------------------------------
typedef struct Layer_StructDF{
	char name[MAXLAYERNAME2];
	int lflag;
} Layer_Struct;

//------------------------------------------------
//	既定義線種
//------------------------------------------------
typedef struct Predefined_Linetype_StructDF{
	char name[MAXLINETYPENAME];
} Predefined_Linetype_Struct;

//------------------------------------------------
//	ユーザ定義線種
//------------------------------------------------
typedef struct Userdefined_Linetype_StructDF{
	char name[MAXLINETYPENAME];
	int segment;
	double pitch[MAXPITCH];
} Userdefined_Linetype_Struct;

//------------------------------------------------
//	既定義色
//------------------------------------------------
typedef struct Predefined_Colour_StructDF{
	char name[MAXCOLOURNAME];
} Predefined_Colour_Struct;

//------------------------------------------------
//	ユーザ定義色
//------------------------------------------------
typedef struct Userdefined_Colour_StructDF{
	int		red ;			//レイヤコード
	int		green ;			//色コード
	int		blue ;			//線種コード
} Userdefined_Colour_Struct ;

//------------------------------------------------
//	線幅
//------------------------------------------------
typedef struct Line_Width_StructDF{
	double width;
} Line_Width_Struct;

//------------------------------------------------
//	文字フォント
//------------------------------------------------
typedef struct Text_Font_StructDF{
	char name[MAXTEXTFONTNAME];
} Text_Font_Struct;

//------------------------------------------------
//	図面表題欄
//------------------------------------------------
typedef struct Attribute_StructDF{
	char	p_name[MAXTEXT];		/* 事業名 */
	char	c_name[MAXTEXT];		/* 工事名 */
	char	c_type[MAXTEXT];		/* 契約区分 */
	char	d_title[MAXTEXT];		/* 図面名 */
	char	d_number[MAXTEXT];		/* 図面番号 */
	char	d_type[MAXTEXT];		/* 図面種別 */
	char	d_scale[MAXTEXT];		/* 尺度 */
	int		d_year;					/* 図面作成年(西暦) */
	int		d_month;				/* 図面作成月(西暦) */
	int		d_day;					/* 図面作成日(西暦) */
	char	c_contractor[MAXTEXT];	/* 受注会社名 */
	char	c_owner[MAXTEXT];		/* 発注事業者名 */
} Attribute_Struct;

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

//------------------------------------------------
//	線分
//------------------------------------------------
typedef struct Line_StructDF{
	int layer;				//レイヤコード
	int color;				//色コード
	int type;				//線種コード
	int line_width;			//線幅コード
	double start_x;			//始点Ｘ座標
	double start_y;			//始点Ｙ座標
	double end_x;			//終点Ｘ座標
	double end_y;			//終点Ｙ座標
} Line_Struct;

//------------------------------------------------
//	折線
//------------------------------------------------
typedef struct Polyline_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	int number;					//頂点数
	CArray<double,double> x;	//X座標
	CArray<double, double> y;	//Y座標
} Polyline_Struct;

//------------------------------------------------
//	円
//------------------------------------------------
typedef struct Circle_StructDF{
	int		layer ;			//レイヤコード
	int		color ;			//色コード
	int		type ;			//線種コード
	int		line_width ;	//線幅コード
	double	center_x ;		//中心Ｘ座標
	double	center_y ;		//中心Ｙ座標
	double	radius ;		//半径
} Circle_Struct;

//------------------------------------------------
//	円弧
//------------------------------------------------
typedef struct Arc_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	double	center_x ;			//中心Ｘ座標
	double	center_y ;			//中心Ｙ座標
	double	radius ;			//半径
	int direction;				//向きフラグ
	double start_angle;			//始角
	double end_angle;			//終角
} Arc_Struct;

//------------------------------------------------
//	楕円
//------------------------------------------------
typedef struct Ellipse_StructDF{

	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	double	center_x ;			//中心Ｘ座標
	double	center_y ;			//中心Ｙ座標
	double	radius_x ;			//X方向半径
	double	radius_y ;			//Y方向半径
	double rotation_angle;		//回転角
} Ellipse_Struct;

//------------------------------------------------
//	だ円弧
//------------------------------------------------
typedef struct Ellipse_Arc_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	double	center_x ;			//中心Ｘ座標
	double	center_y ;			//中心Ｙ座標
	double	radius_x ;			//X方向半径
	double	radius_y ;			//Y方向半径
	int direction;				//向きフラグ
	double rotation_angle;		//回転角
	double start_angle;			//始角
	double end_angle;			//終角
} Ellipse_Arc_Struct;

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

//------------------------------------------------
//	スプライン曲線
//------------------------------------------------
typedef struct Spline_StructDF{
	int	layer ;					//レイヤコード
	int	color ;					//色コード
	int	type ;					//線種コード
	int	line_width ;			//線幅コード
	int open_close;				//開閉区分
	int number;					//頂点数
	CArray<double,double> x;	//X座標
	CArray<double, double> y;	//Y座標
} Spline_Struct;

//------------------------------------------------
//	クロソイド曲線
//------------------------------------------------
typedef struct Clothoid_StructDF{
	int	layer ;					/* レイヤコード */
	int	color ;					/* 色コード */
	int	type ;					/* 線種コード */
	int	line_width ;			/* 線幅コード */
	double	base_x ;			/* 配置基点Ｘ座標 */
	double	base_y ;			/* 配置基点Ｙ座標 */
	double	parameter ;			/* クロソイドパラメータ */
	int direction;				/* 向きフラグ */
	double angle;				/* 回転角 */
	double start_length;		/* 開始曲線長 */
	double end_length;			/* 終了曲線長 */
} Clothoid_Struct;

//------------------------------------------------
//	複合図形定義
//------------------------------------------------
typedef struct Sfigorg_StructDF{
	char name[MAXFIGURENAME];
	int flag;
} Sfigorg_Struct;

//------------------------------------------------
//	複合図形配置
//------------------------------------------------
typedef struct Sfigloc_StructDF{
	int layer;						//レイヤコード
	char name[MAXFIGURENAME];		//複合図形名
	double x;						//配置位置X座標
	double y;						//配置位置Y座標
	double angle;					//回転角
	double ratio_x;					//X方向尺度
	double ratio_y;					//Y方向尺度
} Sfigloc_Struct;

//------------------------------------------------
//	既定義シンボル
//------------------------------------------------
typedef struct Externally_Defined_Symbol_StructDF{
	int layer;						//レイヤコード
	int color_flag;					//色コードフラグ
	int color;						//色コード
	char name[MAXSYMBOLNAME];		//シンボル名
	double start_x;					//配置位置X座標
	double start_y;					//配置位置Y座標
	double rotate_angle;			//回転角
	double scale;					//倍率
} Externally_Defined_Symbol_Struct;

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

//------------------------------------------------
//  弧長寸法
//------------------------------------------------
typedef struct CurveDim_StructDF{
	int layer;				/* レイヤコード */
	int color;				/* 色コード */
	int type;				/* 線種コード */
	int line_width;			/* 線幅コード */
	double sun_x;			/* 寸法線原点Ｘ座標 */
	double sun_y;			/* 寸法線原点Ｙ座標 */
	double sun_radius;		/* 寸法線半径 */
	double sun_angle0;		/* 寸法線始角 */
	double sun_angle1;		/* 寸法線終角 */
	int flg2;				/* 補助線１の有無フラグ(0:無 1:有) */
	double ho1_x0;			/* 補助線１基点Ｘ座標 */
	double ho1_y0;			/* 補助線１基点Ｙ座標 */
	double ho1_x1;			/* 補助線１始点Ｘ座標 */
	double ho1_y1;			/* 補助線１始点Ｙ座標 */
	double ho1_x2;			/* 補助線１終点Ｘ座標 */
	double ho1_y2;			/* 補助線１終点Ｙ座標 */
	int flg3;				/* 補助線２の有無フラグ(0:無 1:有) */
	double ho2_x0;			/* 補助線２基点Ｘ座標 */
	double ho2_y0;			/* 補助線２基点Ｙ座標 */
	double ho2_x1;			/* 補助線２始点Ｘ座標 */
	double ho2_y1;			/* 補助線２始点Ｙ座標 */
	double ho2_x2;			/* 補助線２終点Ｘ座標 */
	double ho2_y2;			/* 補助線２終点Ｙ座標 */
	int arr1_code1;			/* 矢印１コード */
	int arr1_code2;			/* 矢印１内外コード */
	double arr1_x;			/* 矢印１配置点Ｘ座標 */
	double arr1_y;			/* 矢印１配置点Ｙ座標 */
	double arr1_r;			/* 矢印１配置倍率 */
	int arr2_code1;			/* 矢印２コード */
	int arr2_code2;			/* 矢印２内外コード */
	double arr2_x;			/* 矢印２配置点Ｘ座標 */
	double arr2_y;			/* 矢印２配置点Ｙ座標 */
	double arr2_r;			/* 矢印２配置倍率 */
	int flg4;				/* 寸法値の有無フラグ */
	int font;				/* 文字フォントコード */
	char str[MAXTEXT];		/* 文字列 */
	double text_x;			/* 文字列配置基点Ｘ座標 */
	double text_y;			/* 文字列配置基点Ｙ座標 */
	double height;			/* 文字範囲高 */
	double width;			/* 文字範囲幅 */
	double spc;				/* 文字間隔 */
	double angle;			/* 文字列回転角 */
	double slant;			/* スラント角度 */
	int b_pnt;				/* 文字配置基点 */
	int direct;				/* 文字書出し方向 */
} CurveDim_Struct;

///////////////////////////
//角度寸法フィーチャ構造体
///////////////////////////
typedef struct AngularDim_StructDF{

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

} AngularDim_Struct;

///////////////////////////
//角度寸法フィーチャ構造体
///////////////////////////
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

///////////////////////////
//直径寸法フィーチャ構造体
///////////////////////////
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

typedef struct Balloon_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
	int vertex_number;
	CArray<double,double> vertex_x;
	CArray<double,double> vertex_y;

	double center_x;
	double center_y;
	double radius;
	
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
} Balloon_Struct;

typedef struct Externally_Defined_Hatch_StructDF{
	int layer;
	char name[MAXHATCHNAME];
	int out_id;
	int number;
	CArray<int, int> in_id;
} Externally_Defined_Hatch_Struct;

typedef struct Fill_area_style_colour_StructDF{
	int layer;
	int color;
	int out_id;
	int number;
	CArray<int,int> in_id;
} Fill_area_style_colour_Struct;

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

typedef struct Ccurve_Org_StructDF{
	int color;			//色コード
	int type;			//線種コード
	int line_width;		//線幅コード
	int flag;			//表示/非表示フラグ
} Ccurve_Org_Struct;

//寸法線用Terminator Symbol
typedef struct TermSymbol_StructDF{
	int target_ID;
	int flag;
	int color;
	int code;
	double direction_x;
	double direction_y;
	double x;
	double y;
	double scale;
} TermSymbol_Struct;

//寸法線用Projection Line
typedef struct ProjLine_StructDF{
	int target_ID;
	double ho_x0;
	double ho_y0;
	double ho_x1;
	double ho_y1;
	double ho_x2;
	double ho_y2;
} ProjLine_Struct;

enum assembly{
	SHEET = 1,
	SFIG_ORG,
	CCURVE_ORG
};

typedef struct tagSXF_POINT {
	double	x ;
	double	y ;
} SXF_POINT;

#endif
