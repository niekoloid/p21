/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.h						作成日：2000.04.17

	１．クラス概要
		SYMBOL_COLOURを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_COLOURC_CLASS_
#define _SXFMapE_SYMBOL_COLOURC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_SYMBOL_COLOURC : public SXFMapEntityBaseC {

public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_SYMBOL_COLOURC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_SYMBOL_COLOURC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_SYMBOL_COLOURC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*
  ENTITY symbol_colour;
      colour_of_symbol : colour;
  END_ENTITY; -- symbol_colour
*/
//#100 = SYMBOL_COLOUR(#40);

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	1. colour へのインスタンスID
	int		m_colour_Inst;

private :

protected :

} ;

#endif
