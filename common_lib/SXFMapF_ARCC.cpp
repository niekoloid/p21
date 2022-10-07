/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						作成日：2000.04.17

	１．クラス概要
		円弧フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ARCC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_ARCC::SXFMapF_ARCC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_ARCC::SXFMapF_ARCC()
{
	m_center_x    = 0.0;
	m_center_y    = 0.0;
	m_radius      = 0.0;
	m_direction   = 0;
	m_start_angle = 0.0;
	m_end_angle   = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_ARCC::~SXFMapF_ARCC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_ARCC::~SXFMapF_ARCC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_ARCC::GetStructData()

	引数  ：	型				引数名				内容
				Arc_Struct* 	INOUT_Struct    	構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_ARCC::GetStructData( Arc_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->center_x      = m_center_x;   		//中心Ｘ座標
	INOUT_Struct->center_y   	= m_center_y;   		//中心Ｙ座標
	INOUT_Struct->radius 		= m_radius;     	    //半径
	INOUT_Struct->direction  	= m_direction;  		//向きフラグ
	INOUT_Struct->start_angle	= m_start_angle;		//始角
	INOUT_Struct->end_angle  	= m_end_angle;  		//終角

	return TRUE;
}
