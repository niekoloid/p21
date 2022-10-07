/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.h						作成日：2000.04.17

	１．クラス概要
		FILL_AREA_STYLE_HATCHINGを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_FILL_AREA_STYLE_HATCHINGC_CLASS_
#define _SXFMapE_FILL_AREA_STYLE_HATCHINGC_CLASS_

#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapE_ONE_DIRECTION_REPEAT_FACTORC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"

class SXFMapE_FILL_AREA_STYLE_HATCHINGC:public SXFMapEntityBaseC{
public :
	SXFMapE_FILL_AREA_STYLE_HATCHINGC( );
	SXFMapE_FILL_AREA_STYLE_HATCHINGC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_FILL_AREA_STYLE_HATCHINGC( );

	int	SetParameter( );

public:
/*
  ENTITY fill_area_style_hatching
	SUBTYPE OF (geometric_representation_item);
	  hatch_line_appearance			: curve_style;
	  start_of_next_hatch_line		: one_direction_repeat_factor;
	  point_of_reference_hatch_line : cartesian_point;
	  pattern_start					: cartesian_point;
	  hatch_line_angle				: plane_angle_measure;
  END_ENTITY; -- fill_area_style_hatching
*/

	CString m_Name;

	int m_HatchLineAppeatance_Inst;
	SXFMapE_CURVE_STYLEC* m_HatchLineAppeatance_p;

	int m_StartOfNextHatchLine_Inst;
	SXFMapE_ONE_DIRECTION_REPEAT_FACTORC* m_StartOfNextHatchLine_p;
	
	int m_PointOfReferenceHatchLine_Inst;
	SXFMapE_CARTESIAN_POINTC* m_PointOfReferenceHatchLine_p;
	
	int m_PatternStart_Inst;
	SXFMapE_CARTESIAN_POINTC* m_PatternStart_p;
	
	double m_HatchLineAngle;

};
#endif
////////////////////////////
