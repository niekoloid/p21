/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.h						作成日：2000.04.17

	１．クラス概要
		SYMBOL_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_STYLEC_CLASS_
#define _SXFMapE_SYMBOL_STYLEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_SYMBOL_COLOURC;

class SXFMapE_SYMBOL_STYLEC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_SYMBOL_STYLEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_SYMBOL_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_SYMBOL_STYLEC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*
  ENTITY symbol_style;
      name            : label;
      style_of_symbol : symbol_style_select;
  END_ENTITY; -- symbol_style
  
  ENTITY symbol_colour;
      colour_of_symbol : colour;
  END_ENTITY; -- symbol_colour
*/
//#100=SYMBOL_COLOUR(#40);
//#110=SYMBOL_STYLE(' ',#100);

	//	1.nameパラメタ
	CString		m_name;

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	2.symbol_colour へのインスタンスID
	int		m_symbol_colour_Inst;

	//	symbol_colourへのポインタ
	SXFMapE_SYMBOL_COLOURC*		m_symbol_colour_P;

private :

protected :

} ;

#endif
