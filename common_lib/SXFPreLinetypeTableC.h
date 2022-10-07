/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.h                作成日：2000.04.29

	１．クラス概要
		既定義線種テーブル情報を管理する

	２．履歴
	    履歴番号    日付け         担当者		概要
		作成		2000.4.29     宮園(FQS)
		更新		2015.04.27	T.Matsushima	JPCERT/CC 指摘 脆弱性対応
**/
#ifndef _SXFPRELINETYPETABLEC_H_
#define _SXFPRELINETYPETABLEC_H_

#include <string.h>
#include <afxtempl.h>

class SXFDefaultPreLineTypeC{
public:
	SXFDefaultPreLineTypeC()
	{
	};
	
	~SXFDefaultPreLineTypeC()
	{
	};
	
	void GetName(char*& out_name)
	{
		out_name = m_Name;
	};
	
	int GetCode()
	{
		return m_Code;
	};
	
	SXFDefaultPreLineTypeC(int in_code, const char *in_name1, const char *in_name2)
	{
		m_Code = in_code;
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(m_Name,in_name1);
		//strcpy(m_Name_202,in_name2);
		strcpy_s(m_Name,_countof(m_Name),in_name1);
		strcpy_s(m_Name_202,_countof(m_Name_202),in_name2);
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	};
	
private:
	char m_Name_202[128];
	int m_Code;
	char m_Name[128];
};

typedef CArray<SXFDefaultPreLineTypeC, SXFDefaultPreLineTypeC&> SXFDEFAULTPRELINETYPE;

class SXFPreLineTypeTableC{  

public:
	SXFPreLineTypeTableC();
	~SXFPreLineTypeTableC();
   
	int GetAP202UserDefCode(const char* in_name);
//	BOOL GetUserLinetype(int in_code,char* out_name);					JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	BOOL GetUserLinetype(int in_code,char* out_name,size_t NameSize);	// バッファサイズを渡すように変更
	int GetCode(const char* in_name);
	BOOL GetPreLinetype(int in_code, char*& out_name);

	int GetPreCode(const char* in_name);

private:
	SXFDEFAULTPRELINETYPE m_DefaultPreLineTypeTable;

};

#endif // _SXFPRELINETYPETABLEC_H_
