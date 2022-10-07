/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

	１．クラス概要
	既定義色のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFPreColourMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFPart21FileC.h"
#include "SXFE_draughting_pre_defined_colourC.h"
#include "SXFE_colour_rgbC.h"
#include "SXFPreDefColorC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPreColourMappingC::SXFPreColourMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFPreColourMappingC::SXFPreColourMappingC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFPreColourMappingC::~SXFPreColourMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
SXFPreColourMappingC::~SXFPreColourMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

	１．機能概要
	既定義色のMapping

	２．インターフェース
	BOOL MappingStruct(SXFPreDefColorC IN_Struct)
	引数:	型					引数名				内容
			SXFPreDefColorC		IN_Struct			SXFPreDefColorC

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/
BOOL SXFPreColourMappingC::MappingStruct(SXFPreDefColorC IN_Struct)
{
	//コード：１から８　→DRAUGHTING_PRE_DEFINED_COLOUR
	//コード：９から１６→COLOUR_RGB
	if (IN_Struct.m_Code <= 8){
		m_str = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct.m_Name);
		m_inst[0] = new SXFE_draughting_pre_defined_colourC(m_str);
		m_ID = m_inst[0]->GetInsID();
		return TRUE;
	}
	else{
		char tmp_char[32];
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_");
		//strcat(tmp_char,IN_Struct.m_Name);
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_");
		strcat_s(tmp_char,_countof(tmp_char),IN_Struct.m_Name);
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		m_str = new SXFD_StrC(tmp_char);
		m_real1 = new SXFD_RealC((double)(IN_Struct.R/255.0));
		m_real2 = new SXFD_RealC((double)(IN_Struct.G/255.0));
		m_real3 = new SXFD_RealC((double)(IN_Struct.B/255.0));
		m_inst[0] = new SXFE_colour_rgbC(m_str,m_real1,m_real2,m_real3);
		m_ID = m_inst[0]->GetInsID();
		return TRUE;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

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
BOOL SXFPreColourMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColourMappingC.cpp								作成日：2000.4.14

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
int SXFPreColourMappingC::GetID()
{
	return m_ID;
}
