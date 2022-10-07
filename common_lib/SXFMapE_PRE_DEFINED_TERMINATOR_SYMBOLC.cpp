/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

	１．機能概要
	    以下のエンティティに関する情報を管理する。

			ENTITY pre_defined_terminator_symbol
				SUBTYPE OF (pre_defined_symbol);
				WHERE
					wr1: SELF.name IN [
									   'blanked arrow',
									   'blanked box',
									   'blanked dot',
									   'dimension origin',
									   'filled arrow',
									   'filled box',
									   'filled dot',
									   'integral symbol',
									   'open arrow',
									   'slash',
									   'unfilled arrow'
									   ];
			END_ENTITY;

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.05.12	　藤本(FQS)	　　なし。

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  　１．機能概要
	    デフォルトコンストラクタ

	２．インターフェイス
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( )

	引数：	型	引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.05.12	　　藤本(FQS)	なし。
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC()
{

	// エンティティ名を設定する。
	m_EntityName = DEF_PRE_DEFINED_TERMINATOR_SYMBOL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  　１．機能概要
	    コンストラクタ

	２．インターフェイス
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(SXFInstanceIDC* IN_InstanceIDManeger)

	引数：	型					引数名					内容
			SXFInstanceIDC*		IN_InstanceIDManeger	インスタンスID
														オブジェクトのポインタ

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.05.12	　　藤本(FQS)	なし。
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(
				SXFInstanceIDC* IN_InstanceIDManeger)
        		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	// エンティティ名を設定する。
	m_EntityName = DEF_PRE_DEFINED_TERMINATOR_SYMBOL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  　１．機能概要
	    デフォルトデストラクタ

	２．インターフェイス
		~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( )

	引数：	型		引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.05.12	　　藤本(FQS)	なし。
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::
			~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  　１．機能概要
	    矢印コードをセットするメンバ関数

	２．インターフェイス
		int	SetParameter( )

	引数：	型		引数名		内容
			なし。

  　復帰値：0

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.05.12	　　藤本(FQS)	なし。
**/

int SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;	
	}

//
//	<矢印コードの判定>
//

	//	'blanked arrow'の時：1
	if ( m_Name=="blanked arrow") {
		m_code = 1;
	}
	//	'blanked box'の時：2
	else if (m_Name=="blanked box") {
		m_code = 2;
	}
	//	'blanked dot'の時：3
	else if ( m_Name=="blanked dot") {
		m_code = 3;
	}
	//	'dimension origin'の時：4
	else if (m_Name=="dimension origin") {
		m_code = 4;
	}
	//	'filled box'の時：5
	else if (m_Name.Find("filled box") != -1 ) {
		m_code = 5;
	}
	//	'filled arrow'の時：6
	else if ( m_Name=="filled arrow") {
		m_code = 6;
	}
	//	'filled dot'の時：7
	else if ( m_Name=="filled dot") {
		m_code = 7;
	}
	//	'integral symbol'の時：8
	else if (m_Name=="integral symbol") {
		m_code = 8;
	}
	//	'open arrow'の時：9	
	else if (m_Name=="open arrow") {
		m_code = 9;
	}
	//	'slash'の時：10
	else if (m_Name=="slash") {
		m_code = 10;
	}
	//	'unfilled arrow'の時：11
	else if (m_Name=="unfilled arrow") {
		m_code = 11;
	}
	//	上記以外の名前の時
	else {
		//err ポイントマーカーの名前が正しくない
	}
	return 0;
}
