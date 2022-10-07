/**
	All Rights Reserved,(c)JACIC 2001
	SXFFetIDC.cpp					作成日：2000.03.21

	１．クラス概要
	ファイルに出力すべきインスタンスIDを管理するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.21	諌山(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFFetIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								作成日：2000.3.21

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFFetIDC::SXFFetIDC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.21			諫山(FQS)			なし。

**/
SXFFetIDC::SXFFetIDC()
{
	m_insID = 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								作成日：2000.3.21

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFFetIDC::~SXFFetIDC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.21			諫山(FQS)			なし。

**/
SXFFetIDC::~SXFFetIDC ()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								作成日：2000.3.21

	１．機能概要
		インスタンスIDの返却

	２．インターフェース
		int	SXFFetIDC::Get_ID()
		
	引数	：	型		引数名				内容
		なし

	復帰値
			int		m_insID		インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.21			諫山(FQS)			なし。

**/
int SXFFetIDC::Get_ID (){
	m_insID += 10 ;
	return m_insID ;
}
