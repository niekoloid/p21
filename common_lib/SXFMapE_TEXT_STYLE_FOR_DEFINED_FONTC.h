/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h						ì¬úF2000.04.17

	PDNXTv
		TEXT_STYLE_FOR_DEFINED_FONTðÇ·éNX

	QDð
		ðÔ	út¯		SÒ		Tv
		ì¬		2000.04.17	

**/
#ifndef _SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC_CLASS_
#define _SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC_CLASS_

class SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC:public SXFMapEntityBaseC{
public :
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC( );
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC( );

	int	SetParameter( );

public:
/*
  ENTITY text_style_for_defined_font;
	  text_colour : colour;
  END_ENTITY; -- text_style_for_defined_font
*/
  
	int m_Color_Inst;
	//type???? m_Color_p;

};
#endif
////////////////////////////