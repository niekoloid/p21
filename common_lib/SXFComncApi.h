#ifndef _SXFCOMNCAPI_H_
#define _SXFCOMNCAPI_H_

#include <afx.h>

int	GFn_SplitSEntityAttr(
				LPCTSTR			lpszSrc,
				CStringArray&	arDest) ;
int	GFn_SplitCEntityAttr(
				LPCTSTR			lpszSrc,
				CStringArray&	arDest) ;
int	GFn_SplitString(
				LPCTSTR			lpszSrc,
				int				nCode,
				CStringArray&	arDest) ;
int	GFn_SplitString(
				LPCTSTR			lpszSrc,
				LPCTSTR			lpszCode,
				CStringArray&	arDest) ;

#endif	// _SXFCOMNCAPI_H_
