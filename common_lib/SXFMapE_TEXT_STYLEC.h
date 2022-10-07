/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.h						作成日：2000.04.17

	１．クラス概要
		TEXT_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
//	<デフォルトコンストラクタ>
	SXFMapE_TEXT_STYLEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_TEXT_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_TEXT_STYLEC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
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

	//	1.nameパラメタ
	CString		m_name;

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	2.text_style_for_defined_font へのインスタンスID
	int		m_text_appe_Inst;

	//	text_style_for_defined_fontへのポインタ
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC*	m_text_appe_P;


	//	<文字高さ>
		double    m_height;
	//	<文字幅>
		double    m_width;
	//	<スラント角度 radian>
		double    m_slant_angle;
	//	<文字列角度 radian>
		double    m_rotate_angle;
	//	<文字間隔>
		double	m_spacing;

private :

protected :

} ;
#endif
