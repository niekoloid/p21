/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	ユーザ定義色のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFUserColourMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_colour_rgbC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFUserColourMappingC::SXFUserColourMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFUserColourMappingC::SXFUserColourMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFUserColourMappingC::~SXFUserColourMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFUserColourMappingC::~SXFUserColourMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	ユーザ定義色のMapping

	２．インターフェース
	BOOL MappingStruct(Userdefined_Colour_Struct* IN_Struct)
	引数:	型							引数名				内容
			Userdefined_Colour_Struct*	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFUserColourMappingC::MappingStruct(Userdefined_Colour_Struct *IN_Struct)
{
	m_str = new SXFD_StrC("");
	m_real1 = new SXFD_RealC((double)(IN_Struct->red/255.0));
	m_real2 = new SXFD_RealC((double)(IN_Struct->green/255.0));
	m_real3 = new SXFD_RealC((double)(IN_Struct->blue/255.0));

	m_inst[0] = new SXFE_colour_rgbC(m_str,m_real1,m_real2,m_real3);

	m_ID = m_inst[0]->GetInsID();

	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	ハッチング(パターン）インスタンスのファイルへの出力

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
BOOL SXFUserColourMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUserColourMappingC.cpp								作成日：2000.4.14

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
int SXFUserColourMappingC::GetID()
{
	return m_ID;
}
