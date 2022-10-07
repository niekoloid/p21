/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.h						作成日：2000.04.17

	１．クラス概要
		COMPOSITE_CURVE_SEGMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_COMPOSITE_CURVE_SEGMENTC_CLASS_
#define _SXFMapE_COMPOSITE_CURVE_SEGMENTC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"
#include "SXFMapT_trimming_preferenceE.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_VECTORC;

class SXFMapE_COMPOSITE_CURVE_SEGMENTC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_COMPOSITE_CURVE_SEGMENTC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_COMPOSITE_CURVE_SEGMENTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_COMPOSITE_CURVE_SEGMENTC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);
/*
  ENTITY composite_curve_segment;
	  transition   : transition_code;
	  same_sense   : BOOLEAN;
	  parent_curve : curve;
	INVERSE
	  using_curves : BAG [1:?] OF composite_curve FOR segments;
	WHERE
	  wr1: 'ASSOCIATIVE_DRAUGHTING.BOUNDED_CURVE' IN TYPEOF(parent_curve);
  END_ENTITY; -- composite_curve_segment
  
  TYPE transition_code = ENUMERATION OF
	(discontinuous,
	 continuous,
	 cont_same_gradient,
	 cont_same_gradient_same_curvature);
  END_TYPE; -- transition_code

*/

	//1.transition_code
	int		m_tran_code;
	
	//2.same_sense
	BOOL	m_sense;

	
	//2.parent_curve へのインスタンスID
	int		m_parent_curve_Inst;

	//parent_curveへのポインタ
	void*	m_parent_curve_P;

	//parent_curveの名前
	CString	m_parent_curve_Name;


private :

protected :

} ;

#endif
