/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.h								作成日：2000.4.17

	１．クラス概要
		定義テーブル要素のルールチェック

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFCheckInfoC.h"

class SXFTableManagerC;

class SXFTableCheckC  :virtual public SXFCheckInfoC
{
public:
	int ExHatchFeature_Check();
	int SfiglocFeature_Check();
	int ExSymbol_Check(int IN_ColorFlag);
	int PointMarkerFeature_CheckC();
	int DimFeature_Check(int IN_TextFlag);
	int CompCurveFeature_Check();
	int LineFeature_Check();
	int TextFeature_Check();
	int FontCheck();
	int WidthCheck();
	int TypeCheck();
	int ColorCheck();
	int LayerCheck();
	SXFTableCheckC();
	virtual ~SXFTableCheckC();

};

#endif // !defined(AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_)
