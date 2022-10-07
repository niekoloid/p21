//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTextFontC.h                        作成日：2000.04.16
//
//	１．クラス概要
//		TextFont Instance Table Dataを管理する
// 
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
#ifndef _SXFTEXTFONTC_H_
#define _SXFTEXTFONTC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFTextFontC
{
public:
	SXFTextFontC(  );
	virtual ~SXFTextFontC();

public:
	int m_Code;
	int m_ID;
	double m_Ascent;
	double m_Decent;

	CString m_Name;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
