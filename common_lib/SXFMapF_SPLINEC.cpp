/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SPLINEC.cpp						作成日：2000.04.17

	１．クラス概要
		スプラインフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_SPLINEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_SPLINEC::SXFMapF_SPLINEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SPLINEC::SXFMapF_SPLINEC()
{
	m_open_close = 0;
	m_number = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_SPLINEC::~SXFMapF_SPLINEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SPLINEC::~SXFMapF_SPLINEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SPLINEC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_SPLINEC::GetStructData(Spline_Struct* INOUT_Struct)

	引数  ：	型				引数名				内容
				Spline_Struct* 	INOUT_Struct    	構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_SPLINEC::GetStructData( Spline_Struct* INOUT_Struct )
{
#include "SXFMapF_CurveStyleBaseC.h"

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->open_close = m_open_close;		//開閉区分
	INOUT_Struct->number     = m_number;			//頂点数

    INOUT_Struct->x.Copy( m_x );	//X座標
	INOUT_Struct->y.Copy( m_y );	//Y座標

	return TRUE;
}
