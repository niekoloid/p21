//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    作成日：2000.04.16
//
//	１．クラス概要
//      PreDefFont Instance Table Dataを管理する    
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFPreLineTypeTableC.h"
#include "SXFPreDefFontC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//	void	SXFPreDefFontC::SXFPreDefFontC()
//	引数:	型						引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFPreDefFontC::SXFPreDefFontC()
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	m_MappingManager = NULL;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//	void	SXFPreDefFontC::~SXFPreDefFontC()
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFPreDefFontC::~SXFPreDefFontC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    作成日：2000.04.16
//
//  １．機能概要
//      PreDefFont Nameの設定（Codeを決めます）
//  ２．インターフェース
//      BOOL SetName(LPCTSTR IN_Name)
//	    引数: 型			  引数名			    内容
//            LPCTSTR        IN_Name               既定義線種名
//			
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
BOOL SXFPreDefFontC::SetName(LPCTSTR IN_Name)
{
	SXFPreLineTypeTableC prelinetypetable;
	m_Code = prelinetypetable.GetPreCode(IN_Name);
	if(m_Code <= 0)
		return FALSE;
	m_Name=IN_Name;
	return TRUE;
}