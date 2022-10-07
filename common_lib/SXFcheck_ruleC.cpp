/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFcheck_ruleC.cpp

	１．クラス概要
	SXFErrorLogGetCクラスとのインターフェースを提供する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27	　藤本(FQS)	　　なし。

**/
#include "stdafx.h"
#include "SXFcheck_ruleC.h"
#include "SXFErrorLogGetC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFcheck_ruleC.cpp

  　１．機能概要
	    デフォルトコンストラクタ

	２．インターフェイス
	SXFcheck_ruleC::SXFcheck_ruleC()

	引数：	型	引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27	　　藤本(FQS)	なし。
**/
SXFcheck_ruleC::SXFcheck_ruleC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFcheck_ruleC.cpp

	１．機能概要
	　　デフォルトデストラクタ

	２．インターフェイス
		SXFcheck_ruleC::~SXFcheck_ruleC()

	引数：	型	引数名		内容
	　　　　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.28	　　藤本(FQS)	なし。
**/
SXFcheck_ruleC::~SXFcheck_ruleC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
　　SXFcheck_ruleC.cpp

	１．機能概要
	SXFErrorLogGetCクラスとのインターフェースを提供する。

	２．インターフェイス
		void SXFcheck_ruleC::Get(int &OUT_msgnum,	
								 CStringArray *OUT_name, 
								 CUIntArray *OUT_msgno, 
								 CStringArray *OUT_message1, 
								 CStringArray *OUT_message2)

	引数：型	引数名				内容
	int 			&OUT_msgnum		エラー数
	CStringArray 	*OUT_name 		エンティティ（フィーチャ）名
	CUIntArray 		*OUT_msgno		メッセージ番号
	CStringArray 	*OUT_message1 	メッセージ１
	CStringArray 	*OUT_message2	メッセージ２

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27　	藤本(FQS)	なし。
**/
void SXFcheck_ruleC::Get(int &OUT_msgnum,	
							 CStringArray *OUT_name, 
							 CUIntArray *OUT_msgno, 
							 CStringArray *OUT_message1, 
							 CStringArray *OUT_message2)
{
	SXFErrorLogGetC	exec;
	exec.GetLogFile(OUT_msgnum, OUT_name, OUT_msgno, OUT_message1, OUT_message2);
}