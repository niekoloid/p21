/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
	  文字列操作クラス

	２.メンバー関数一覧
	  SXFTokenC()
	  ~SXFTokenC()
	  void Set(LPCSTR IN_Lps)
	  CString CurText()
	  BOOL GetToken()


	３．履歴
	履歴番号	日付		担当者		概要
	作成		2000.04.27	藤本(FQS)	なし。

**/
#include "stdafx.h"
#include "SXFTokenC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
		SXFTokenC クラスのコンストラクタ

	２．インターフェイス
		SXFTokenC::SXFTokenC()
		引  数：型			引数名		内容
				なし。

		復帰値：なし。

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.27	藤本(FQS)	なし。
**/
SXFTokenC::SXFTokenC()
{
	m_eof = FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
		SXFTokenC クラスのデストラクタ

	２．インターフェイス
		SXFTokenC::~SXFTokenC()

		引  数：型			引数名		内容
				なし。

		復帰値：なし。

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.27	藤本(FQS)	なし。
**/
SXFTokenC::~SXFTokenC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
		文字列をセットする

	２．インターフェイス
		void SXFTokenC::Set(LPCSTR IN_Lps)

		引  数：型			引数名		内容
			  LPCSTR		IN_Lps		文字列

		復帰値：なし。

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.27	藤本(FQS)	なし。
**/ 
void SXFTokenC::Set(LPCSTR IN_Lps)
{
	m_source = IN_Lps;	// 文字列
	m_lps = m_source;	// 文字列ポインタ用
	getc();
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
		現在、未使用

	２．インターフェイス
		CString SXFTokenC::CurText()

		引  数：型			引数名		内容
				なし。

		復帰値：文字列

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.27	藤本(FQS)	なし。
**/
CString SXFTokenC::CurText()
{
	CString	s = m_string;
	s += static_cast<CHAR>(m_cur);
	const char *p = strchr(m_lps, '\n');
	if (p) p = strchr(p, '\n');
	if (p) {
		s += ((CString)m_lps).Left((int)( p - m_lps ));
	}
	else {
		s += m_lps;
	}
	return s;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFTokenC.cpp

	１．機能概要
		文字列からトークンを取得する

	２．インターフェイス
		BOOL SXFTokenC::GetToken()

		引  数：型			引数名		内容
				なし。

		復帰値：トークが取得された場合はTRUE、それ以外はFALSE

	３．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.27	藤本(FQS)	なし。
**/
BOOL SXFTokenC::GetToken()
{
	// 解析する文字列が存在するかチェックする
	if (m_cur == 0) {
		m_eof = TRUE;
		m_Type = T_EOF;
		return FALSE;
	}

	//
	char buf[10240];//zyx 0523 1024->10240
	char *bp = buf;
	*bp = 0;
	
	//START:
	// スペース、改行を読み飛ばす
	while (m_cur == ' ' || m_cur == '\n') getc();

	// 解析する文字列が存在するかチェックする
	if (m_cur == 0) {
		m_eof = TRUE;
		m_Type = T_EOF;
		return FALSE;
	}

	// 
	if (isalpha(m_cur) || m_cur == '_') {
		// 英数字と'_'で構成される文字列
		while (isalnum(m_cur) || m_cur == '_') {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_STRING;
	}
	// 
	else if (isdigit(m_cur)) {
DIGIT:
		// 数字と'.'で構成される文字列
		BOOL	bReal = FALSE;
		BOOL	bInvalid = FALSE;
		while (isdigit(m_cur)) {
			*bp++ = m_cur;
			getc();
		}
		if (m_cur == '.') {
			// 小数点
			bReal = TRUE;
			*bp++ = m_cur;
			getc();
			// 小数点以下の数字
			while (isdigit(m_cur)) {
				*bp++ = m_cur;
				getc();
			}
		}
		if (m_cur == 'E' || m_cur == 'e') {
			// 指数部
			bReal = TRUE;
			*bp++ = m_cur;
			getc();
			if (m_cur == '+' || m_cur == '-') {
				// 符号
				*bp++ = m_cur;
				getc();
			}
			if (isdigit(m_cur)) {
				// 指数部の数字
				while (isdigit(m_cur)) {
					*bp++ = m_cur;
					getc();
				}
			}
			else {
				// 認識不能
				*bp++ = m_cur;
				getc();
				bInvalid = TRUE;
			}
		}
		if (isalnum(m_cur)) {
			// 認識不能
			bInvalid = TRUE;
			while (isalnum(m_cur)) {
				*bp++ = m_cur;
				getc();
			}
		}

		*bp = 0;
		if (bInvalid) {
			m_Type = T_STRING;
		}
		else if (bReal) {
			m_Type = T_REAL;
		}
		else {
			m_Type = T_INTEGER;
		}
	}
// MOD(S)	K.Naono	04.02.09
//	else if (m_cur == '\'' || m_cur == '"') {
	else if (m_cur == '\'') {
		// クオート文字列
		int ch = m_cur;
		*bp++ = m_cur;
		getc();

		// クォートが続く場合('')は取得する
		while( m_cur ) {
			if( m_cur == '\'' ) {
				if( m_lps[0] == '\'' ) {
					*bp++ = m_cur ;
					getc() ;
					getc() ;
					continue ;
				}
				break ;
			}
			*bp++ = m_cur ;
			getc() ;
		}
		*bp++ = m_cur;
		getc();
		*bp = 0;
		m_Type = T_STRING;
	}
	else if (m_cur == '"' ) {
// MOD(E)	K.Naono	04.02.09
		// クオート文字列
		int ch = m_cur;
		*bp++ = m_cur;
		getc();
		while (m_cur && m_cur != ch) {
			*bp++ = m_cur;
			getc();
		}
		*bp++ = m_cur;
		getc();
		*bp = 0;
		m_Type = T_STRING;
	}
	else if (m_cur == '#') {
		// インスタンスID
		*bp++ = m_cur;
		getc();
		while (isdigit(m_cur)) {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_ID;
	}
	else if (m_cur == '-' || m_cur == '+') {
		// マイナス？
		*bp++ = m_cur;
		getc();
		if (isdigit(m_cur)) {
			goto DIGIT;
		}
		else {
			*bp = 0;
			m_Type = T_PUNCT;
		}
	}
	else if (ispunct(m_cur)) {
		// 区切り文字
//		while (ispunct(m_cur)) {
			*bp++ = m_cur;
			getc();
//		}
		*bp = 0;
		m_Type = T_PUNCT;
	}
	else if (m_cur == '\n') {
		// 改行コード
		getc();
		m_Type = T_EOL;
	}
	else {
		// 文字列
		while (m_cur && m_cur != ' ') {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_STRING;
	}
	m_string = buf;

	return TRUE;
}
