/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.h						作成日：2000.04.17

	１．クラス概要
		FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC_CLASS_
#define _SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC_CLASS_

class SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC:public SXFMapEntityBaseC{
public :
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC( );
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC( );

	int	SetParameter( );

public:
/*
  ENTITY fill_area_style_tile_symbol_with_style
	SUBTYPE OF (geometric_representation_item);
	  symbol : annotation_symbol_occurrence;
  END_ENTITY; -- fill_area_style_tile_symbol_with_style
*/

	CString m_Name;
	int m_Symbol_Inst;

};
#endif
////////////////////////////
