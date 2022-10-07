/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

	１．クラス概要
		既定義線種テーブル情報を管理する

	２．履歴
	    履歴番号    日付け         担当者		概要
		作成		2000.4.29     宮園(FQS)
**/
#include "stdafx.h"
#include <afx.h>
#include "SXFPreLineTypeTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      クラス構築

  ２．インターフェース
		void	SXFPreLineTypeTableC::SXFPreLineTypeTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け         担当者		 概要
		作成		2000.04.29     宮園(FQS)
**/
SXFPreLineTypeTableC::SXFPreLineTypeTableC()
{
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 1,  "continuous",                      "continuous")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 2,  "dashed",                          "dashed")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 3,  "dashed spaced",                   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 4,  "long dashed dotted",              "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 5,  "long dashed double-dotted",       "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 6,  "long dashed triplicate-dotted",   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 7,  "dotted",                          "dotted")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 8,  "chain",                           "chain")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 9,  "chain double dash",               "chain double dash")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 10, "dashed dotted",                   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 11, "double-dashed dotted",            "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 12, "dashed double-dotted",            "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 13, "double-dashed double-dotted",     "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 14, "dashed triplicate-dotted",        "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 15, "double-dashed triplicate-dotted", "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 16, "",                                "")  );
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      デストラクタ

  ２．インターフェース
		void	SXFPreLineTypeTableC::~SXFPreLineTypeTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け         担当者		 概要
	    作成		2000.04.29     宮園(FQS)

**/
SXFPreLineTypeTableC::~SXFPreLineTypeTableC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      コードに対応する線種名を取得する

  ２．インターフェース
		BOOL	SXFPreLineTypeTableC::GetPreLinetype(int in_code, 
													char *&out_name)
		
	引数	：	型		引数名			内容
				int		in_code			線種コード		
				char*&	out_name		線種名
	復帰値
			TRUE	対応する線種名あり
			FALSE	対応する線種名なし

  ３．履歴
	    履歴番号    日付け         担当者		 概要
		 作成		2000.04.29     宮園(FQS)

**/
BOOL SXFPreLineTypeTableC::GetPreLinetype(int in_code, char *&out_name)
{
	if(in_code > m_DefaultPreLineTypeTable.GetSize())
		return FALSE;
	m_DefaultPreLineTypeTable[in_code-1].GetName(out_name);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      線種名に対応するコードを取得する

  ２．インターフェース
	int		SXFPreLineTypeTableC::GetAP202UserDefCode(const char* in_name)
		
	引数	：	型		引数名			内容
				char*	int_name		線種名
	復帰値
			int		code	線種コード

  ３．履歴
	    履歴番号    日付け         担当者		 概要
	     作成		2000.04.29     宮園(FQS)

**/
int SXFPreLineTypeTableC::GetAP202UserDefCode(const char* in_name)
{
	char* type_name1;
	CString type_name2;
	CString tmp_name = in_name;
	int ret = 1;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize()-1; i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name1);
		type_name2 = type_name1;
		if (tmp_name.Find(type_name2) != -1){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}
/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      線種名に対応するコードを取得する

  ２．インターフェース
	int		SXFPreLineTypeTableC::GetCode(const char* in_name)
		
	引数	：	型		引数名			内容
				char*	int_name		線種名
	復帰値
			int		code	線種コード

  ３．履歴
	    履歴番号    日付け         担当者		 概要
	     作成		2000.04.29     宮園(FQS)

**/
int SXFPreLineTypeTableC::GetCode(const char* in_name)
{
	char* type_name;
	int ret = 1;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize(); i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name);
		if ( strcmp(type_name,in_name) == 0){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      線種名に対応するコードを取得する

  ２．インターフェース
	int		SXFPreLineTypeTableC::GetPreCode(const char* in_name)
		
	引数	：	型		引数名			内容
				char*	int_name		線種名
	復帰値
			int		code	線種コード

  ３．履歴
	    履歴番号    日付け         担当者		 概要
	     作成		2000.04.29     宮園(FQS)

**/
int SXFPreLineTypeTableC::GetPreCode(const char* in_name)
{
	char* type_name;
	int ret = 0;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize(); i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name);
		if ( strcmp(type_name,in_name) == 0){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                作成日：2000.04.29

  １．機能概要
      線種名に対応するtypeを取得する

  ２．インターフェース
	int		SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name,size_t NameSize)
		
	引数	：	型		引数名			内容
				　int in_code			線種コード
				  char*	out_name		線種名
				  size_t NameSize		線種名バッファサイズ
	復帰値
			正常時：TRUE
			異常時：FALSE

  ３．履歴
	    履歴番号    日付け         担当者		 概要
	    作成		2000.04.29     宮園(FQS)
		更新		2015.04.27		T.Matsushima	JPCERT/CC 指摘 脆弱性対応

**/
//BOOL SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name)
BOOL SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name,size_t NameSize)
{
	char *pre_name;

	if(in_code >= m_DefaultPreLineTypeTable.GetSize())
		return FALSE;
	m_DefaultPreLineTypeTable[in_code-1].GetName(pre_name);
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(out_name,"$$");
	//strcat(out_name,pre_name);
	//strcat(out_name,"_");
	strcpy_s(out_name,NameSize,"$$");
	strcat_s(out_name,NameSize,pre_name);
	strcat_s(out_name,NameSize,"_");
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	return TRUE;
}

