/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_COLOURC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_COLOUR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
