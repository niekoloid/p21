/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TEXT_LITERAL_WITH_EXTENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_TEXT_LITERAL_WITH_EXTENTC_CLASS_
#define _SXFMapE_TEXT_LITERAL_WITH_EXTENTC_CLASS_

#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_PLANAR_EXTENTC.h"


class SXFMapE_TEXT_LITERAL_WITH_EXTENTC:public SXFMapEntityBaseC{
public :
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC( );
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_TEXT_LITERAL_WITH_EXTENTC( );

	int	SetParameter( );

public:
/*
  ENTITY text_literal
	SUBTYPE OF (geometric_representation_item);
	  literal	: presentable_text;
	  placement : axis2_placement;
	  alignment : text_alignment;
	  path		: text_path;
	  font		: font_select;
  END_ENTITY; -- text_literal

  ENTITY text_literal_with_extent
	SUBTYPE OF (text_literal);
	  extent : planar_extent;
  END_ENTITY; -- text_literal_with_extent
*/
	CString m_Name;

	CString m_Literal;

	int m_Placement_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_Placement_p;

	CString m_Alignment;
	CString m_Path;

	int m_Font_Inst;
	//type???? m_Font_p;

	int m_PlanarExtent_Inst;
	SXFMapE_PLANAR_EXTENTC* m_PlanarExtent_p;

};
#endif
////////////////////////////
