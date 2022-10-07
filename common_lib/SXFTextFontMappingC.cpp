/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	文字フォントのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFTextFontMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_externally_defined_text_fontC.h"
#include "SXFE_External_sourceC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTextFontMappingC::SXFTextFontMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFTextFontMappingC::SXFTextFontMappingC()
:	m_ID(-1),
	m_str1(NULL),
	m_str2(NULL),
	m_type1(NULL),
	m_type2(NULL)
{
	for(int i=0; i<2; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFTextFontMappingC::~SXFTextFontMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFTextFontMappingC::~SXFTextFontMappingC()
{
	if (m_inst[1] != NULL)
		delete m_inst[1];
	if (m_str1 != NULL)
		delete m_str1;
	if (m_str2 != NULL)
		delete m_str2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．機能概要
	文字フォントのMapping

	２．インターフェース
	BOOL MappingStruct(Text_Font_Struct* IN_Struct)
	引数:	型					引数名				内容
			Text_Font_Struct*	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFTextFontMappingC::MappingStruct(Text_Font_Struct *IN_Struct)
{

	m_type1 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_str1 = new SXFD_StrC("scadec");
	m_type1->SetNext(m_str1);
	m_inst[0] = new SXFE_external_sourceC(m_type1) ;

	m_type2 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_str2 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_type2->SetNext(m_str2);
	m_inst[1] = new SXFE_externally_defined_text_fontC(m_type2,m_inst[0]) ;

	m_ID = m_inst[1]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．機能概要
	文字フォントインスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFTextFontMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[1]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.cpp								作成日：2000.4.14

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
int SXFTextFontMappingC::GetID()
{
	return m_ID;
}
