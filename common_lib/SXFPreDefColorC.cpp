//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.cpp                    作成日：2000.04.16
//
//	１．クラス概要
//      PreDefColor Instance Table Dataを管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFRGBTableC.h"
#include "SXFPreDefColorC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//		void	SXFPreDefColorC::SXFPreDefColorC( )
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFPreDefColorC::SXFPreDefColorC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	R=-1;
	G=-1;
	B=-1;
	m_MappingManager = NULL;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//	void	SXFPreDefColorC::~SXFPreDefColorC()
//	
//	引数:	型						引数名				内容
//			なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFPreDefColorC::~SXFPreDefColorC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      Color Nameの設定
//
//  ２．インターフェース
//      BOOL SetName(LPCTSTR IN_Name)
//
//	    引数: 型			  引数名			    内容
//            LPCTSTR        IN_Name               既定義色名
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
BOOL SXFPreDefColorC::SetName(LPCTSTR IN_Name)
{
	SXFRGBTableC RGBtable;
	if (!RGBtable.GetRGB(IN_Name, m_Code, R, G, B ))
		return FALSE;
	m_Name = IN_Name;
	return TRUE;
}