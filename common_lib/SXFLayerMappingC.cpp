/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	レイヤのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFLayerMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFLayerC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_presentation_layer_assignmentC.h"
#include "SXFE_presentation_layer_usageC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFLayerMappingC::SXFLayerMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFLayerMappingC::SXFLayerMappingC()
{
	for (int i = 0; i < 2; i++){
		m_inst[i] = NULL;
	}
	m_aggr1 = NULL;
	m_elem1 = NULL;
	m_sheet = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFLayerMappingC::~SXFLayerMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFLayerMappingC::~SXFLayerMappingC()
{
	if (m_inst[1] != NULL)
		delete m_inst[1];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．機能概要
	レイヤのMapping

	２．インターフェース
	BOOL MappingStruct(SXFLayerC* IN_Layer)
	引数:	型				引数名				内容
			SXFLayerC*		IN_Layer			SXFLayerCオブジェクトのポインタ

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFLayerMappingC::MappingStruct(SXFLayerC *IN_Layer)
{
	m_str1 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Layer->m_Name);
	m_str2 = new SXFD_StrC(" ");
	m_aggr1 = new SXFD_AggrC();
	for (int i = 0; i < IN_Layer->m_Element.GetSize(); i++){
		m_elem1 = new SXFD_InstC(IN_Layer->m_Element[i]);
		m_aggr1->AddElem(m_elem1);
	}
	m_inst[0]=new SXFE_presentation_layer_assignmentC(m_str1,m_str2,m_aggr1);
	m_ID = m_inst[0]->GetInsID();

	m_sheet = new SXFD_InstC(IN_Layer->m_SheetID);
	m_inst[1]=new SXFE_presentation_layer_usageC(m_inst[0],m_sheet);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．機能概要
	インスタンスのファイルへの出力

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
BOOL SXFLayerMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[1]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.cpp								作成日：2000.4.14

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
int SXFLayerMappingC::GetID()
{
	return m_ID;
}
