/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
