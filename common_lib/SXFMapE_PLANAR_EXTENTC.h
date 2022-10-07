/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_EXTENTC.h						作成日：2000.04.17

	１．クラス概要
		PLANAR_EXTENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_PLANAR_EXTENTC_CLASS_
#define _SXFMapE_PLANAR_EXTENTC_CLASS_

class SXFMapE_PLANAR_EXTENTC:public SXFMapEntityBaseC{
public :
	SXFMapE_PLANAR_EXTENTC( );
	SXFMapE_PLANAR_EXTENTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PLANAR_EXTENTC( );

	int	SetParameter( );

public:

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

};
#endif
