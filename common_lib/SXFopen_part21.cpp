/**
	All Rights Reserved,(c) JACIC 2001
	SXFopen_part21.cpp								作成日：2000.4.28

	１．機能概要
		ファイルのオープン

	２．インターフェース
	int SXFopen_AP202(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char IN_author[257], char IN_org[257],char IN_translator_name[257],char OUT_version[257]);
	引数:	型				引数名				内容
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
	作成			2000.4.28			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFManageC.h"
#define EXT_BODY
#include "SXF_EXT.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFopen_AP202(char IN_file_name[], int IN_rw_flg, double IN_tolerance1, double IN_tolerance2, double IN_divide, int IN_level, int IN_mode, char IN_author[], char IN_org[], char IN_translator_name[], char OUT_version[])
{
	//変換管理オブジェクト生成
	gl_Man = new SXFManageC();
	int ret = gl_Man->Open(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode,IN_author,IN_org,IN_translator_name,OUT_version);
	if (ret < 0){
		delete gl_Man;
		gl_Man = NULL;
	}
	return ret;
}

__declspec(dllexport) int WINAPI SXFset_file_version_AP202(char IN_file_version[])
{
	gl_FileVersion = IN_file_version;
	return 0;
}

__declspec(dllexport) int WINAPI SXFget_file_version_AP202(char OUT_file_version[])
{
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(OUT_file_version, (LPCTSTR)gl_FileVersion);
	// バッファサイズは仕様書より取得
	strcpy_s(OUT_file_version, 257, (LPCTSTR)gl_FileVersion);
	return 0;
}
