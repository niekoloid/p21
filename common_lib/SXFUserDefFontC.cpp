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
#include "stdafx.h"
#include "SXFUserDefFontC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    作成日：2000.04.16
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//	void	SXFUserDefFontC::SXFUserDefFontC( )
//	引数:	型						引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周  
//
//------------------------------------------------------------
SXFUserDefFontC::SXFUserDefFontC( )
{
	//initialization
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	m_Segment = -1;
	m_Pitch.RemoveAll();
	m_MappingManager = NULL;
	m_Level1Code = -1;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    作成日：2000.04.16
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//	void	SXFUserDefFontC::~SXFUserDefFontC()
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周  
//
//------------------------------------------------------------
SXFUserDefFontC::~SXFUserDefFontC()
{
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    作成日：2000.04.16
//
//  １．機能概要
//      Overload the preprocessor symbol "="
//      
//  ２．インターフェース
//	SXFUserDefFontC&	SXFUserDefFontC::operator=(const SXFUserDefFontC& IN_Userfont)
//	引数:	型								引数名				内容
//			SXFUserDefFontC&				IN_Userfont			ユーザ定義線種
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周  
//
//------------------------------------------------------------

SXFUserDefFontC& SXFUserDefFontC::operator=(const SXFUserDefFontC& IN_Userfont){
	m_Code = IN_Userfont.m_Code;
	m_ID = IN_Userfont.m_ID;
	m_Name = IN_Userfont.m_Name;
	m_Segment = IN_Userfont.m_Segment;

//	MOD(S)	チューニング対応	K.Naono	03.07.03
//	for (int i = 0; i < m_Segment; i++){
//		m_Pitch.Add(IN_Userfont.m_Pitch[i]);
//	}
	m_Pitch.Append(IN_Userfont.m_Pitch) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	m_MappingManager = IN_Userfont.m_MappingManager;
	m_Level1Code = IN_Userfont.m_Level1Code;

	return *this;
}
