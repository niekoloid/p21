/**
	All Rights Reserved,(c)JACIC 2001
	SXFF_FEATURENAMEEE.h						作成日：2000.04.21

	１．機能概要
		SCADECのフィーチャ名を定義する

	２．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

#ifndef _T_FEATURETYPEE_H_
#define	_T_FEATURETYPEE_H_

//#include "SXFErrorMsgC.h"

typedef enum E_type{

	NONFEATURE=0,
	drawing_sheet_feature,
	layer_feature,
	pre_defined_font_feature,
	user_defined_font_feature,
	pre_defined_colour_feature,
	user_defined_colour_feature,
	width_feature,
	text_font_feature,

	point_marker_feature,
	line_feature,
	polyline_feature,
	circle_feature,
	arc_feature,
	ellipse_feature,
	ellipse_arc_feature,
	text_string_feature,
	spline_feature,
	clothoid_feature,
	attribute_feature,

	sfig_locate_feature,
	sfig_org_feature,
	externally_defined_symbol_feature,
	linear_dim_feature,
	curve_dim_feature,
	angular_dim_feature,
	radius_dim_feature,
	diameter_dim_feature,
	label_feature,
	balloon_feature,
	externally_defined_hatch_feature,
	fill_area_style_colour_feature,
	fill_area_style_hatching_feature,
	fill_area_style_tiles_feature,
	composite_curve_org_feature,

	projection_line,
	dimension_line,
	dimension_terminator_symbol

}E_Ftype;

#endif

