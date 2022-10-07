/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFErrorLogGetC.cpp

	１．クラス概要
	エラーログからエラーをスタックし返却する

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27	　藤本(FQS)	　　なし。

**/
#include "stdafx.h"
#include <afx.h>
#include <fstream>
#include "SXFErrorLogGetC.h"

#define MAXCHR 16384
#define DELIMITER ":"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
	SXFErrorLogGetC.cpp

  　１．機能概要
	    デフォルトコンストラクタ

	２．インターフェイス
	SXFErrorLogGetC::SXFErrorLogGetC()
	引数：	型	引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27	　　藤本(FQS)	なし。
**/
SXFErrorLogGetC::SXFErrorLogGetC()
{
}
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
　　SXFErrorLogGetC.cpp

	１．機能概要
	　　デフォルトデストラクタ

	２．インターフェイス
		SXFErrorLogGetC::~SXFErrorLogGetC()
	引数：	型	引数名		内容
	　　　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.28	　　藤本(FQS)	なし。
**/
SXFErrorLogGetC::~SXFErrorLogGetC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.27
　　SXFErrorLogGetC.cpp

	１．機能概要
	エラーログからエラーをスタックし返却する

	２．インターフェイス
　　　　BOOL SXFErrorLogGetC::GetLogFile(int &OUT_msgnum,	
										 CStringArray *OUT_name, 
										 CUIntArray *OUT_msgno, 
										 CStringArray *OUT_message1, 
								   		 CStringArray *OUT_message2)	

	引数：型		引数名			内容
	int 			&OUT_msgnum		エラー数
	CStringArray 	*OUT_name		エンティティ（フィーチャ）名
	CUIntArray 		*OUT_msgno		メッセージ番号
	CStringArray 	*OUT_message1	メッセージ１
	CStringArray 	*OUT_message2	メッセージ２

	復帰値：ログファイルを正常に開く事が出来たらTRUEを返す。
	　　　　開けなかったら、FALSEを返却する。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.27　	藤本(FQS)	なし。
**/
BOOL SXFErrorLogGetC::GetLogFile(int &OUT_msgnum,	
				CStringArray *OUT_name, 
				CUIntArray *OUT_msgno, 
				CStringArray *OUT_message1, 
				CStringArray *OUT_message2)
{

	FILE *Logfile = NULL;
	char 	*name, *msgno_string, *message1, *message2, buf[256];
	int		msgno;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	if (( Logfile =fopen("outAP202.log","r"))==NULL){
//		return FALSE;
//	};

	//ログファイルオープン
	errno_t	err = fopen_s(&Logfile, "outAP202.log" , "r" );
	if( (err != 0) || (Logfile == NULL) ) {
		return FALSE;
	}
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	fgets(buf,256,Logfile);

	while ((fgets(buf,256,Logfile) != NULL)){

	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//name = strtok(buf,DELIMITER);
		//msgno_string    = strtok(NULL,DELIMITER);
		//message1 = strtok(NULL,DELIMITER);
		//message2 = strtok(NULL,DELIMITER);

		char *context = NULL;
		name = strtok_s(buf,DELIMITER, &context);
		msgno_string    = strtok_s(NULL,DELIMITER, &context);
		message1 = strtok_s(NULL,DELIMITER, &context);
		message2 = strtok_s(NULL,DELIMITER, &context);
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

		OUT_name->Add(name);
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//OUT_msgno->Add(sscanf(msgno_string, "%x", &msgno));
		OUT_msgno->Add(sscanf_s(msgno_string, "%x", &msgno));
		OUT_message1->Add(message1);
		OUT_message2->Add(message2);
		OUT_msgnum++;
	}
	fclose(Logfile);
	return TRUE;
}
