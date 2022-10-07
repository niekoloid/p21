/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						作成日：2000.04.17

	１．クラス概要
		既定義シンボルフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_EXSYMBOLC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_EXSYMBOLC::SXFMapF_EXSYMBOLC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_EXSYMBOLC::SXFMapF_EXSYMBOLC()
{
	m_start_x = 0.0;	    //配置位置X座標
	m_start_y = 0.0;		//配置位置Y座標
	m_rotate_angle = 0.0;	//回転角
	m_scale = 0.0;			//倍率
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_EXSYMBOLC::~SXFMapF_EXSYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_EXSYMBOLC::~SXFMapF_EXSYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_EXSYMBOLC::GetStructData(Externally_Defined_Symbol_Struct* INOUT_Struct)

	引数：	型									引数名			内容
			Externally_Defined_Symbol_Struct 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_EXSYMBOLC::GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color_flag  = m_color_flag ;		//色コードフラグ
	INOUT_Struct->color       = m_color ;			//色コード

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->name, m_name );	//シンボル名

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

	INOUT_Struct->start_x      = m_start_x     ;			//配置位置X座標
	INOUT_Struct->start_y      = m_start_y     ;			//配置位置Y座標
	INOUT_Struct->rotate_angle = m_rotate_angle;			//回転角
	INOUT_Struct->scale        = m_scale       ;			//倍率

	return TRUE;
}
