/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ColorBaseC.cpp					作成日：2000.04.17

	１．クラス概要
		シンボル、文字、ハッチングフィーチャの色を管理するクラス
		（CurveStyle以外）

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapF_ColorBaseC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ColorBaseC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_ColorBaseC::SXFMapF_ColorBaseC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_ColorBaseC::SXFMapF_ColorBaseC()
{
	m_color=0;				//色コード

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ColorBaseC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_ColorBaseC::~SXFMapF_ColorBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_ColorBaseC::~SXFMapF_ColorBaseC()
{
}
