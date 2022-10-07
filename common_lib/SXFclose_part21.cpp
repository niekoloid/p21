/**
	All Rights Reserved,(c) JACIC 2001
	SXFclose_part21.cpp								作成日：2000.4.29

	１．機能概要
		ファイルのクローズ

	２．インターフェース
	int SXFclose_AP202();
	引数:	型				引数名			内容
			なし。
	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.29			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXF_EXT.h"
#include "SXFManageC.h"
#include "SXFErrorMsgC.h"
#include "SXFErrorRecC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFclose_AP202()
{
	//ファイルがオープンされていなければエラー
	if (gl_Man == NULL){
		if (gl_log_file == NULL){
			gl_log_file = new ofstream("outAP202.log",ios::out);
			if(gl_log_file->fail()){
				delete gl_log_file;
				gl_log_file = NULL;
				cerr << "Error opening outAP202.log" << endl;
				return -1;
			}
		}
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);
		gl_log_file->close();
		delete gl_log_file;
		gl_log_file = NULL;
		return SXFOPENSTEPFILE;
	}
	int ret;
	if ((ret = gl_Man->Close()) < 0)
		return ret;
	//変換管理オブジェクト領域解放
	if (gl_Man){
		delete gl_Man;
		gl_Man = NULL;
	}
	//	SXFErrorMsgC.cpp の51行目のnewで作成されるオブジェクトのdelete
	SXFErrorRecC *erec;
	while( erec = SXFErrorMsgC::PeekError() )
	{
		delete erec ;
	}
	return 0;
}
