/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_IntC.cpp						作成日：2000.04.12

	１．クラス概要
		整数型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFD_IntC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2000.04.12

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFD_IntC::SXFD_IntC(int data)
	
	引数:	型					引数名				内容
			int					data				int型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_IntC::SXFD_IntC(int data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2000.04.12

	１．機能概要
		データのセット

	２．インターフェース
		void	SXFD_IntC::SetData( int data )
		
	引数:	型					引数名				内容
			int					data				int型要素	

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_IntC::SetData( int data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得

	２．インターフェース
		int	SXFD_IntC::GetData( )
	引数	:	型					引数名				内容
		なし								

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
int	SXFD_IntC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2000.04.12

	１．機能概要
		要素を出力

	２．インターフェース
		void	WriteAttr(SXFPart21FileC *IN_file)
	引数:	型					引数名				内容
			SXFPart21FileC		*IN_file			ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_IntC::WriteAttr(SXFPart21FileC *IN_file) {
	CString int_str;
	int_str.Format("%d",m_Data);
	IN_file->WriteString(int_str);
}

