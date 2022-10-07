/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.cpp						作成日：2000.04.17

	１．クラス概要
		EXHATCHフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_LayerBaseC.h"
#include "SXFMapF_EXHATCHC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_EXHATCHC::SXFMapF_EXHATCHC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_EXHATCHC::SXFMapF_EXHATCHC()
{
	m_out_id = 0;
	m_number = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_EXHATCHC::~SXFMapF_EXHATCHC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_EXHATCHC::~SXFMapF_EXHATCHC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_EXHATCHC::GetStructData( Externally_Defined_Hatch_Struct* INOUT_Struct)

	引数 ：	型									引数名			内容
			Externally_Defined_Hatch_Struct* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_EXHATCHC::GetStructData( Externally_Defined_Hatch_Struct* INOUT_Struct )
{
	INOUT_Struct->layer       = m_layer ;			//レイヤコード

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->name, m_name );	//ハッチング名

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

	INOUT_Struct->out_id    = m_out_id;
	INOUT_Struct->number    = m_number;

	INOUT_Struct->in_id.Copy( m_in_id );

	return TRUE;
}
