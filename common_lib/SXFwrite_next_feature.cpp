/**
	All Rights Reserved,(c) JACIC 2001
	SXFwrite_next_feature.cpp								作成日：2000.4.29

	１．機能概要
	一般フィーチャ要素のファイルへの出力

	２．インターフェース
	int SXFwrite_next_feature_AP202(char *IN_FeatureType, void *IN_str)
	引数:	型				引数名				内容
			char*			IN_FeatureType		フィーチャ型
			void*			IN_str				構造体

	復帰値	正常時：インスタンスID
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.29			宮園(FQS)			なし。

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

__declspec(dllexport) int WINAPI SXFwrite_next_feature_AP202(char *IN_FeatureType, void *IN_str)
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
	int code = gl_Man->Write_next_feature(IN_FeatureType,IN_str);
	return code;
}
