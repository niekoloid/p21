/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SHEETC.cpp						作成日：2000.04.17

	１．クラス概要
		用紙フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_SHEETC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SHEETC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_SHEETC::SXFMapF_SHEETC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SHEETC::SXFMapF_SHEETC()
{
	m_name.Empty();
	m_type   =0;
	m_orient =0;
	m_int_x =0;
	m_int_y =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SHEETC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_SHEETC::~SXFMapF_SHEETC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SHEETC::~SXFMapF_SHEETC()
{
}
    
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SHEETC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_SHEETC::GetStructData(Sheet_Struct* INOUT_Struct)

	引数  ：	型				引数名				内容
				Sheet_Struct* INOUT_Struct    		構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_SHEETC::GetStructData( Sheet_Struct* INOUT_Struct )
{

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->name, m_name );

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

	INOUT_Struct->type	=  m_type;
	INOUT_Struct->orient=  m_orient;
	INOUT_Struct->x		=  m_int_x;
	INOUT_Struct->y		=  m_int_y;

	return TRUE;
}
