/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_TEXT_STYLEC.h						作成日：2000.04.21

	１．クラス概要
		TEXT_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapA_TEXT_STYLEC_CLASS_
#define _SXFMapA_TEXT_STYLEC_CLASS_

#include <afx.h>

#include "SXFMapT_EnumC.h"

class SXFMapA_TEXT_STYLEC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapA_TEXT_STYLEC( ) ;

//
//	<デストラクタ>
	virtual	~SXFMapA_TEXT_STYLEC() ;

////////stylesの種類
E_AnnoKindtype	m_stylesKind;//////////////////////
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<定義テーブル問い合わせ用のインスタンスID>

	//	ColourへのインスタンスＩＤ
	int m_colorID;
	
//	<定義テーブル要素のコード>

	//	Colourコード
	int m_color;

//	<nameパラメタ>
	double	  m_name;

//	<文字高さ>
	double	  m_height;
//	<文字幅>
	double	  m_width;
//	<スラント角度 radian>
	double	  m_slant_angle;
//	<文字列角度 radian>
	double	  m_rotate_angle;
//	<文字間隔>
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
