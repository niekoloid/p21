/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						作成日：2000.04.17

	１．クラス概要
		SYMBOL_COLOURを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_COLOURC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC()
{
//	<初期化>
	m_EntityName = DEF_SYMBOL_COLOUR;
//<エンティティデータ>

//#100 = SYMBOL_COLOUR(#40);

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	1. colour へのインスタンスID
	m_colour_Inst =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_SYMBOL_COLOUR;
//<エンティティデータ>
//#100 = SYMBOL_COLOUR(#40);

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	1. colour へのインスタンスID
	m_colour_Inst =0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_COLOURC::~SXFMapE_SYMBOL_COLOURC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::~SXFMapE_SYMBOL_COLOURC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_SYMBOL_COLOURC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_SYMBOL_COLOURC::SetParameter()
{
//	<1. エンティティパラメタの設定>

//<エンティティデータ>

//#100 = SYMBOL_COLOUR(#40);

	SXFMapEntAConvC convent(m_EntityArray);

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	2.colour へのインスタンスID
	convent.GetInst(0,m_colour_Inst);

	return 0;
}
