/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_TEXT_STYLEC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		TEXT_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapA_TEXT_STYLEC_CLASS_
#define _SXFMapA_TEXT_STYLEC_CLASS_

#include <afx.h>

#include "SXFMapT_EnumC.h"

class SXFMapA_TEXT_STYLEC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapA_TEXT_STYLEC( ) ;

//
//	<�f�X�g���N�^>
	virtual	~SXFMapA_TEXT_STYLEC() ;

////////styles�̎��
E_AnnoKindtype	m_stylesKind;//////////////////////
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<��`�e�[�u���₢���킹�p�̃C���X�^���XID>

	//	Colour�ւ̃C���X�^���X�h�c
	int m_colorID;
	
//	<��`�e�[�u���v�f�̃R�[�h>

	//	Colour�R�[�h
	int m_color;

//	<name�p�����^>
	double	  m_name;

//	<��������>
	double	  m_height;
//	<������>
	double	  m_width;
//	<�X�����g�p�x radian>
	double	  m_slant_angle;
//	<������p�x radian>
	double	  m_rotate_angle;
//	<�����Ԋu>
	double	m_spacing;
	
/*
  ENTITY text_style;
	  name				   : label;
	  character_appearance : character_style_select;
  END_ENTITY; -- text_style

  ENTITY text_style_for_defined_font;
	  text_colour : colour;
  END_ENTITY; -- text_style_for_defined_font

  ENTITY text_style_with_box_characteristics
	SUBTYPE OF (text_style);
	  characteristics : SET [1:4] OF box_characteristic_select;
	WHERE
	  wr1: SIZEOF(QUERY ( c1 <* SELF.characteristics 
						   | (SIZEOF(QUERY ( c2 <* (SELF.characteristics - c1) 
											  | (TYPEOF(c1) =  TYPEOF(c2)))) 
								> 0
							  ) )) 
			   = 0;
  END_ENTITY; -- text_style_with_box_characteristics

  TYPE box_characteristic_select = SELECT
	(box_height,
	 box_width,
	 box_slant_angle,
	 box_rotate_angle);
  END_TYPE; -- box_characteristic_select

  ENTITY text_style_with_spacing
	SUBTYPE OF (text_style);
	  character_spacing : character_spacing_select;
  END_ENTITY; -- text_style_with_spacing*/

private :

protected :

} ;
#endif
