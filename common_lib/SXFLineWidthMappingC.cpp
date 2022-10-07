/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．クラス概要
	線幅のMapping

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFLineWidthMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_TypeC.h"
#include "SXFPart21FileC.h"
#include "SXFE_length_measure_with_unitC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFLineWidthMappingC::SXFLineWidthMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
SXFLineWidthMappingC::SXFLineWidthMappingC()
:	m_ID(-1),
	m_unit_inst(NULL),
	m_real(NULL),
	m_type(NULL)
{
	m_inst[0] = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFLineWidthMappingC::~SXFLineWidthMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
SXFLineWidthMappingC::~SXFLineWidthMappingC()
{
	if (m_inst[0] != NULL)
		delete m_inst[0];
	if (m_real != NULL)
		delete m_real;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．機能概要
	線幅のMapping

	２．インターフェース
	BOOL MappingStruct(Line_Width_Struct* IN_Struct)
	引数:	型							引数名				内容
			Line_Width_Struct*			IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
BOOL SXFLineWidthMappingC::MappingStruct(Line_Width_Struct *IN_Struct)
{
	m_type = new SXFD_TypeC(DEF_POSITIVE_LENGTH_MEASURE);
	m_real = new SXFD_RealC(IN_Struct->width);
	m_type->SetNext(m_real);

	//単位のインスタンスIDを取得する必要あり。
	m_unit_inst = new SXFD_InstC(10);

	m_inst[0] = new SXFE_length_measure_with_unitC(m_type,m_unit_inst);

	m_ID = m_inst[0]->GetInsID();
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．機能概要
	インスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
BOOL SXFLineWidthMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[0]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineWidthMappingC.cpp					作成日：2000.04.14

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.14	宮園(FQS)	なし。
**/
int SXFLineWidthMappingC::GetID()
{
	return m_ID;
}
