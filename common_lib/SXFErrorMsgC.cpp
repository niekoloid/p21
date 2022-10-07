/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								作成日：2000.3.27

	１．クラス概要
	エラーメッセージリスト管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"
#include "SXFErrorRecC.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								作成日：2000.3.27

	１．機能概要
		エラーメッセージをリストに追加

	２．インターフェース
	static void	RecordError(SXFErrorCode IN_Code, 
							CString IN_Name,
							int IN_param, ...)

	引数:	型				引数名			内容
			SXFErrorCode	IN_Code			エラーメッセージ番号
			char*			IN_Name			フィーチャ名
			int				IN_param		引数の個数

	復帰値	なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。
	更新			2015.04.27			T.Matsushima		SXFPopMsg_AP202()が仕様書通りに動作していないので修正

**/
void	SXFErrorMsgC::RecordError(SXFErrorCode IN_Code, const char* IN_Name, int IN_param, ...)
{
//	char strmsg[5000];	Move to SXFPopMsg_AP202.cpp		SXFPopMsg_AP202()修正
	va_list args;
	/* 引数リストへのポインタ */
	va_start (args, IN_param);
	/* エラー情報の設定 */
	SXFErrorRecC *erec = new SXFErrorRecC(IN_Code,IN_Name);

	/* 引数リストへのポインタからエラーメッセージ作成 */
//	MOD(S)	SXFPopMsg_AP202()修正	T.Matsushima	2015.04.27
	//vsprintf(strmsg, erec->GetText(), args);
	//erec->SetText(strmsg);
	erec->MakeErrorMessage(args);
//	MOD(E)	SXFPopMsg_AP202()修正	T.Matsushima	2015.04.27

	va_end (args);
	/* エラーログファイルへの書き込み */
	erec->WriteLog(gl_log_file);
	/* エラーリストにエラー情報追加 */
	gl_ErrorList.AddTail(erec);
};

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								作成日：2000.3.27

	１．機能概要
		エラーメッセージをリストに追加(ログ出力なしモード)

	２．インターフェース
	static void	RecordError2(SXFErrorCode IN_Code, 
							CString IN_Name,
							int IN_param, ...)

	引数:	型				引数名			内容
			SXFErrorCode	IN_Code			エラーメッセージ番号
			char*			IN_Name			フィーチャ名
			int				IN_param		引数の個数

	復帰値	なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2004.3.05			K.Naono(FQS)		なし。
	更新			2015.04.27			T.Matsushima		SXFPopMsg_AP202()が仕様書通りに動作していないので修正

**/
void	SXFErrorMsgC::RecordError2(SXFErrorCode IN_Code, const char* IN_Name, int IN_param, ...)
{
//	char strmsg[5000];	Move to SXFPopMsg_AP202.cpp		SXFPopMsg_AP202()修正
	va_list args;
	/* 引数リストへのポインタ */
	va_start (args, IN_param);
	/* エラー情報の設定 */
	SXFErrorRecC *erec = new SXFErrorRecC(IN_Code,IN_Name);

	/* 引数リストへのポインタからエラーメッセージ作成 */
//	MOD(S)	SXFPopMsg_AP202()修正	T.Matsushima	2015.04.27
	//vsprintf(strmsg, erec->GetText(), args);
	//erec->SetText(strmsg);
	erec->MakeErrorMessage(args);
//	MOD(E)	SXFPopMsg_AP202()修正	T.Matsushima	2015.04.27

	va_end (args);
	/* エラーリストにエラー情報追加 */
	gl_ErrorList.AddTail(erec);
};

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								作成日：2000.3.27

	１．機能概要
		エラーメッセージリストからメッセージをPOPする

	２．インターフェース
	static SXFErrorRecC*	PeekError()

	引数:	型				引数名			内容
			なし。

	復帰値	SXFErrorRecC*(エラーメッセージ番号、フィーチャ名、エラーメッセージ）を返却

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFErrorRecC*	SXFErrorMsgC::PeekError(){
	SXFErrorRecC *erec;
	if(gl_ErrorList.IsEmpty())
		return NULL;
	erec = (SXFErrorRecC*)gl_ErrorList.GetTail();
	gl_ErrorList.RemoveTail();
	return erec;
}

