/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．クラス概要
	補助線のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFProjMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFD_EnumC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_directionC.h"
#include "SXFE_vectorC.h"
#include "SXFE_lineC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXFE_styled_itemC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFProjMappingC::SXFProjMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFProjMappingC::SXFProjMappingC()
:	m_slist(NULL),
	m_ins1(NULL),
	m_ins2(NULL),
	m_ins3(NULL),
	m_ins4(NULL),
	m_aggr1(NULL),
	m_aggr2(NULL),
	m_aggr3(NULL),
	m_aggr4(NULL),
	m_aggr5(NULL),
	m_aggr6(NULL),
	m_aggr7(NULL),
	m_str1(NULL),
	m_str2(NULL),
	m_str3(NULL),
	m_str4(NULL),
	m_str5(NULL),
	m_str6(NULL),
	m_str7(NULL),
	m_str8(NULL),
	m_real1(NULL),
	m_real2(NULL),
	m_real3(NULL),
	m_real4(NULL),
	m_real5(NULL),
	m_real6(NULL),
	m_real7(NULL),
	m_enum1(NULL),
	m_bool1(NULL)
{
	m_Flag = -1;
	for(int i=0; i<8; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFProjMappingC::SXFProjMappingC(int IN_Flag)
	引数:	型				引数名				内容
			int 			IN_Flag				順番フラグ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFProjMappingC::SXFProjMappingC(int IN_Flag)
:	m_slist(NULL),
	m_ins1(NULL),
	m_ins2(NULL),
	m_ins3(NULL),
	m_ins4(NULL),
	m_aggr1(NULL),
	m_aggr2(NULL),
	m_aggr3(NULL),
	m_aggr4(NULL),
	m_aggr5(NULL),
	m_aggr6(NULL),
	m_aggr7(NULL),
	m_str1(NULL),
	m_str2(NULL),
	m_str3(NULL),
	m_str4(NULL),
	m_str5(NULL),
	m_str6(NULL),
	m_str7(NULL),
	m_str8(NULL),
	m_real1(NULL),
	m_real2(NULL),
	m_real3(NULL),
	m_real4(NULL),
	m_real5(NULL),
	m_real6(NULL),
	m_real7(NULL),
	m_enum1(NULL),
	m_bool1(NULL)
{
	m_Flag = IN_Flag;
	for(int i=0; i<8; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFProjMappingC::~SXFProjMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFProjMappingC::~SXFProjMappingC()
{

	if (m_inst[7] != NULL)
		delete m_inst[7];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	補助線のMapping

	２．インターフェース
	BOOL MappingStruct(ProjLine_Struct IN_Struct)
	引数:	型					引数名				内容
			ProjLine_Struct		IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
BOOL SXFProjMappingC::MappingStructDim(ProjLine_Struct IN_Struct)
{
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem( new SXFD_RealC(IN_Struct.ho_x2) ) ;
	m_aggr1->AddElem( new SXFD_RealC(IN_Struct.ho_y2) ) ;
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.ho_x1);
	m_real2 = new SXFD_RealC(IN_Struct.ho_y1);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real1) ;
	m_aggr2->AddElem(m_real2) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;

	m_str3 = new SXFD_StrC(" ");
	double m_direction_x = IN_Struct.ho_x2 - IN_Struct.ho_x1;
	double m_direction_y = IN_Struct.ho_y2 - IN_Struct.ho_y1;
	m_real3 = new SXFD_RealC(m_direction_x);
	m_real4 = new SXFD_RealC(m_direction_y);
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem(m_real3) ;
	m_aggr3->AddElem(m_real4) ;
	m_inst[2] = new SXFE_directionC(m_str3,m_aggr3) ;

	m_str4 = new SXFD_StrC(" ");
	m_real5 = new SXFD_RealC(1.0);
	m_inst[3] = new SXFE_vectorC(m_str4,m_inst[2],m_real5);

	m_str5 = new SXFD_StrC(" ");
	m_real6 = new SXFD_RealC(IN_Struct.ho_x0);
	m_real7 = new SXFD_RealC(IN_Struct.ho_y0);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem(m_real6) ;
	m_aggr4->AddElem(m_real7) ;
	m_inst[4] = new SXFE_cartesian_pointC(m_str5,m_aggr4) ;

	m_str6 = new SXFD_StrC(" ");
	m_inst[5] = new SXFE_lineC(m_str6,m_inst[4],m_inst[3]) ;

	m_str7 = new SXFD_StrC(" ");
	m_aggr5 = new SXFD_AggrC();
	m_aggr5->AddElem(m_inst[1]);
	m_aggr6 = new SXFD_AggrC();
	m_aggr6->AddElem(m_inst[0]);
	m_bool1 = new SXFD_BoolC(TRUE);
	m_enum1 = new SXFD_EnumC("CARTESIAN");
	m_inst[6] = new SXFE_trimmed_curveC
					(m_str7,
					 m_inst[5],
					 m_aggr5,
					 m_aggr6,
					 m_bool1,
					 m_enum1) ;
	
	char tmp_char[64];
	switch(m_Flag){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_prj_1");
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_prj_1");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_prj_2");
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_prj_2");
		break;
	default:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char," ");
		strcpy_s(tmp_char,_countof(tmp_char)," ");
		break;
	}
	m_str8 = new SXFD_StrC(tmp_char);
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_slist->AddTail(DEF_PROJECTION_CURVE);
	m_ins1 = new SXFD_InstC(IN_Struct.target_ID);
	m_aggr7 = new SXFD_AggrC() ;
	m_aggr7->AddElem( m_ins1 ) ;
	m_inst[7] = new SXFE_styled_itemC(m_str8,m_aggr7,m_inst[6],m_slist) ;
	m_ID = m_inst[7]->GetInsID();
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	補助線インスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
BOOL SXFProjMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[7]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFProjMappingC.cpp								作成日：2000.4.17

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFProjMappingC::GetID()
{
	return m_ID;
}
