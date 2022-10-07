/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．クラス概要
	エラーメッセージをファイルに出力するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。
	更新			2015.04.27			T.Matsushima		SXFPopMsg_AP202()が仕様書通りに動作していないので修正

**/
#include "stdafx.h"
#include <string.h>
#include "SXFErrorRecC.h"
#include "SXFErrorMsgStruct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
		コンストラクタ

	２．インターフェース
	SXFErrorRecC(SXFErrorCode IN_ecode, CString IN_Name);

	引数:	型				引数名			内容
			SXFErrorCode	IN_ecode		エラーメッセージ番号
			char*			IN_Name			フィーチャ名

	復帰値	なし。
	

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFErrorRecC::SXFErrorRecC(SXFErrorCode IN_ecode,const char* IN_Name)	// Add const
{
	m_Name = IN_Name;
	m_Code = IN_ecode;

// GetErrorText()はエラーを作成する時に呼び出す。	SXFPopMsg_AP202()修正
//	m_Text = GetErrorText(IN_ecode);
	m_Text = NULL;
}

// SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
// m_Text を newで確保するように変更したため デストラクタ追加
SXFErrorRecC::~SXFErrorRecC()
{
	if(m_Text){
		delete[] m_Text;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
		エラーメッセージの設定

	２．インターフェース	
	void SetText(char *IN_text);

	引数:	型				引数名			内容
			char*			IN_Text			エラーメッセージ

	復帰値	なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
/*	削除	SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
void SXFErrorRecC::SetText(char *IN_text){
	m_Text = IN_text;
}
*/
/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
	エラーメッセージをログファイルへ出力する

	２．インターフェース
	void WriteLog(ofstream *IN_log_file);

	引数:	型				引数名			内容
			ofstream		IN_log_file		エラーログファイル

	復帰値	なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
void SXFErrorRecC::WriteLog(ofstream *IN_log_file){
	*IN_log_file << m_Name << " : " << -m_Code << " : " << m_Text << endl;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
	エラーメッセージの取得

	２．インターフェース
	char* GetText();

	引数:	型				引数名			内容
			なし。

	復帰値	メンバm_Textを返却する。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
const char* SXFErrorRecC::GetText(){
	return m_Text;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
	エラーコードの取得

	２．インターフェース
	int GetCode();

	引数:	型				引数名			内容
			なし。

	復帰値	メンバm_Codeを返却する。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFErrorRecC::GetCode(){
	return (int)m_Code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
	エラーフィーチャ名の取得

	２．インターフェース
	char* GetName();

	引数:	型				引数名			内容
			なし。

	復帰値	メンバm_Nameを返却する。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
const char* SXFErrorRecC::GetName(){
	return m_Name;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									作成日：2000.3.27

	１．機能概要
	エラーメッセージの作成

	２．インターフェース
	char*	GetErrorText(SXFErrorCode IN_Code);

	引数:	型				引数名			内容
			SXFErrorCode	IN_Code			エラーメッセージ番号

	復帰値	エラーメッセージ番号に対応するメッセージを返却。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
char* SXFErrorRecC::GetErrorText(SXFErrorCode IN_Code) {
	char	*ret_Str ;
	ret_Str = "" ;

	for(int num=0 ; ErrorMsg[num].m_Text ; num++ ) {
		if( ErrorMsg[num].m_Code == IN_Code ) {
			ret_Str = ErrorMsg[num].m_Text ;
			break ;
		}
	}
	return ret_Str ;
}

// SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
// 引数リストへのポインタからエラーメッセージ作成
void SXFErrorRecC::MakeErrorMessage(va_list args)
{
	if(m_Text){
		delete[] m_Text;
	}
	const char *fmt = GetErrorText(m_Code);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	const int TextBufSize = _vscprintf(fmt, args) + 1;
	m_Text = new char[TextBufSize];
	vsprintf_s(m_Text, TextBufSize, fmt, args);
}
