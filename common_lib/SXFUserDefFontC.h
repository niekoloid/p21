//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    作成日：2000.04.16
//
//	１．クラス概要
//      UserDefFont Instance Table Dataを管理する  
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周  
//
//------------------------------------------------------------
#ifndef _SXFUSERDEFFONTC_H_
#define _SXFUSERDEFFONTC_H_

#include <afx.h>
#include <afxtempl.h>

class SXFTableMapManagerC;

class SXFUserDefFontC  
{
public:
	SXFUserDefFontC(  );
	virtual ~SXFUserDefFontC();

public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int m_Segment;
	CArray<double,double> m_Pitch;
	SXFUserDefFontC& operator=(const SXFUserDefFontC& IN_Userfont);
	SXFTableMapManagerC* m_MappingManager;
	int m_Level1Code;

};

#endif
