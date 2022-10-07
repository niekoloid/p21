/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．クラス概要
	複合図形定義のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFSfigMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_representation_contextC.h"
#include "SXFE_draughting_subfigure_representationC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_representation_mapC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFSfigMappingC::SXFSfigMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFSfigMappingC::SXFSfigMappingC()
{
	for (int i = 0; i < 5; i++){
		m_inst[i] = NULL;
	}
	m_elem_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFSfigMappingC::~SXFSfigMappingC()
	引数:	型				引数名				内容
			なし				


	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFSfigMappingC::~SXFSfigMappingC()
{
#if 1
	SXFInstanceC::InitDeleteMap();
	if (m_inst[4] != NULL)
		delete m_inst[4];
	SXFInstanceC::EndDeleteMap();
#endif
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．機能概要
	Mappingを行う。

	２．インターフェース
	BOOL MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID)
	引数:	型				引数名				内容
			Sfigorg_Struct	IN_Struct			構造体
			CUIntArray*		IN_ChildrenID		複合図形定義が指すフィーチャ要素のID配列
	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFSfigMappingC::MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID)
{

	////////////////////////////
	//単位インスタンス
	////////////////////////////
	m_inst[0] = new SXFE_representation_contextC();

	m_str1 = new SXFD_StrC(" ");
	m_aggr1 = new SXFD_AggrC() ;
	m_real1 = new SXFD_RealC(0.0);
	m_real2 = new SXFD_RealC(0.0);
	m_aggr1->AddElem(m_real1);
	m_aggr1->AddElem(m_real2);
	m_inst[1] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_str3 = new SXFD_StrC(DEF_DOLLAR);
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str2,m_inst[1],m_str3);

	char sfig_name[310];
	switch(IN_Struct.flag){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_FM_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_FM_");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_FG_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_FG_");
		break;
	case 3:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_G_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_G_");
		break;
	case 4:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_P_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_P_");
		break;
	default:
		return FALSE;
		break;
	}
	//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcat(sfig_name,IN_Struct.name);
	strcat_s(sfig_name,_countof(sfig_name),IN_Struct.name);
	m_str4 = new SXFD_StrC(sfig_name);
	///////////////////////////
	//複合図形が指す要素の登録
	///////////////////////////
	m_aggr2 = new SXFD_AggrC();
	for (int i = 0; i < IN_ChildrenID->GetSize(); i++){
		m_elem_inst = new SXFD_InstC(IN_ChildrenID->GetAt(i));
		m_aggr2->AddElem(m_elem_inst);
	}
	m_aggr2->AddElem(m_inst[2]);
	m_inst[3] = new SXFE_draughting_subfigure_representationC(m_str4,m_aggr2,m_inst[0]);
	//
	m_inst[4] = new SXFE_symbol_representation_mapC(m_inst[2],m_inst[3]);
	m_ID = m_inst[4]->GetInsID();////////複合図形のＩＤ

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．機能概要
	複合図形定義のキーインスタンスのIDを返す。

	２．インターフェース
	int GetID()
	引数:	型				引数名				内容
			なし
	復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
int SXFSfigMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								作成日：2001.06.14

	１．機能概要
	複合図形定義をファイルへ出力する

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名				内容
			SXFPart21FileC*		IN_File				ファイルオブジェクトのアドレス

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFSfigMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[4]->WriteP21(IN_File);
	return TRUE;
}
