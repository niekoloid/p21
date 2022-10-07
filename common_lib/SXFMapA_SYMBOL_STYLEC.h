/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_SYMBOL_STYLEC.h						作成日：2000.04.21

	１．クラス概要
		SYMBOL_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapA_SYMBOL_STYLEC_CLASS_
#define _SXFMapA_SYMBOL_STYLEC_CLASS_

#include <afx.h>

#include "SXFMapT_EnumC.h"

class SXFMapA_SYMBOL_STYLEC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapA_SYMBOL_STYLEC( ) ;

//
//	<デストラクタ>
	virtual	~SXFMapA_SYMBOL_STYLEC() ;

////////stylesの種類
E_AnnoKindtype  m_stylesKind;//////////////////////
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<定義テーブル問い合わせ用のインスタンスID>

	//	ColourへのインスタンスＩＤ
	int m_colorID;

//	<定義テーブル要素のコードD>

	//	Colourコード
	int m_color;

private :

protected :

} ;
#endif
