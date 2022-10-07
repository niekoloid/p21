//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   作成日：2000.04.10
//
//	１．クラス概要
//      UserDefColor Instance Table Dataを管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.10     周
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFUserDefColorC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   作成日：2000.04.10
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
// 	void	SXFUserDefColorC::SXFUserDefColorC( )
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.10     周
//
//------------------------------------------------------------
SXFUserDefColorC::SXFUserDefColorC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	R=-1;
	G=-1;
	B=-1;
	m_MappingManager = NULL;
	m_Level1Code = -1;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   作成日：2000.04.10
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//	void	SXFUserDefColorC::~SXFUserDefColorC()
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.10     周
//
//------------------------------------------------------------
SXFUserDefColorC::~SXFUserDefColorC()
{
}
