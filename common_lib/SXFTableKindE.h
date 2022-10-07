
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．機能概要
		定義テーブルの種別をENUM型で定義する

		定義テーブル種別	
			1:レイヤ
			2:既定義色
			3:ユーザ定義色
			4:既定義線種
			5:ユーザ定義線種
			6:線幅
			7:文字フォント

	２．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

#ifndef _TABLEKIND_H_
#define	_TABLEKIND_H_

typedef enum TableType{
	E_LAYER = 1,	//1:レイヤ
	E_PRECOLOR,		//2:既定義色
	E_USERCOLOR,	//3:ユーザ定義色
	E_PREFONT,		//4:既定義線種
	E_USERFONT,		//5:ユーザ定義線種
	E_WIDTH,		//6:線幅
	E_TEXTFONT		//7:文字フォント
}TableKind;

#endif
