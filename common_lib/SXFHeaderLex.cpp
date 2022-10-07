//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．クラス概要
//		字句解析を行うクラス
//
//	２．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)	ヘッダ解析処理の改善対応
//
//---------------------------------------------------------

#include "stdafx.h"
#include "SXFHeaderLex.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		コンストラクタ
//
//	２．インターフェイス
//      CSXFHeaderLex::CSXFHeaderLex(CString& string)
//
//		引数: 型			引数名			内容
//			CString&		string			字句解析対照の文字列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CSXFHeaderLex::CSXFHeaderLex(CString& string)
{
	m_Pointer = 0 ;
	m_LineCount = 1 ;
	m_sString = string;
	m_sString += static_cast<TCHAR>(TT_EOF);
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		デストラクタ
//
//	２．インターフェイス
//		CSXFHeaderLex::~CSXFHeaderLex()
//
//		引数:	なし
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CSXFHeaderLex::~CSXFHeaderLex()
{

}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		行番号取得
//
//	２．インターフェイス
//		int CSXFHeaderLex::GetLineNo() {
//
//		引数:	なし
//
//		復帰値	行番号
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int CSXFHeaderLex::GetLineNo()
{
	return	m_LineCount ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		トークン取得
//
//	２．インターフェイス
//		CString& CSXFHeaderLex::GetTokenImage()
//
//		引数:	なし
//
//		復帰値	トークン文字列
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CString& CSXFHeaderLex::GetTokenImage()
{
	return m_Token ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		字句解析
//
//	２．インターフェイス
//		int CSXFHeaderLex::Lex()
//
//		引数:	なし
//
//		復帰値	終了/トークン
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int CSXFHeaderLex::Lex()
{
	TCHAR	me_c = getc() ;

	if( me_c == ' ' || me_c=='\t' ) {
		setTokenImage(me_c) ;
		return	(int)me_c ;
	}

	// EOF
	if (me_c == TT_EOF)	return TT_EOF ;


	// STRING
	if( me_c == '\'' ) {
		CString TokenImage ;
		consumeQuote(TokenImage) ;
		setTokenImage(TokenImage) ;
		return	TT_STRING ;
	}

	// COMMENT
	if( me_c == '/' ) {
		if( (me_c = getc()) == '/' ) {
			setTokenImage("//") ;
			return	TT_LINE_COMMENT ;
		} else if(me_c == '*') {
			setTokenImage("/*") ;
			return	TT_BLOCK_COMMENT_START ;
		} else {
			ungetc() ;
			me_c = '/' ;
		}
	}
	if( me_c == '*' ) {
		if( (me_c = getc()) == '/' ) {
			setTokenImage("*/") ;
			return	TT_BLOCK_COMMENT_END ;
		} else {
			ungetc() ;
			me_c = '*' ;
		}
	}

	//Alpha Start
	if ( me_c=='_' || isAlpha(me_c) || me_c == '$' || me_c == '/' || isDigit((char)me_c) ) {
		CString	TokenImage ;
		do {
			TokenImage += (TCHAR)me_c ;
		} while ( (me_c=getc()) != TT_EOF && (me_c=='_' || me_c == '$' || me_c=='.'|| isDigit((char)me_c) || isAlpha(me_c)) ) ;

		ungetc() ;
		setTokenImage(TokenImage) ;

		for(int i = 0; TB_TOKEN_TABLE[i].lpszIdName; i++) {
			if( GetTokenImage() == TB_TOKEN_TABLE[i].lpszIdName ) {
				return TB_TOKEN_TABLE[i].nTokenId ;
			}
		}

		return TT_IDENTIFIER ;
	}

	switch (me_c) {
	case '\n':
		m_LineCount ++ ;
		setTokenImage(me_c) ;
		return TT_EOL ;
	default:
		setTokenImage(me_c) ;
		return me_c;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		"'"～"'"の間の文字列を抽出する
//
//	２．インターフェイス
//		void CSXFHeaderLex::consumeQuote(CString& str)
//
//		引数: 型				引数名			    内容
//			CString&		str			文字列格納用CString
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::consumeQuote(CString& str)
{
	if( !str.IsEmpty() ) {
		str.Empty() ;
	}

	int	token ;
	while( (token = getc()) != TT_EOF ) {
		if( token == TT_EOL ) {
			return ;
		}

		if( token == '\'' ) {
			if( getc() == '\'') {
				str += (TCHAR)token ;
			} else {
				ungetc() ;
				return ;
			}
		}
		str += (TCHAR)token ;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		英字かどうかを判定する
//
//	２．インターフェイス
//		BOOL CSXFHeaderLex::isAlpha(TCHAR ch)
//
//		引数: 型			引数名		内容
//			TCHAR			ch			文字
//
//		復帰値
//			TRUE :英字
//			FALSE:英字以外
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
BOOL CSXFHeaderLex::isAlpha(TCHAR ch)
{
	return	( 'A' <= ch && ch <= 'z') ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		数字かどうかを判定する
//
//	２．インターフェイス
//		BOOL CSXFHeaderLex::isDigit(TCHAR ch)
//
//		引数: 型			引数名		内容
//			TCHAR			ch			文字
//
//		復帰値
//			TRUE :数字
//			FALSE:数字以外
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
BOOL CSXFHeaderLex::isDigit(TCHAR ch)
{
	return	( '0' <= ch && ch <= '9') ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		カレント1文字取得
//
//	２．インターフェイス
//		TCHAR CSXFHeaderLex::getc()
//
//		引数:なし
//
//		復帰値
//			文字
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
TCHAR CSXFHeaderLex::getc()
{
	//
	// <終端>
	if( m_sString.GetLength() <= m_Pointer ) {
		return TT_EOF ;
	}
	TCHAR	ret = m_sString[m_Pointer] ;
	m_Pointer ++ ;
	return	ret ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		カレントポインタを1つ前に戻す
//
//	２．インターフェイス
//		TCHAR CSXFHeaderLex::ungetc()
//
//		引数:なし
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::ungetc()
{
	if( m_Pointer > 0 ) {
		m_Pointer -- ;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		トークンを設定する
//
//	２．インターフェイス
//		void CSXFHeaderLex::setTokenImage(CString str)
//
//		引数: 型			引数名		内容
//			CString			str			文字列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::setTokenImage(CString str)
{
	m_Token = str ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					作成日：2001.09.17
//
//	１．機能概要
//		トークンを設定する
//
//	２．インターフェイス
//		void CSXFHeaderLex::setTokenImage(TCHAR str)
//
//		引数: 型			引数名		内容
//			TCHAR			str			文字列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::setTokenImage(TCHAR str)
{
	m_Token = str ;
}
