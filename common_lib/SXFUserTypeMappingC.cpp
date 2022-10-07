/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	ユーザ定義線種のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFUserTypeMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_curve_style_font_patternC.h"
#include "SXFE_curve_style_fontC.h"
#include "SXFD_ListAggrC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFUserTypeMappingC::SXFUserTypeMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFUserTypeMappingC::SXFUserTypeMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFUserTypeMappingC::~SXFUserTypeMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFUserTypeMappingC::~SXFUserTypeMappingC()
{
	if (m_inst[4] != NULL)
		delete m_inst[4];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	角度寸法のMapping

	２．インターフェース
	BOOL MappingStruct(Userdefined_Linetype_Struct* IN_Struct)
	引数:	型								引数名				内容
			Userdefined_Linetype_Struct*	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFUserTypeMappingC::MappingStruct(Userdefined_Linetype_Struct *IN_Struct)
{
	for (int i = 0; i < IN_Struct->segment/2;i++){
		m_real1 = new SXFD_RealC(IN_Struct->pitch[2*i]);
		m_real2 = new SXFD_RealC(IN_Struct->pitch[2*i+1]);
		m_inst[i] = new SXFE_curve_style_font_patternC(m_real1,m_real2) ;
	}
	m_list_aggr = new SXFD_ListAggrC();
	for (i = 0; i < IN_Struct->segment/2; i++){
		m_list_aggr->AddElem(m_inst[i]);
	}
	m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_inst[4] = new SXFE_curve_style_fontC(m_str,m_list_aggr);

	m_ID = m_inst[4]->GetInsID();

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

	１．機能概要
	ユーザ定義線種インスタンスのファイルへの出力

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
BOOL SXFUserTypeMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[4]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserTypeMappingC.cpp								作成日：2000.4.14

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
int SXFUserTypeMappingC::GetID()
{
	return m_ID;
}
