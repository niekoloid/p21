/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						作成日：2000.04.17

	１．クラス概要
		ハッチング（塗り）フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_FILLCOLOURC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_FILLCOLOURC::SXFMapF_FILLCOLOURC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_FILLCOLOURC::SXFMapF_FILLCOLOURC()
{
	m_out_id = 0;
	m_number = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_FILLCOLOURC::~SXFMapF_FILLCOLOURC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_FILLCOLOURC::~SXFMapF_FILLCOLOURC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLCOLOURC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_FILLCOLOURC::GetStructData(Fill_area_style_colour_Struct* INOUT_Struct)

	引数 ：	型								引数名			内容
			Fill_area_style_colour_Struct* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_FILLCOLOURC::GetStructData( Fill_area_style_colour_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード

	INOUT_Struct->out_id    = m_out_id;
	INOUT_Struct->number    = m_number;

	INOUT_Struct->in_id.Copy( m_in_id );

	return TRUE;
}
