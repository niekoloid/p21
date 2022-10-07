/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	既定義線種のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFPreTypeMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_draughting_pre_defined_curve_fontC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPreTypeMappingC::SXFPreTypeMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFPreTypeMappingC::SXFPreTypeMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFPreTypeMappingC::~SXFPreTypeMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFPreTypeMappingC::~SXFPreTypeMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	既定義線種のMapping

	２．インターフェース
	BOOL MappingStruct(Predefined_Linetype_Struct* IN_Struct)
	引数:	型								引数名				内容
			Predefined_Linetype_Struct*		IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFPreTypeMappingC::MappingStruct(Predefined_Linetype_Struct* IN_Struct)
{
	m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_inst[0] = new SXFE_draughting_pre_defined_curve_fontC(m_str) ;

	m_ID = m_inst[0]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	既定義線種インスタンスのファイルへの出力

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
BOOL SXFPreTypeMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreTypeMappingC.cpp								作成日：2000.4.14

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
int SXFPreTypeMappingC::GetID()
{
	return m_ID;
}
