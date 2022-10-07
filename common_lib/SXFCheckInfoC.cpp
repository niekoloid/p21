/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								作成日：2001.2.15

	１．クラス概要
		ルールチェック情報を管理するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.15			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFCheckInfoC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								作成日：2001.2.15

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFCheckInfoC::SXFCheckInfoC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.15			宮園(FQS)			なし。

**/
SXFCheckInfoC::SXFCheckInfoC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								作成日：2001.2.15

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFCheckInfoC::~SXFCheckInfoC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.15			宮園(FQS)			なし。

**/
SXFCheckInfoC::~SXFCheckInfoC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.cpp								作成日：2001.2.15

	１．機能概要
		初期化

	２．インターフェース
		void	SXFTableCheckC::initialize()
		
	引数	：	型			引数名			内容
				なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.15			宮園(FQS)			なし。

**/
void SXFCheckInfoC::initialize()
{
	m_layer = -1;
	m_color = -1;
	m_type = -1;
	m_line_width = -1;
	m_font = -1;
}
