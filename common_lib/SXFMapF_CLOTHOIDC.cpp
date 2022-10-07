/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						作成日：2007.01.30

	１．クラス概要
		クロソイドフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2007.01.30	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_CLOTHOIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_CLOTHOIDC::SXFMapF_CLOTHOIDC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
SXFMapF_CLOTHOIDC::SXFMapF_CLOTHOIDC()
{
	base_x = 0.0;
	base_y = 0.0;
	parameter = 0.0;
	direction = 0;
	angle = 0.0;
	start_length = 0.0;
	end_length = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_CLOTHOIDC::~SXFMapF_CLOTHOIDC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
SXFMapF_CLOTHOIDC::~SXFMapF_CLOTHOIDC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_CLOTHOIDC::GetStructData(Clothoid_Struct* INOUT_Struct)

	引数  ：	型				引数名				内容
				Clothoid_Struct* 	INOUT_Struct    	構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
BOOL SXFMapF_CLOTHOIDC::GetStructData( Clothoid_Struct* INOUT_Struct )
{
#include "SXFMapF_CurveStyleBaseC.h"

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->base_x = base_x;
	INOUT_Struct->base_y = base_y;
	INOUT_Struct->parameter = parameter;
	INOUT_Struct->direction = direction;
	INOUT_Struct->angle = angle;
	INOUT_Struct->start_length = start_length;
	INOUT_Struct->end_length = end_length;

	return TRUE;
}
