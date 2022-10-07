/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						作成日：2000.04.17

	１．クラス概要
		SYMBOL_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_STYLEC.h"
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
	SXFMapE_SYMBOL_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC()
{
//	<初期化>
	m_EntityName = DEF_SYMBOL_STYLE;
//<エンティティデータ>

//#110=SYMBOL_STYLE(' ',#100);
	//	1.nameパラメタ
	m_name.Empty();

	//	2.symbol_colour へのインスタンスID
	m_symbol_colour_Inst = 0;

	//	symbol_colourへのポインタ
	m_symbol_colour_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_SYMBOL_STYLE;
//<エンティティデータ>

//#110=SYMBOL_STYLE(' ',#100);
	//	1.nameパラメタ
	m_name.Empty();

	//	2.symbol_colour へのインスタンスID
	m_symbol_colour_Inst = 0;

	//	symbol_colourへのポインタ
	m_symbol_colour_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_STYLEC::~SXFMapE_SYMBOL_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::~SXFMapE_SYMBOL_STYLEC()
{
	if(m_symbol_colour_P != NULL)
	{
		delete m_symbol_colour_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_SYMBOL_STYLEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_SYMBOL_STYLEC::SetParameter()

{
//	<1. エンティティパラメタの設定>

	int ircode=0;
//<エンティティデータ>

//#110=SYMBOL_STYLE(' ',#100);

	SXFMapEntAConvC convent(m_EntityArray);

	//	1.nameパラメタ
	convent.GetCString(0,m_name);

	//	2.symbol_colour へのインスタンスID
	convent.GetInst(1,m_symbol_colour_Inst);


//	<2. 参照先のDIRECTIONエンティティパラメタの設定>
	//#100=SYMBOL_COLOUR(#40);

	//エンティティインスタンスを作成
	m_symbol_colour_P = new SXFMapE_SYMBOL_COLOURC(m_InstanceIDManager);

	if (m_EntityArray->GetSize() > 1){
		if (m_EntityArray->GetAt(1) == DEF_DOLLAR){
			return 1;
		}
	}

	ircode = m_symbol_colour_P->SetRootID(m_symbol_colour_Inst);
		if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_symbol_colour_P->SetParameter();
		if ( ircode < 0 )	return ircode ;

	return 0;
}
