/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								作成日：2000.4.17

	１．クラス概要
		定義テーブル要素のユニークチェックを行う

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFCheckInfoC.h"

class SXFTableManagerC;

class SXFTableUniqueCheckC  :virtual public SXFCheckInfoC
{
public:
	int NameUniqueCheck(int IN_TableType);
	SXFTableUniqueCheckC();
	virtual ~SXFTableUniqueCheckC();

protected:
	double	m_UniqueWidth;		/* 線幅 */
	CString m_UniqueName;		/* 名前 */
};

#endif // !defined(AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_)
