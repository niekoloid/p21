/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．クラス概要
		Type型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFD_TypeC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFD_TypeC(char *data)
	引数:	型						引数名				内容
			char					*data		type型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_TypeC::SXFD_TypeC(char *data) {
	m_Data = data ;
	m_Next = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		データのセット

	２．インターフェース
	void	SXFD_TypeC::SetNext( SXFInstanceC* next )
	引数:	型								引数名				内容
			SXFInstanceC*					next			ｲﾝｽﾀﾝｽ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_TypeC::SetNext( SXFInstanceC* next ) {
	m_Next = next ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得

	２．インターフェース
	LPCTSTR	SXFD_TypeC::GetData( )
	引数:	型								引数名				内容
			なし					

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
LPCTSTR	SXFD_TypeC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得

	２．インターフェース
		SXFInstanceC*	SXFD_TypeC::GetNext( )	
	引数:	型								引数名				内容
			なし					

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFInstanceC* SXFD_TypeC::GetNext( ){
	return m_Next;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		要素を出力

	２．インターフェース
		void	WriteAttr(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC					*IN_file	ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void SXFD_TypeC::WriteAttr(SXFPart21FileC *IN_file){
	IN_file->WriteString(m_Data);
	IN_file->WriteString("(");
	if(m_Next != NULL) 
		m_Next->WriteAttr(IN_file);
	IN_file->WriteString(")");
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						作成日：2000.04.12

	１．機能概要
		インスタンスを出力

	２．インターフェース
		void	WriteP21(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC					*IN_file	ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void SXFD_TypeC::WriteP21(SXFPart21FileC *IN_file){
	if(m_Next != NULL)
		m_Next->WriteP21(IN_file);
}
