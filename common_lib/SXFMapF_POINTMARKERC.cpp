/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_POINTMARKERC.cpp						作成日：2000.04.17

	１．クラス概要
		点マーカフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_POINTMARKERC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_POINTMARKERC::SXFMapF_POINTMARKERC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_POINTMARKERC::SXFMapF_POINTMARKERC()
{
	m_start_x = 0.0;	    //配置位置X座標
	m_start_y = 0.0;		//配置位置Y座標
	m_marker_code;			//マーカコード
	m_rotate_angle = 0.0;	//回転角
	m_scale = 0.0;			//尺度
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_POINTMARKERC::~SXFMapF_POINTMARKERC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_POINTMARKERC::~SXFMapF_POINTMARKERC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_POINTMARKERC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_POINTMARKERC::GetStructData()

	引数 ：	型						引数名				内容
			Point_Marker_Struct* 	INOUT_Struct 	   構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_POINTMARKERC::GetStructData( Point_Marker_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード

	INOUT_Struct->start_x       = m_start_x     ;	//配置位置X座標
	INOUT_Struct->start_y       = m_start_y     ;	//配置位置Y座標
	INOUT_Struct->marker_code = m_marker_code;		//マーカコード
	INOUT_Struct->rotate_angle  = m_rotate_angle;	//回転角
	INOUT_Struct->scale         = m_scale       ;	//尺度

	return TRUE;
}
