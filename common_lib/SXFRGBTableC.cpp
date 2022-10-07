/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                作成日：2000.04.29

	１．クラス概要
		色テーブル情報を管理する

	２．履歴
	    履歴番号    日付け         担当者		概要
		作成		2000.4.29     宮園(FQS)
**/
#include "stdafx.h"
#include <afx.h>
#include "SXFRGBTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                作成日：2000.04.29

  １．機能概要
      コンストラクタ

  ２．インターフェース
		void	SXFRGBTableC::SXFRGBTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
SXFRGBTableC::SXFRGBTableC(){
	m_DefaultColorTable.Add( SXFDefaultRGBC( 1,"black"     ,  0,  0,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 2,"red"       ,255,  0,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 3,"green"     ,  0,255,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 4,"blue"      ,  0,  0,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 5,"yellow"    ,255,252,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 6,"magenta"   ,255,  0,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 7,"cyan"      ,  0,255,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 8,"white"     ,255,255,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 9,"deeppink"  ,192,  0,128)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(10,"brown"     ,192,128, 64)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(11,"orange"    ,255,128,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(12,"lightgreen",128,192,128)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(13,"lightblue" ,  0,128,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(14,"lavender"  ,128, 64,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(15,"lightgray" ,192,192,192)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(16,"darkgray"  ,128,128,128)  );
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                作成日：2000.04.29

  １．機能概要
      デストラクタ

  ２．インターフェース
		void	SXFRGBTableC::~SXFRGBTableC()
		
	引数	：	型		引数名				内容
		なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
SXFRGBTableC::~SXFRGBTableC(){
}

int SXFRGBTableC::GetCode(int red,int green,int blue){
	int code = 3;
	double err , min_err = 1.0e99;
	for(int i= 0; i < m_DefaultColorTable.GetSize(); i++){
		err = m_DefaultColorTable[i].GetError(red,green,blue);
		if(err < min_err){
			min_err = err;
			code = m_DefaultColorTable[i].GetCode();
		}
	}
	return code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                作成日：2000.04.29

  １．機能概要
      色名から色コードを取得する

  ２．インターフェース
		int	SXFRGBTableC::GetColorCode(const char* name,int& code)
		
	引数	：	型		引数名		内容
				char*	name		色名
				int&	code		色コード

	復帰値
			TRUE	色名に対応するRGB値あり
			FALSE	色名に対応するRGB値なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
BOOL SXFRGBTableC::GetRGB(const char* name, int& code, int& red, int& green, int& blue){
	char* color_name;
	BOOL findflg= FALSE;
	for (int i= 0; i < m_DefaultColorTable.GetSize(); i++){
		m_DefaultColorTable[i].GetName(color_name);
		if (strcmp(color_name, name) == 0){
			m_DefaultColorTable[i].GetDefaultRGB(red,green,blue);
			code = m_DefaultColorTable[i].m_Code;
			findflg= TRUE;

			break;
		}
	}
	if(findflg== FALSE)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                作成日：2000.04.29

  １．機能概要
      色コードから色名を取得する

  ２．インターフェース
		int	SXFRGBTableC::GetPreColor(int code, char* & name, int& red, int& green, int& blue)
		
	引数	：	型		引数名		内容
				char*	name		色名
				int&	code		色コード
				int&	red			R値
				int&	green		G値
				int&	blue		B値
	復帰値
			TRUE	色コードに対応するRGB値あり
			FALSE	色コードに対応するRGB値なし

  ３．履歴
	    履歴番号    日付け			担当者		 概要
	    作成		2000.04.29      宮園(FQS)
**/
BOOL SXFRGBTableC::GetPreColor(int code, char* & name, int& red, int& green, int& blue)
{
	if(code > m_DefaultColorTable.GetSize())
		return FALSE;
	m_DefaultColorTable[code-1].GetName(name);
	m_DefaultColorTable[code-1].GetDefaultRGB(red,green,blue);
	return TRUE;
}
