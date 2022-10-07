//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.h					  作成日：2000.04.16
//
//	１．クラス概要
//		PreDefColor Instance Table Dataを管理する
//
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2000.04.16	   周
//
//------------------------------------------------------------
#ifndef _SXFPREDEFCOLORC_H_
#define _SXFPREDEFCOLORC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFPreDefColorC  
{
public:
	SXFPreDefColorC(  );
	virtual ~SXFPreDefColorC();
	BOOL SetName(LPCTSTR IN_Name);
public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int R,G,B;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
