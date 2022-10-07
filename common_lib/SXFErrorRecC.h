/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.h									作成日：2000.3.27

	１．クラス概要
	エラーメッセージをファイルに出力するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。
	更新			2015.04.27			T.Matsushima		SXFPopMsg_AP202()が仕様書通りに動作していないので修正

**/
#ifndef _ERRORRECC_H_
#define	_ERRORRECC_H_

#include <afx.h>
#include <fstream>
#include "SXFErrorCode.h"

class SXFErrorRecC : public CObject {
protected:
	SXFErrorCode		m_Code ;	//エラーメッセージ番号
	char				*m_Text ;	//エラーメッセージ
// SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
//	char				*m_Name;	//フィーチャ名
	CString				m_Name;		//フィーチャ名
private:
	SXFErrorRecC(){}
public:
	SXFErrorRecC(SXFErrorCode IN_ecode,const char* IN_Name);	// Add const
	virtual ~SXFErrorRecC();

	void WriteLog(ofstream *IN_log_file);
	char*	GetErrorText(SXFErrorCode IN_Code);

// SXFPopMsg_AP202()修正	2015.04.27	T.Matsushima
	void MakeErrorMessage(va_list args);	// 引数リストへのポインタからエラーメッセージ作成
//	void SetText(char *IN_text);	削除
	int GetCode();
	const char* GetName();	// 戻り値 const 追加
	const char* GetText();	// 戻り値 const 追加
};

#endif	// _ERRORRECC_H_ 
