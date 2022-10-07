/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_BEZIER_CURVEC.h						作成日：2000.04.17

	１．クラス概要
		BEZIER_CURVEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_BEZIER_CURVEC_CLASS_
#define _SXFMapE_BEZIER_CURVEC_CLASS_

#include "SXFMapE_CARTESIAN_POINTC.h"


class SXFMapE_BEZIER_CURVEC:public SXFMapEntityBaseC{
public :
	SXFMapE_BEZIER_CURVEC( );
	SXFMapE_BEZIER_CURVEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_BEZIER_CURVEC( );

	int	SetParameter( );

public:

/*
  ENTITY bezier_curve
	SUBTYPE OF (b_spline_curve);
  END_ENTITY; -- bezier_curve
*/
/*
  ENTITY b_spline_curve
	SUBTYPE OF (bounded_curve);
	  degree			  : INTEGER;
	  control_points_list : LIST [2:?] OF cartesian_point;
	  curve_form		  : b_spline_curve_form;
	  closed_curve		  : LOGICAL;
	  self_intersect	  : LOGICAL;
  END_ENTITY; -- b_spline_curve


*/

	CString m_Name;

	int m_Degree;

	int m_PointCount;
	CArray<int,int>	m_PointArray_Inst;
	CArray<SXFMapE_CARTESIAN_POINTC*, SXFMapE_CARTESIAN_POINTC*>
		m_PointArray_p;

	CString m_CurveForm;

	//LOGICAL ---- CString ????
	CString m_ClosedCurve;
	CString m_SelfIntersect;
};
#endif
