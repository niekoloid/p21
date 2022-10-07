/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						作成日：2000.04.17

	１．クラス概要
		FILLHATCHINGフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_FILLHATCHINGC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_FILLHATCHINGC::SXFMapF_FILLHATCHINGC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_FILLHATCHINGC::SXFMapF_FILLHATCHINGC()
{
	int m_hatch_number = 0;
	for(int i=0;i<MAXHATCHNUMBER;i++){
		m_hatch_color[i] = 0;
		m_hatch_type[i] = 0;
		m_hatch_line_width[i] = 0;
		m_hatch_start_x[i] = 0.0;
		m_hatch_start_y[i] = 0.0;
		m_hatch_spacing[i] = 0.0;
		m_hatch_angle[i] = 0.0;
	}
	int m_out_id = 0;
	int m_number = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_FILLHATCHINGC::~SXFMapF_FILLHATCHINGC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_FILLHATCHINGC::~SXFMapF_FILLHATCHINGC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_FILLHATCHINGC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_FILLHATCHINGC::GetStructData(Fill_area_style_hatching_Struct* INOUT_Struct)

	引数 ：	型									引数名			内容
			Fill_area_style_hatching_Struct* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_FILLHATCHINGC::GetStructData( Fill_area_style_hatching_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//レイヤコード

	INOUT_Struct->hatch_number  = m_hatch_number;	//ハッチング線のパターン数

	for(int i=0;i<MAXHATCHNUMBER;i++){
		INOUT_Struct->hatch_color[i]      =  m_hatch_color[i];	
		INOUT_Struct->hatch_type[i]       =  m_hatch_type[i];	
		INOUT_Struct->hatch_line_width[i] = m_hatch_line_width[i];
		INOUT_Struct->hatch_start_x[i]    =  m_hatch_start_x[i];
		INOUT_Struct->hatch_start_y[i]    =  m_hatch_start_y[i];
		INOUT_Struct->hatch_spacing[i]    =  m_hatch_spacing[i];
		INOUT_Struct->hatch_angle[i]      =  m_hatch_angle[i];
	}

	INOUT_Struct->out_id = m_out_id;			//外形の複合曲線のフィーチャコード
	INOUT_Struct->number = m_number;			//中抜きの領域数

	INOUT_Struct->in_id.Copy( m_in_id);			//中抜きの複合曲線のフィーチャコード

	return TRUE;
}
