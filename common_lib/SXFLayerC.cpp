//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFLayerC.cpp                           作成日：2000.04.16
//
//	１．クラス概要
//      Layer Instance Table Dataを管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFLayerC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFLayerC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//		void	SXFLayerC::SXFLayerC()
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFLayerC::SXFLayerC()
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	m_LfFlag = -1;
	m_ElementsReferenceID = -1;
	m_Element.RemoveAll();
	m_SheetID = -1;
	m_MappingManager = NULL;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFLayerC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//		void	SXFLayerC::~SXFLayerC()
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFLayerC::~SXFLayerC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFLayerC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//      Overload the preprocessor symbol "="
//
//  ２．インターフェース
//		SXFLayerC& SXFLayerC::operator=(const SXFLayerC &IN_Layer)
//		
//	引数	：	型			引数名		内容
//				SXFLayerC&  IN_Layer	レイヤオブジェクトのアドレス
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFLayerC& SXFLayerC::operator=(const SXFLayerC &IN_Layer)
{
	m_Code = IN_Layer.m_Code;
	m_ID = IN_Layer.m_ID;
	m_Name = IN_Layer.m_Name;
	m_LfFlag = IN_Layer.m_LfFlag;
	m_ElementsReferenceID = IN_Layer.m_ElementsReferenceID;

//	MOD(S)	チューニング対応	K.Naono	03.07.04
//	for (int i = 0; i < IN_Layer.m_Element.GetSize(); i++){
//		m_Element.Add(IN_Layer.m_Element[i]);
//	}
	m_Element.Append(IN_Layer.m_Element) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.04
	m_SheetID = IN_Layer.m_SheetID;
	m_MappingManager = IN_Layer.m_MappingManager;
	return *this;

}
