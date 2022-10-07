/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．クラス概要
	変換管理クラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "SXFManageC.h"
#include "SXFComInfoC.h"
#include "SXF_EXT.h"
#include "SXFErrorMsgC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFTableManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileReadC.h"
#include "SXFEntitySchemaC.h"
#include "SXFAPI_RevInfo.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFManageC::SXFManageC()
	引数:	型				引数名			内容
			なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
SXFManageC::SXFManageC()
{
	m_Assem_type = -1;
	m_WriteFile = NULL;
	m_TableManager = NULL;
	m_WriteManager = NULL;
	m_ReadFile = NULL;
	m_InstanceIDManager = NULL;
	m_ReadAP202Manager = NULL;
	m_ReadExHatchFile = NULL;
	m_ExHatchFileInstanceIDManager = NULL;
	m_ExHatchFileTableManager = NULL;
	m_ExHatchFileReadAP202Manager = NULL;
	m_ReadExSymbolFile = NULL;
	m_ExSymbolFileInstanceIDManager = NULL;
	m_ExSymbolFileTableManager = NULL;
	m_ExSymbolFileReadAP202Manager = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFManageC::~SXFManageC()
	引数:	型				引数名			内容
			なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
SXFManageC::~SXFManageC()
{
	if (m_WriteFile != NULL)
		delete m_WriteFile;
	if (m_WriteManager != NULL)
		delete m_WriteManager;
	if (m_ReadFile != NULL)
		delete m_ReadFile;
	if (m_InstanceIDManager != NULL)
		delete m_InstanceIDManager;
	if (m_ReadAP202Manager != NULL)
		delete m_ReadAP202Manager;
	if (m_TableManager != NULL)
		delete m_TableManager;
	if (m_ReadExHatchFile != NULL)
		delete m_ReadExHatchFile;
	if (m_ExHatchFileInstanceIDManager != NULL)
		delete m_ExHatchFileInstanceIDManager;
	if (m_ExHatchFileTableManager != NULL)
		delete m_ExHatchFileTableManager;
	if (m_ExHatchFileReadAP202Manager != NULL)
		delete m_ExHatchFileReadAP202Manager;
	if (m_ReadExSymbolFile != NULL)
		delete m_ReadExSymbolFile;
	if (m_ExSymbolFileInstanceIDManager != NULL)
		delete m_ExSymbolFileInstanceIDManager;
	if (m_ExSymbolFileTableManager != NULL)
		delete m_ExSymbolFileTableManager;
	if (m_ExSymbolFileReadAP202Manager != NULL)
		delete m_ExSymbolFileReadAP202Manager;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	ファイルをオープンする

	２．インターフェース
	int Open(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char IN_author[257], char IN_org[257],char IN_translator_name[257],char OUT_version[257]);
	引数:	型				引数名			内容
			char			IN_file_name		ファイル名
			int				IN_rw_flg			読み書きフラグ
			double			IN_tolerance1		許容誤差
			double			IN_tolerance2		角度用許容誤差
			double			IN_divide			ダウンコンバート用許容誤差
			int				IN_level			レベル(1or2)
			int				IN_mode				モード (0:併用
														1:フィーチャコメント
														2:AP202）
			char			IN_author			ファイル作成者
			char			IN_org				作成者所属
			char			IN_translator_name	トランスレータ名
			char			OUT_version			共通ライブラリバージョン
	復帰値	正常時：０
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Open(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char INOUT_author[257], char INOUT_org[257],char INOUT_translator_name[257],char OUT_version[257])
{

	int ret;
	/////////////////////////////
	//エラーログファイルオープン
	/////////////////////////////
	gl_log_file = new ofstream("outAP202.log",ios::out);
	if(gl_log_file->fail()){
		delete gl_log_file;
		gl_log_file = NULL;
		cerr << "Error opening outAP202.log" << endl;
		return -1;
	}

	////////////////////////////
	//引数のチェック
	////////////////////////////
	if ((ret = Param_Check(IN_rw_flg,IN_level,IN_mode)) < 0)
		return ret;

	////////////////////////////
	//		READ
	////////////////////////////
	if (IN_rw_flg == 0){//read
		//共通情報登録
		m_Info.Set_Read_Come(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode);
		//インスタンスＩＤオブジェクト生成
		m_InstanceIDManager = new SXFInstanceIDC();
		//テーブル管理オブジェクトの生成
		m_TableManager = new SXFTableManagerC(&m_Info,m_InstanceIDManager);

		//AP202Read管理オブジェクト生成
		m_ReadAP202Manager = new SXFReadAP202ManagerC(m_InstanceIDManager,m_TableManager,&m_Info);

		//ファイル入力オブジェクト生成
		m_ReadFile = new SXFPart21FileReadC(m_TableManager,m_ReadAP202Manager,&m_Info,m_InstanceIDManager);

		//ファイルのオープン
#ifdef _DEBUG
		clock_t	start = clock() ;
#endif
#ifdef _RELEASE
		clock_t	start = clock() ;
#endif

		ret = m_ReadFile->OpenPart21ReadFile(IN_file_name);
		if (ret < 0)
			return ret;
#ifdef _DEBUG
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("OpenPart21ReadFile():%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("OpenPart21ReadFile():%2.1f 秒です。\n", duration) ;
#endif

		/////////////////////////////////////////
		//Part21ファイルのチェック
		/////////////////////////////////////////
#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif

		SXFEntitySchemaC exec;
		exec.part21 = m_ReadFile;
		exec.EntitySchemaCheck();
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("EntitySchemaCheck():%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("EntitySchemaCheck():%2.1f 秒です。\n", duration) ;
#endif

		/////////////////////////////////////////
		//ヘッダ情報取得
		/////////////////////////////////////////
#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		int FileLevel = -1;
		int FileMode = -1;
		char FileName[257];
		CString	strOutVersion;
		m_ReadFile->GetHeadData(&FileLevel,&FileMode,FileName,INOUT_author,INOUT_org,strOutVersion.GetBuffer(257),INOUT_translator_name);
		strOutVersion.ReleaseBuffer();
		//ファイルバージョンの取得
		int pos = strOutVersion.Find("$$");
		if (pos == -1)
		{
			//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
			//strcpy(OUT_version, (LPCTSTR)strOutVersion);
			// バッファサイズは仕様書より取得
			strcpy_s(OUT_version, 257, (LPCTSTR)strOutVersion);
			gl_FileVersion.Empty();
		}
		else
		{
			//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
			//strcpy(OUT_version, strOutVersion.Left(pos));
			// バッファサイズは仕様書より取得
			strcpy_s(OUT_version, 257, strOutVersion.Left(pos));
			gl_FileVersion = strOutVersion.Mid(pos + 2);
		}
		//ルールチェックオブジェクトにテーブル管理オブジェクトのアドレスを渡す。
		m_rulecheck.m_TableManager = m_TableManager;
		//ルールチェックオブジェクトに共通情報管理のアドレスを渡す。
		m_rulecheck.m_ComInfo = &m_Info;
		//ルールチェックオブジェクトにReadAP202管理オブジェクトのアドレスを渡す。
		m_rulecheck.m_ReadAP202Manager = m_ReadAP202Manager;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ヘッダ情報取得:%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ヘッダ情報取得:%2.1f 秒です。\n", duration) ;
#endif

#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		if( !m_TableManager->MappingAP202Table() )
			return -1;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("MappingAP202Table():%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("MappingAP202Table():%2.1f 秒です。\n", duration) ;
#endif

#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		if( ! m_ReadAP202Manager->ArrangeChild(0) )//引数０：StepFile読み込み時
			return -1;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ArrangeChild():%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ArrangeChild():%2.1f 秒です。\n", duration) ;
#endif

	}
	////////////////////////////
	//		WRITE
	////////////////////////////
	else if (IN_rw_flg == 1){//write
		//共通情報登録
		m_Info.Set_Write_Come(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode,INOUT_author,INOUT_org,INOUT_translator_name);
		//外部変数初期化
		gl_InstanceID = 20;
		//ファイルオープン
		m_WriteFile = new SXFPart21FileWriteC();
		ret = m_WriteFile->OpenPart21WriteFile(IN_file_name);
		if (ret < 0){
			gl_log_file->close();
			delete gl_log_file;
			gl_log_file = NULL;
			return ret;
		}
		////////////////////////////
		//バージョンの設定
		////////////////////////////
		CString	strVersion(SCADEC_API_RevInfo);
		if (!gl_FileVersion.IsEmpty())
		{
			//ファイルバージョン付加
			strVersion += "$$";
			strVersion += gl_FileVersion;
		}
		char Version[257];
//		strcpy(Version,(LPCTSTR)strVersion);	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		strcpy_s(Version,_countof(Version),(LPCTSTR)strVersion);
		//////////////
		//ヘッダの出力
		m_WriteFile->SetHeadSection(&IN_level,&IN_mode,IN_file_name,INOUT_author,INOUT_org,Version,INOUT_translator_name);
		ret = m_WriteFile->WriteHeadSection();
		if (ret < 0){
			gl_log_file->close();
			delete gl_log_file;
			gl_log_file = NULL;
			return ret;
		}
		//////
		//インスタンスＩＤオブジェクト生成
		m_InstanceIDManager = new SXFInstanceIDC();

/* 2006.03.13 メモリ取得サイズの変更（大容量ファイル対応） ===> */
//		if( !m_InstanceIDManager->InitFileMapping( 500000 ) )
		if( !m_InstanceIDManager->InitFileMapping( 1000000 ) )
/* 2006.03.13 メモリ取得サイズの変更（大容量ファイル対応） <=== */
			return -1;

		//テーブル管理オブジェクトの生成
		m_TableManager = new SXFTableManagerC(m_WriteFile->GetFileHandle(),&m_Info,m_WriteFile,m_InstanceIDManager);
		//AP202管理オブジェクトの生成
		m_WriteManager = new SXFWriteManagerC(m_WriteFile->GetFileHandle(),m_TableManager,&m_Info,m_WriteFile,m_InstanceIDManager);
		//ルールチェックオブジェクトにテーブル管理オブジェクトのアドレスを渡す。
		m_rulecheck.m_TableManager = m_TableManager;
		//ルールチェックオブジェクトにAP202管理オブジェクトのアドレスを渡す。
		m_rulecheck.m_WriteManager = m_WriteManager;
		//ルールチェックオブジェクトに共通情報管理のアドレスを渡す。
		m_rulecheck.m_ComInfo = &m_Info;
		//エラーメッセージ用インスタンスIDの登録
		//WRITE時はデフォルトで"-"
		m_rulecheck.m_InstanceID = "-";

	}
	else{
		SXFErrorMsgC::RecordError(SXFRWFLAG,"",1,IN_rw_flg);		
		return SXFRWFLAG;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	ファイルをクローズする

	２．インターフェース
	int Close();
	引数:	型				引数名			内容
			なし。
	復帰値	正常時：０
			異常時：エラー番号

			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Close()
{
	//ファイルバージョンリセット
	gl_FileVersion.Empty();

	int flg;
	m_Info.Get_Flg(flg);
	if (flg == 0){
		//ファイルクローズ
		m_ReadFile->ClosePart21ReadFile();
		if (m_ReadExHatchFile != NULL)
			//外部定義ファイル(ハッチ)クローズ
			m_ReadExHatchFile->ClosePart21ReadFile();
		if (m_ReadExSymbolFile != NULL)
			//外部定義ファイル(シンボル)クローズ
			m_ReadExSymbolFile->ClosePart21ReadFile();
	}
	///////////////////////////////////////
	//WRITE時：ファイルクローズ
	///////////////////////////////////////
	else if (flg == 1){
		//SHEET Mapping
		m_WriteManager->CloseAssembly();
		//LAYER Mapping
		m_TableManager->LayerMapping();
		//INVISIVILITY Mapping
		//LAYER
		m_TableManager->MappingInvisibility();
		//COMPOSITE_CURVE
		m_WriteManager->MappingInvisibility();
		//ファイルクローズ
		m_WriteFile->ClosePart21WriteFile();
	}
	else
		return -1;

	///////////////////////////////////////
	//エラーログファイルクローズ
	///////////////////////////////////////
	gl_log_file->close();
	delete gl_log_file;
	gl_log_file = NULL;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	オープン時に渡された引数（読み書きフラグ、レベル、モード）のチェックを行う。

	２．インターフェース
	int Param_Check(int IN_rw_flg,int IN_level, int IN_mode)
	引数:	型				引数名			内容
			int				IN_rw_flg			読み書きフラグ
			int				IN_level			レベル
			int				IN_mode				モード
	復帰値	正常時：０
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Param_Check(int IN_rw_flg,int IN_level, int IN_mode)
{
	//読み書きフラグのチェック
	if ((IN_rw_flg != 0) && (IN_rw_flg != 1)){
		SXFErrorMsgC::RecordError(SXFRWFLAG,"",1,IN_rw_flg);
		return SXFRWFLAG;
	}
	//レベルのチェック
	switch (IN_level){
		/** 1のときワーニングとして処理続行 **/
		case 1:
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//			SXFErrorMsgC::RecordError(SXFWARNINGLEVEL,"",1,IN_level);
			SXFErrorMsgC::RecordError2(SXFWARNINGLEVEL,"",1,IN_level);
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			break;
		case 2:
			break;
		/** 1,2以外のときエラー処理 **/
		default:
			SXFErrorMsgC::RecordError(SXFNOLEVEL,"",1,IN_level);
			return SXFNOLEVEL;
	}
	//モードのチェック
	switch (IN_mode){
		/** ０，１のときワーニングとして処理続行 **/
		case 0:
 		case 1:
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//			SXFErrorMsgC::RecordError(SXFWARNINGMODE,"",1,IN_mode);
			SXFErrorMsgC::RecordError2(SXFWARNINGMODE,"",1,IN_mode);
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			break;
		case 2:
			break;
		/** ０，１，２以外のときエラー処理 **/
		default:
			SXFErrorMsgC::RecordError(SXFNOMODE,"",1,IN_mode);
			return SXFNOMODE;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	定義テーブルフィーチャをファイルに出力する

	２．インターフェース
	int Write_table(int IN_table_type, void* IN_str)
	引数:	型				引数名				内容
			int				IN_table_type		定義テーブル型
			void*			IN_str				構造体
	復帰値	正常時：コード
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Write_table(int IN_table_type, void* IN_str)
{
	//ルールチェックオブジェクト呼び出し
	int error_code = m_rulecheck.TableRuleCheck(IN_table_type,IN_str);

	if (error_code < 0)
		return error_code;
	else{
		//定義テーブル管理呼出し
		int code = m_TableManager->RegisterStructTable(IN_table_type,IN_str);
		return code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	共通情報管理オブジェクトを返す

	２．インターフェース
	SXFComInfoC GetInfo()
	引数:	型				引数名				内容
	なし。
	復帰値	m_Info
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
SXFComInfoC SXFManageC::GetInfo()
{
	return m_Info;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	アセンブリ要素フィーチャをファイルに出力する
	
	２．インターフェース
	int Write_assembly_name(int IN_Assem_type, void *IN_Struct)
	引数:	型				引数名				内容
			int				IN_Assem_type		アセンブリ型
			void*			IN_Struct				構造体
	復帰値	正常時：共通ライブラリがふる番号
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Write_assembly_name(int IN_Assem_type, void *IN_Struct)
{
	//ルールチェックオブジェクト呼び出し
	int error_code = m_rulecheck.AssemblyRuleCheck(IN_Assem_type,IN_Struct);
	if (error_code < 0){
		m_WriteManager->ErrorAssembly();
		m_Assem_type = -1;
		return error_code ;
	}
	else{
		int Assem_code = m_WriteManager->RegisterAssembly(IN_Assem_type,IN_Struct);
		//今開かれているアセンブリタイプ、エラーのときは-１
		m_Assem_type = m_WriteManager->GetAssemType();
		return Assem_code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	一般要素フィーチャをファイルに出力する

	２．インターフェース
	int Write_next_feature(char *IN_FeatureType, void *IN_Struct)
	引数:	型				引数名				内容
			char*			IN_FeatureType		フィーチャ型
			void*			IN_Struct			構造体
	
	復帰値	正常時：インスタンス番号
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Write_next_feature(char *IN_FeatureType, void *IN_Struct)
{
	//ルールチェックオブジェクト呼び出し
	int error_code = m_rulecheck.FeatureRuleCheck(m_Assem_type,IN_FeatureType,IN_Struct);
	if (error_code < 0){
		return error_code ;
	}
	else{
		error_code = m_WriteManager->RegisterFeature(IN_FeatureType,IN_Struct);
		return error_code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	定義テーブル要素をよんで、構造体を返す

	２．インターフェース
	int Read_table(int IN_TableType, LPVOID &OUT_Struct, int &OUT_EndFlag)
	引数:	型				引数名				内容
			int				IN_TableType		テーブル型
			LPVOID&			OUT_Struct			構造体
			int&			OUT_EndFlag			終了フラグ（０：継続、１：後続なし）
	復帰値	正常時：コード
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Read_table(int IN_TableType, LPVOID OUT_Struct, int* OUT_EndFlag)
{	
	//構造体の取りだし
	int code = m_TableManager->GetTableElement(IN_TableType,OUT_Struct,OUT_EndFlag);
	if (code < 0)
		return code;
	//ルールチェック
	//OPEN時にルールチェック済み
	//レベルのチェックのみ行う
	int error_code = m_rulecheck.TableRuleCheck(IN_TableType,OUT_Struct);
	if (error_code < 0)
		return error_code;
	return code;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	アセンブリ要素を読みこんで、構造体を返す

	２．インターフェース
	int Read_assembly_name(int IN_Type, LPVOID &OUT_Struct, int &OUT_EndFlag)
	引数:	型				引数名				内容
			int				IN_Type				アセンブリ型
			LPVOID&			OUT_Struct			構造体
			int&			OUT_EndFlag			終了フラグ（０：継続、１：後続なし）
	復帰値	正常時：共通ライブラリがふる番号
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。

**/
int SXFManageC::Read_assembly_name(int IN_Type, LPVOID &OUT_Struct, int *OUT_EndFlag)
{
	m_Assem_type = -1;
	int InstanceID = -1;
	int returnCode = -1;
	returnCode = m_ReadAP202Manager->GetNextAssembly(IN_Type,OUT_Struct,OUT_EndFlag,InstanceID);
	if (returnCode < 0)
		return returnCode;
	//エラーメッセージ用インスタンスID
	m_rulecheck.m_InstanceID.Format("#%d",InstanceID);	
	//ルールチェック
	//ルールチェックオブジェクト呼び出し
	int error_code = m_rulecheck.AssemblyRuleCheck(IN_Type,OUT_Struct);
	if (error_code < 0) {
		// ここで削除
		Delete_assembly(IN_Type,OUT_Struct);
		OUT_Struct = NULL;
		return error_code;
	}
		///現在のアセンブリ型　フィーチャ要素のルールチェックに使用
		m_Assem_type = IN_Type;
	return returnCode;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.05.29

	１．機能概要
	一般フィーチャ要素を読みこんで、構造体を返す

	２．インターフェース
	int Read_next_feature(char* OUT_Type, size_t TypeSize, LPVOID &OUT_Struct, int &OUT_EndFlag)
	引数:	型				引数名				内容
			char*			OUT_Type			フィーチャ型
			size_t			TypeSize			フィーチャ型のバッファサイズ
			LPVOID&			OUT_Struct			構造体
			int&			OUT_EndFlag			終了フラグ（０：継続、１：後続なし）
	復帰値	正常時：インスタンス番号
			異常時：エラー番号
			
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。
	更新			2015.04.27			T.Matsushima		JPCERT/CC 指摘 脆弱性対応

**/
//int SXFManageC::Read_next_feature(char* OUT_Type, LPVOID &OUT_Struct, int *OUT_EndFlag)
int SXFManageC::Read_next_feature(char* OUT_Type,size_t TypeSize, LPVOID &OUT_Struct, int *OUT_EndFlag)
{
	int returnID;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	returnID = m_ReadAP202Manager->GetNextFeature(OUT_Type,OUT_Struct,OUT_EndFlag);
	returnID = m_ReadAP202Manager->GetNextFeature(OUT_Type,TypeSize,OUT_Struct,OUT_EndFlag);
	if (returnID < 0)
		return returnID;

	//エラーメッセージ用インスタンスID
	m_rulecheck.m_InstanceID.Format("#%d",returnID);
	//ルールチェック
	//ルールチェックオブジェクト呼び出し
	int error_code = m_rulecheck.FeatureRuleCheck(m_Assem_type,OUT_Type,OUT_Struct);
	if (error_code < 0) {
		// ここで削除
		Delete_feature(OUT_Type,OUT_Struct);
		OUT_Struct = NULL;
		return error_code;
	}

	return returnID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.2.23

	１．機能概要
		フィーチャ構造体の領域解放

	２．インターフェース
	void SXFManageC::Delete_feature(char* feature_name,void *& f_struct)

	引数:	型			引数名			内容
			char*		feature_name	フィーチャ名
			void*&		f_struct		フィーチャ構造体のアドレス

	復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.23			佐々木(FQS)			なし。

**/
void SXFManageC::Delete_feature(char* feature_name,void *& f_struct)
{
	if (f_struct)
		if (strcmp(feature_name,DEF_POLYLINE) == 0)
			delete (Polyline_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_SPLINE) == 0)
			delete (Spline_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_CLOTHOID) == 0)
			delete (Clothoid_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_LABEL) == 0)
			delete (Label_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_BALLOON) == 0)
			delete (Balloon_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_HATCHING) == 0)
			delete (Fill_area_style_hatching_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_EXTERNALLY_DEFINED_HATCH) == 0)
			delete (Externally_Defined_Hatch_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_COLOUR) == 0)
			delete (Fill_area_style_colour_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_TILES) == 0)
			delete (Fill_area_style_tiles_Struct*)f_struct;
		else 
			delete f_struct;
	f_struct = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2001.2.23

	１．機能概要
		アセンブリ構造体の領域解放

	２．インターフェース
	void SXFManageC::Delete_assembly(int assem_type,void *& f_struct)

	引数:	型			引数名		内容
			char*		assem_type	アセンブリ型
										１：用紙
										２：複合図形
										３：複合曲線
			void*&		f_struct	フィーチャ構造体のアドレス

	復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.3.28			佐々木(FQS)			なし。

**/
void SXFManageC::Delete_assembly(int assem_type,void *& f_struct)
{
	if (f_struct){
		switch(assem_type){
			case 1:
			case 2:
			case 3:
				delete f_struct;
				break;
			default:
				SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,assem_type);
				break;
		}
	}
	f_struct = NULL;
}
