/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_TILE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_FILL_AREA_STYLE_TILEC_CLASS_
#define _SXFMapE_FILL_AREA_STYLE_TILEC_CLASS_


#include "SXFMapE_TWO_DIRECTION_REPEAT_FACTORC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.h"

class SXFMapE_FILL_AREA_STYLE_TILEC:public SXFMapEntityBaseC{
public :
	SXFMapE_FILL_AREA_STYLE_TILEC( );
	SXFMapE_FILL_AREA_STYLE_TILEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_FILL_AREA_STYLE_TILEC( );

	int	SetParameter( );

public:

/*
  ENTITY fill_area_style_tiles
	SUBTYPE OF (geometric_representation_item);
	  tiling_pattern : two_direction_repeat_factor;
	  tiles			 : SET [1:?] OF fill_area_style_tile_shape_select;
	  tiling_scale	 : positive_ratio_measure;
  END_ENTITY; -- fill_area_style_tiles
*/
//	#2679 = FILL_AREA_STYLE_TILES('fill_area_style_tiles1', #2678, (#2673), 1.);

	CString m_name;

	int m_TilingPattern_Inst;
	SXFMapE_TWO_DIRECTION_REPEAT_FACTORC* m_TilingPattern_p;

	CArray<int,int> m_TileArray_Inst;
	int m_TileCount;
	CArray<SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC*,
		   SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC*>
		   m_TileArray_p;

	double m_TilingScale;

};
#endif
////////////////////////////
