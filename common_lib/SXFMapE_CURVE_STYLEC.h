/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.h						作成日：2000.04.17

	１．クラス概要
		CURVE_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLEC_CLASS_
#define _SXFMapE_CURVE_STYLEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_VECTORC;

class SXFMapE_CURVE_STYLEC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_CURVE_STYLEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_CURVE_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_CURVE_STYLEC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*
  ENTITY curve_style;
	  name		   : label;
	  curve_font   : curve_font_or_scaled_curve_font_select;
	  curve_width  : size_select;
	  curve_colour : colour;
  END_ENTITY; -- curve_style
*/
//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.nameパラメタ
	CString		m_name;

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	2.font へのインスタンスID
	int		m_font_Inst;

	//	3.width へのインスタンスID
	int		m_width_Inst;

	//	4.colour へのインスタンスID
	int		m_colour_Inst;

private :

protected :

} ;

#endif
