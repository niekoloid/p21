/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								作成日：2000.4.16

	１．クラス概要
	InvisibilityのMapping
	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.16			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFInvisibilityMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_invisibilityC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								作成日：2000.4.16

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFInvisibilityMappingC::SXFInvisibilityMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.16			宮園(FQS)			なし。

**/
SXFInvisibilityMappingC::SXFInvisibilityMappingC()
{
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_aggr = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								作成日：2000.4.16

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFInvisibilityMappingC::~SXFInvisibilityMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.16			宮園(FQS)			なし。

**/
SXFInvisibilityMappingC::~SXFInvisibilityMappingC()
{
	if (m_inst2 != NULL)
		delete m_inst2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								作成日：2000.4.16

	１．機能概要
	InvisibilityのMapping

	２．インターフェース
	BOOL SXFInvisibilityMappingC::MappingStruct(CUIntArray* IN_Invisibility)
	引数:	型				引数名				内容
			CUIntArray* 	IN_Invisibility				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.16			宮園(FQS)			なし。

**/
BOOL SXFInvisibilityMappingC::MappingStruct(CUIntArray* IN_Invisibility)
{
	m_aggr = new SXFD_AggrC();
	for (int i = 0; i < IN_Invisibility->GetSize(); i++){
		m_inst1 = new SXFD_InstC(IN_Invisibility->GetAt(i));
		m_aggr->AddElem(m_inst1);
	}
	m_inst2 = new SXFE_invisibilityC(m_aggr);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFInvisibilityMappingC.cpp								作成日：2000.4.16

	１．機能概要
	インスタンスのファイルへの出力

	２．インターフェース
	BOOL SXFInvisibilityMappingC::WriteAP202(SXFPart21FileC *IN_File)
	引数:	型				引数名				内容
			SXFPart21FileC 	*IN_File		ファイルオブジェクトのアドレス	

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.16			宮園(FQS)			なし。

**/
BOOL SXFInvisibilityMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst2->WriteP21(IN_File);
	return TRUE;
}
