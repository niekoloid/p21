//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           作成日：2000.04.16
//
//	１．クラス概要
//		線幅の構造体、コード、インスタンスＩＤなどを保持するクラス
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------

#include "stdafx.h"
#include <afx.h>
#include <math.h>
#include "SXFPreWidthTableC.h"
#include "SXFWidthC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//		コンストラクタ
//
//  ２．インターフェース
//		void	SXFWidthC::SXFWidthC( )
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFWidthC::SXFWidthC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Width = -1.0;
	m_MappingManager = NULL;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//		デストラクタ
//
//  ２．インターフェース
//		void	SXFWidthC::~SXFWidthC( )
//		
//	引数	：	型		引数名				内容
//		なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
SXFWidthC::~SXFWidthC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           作成日：2000.04.16
//
//  １．機能概要
//		線幅に対応するコードを求める
//      
//  ２．インターフェース
//	int InquireCode(double IN_Width,double IN_Eps)
//	引数:	型			引数名			内容
//			double		IN_Width		線幅
//			double		IN_Eps			許容誤差	
//
//	復帰値  
//          正常時：Code	:線幅ｺｰﾄﾞ
//		    異常時：0		:対応する線幅ｺｰﾄﾞなし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
int SXFWidthC::InquireCode(double IN_Width,double IN_Eps)
{
	SXFPreWidthTableC prewidthtable;
	return prewidthtable.GetCode(IN_Width, IN_Eps);
}
