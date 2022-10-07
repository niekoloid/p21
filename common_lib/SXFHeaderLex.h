//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFHeaderLex.h					作成日：2001.09.17
//
//	１．クラス概要
//		字句解析を行うクラス
//
//	２．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)	ヘッダ解析処理の改善対応
//
//---------------------------------------------------------

#if !defined(AFX_SXFHEADERLEX_H__D3AA1A5C_A983_42EF_AEFB_7597A6D9ADED__INCLUDED_)
#define AFX_SXFHEADERLEX_H__D3AA1A5C_A983_42EF_AEFB_7597A6D9ADED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afx.h"

#define TT_EOF					-1
#define TT_EOL					'\n'
#define TT_INTEGER				-2
#define TT_REAL					-3
#define TT_WORD					-4
#define TT_STRING				-5
#define	TT_LINE_COMMENT			-6
#define	TT_BLOCK_COMMENT_START	-7
#define	TT_BLOCK_COMMENT_END	-8
#define	TT_IDENTIFIER			-9
#define	TT_HEADER				-10
#define	TT_FILE_DESCRIPTION		-11
#define	TT_FILE_NAME			-12
#define	TT_FILE_SCHEMA			-13
#define	TT_ENDSEC				-14

typedef struct  {
	char*	lpszIdName ;
	int		nTokenId ;
} TOKEN_ELEM_DATA ;

static TOKEN_ELEM_DATA	TB_TOKEN_TABLE[] = {
	{"HEADER",			TT_HEADER},
	{"FILE_DESCRIPTION",TT_FILE_DESCRIPTION},
	{"FILE_NAME",		TT_FILE_NAME},
	{"FILE_SCHEMA",		TT_FILE_SCHEMA},
	{"ENDSEC",			TT_ENDSEC},
	{NULL,				0},
} ;

class CSXFHeaderLex  
{
public:
	//	コンストラクタ
	CSXFHeaderLex(CString& string);

	//	デストラクタ
	virtual ~CSXFHeaderLex();

	int GetLineNo() ;
	CString& GetTokenImage() ;
	int	Lex() ;

protected:
	int		m_Pointer ;
	int		m_LineCount ;
	CString	m_sString ;
	CString	m_Token ;

private:
	TCHAR	getc() ;
	void	ungetc() ;
	void	setTokenImage(CString str) ;
	void	setTokenImage(TCHAR str) ;
	BOOL	isAlpha(TCHAR ch) ;
	BOOL	isDigit(TCHAR ch) ;
	void	consumeQuote(CString& str) ;
};

#endif // !defined(AFX_SXFHEADERLEX_H__D3AA1A5C_A983_42EF_AEFB_7597A6D9ADED__INCLUDED_)
