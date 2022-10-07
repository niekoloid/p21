/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                作成日：2000.04.29

	１．クラス概要
		線幅テーブル情報を管理する

	２．履歴
	    履歴番号    日付け         担当者		概要
		作成		2000.4.29     宮園(FQS)
**/
#include "stdafx.h"
#include <math.h>
#include "SXFPreWidthTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                作成日：2000.04.29

  １．機能概要
      コンストラクタ

  ２．インターフェース
		void	SXFPreWidthTableC::SXFPreWidthTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
SXFPreWidthTableC::SXFPreWidthTableC()
{
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 1, 0.13) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 2, 0.18) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 3, 0.25) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 4, 0.35) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 5, 0.5) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 6, 0.7) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 7, 1.0) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 8, 1.4) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 9, 2.0) );
/*  2012.05.21 トレランスよりも小さい値が0になるため削除
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC(10, 0.0) );
*/
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                作成日：2000.04.29

  １．機能概要
      デストラクタ

  ２．インターフェース
		void	SXFPreWidthTableC::~SXFPreWidthTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
SXFPreWidthTableC::~SXFPreWidthTableC(){
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                作成日：2000.04.29

  １．機能概要
      コードに対応する線幅を取得する

  ２．インターフェース
		BOOL SXFPreWidthTableC::GetPreWidth(int in_code, 
												double &out_width)

	引数	：	型		引数名		内容
				int		in_code		線幅コード
				double&	out_width	線幅

	復帰値
			TRUE		対応する線幅あり
			FALSE		対応する線幅なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
BOOL SXFPreWidthTableC::GetPreWidth(int in_code, double &out_width)
{
/*  2012.09.01 Tableのサイズが小さくなったため変更
	if(in_code >= m_DefaultPreWidthTable.GetSize() )
*/
	if(in_code > m_DefaultPreWidthTable.GetSize() )
		return FALSE;

	m_DefaultPreWidthTable[in_code-1].GetWidth(out_width);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                作成日：2000.04.29

  １．機能概要
      線幅に対応するコードを取得する

  ２．インターフェース
		int SXFPreWidthTableC::GetCode(double IN_Width,double IN_Eps)

	引数	：	型		引数名		内容
				double	IN_width	線幅
				double	IN_Eps		許容誤差

	復帰値
			int		code	線幅コード(0:対応する線幅ｺｰﾄﾞなし)

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
int SXFPreWidthTableC::GetCode(double IN_Width,double IN_Eps)
{
	for(int i=0;i<m_DefaultPreWidthTable.GetSize();i++){

/* 2012.05.21 配列の範囲を超えてアクセスしていたので削除
		if ((fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < IN_Eps) &&
			(fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < fabs(IN_Width - m_DefaultPreWidthTable[i+1].m_Width)))
*/
		if (fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < IN_Eps) // 2012.05.21
		return m_DefaultPreWidthTable[i].m_Code;
	}
	return 0;
}