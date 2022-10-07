/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVEC.h						作成日：2000.04.17

	１．クラス概要
		COMPOSITE_CURVEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_COMPOSITE_CURVEC_CLASS_
#define _SXFMapE_COMPOSITE_CURVEC_CLASS_

class SXFInstanceIDC;
class SXFMapE_COMPOSITE_CURVE_SEGMENTC;

class SXFMapE_COMPOSITE_CURVEC:public SXFMapEntityBaseC{
public :
	SXFMapE_COMPOSITE_CURVEC( );
	SXFMapE_COMPOSITE_CURVEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_COMPOSITE_CURVEC( );

	int	SetParameter( );

public:

//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);
/*
  ENTITY composite_curve
	SUBTYPE OF (bounded_curve);
	  segments		 : LIST [1:?] OF composite_curve_segment;
	  self_intersect : LOGICAL;
	DERIVE
	  n_segments   : INTEGER := SIZEOF(segments);
	  closed_curve : LOGICAL := segments[n_segments].transition <> 
						discontinuous;
	WHERE
	  wr1: ((NOT closed_curve) AND (SIZEOF(QUERY ( temp <* segments | (
			   temp.transition = discontinuous) )) = 1)) OR (closed_curve 
			   AND (SIZEOF(QUERY ( temp <* segments | (temp.transition = 
			   discontinuous) )) = 0));
  END_ENTITY; -- composite_curve
*/
	CString m_Name;

	int m_SegmentCount;

	CArray<int,int>	m_SegmentArray_Inst;

	BOOL m_Intersect;

//	不要かも ///////////////////////////////////////////////////////////////

	CArray<SXFMapE_COMPOSITE_CURVE_SEGMENTC*, SXFMapE_COMPOSITE_CURVE_SEGMENTC*>
		m_SegmentArray_p;

};
#endif
