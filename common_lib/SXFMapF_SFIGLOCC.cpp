/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SFIGLOCC.cpp						作成日：2000.04.17

	１．クラス概要
		複合図形配置フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_SFIGLOCC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_SFIGLOCC::SXFMapF_SFIGLOCC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SFIGLOCC::SXFMapF_SFIGLOCC()
{
	m_start_x = 0.0;	    //配置位置X座標
	m_start_y = 0.0;		//配置位置Y座標
	m_angle   = 0.0;		//回転角
	m_ratio_x = 0.0;		//X方向尺度
	m_ratio_y = 0.0;		//Y方向尺度
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_SFIGLOCC::~SXFMapF_SFIGLOCC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SFIGLOCC::~SXFMapF_SFIGLOCC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_SFIGLOCC::GetStructData(Sfigloc_StructDF* INOUT_Struct)

	引数 ：	型					引数名			内容
			Sfigloc_StructDF* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_SFIGLOCC::GetStructData( Sfigloc_StructDF* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->name, m_name );			//複合図形名

	// 文字要素と同じく257バイト以上の文字列は256に切り詰める
	size_t ilen = strlen(m_name);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name );
	}
	else {
		/* メッセージを出力 */
		// ここも m_RootID = 0,m_TypeName == "" だけど文字要素と同じ処理にしておく
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* 先頭から256バイト切り取る */
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name.Left(256) );
	}
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	INOUT_Struct->x      = m_start_x     ;			//配置位置X座標
	INOUT_Struct->y      = m_start_y     ;			//配置位置Y座標
	INOUT_Struct->angle      = m_angle   ;			//回転角
	INOUT_Struct->ratio_x    = m_ratio_x ;			//X方向尺度
	INOUT_Struct->ratio_y    = m_ratio_y ;			//y方向尺度

	return TRUE;
}
