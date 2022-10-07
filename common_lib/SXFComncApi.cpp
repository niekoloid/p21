#include "stdafx.h"
#include "SXFComncApi.h"

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					作成日：2003.07.03
//
//	１．機能概要
//		属性情報文字列をカンマ(,)をセパレートとして
//		分割する
//
//	２．インターフェイス
//      GFn_SplitSEntityAttr(
//					LPCTSTR			lpszSrc,
//					CStringArray&	arDest)
//
//		引数: 型			引数名			内容
//			LPCTSTR			lpszSrc			属性情報文字列
//			CStringArray&	arDest			分割文字列格納配列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		担当者			概要
//		作成		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitSEntityAttr(
					LPCTSTR			lpszSrc,
					CStringArray&	arDest) {

	LPCTSTR		p = lpszSrc ;
	LPCTSTR		pS = p ;
	int			nBracket = 0 ;
	bool		fQuot = false ;

	while(true) {
		switch(p[0]) {
		case 0 :
			goto EXIT_LABEL ;

		case '(' :
			if( fQuot ) {
				break ;
			}
			++nBracket ;
			if( nBracket == 1 ) {
				pS = _tcsinc(pS) ;
			}
			break ;

		case ')' :
			if( fQuot ) {
				break ;
			}
			--nBracket ;
			if( nBracket < 1 ) {
				goto EXIT_LABEL ;
			}
			break ;

		case '\'' :
			fQuot = !fQuot ;
			break ;

		case ',' :
			if( !fQuot && nBracket == 1 ) {
				goto NEXT_LABEL ;
			}
			break ;

		default :
			break ;
		}
		p = _tcsinc(p) ;
		continue ;

	NEXT_LABEL :
		CString o(pS, (int)(p - pS)) ;
		arDest.Add(o) ;
		p = _tcsinc(p) ;
		pS = p ;
		continue ;
	}

EXIT_LABEL :
	CString o(pS, (int)(p - pS)) ;
	arDest.Add(o) ;

	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					作成日：2003.07.03
//
//	１．機能概要
//		複合エンティティ文字列からエンティティ単位に
//		分割する
//
//	２．インターフェイス
//      GFn_SplitCEntityAttr(
//					LPCTSTR			lpszSrc,
//					CStringArray&	arDest)
//
//		引数: 型			引数名			内容
//			LPCTSTR			lpszSrc			属性情報文字列
//			CStringArray&	arDest			分割文字列格納配列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		担当者			概要
//		作成		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitCEntityAttr(
					LPCTSTR			lpszSrc,
					CStringArray&	arDest) {

	LPCTSTR		p = lpszSrc ;
	LPCTSTR		pS = p ;
	int			nBracket = 0 ;
	bool		fQuot = false ;

	while(true) {
		switch(p[0]) {
		case 0 :
			goto EXIT_LABEL ;

		case '(' :
// ADD(S)	K.Naono	04.02.27
			if( fQuot ) {
				break ;
			}
// ADD(E)	K.Naono	04.02.27
			++nBracket ;
			if( nBracket == 1 ) {
				pS = _tcsinc(pS) ;
			}
			break ;

		case ')' :
// ADD(S)	K.Naono	04.02.27
			if( fQuot ) {
				break ;
			}
// ADD(E)	K.Naono	04.02.27
			--nBracket ;
			if( nBracket == 1 ) {
				goto NEXT_LABEL ;
			}

			if( nBracket < 1 ) {
				goto EXIT_LABEL ;
			}
			break ;
// ADD(S)	K.Naono	04.02.27
		case '\'' :
			fQuot = !fQuot ;
			break ;
// ADD(E)	K.Naono	04.02.27

		default :
			break ;
		}
		p = _tcsinc(p) ;
		continue ;

	NEXT_LABEL :
		CString o(pS, (int)( p - pS + 1)) ;
		arDest.Add(o) ;
		p = _tcsinc(p) ;
		pS = p ;
		continue ;
	}

EXIT_LABEL :
	if( p != pS ) {
		CString o(pS, (int)(p - pS)) ;
		arDest.Add(o) ;
	}

	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					作成日：2003.07.03
//
//	１．機能概要
//		指定された区切り文字で文字列を分割する
//
//	２．インターフェイス
//      GFn_SplitString(
//					LPCTSTR			lpszSrc,
//					int				nCode,
//					CStringArray&	arDest)
//
//		引数: 型			引数名			内容
//			LPCTSTR			lpszSrc			属性情報文字列
//			int				nCode			区切り文字コード
//			CStringArray&	arDest			分割文字列格納配列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		担当者			概要
//		作成		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitString(
					LPCTSTR			lpszSrc,
					int				nCode,
					CStringArray&	arDest) {

	arDest.SetSize(0) ;

	CString	str ;
	char	*dp, *p ;

	for(dp=p=(char*)lpszSrc; p; dp=p+1) {
		if( (p=strchr(dp,nCode)) ) {
			p[0] = NULL ;
		}
		str = dp ;
		arDest.Add(str) ;
	}
	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					作成日：2003.07.03
//
//	１．機能概要
//		指定された区切り文字で文字列を分割する
//
//	２．インターフェイス
//      GFn_SplitString(
//					LPCTSTR			lpszSrc,
//					LPCTSTR			lpszCode,
//					CStringArray&	arDest)
//
//		引数: 型			引数名			内容
//			LPCTSTR			lpszSrc			属性情報文字列
//			LPCTSTR			lpszCode		区切り文字列
//			CStringArray&	arDest			分割文字列格納配列
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		担当者			概要
//		作成		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitString(
					LPCTSTR			lpszSrc,
					LPCTSTR			lpszCode,
					CStringArray&	arDest) {

	arDest.SetSize(0) ;

	CString	str ;
	char	*dp, *p ;

	for(dp=p=(char*)lpszSrc; p; dp=p+1) {
		if( (p=strstr(dp,lpszCode)) ) {
			memset(p,0x00,strlen(lpszCode)) ;
			p += (strlen(lpszCode)-1) ;
		}
		else{
			break;
		}
		str = dp ;
		arDest.Add(str) ;
	}
	return (int)arDest.GetSize() ;
}
