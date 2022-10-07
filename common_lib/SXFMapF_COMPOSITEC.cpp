/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.cpp						作成日：2000.04.17

	１．クラス概要
		複合曲線フィーチャを管理するクラス
		
	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_COMPOSITEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_COMPOSITEC::SXFMapF_COMPOSITEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_COMPOSITEC::SXFMapF_COMPOSITEC()
{
	m_flag   =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_COMPOSITEC::~SXFMapF_COMPOSITEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_COMPOSITEC::~SXFMapF_COMPOSITEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_COMPOSITEC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_COMPOSITEC::GetStructData()

	引数 ：	型					引数名			内容
			Ccurve_Org_Struct* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_COMPOSITEC::GetStructData( Ccurve_Org_Struct* INOUT_Struct )
{

	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->flag		  =	m_flag;				//表示/非表示フラグ

	return TRUE;
}

