//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTextFontC.cpp                        作成日：2000.04.16
//
//	１．クラス概要
//     TextFont Instance Table Dataを管理する
// 
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------

#include "stdafx.h"
#include "SXFTextFontC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTextFontC.cpp                        作成日：2000.04.16
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//		void	SXFTextFontC::SXFTextFontC( )
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFTextFontC::SXFTextFontC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Ascent=1.0;
	m_Decent=0.0;
	m_Name.Empty();
	m_MappingManager = NULL;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTextFontC.cpp                        作成日：2000.04.16
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//		void	SXFTextFontC::~SXFTextFontC( )
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFTextFontC::~SXFTextFontC()
{
}
