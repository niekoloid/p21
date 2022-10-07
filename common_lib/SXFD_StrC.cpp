/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						作成日：2000.04.12

	１．クラス概要
		文字型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFutyConvKanjiC.h"
#include "SXFPart21FileC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						作成日：2000.04.12

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFD_StrC::SXFD_StrC( char *data )
	引数:	型						引数名				内容
			char*					data			char型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_StrC::SXFD_StrC( char *data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						作成日：2000.04.12

	１．機能概要
		データのセット

	２．インターフェース
		void	SXFD_StrC::SetData( char* data )
	引数:	型						引数名				内容
			char*					data			char型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_StrC::SetData( char* data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得

	２．インターフェース
		void	LPCTSTR	SXFD_StrC::GetData( )
	引数:	型						引数名				内容
			なし							

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
LPCTSTR	SXFD_StrC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						作成日：2000.04.12

	１．機能概要
		要素の出力

	２．インターフェース
	void	WriteAttr(SXFPart21FileC *IN_file)
	引数:	型						引数名				内容
			SXFPart21FileC			*IN_file			ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void SXFD_StrC::WriteAttr(SXFPart21FileC *IN_file){
	if (m_Data == DEF_DOLLAR){
		CString str;
		str.Format("%s",m_Data);
		IN_file->WriteString(str);
	}
	else{
		char name[MAXUNICODETEXT];
//		SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)m_Data,name);
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)m_Data,name);
		SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)m_Data,name,_countof(name));
		IN_file->WriteString(DEF_S_QUOTE);
		IN_file->WriteString(name);
		IN_file->WriteString(DEF_S_QUOTE);
	}
}

