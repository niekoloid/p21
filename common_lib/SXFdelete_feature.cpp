/**
	All Rights Reserved,(c) JACIC 2001
	SXFdelete_feature.cpp								作成日：2001.2.23

	１．機能概要
		フィーチャ構造体の領域解放

	２．インターフェース
	int SXFdelete_feature_AP202(char* feature_name,void*& f_struct);

	引数:	型			引数名			内容
			char*		feature_name	フィーチャ名
			void*&		f_struct		フィーチャ構造体のアドレス

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.23			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXF_EXT.h"
#include "SXFManageC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFdelete_feature_AP202(char* feature_name,void*& f_struct)
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
	gl_Man->Delete_feature(feature_name,f_struct);
	return 0;
}
