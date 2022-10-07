/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.h						作成日：2000.04.17

	１．クラス概要
		PLANAR_BOXを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_PLANAR_BOXC_CLASS_
#define _SXFMapE_PLANAR_BOXC_CLASS_

#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"

class SXFMapE_PLANAR_BOXC:public SXFMapEntityBaseC{
public :
	SXFMapE_PLANAR_BOXC( );
	SXFMapE_PLANAR_BOXC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PLANAR_BOXC( );

	int	SetParameter( );

public:

/*
  ENTITY planar_box
	SUBTYPE OF (planar_extent);
	  placement : axis2_placement;
  END_ENTITY; -- planar_box
*/
/*
  ENTITY planar_extent
	SUBTYPE OF (geometric_representation_item);
	  size_in_x : length_measure;
	  size_in_y : length_measure;
  END_ENTITY; -- planar_extent
*/

	CString m_Name;

	double m_Size_x;
	double m_Size_y;

	int m_Placement_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_Placement_p;

};
#endif
////////////////////////////
