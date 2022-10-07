//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp				   作成日：2001.06.20
//
//	１．クラス概要
//		Feature Assemblyの親子関係を管理する
//
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.20	   佐々木(FQS)		  なし
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFFeatureAssemblyC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp					作成日：2001.06.20
//
//  １．機能概要
//      コンストラクタ
//
//  ２．インターフェース
//		void	SXFFeatureAssemblyC::SXFFeatureAssemblyC()
//		
//	引数	：	型		引数名				内容
//		なし
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.20	   佐々木(FQS)		  なし
//
//------------------------------------------------------------
SXFFeatureAssemblyC::SXFFeatureAssemblyC()
{
	AssemblyCode = -1;
	AssemblyID = -1;
	ChildList = NULL;
	AssemSymbolType = -1;
	AssemSheetType = -1;
	AssemSheetX = 0;
	AssemSheetY = 0;
	AssemSheetOrient = -1;
	AssemCurveFlag = -1;
	m_CurveColour = 0;
	m_CurveType = 0;
	m_CurveWidth = 0;
	m_SfigLocateFlag = -1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp				   作成日：2001.06.20
//
//  １．機能概要
//      デストラクタ
//
//  ２．インターフェース
//		void	SXFFeatureAssemblyC::~SXFFeatureAssemblyC()
//		
//	引数	：	型		引数名				内容
//		なし
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.20	   佐々木(FQS)		  なし
//
//------------------------------------------------------------
SXFFeatureAssemblyC::~SXFFeatureAssemblyC()
{
	if(ChildList != NULL){
		POSITION childpos = ChildList->GetHeadPosition();
		while(childpos!=NULL){
			SXFFeatureChildC* child = ChildList->GetAt(childpos);
			if(child!=NULL)
				delete child;
			ChildList->GetNext(childpos);
		}
		delete ChildList;
	}
}
