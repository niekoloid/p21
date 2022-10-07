/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapA_TEXT_STYLEC.cpp						作成日：2000.04.21

	１．クラス概要
		TEXT_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#include "stdafx.h"
#include "SXFMapA_TEXT_STYLEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
	
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_TEXT_STYLEC.cpp						作成日：2000.04.21

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapA_TEXT_STYLEC::SXFMapA_TEXT_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapA_TEXT_STYLEC::SXFMapA_TEXT_STYLEC()
{
//
//	<初期化>
//

	//stylesの種類
	m_stylesKind = CURVESTYLE;
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<定義テーブル問い合わせ用のインスタンスID>
	//	ColourへのインスタンスＩＤ
	m_colorID=0;

//	<定義テーブル要素のコードD>
	//	Colourコード
	m_color=-1;

//	<文字高さ>
	m_height=0.;
//	<文字幅>
	m_width=0.;
//	<スラント角度 radian>
	m_slant_angle=0.;
//	<文字列角度 radian>
	m_rotate_angle=0.;
//	<文字間隔>
	m_spacing=0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_TEXT_STYLEC.cpp						作成日：2000.04.21

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapA_TEXT_STYLEC::~SXFMapA_TEXT_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapA_TEXT_STYLEC::~SXFMapA_TEXT_STYLEC()
{
}
