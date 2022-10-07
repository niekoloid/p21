/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_COLOURC.h						作成日：2000.04.17

	１．クラス概要
		FILL_AREA_STYLE_COLOURを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_FILL_AREA_STYLE_COLOURC_CLASS_
#define _SXFMapE_FILL_AREA_STYLE_COLOURC_CLASS_

class SXFMapE_FILL_AREA_STYLE_COLOURC:public SXFMapEntityBaseC{
public :
	SXFMapE_FILL_AREA_STYLE_COLOURC( );
	SXFMapE_FILL_AREA_STYLE_COLOURC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_FILL_AREA_STYLE_COLOURC( );

	int	SetParameter( );

public:

/*
  ENTITY fill_area_style_colour;
	  name		  : label;
	  fill_colour : colour;
  END_ENTITY; -- fill_area_style_colour
*/

	CString m_Name;

	int m_FillColour_Inst;

};
#endif
////////////////////////////
