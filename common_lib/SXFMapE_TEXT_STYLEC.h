/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TEXT_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_TEXT_STYLEC_CLASS_
#define _SXFMapE_TEXT_STYLEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC;

class SXFMapE_TEXT_STYLEC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_TEXT_STYLEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_TEXT_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_TEXT_STYLEC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*
  ENTITY text_style;
      name                 : label;
      character_appearance : character_style_select;
  END_ENTITY; -- text_style

  TYPE character_style_select = SELECT
    (text_style_for_defined_font);
  END_TYPE; -- character_style_select

  ENTITY text_style_for_defined_font;
      text_colour : colour;
  END_ENTITY; -- text_style_for_defined_font

  ENTITY text_style_with_box_characteristics
    SUBTYPE OF (text_style);
      characteristics : SET [1:4] OF box_characteristic_select;
    WHERE
      wr1: SIZEOF(QUERY ( c1 <* SELF.characteristics 
         | (SIZEOF(QUERY ( c2 <* (SELF.characteristics - c1) 
          | (TYPEOF(c1) =  TYPEOF(c2)))) > 0   ) ))  = 0;
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
  END_ENTITY; -- text_style_with_spacing
*/

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	//	1.name�p�����^
	CString		m_name;

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	2.text_style_for_defined_font �ւ̃C���X�^���XID
	int		m_text_appe_Inst;

	//	text_style_for_defined_font�ւ̃|�C���^
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC*	m_text_appe_P;


	//	<��������>
		double    m_height;
	//	<������>
		double    m_width;
	//	<�X�����g�p�x radian>
		double    m_slant_angle;
	//	<������p�x radian>
		double    m_rotate_angle;
	//	<�����Ԋu>
		double	m_spacing;

private :

protected :

} ;
#endif
