/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SymbolStyleBaseC.cpp						作成日：2000.04.17

	１．クラス概要
		フィーチャのSymbolStyleを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapF_SymbolStyleBaseC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SymbolStyleBaseC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_SymbolStyleBaseC::SXFMapF_SymbolStyleBaseC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SymbolStyleBaseC::SXFMapF_SymbolStyleBaseC()
{
	m_color=0;				//色コード
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SymbolStyleBaseC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_SymbolStyleBaseC::~SXFMapF_SymbolStyleBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SymbolStyleBaseC::~SXFMapF_SymbolStyleBaseC()
{
}
