/**
	All Rights Reserved,(c) JACIC 2001
	SXFread_next_feature.cpp								作成日：2000.4.29

	１．機能概要
	一般フィーチャ要素の読み込み

	２．インターフェース
	int SXFread_next_feature_AP202(char *&OUT_Type, void *&OUT_Struct, int &OUT_EndFlag)
	引数:	型				引数名				内容
			char*&			OUT_Type			フィーチャ型
			void*&			OUT_Struct			構造体
			int&			OUT_EndFlag			終了フラグ（０：継続　１：後続なし）

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

__declspec(dllexport) int WINAPI SXFread_next_feature_AP202(char *OUT_Type, void *&OUT_Struct, int *OUT_EndFlag)
{
	//ファイルがオープンされていなければエラー
	if (gl_Man == NULL){
		if (gl_log_file == NULL){
			gl_log_file = new ofstream("outAP202.log",ios::out);
			if(gl_log_file->fail()){
				delete gl_log_file;
				gl_log_file = NULL;
				cerr << "Error opening outAP202.log" << endl;
				*OUT_EndFlag = 1;
				return -1;
			}
		}
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);
		gl_log_file->close();
		delete gl_log_file;
		gl_log_file = NULL;
		*OUT_EndFlag = 1;
		return SXFOPENSTEPFILE;
	}
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	int code = gl_Man->Read_next_feature(OUT_Type,OUT_Struct,OUT_EndFlag);
/*
	仕様書にはサイズの指定が無い。
	内部的にフィーチャ名称は char [64]で定義されている。
	また、同梱のSampleも char FeatureName[64]; なのでバッファサイズを 64にする。
*/
	int code = gl_Man->Read_next_feature(OUT_Type, 64, OUT_Struct,OUT_EndFlag);
	return code;

}
