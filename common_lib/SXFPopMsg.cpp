/**
	All Rights Reserved,(c) JACIC 2001
	SXFPopMsg.cpp								作成日：2000.4.29

	１．機能概要
		エラー情報を返却する

	２．インターフェース
	static int SXFPopMsg_AP202(char *&OUT_name, int *OUT_msgno, char *&OUT_text);

	引数:	型				引数名			内容
			char			OUT_name		フィーチャ名
			int				OUT_msgno		メッセージ番号
			char			OUT_text		メッセージ

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.29			宮園(FQS)			なし。
	更新			2015.04.27			T.Matsushima		SXFPopMsg_AP202()が仕様書通りに動作していないので修正

**/

#include "stdafx.h"
#include "SXFErrorRecC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFPopMsg_AP202(char *&OUT_name, int *OUT_msgno, char *&OUT_text)
{
	SXFErrorRecC *erec;
	//エラーメッセージをポップ
	erec = SXFErrorMsgC::PeekError();
	if(erec==NULL)
		return 1;

// SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
	//フィーチャ名取得
//	OUT_name = erec->GetName();
	static char name[64];
	strncpy_s(name,_countof(name), erec->GetName(),_TRUNCATE);
	OUT_name = name;
	//エラーメッセージNo取得
	*OUT_msgno = - erec->GetCode();
	//エラーメッセージ取得
//	OUT_text = erec->GetText();
	static char strmsg[5000];	// From to SXFErrorMsgC::RecordError()
	strncpy_s(strmsg,_countof(strmsg), erec->GetText(),_TRUNCATE);
	OUT_text = strmsg;

	//	SXFErrorMsgC.cpp の51行目のnewで作成されるオブジェクトのdelete
	delete erec ;
	return *OUT_msgno;

}
