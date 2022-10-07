/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．クラス概要
	スプラインのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
#include "stdafx.h"
#include <math.h>
#include "SXFClothoidMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_EnumC.h"
#include "SXFD_BoolC.h"
#include "SXFD_IntC.h"
#include "SXFD_TypeC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_clothoidC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFE_composite_curve_segmentC.h"
#include "SXFD_ListAggrC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFClothoidMappingC::SXFClothoidMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
SXFClothoidMappingC::SXFClothoidMappingC()
{
	m_TableManager = NULL;
	m_ID = -1;
	for (int i = 0; i < INST_NUM; i++){
		m_inst[i] = NULL;
	}
	for (i = 0; i < AGGR_NUM; i++){
		m_aggr[i] = NULL;
	}
	for (i = 0; i < STR_NUM; i++){
		m_str[i] = NULL;
	}
	for (i = 0; i < REAL_NUM; i++){
		m_real[i] = NULL;
	}
	for (i = 0; i < ENUM_NUM; i++){
		m_enum[i] = NULL;
	}
	for (i = 0; i < TYPE_NUM; i++){
		m_type[i] = NULL;
	}
	for (i = 0; i < BOOL_NUM; i++){
		m_bool[i] = NULL;
	}
	m_slist = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFClothoidMappingC(SXFTableManagerC* IN_TableManager)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ		

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
SXFClothoidMappingC::SXFClothoidMappingC(SXFTableManagerC* IN_TableManager)
{
	m_TableManager = IN_TableManager;
	m_ID = -1;
	for (int i = 0; i < INST_NUM; i++){
		m_inst[i] = NULL;
	}
	for (i = 0; i < AGGR_NUM; i++){
		m_aggr[i] = NULL;
	}
	for (i = 0; i < STR_NUM; i++){
		m_str[i] = NULL;
	}
	for (i = 0; i < REAL_NUM; i++){
		m_real[i] = NULL;
	}
	for (i = 0; i < ENUM_NUM; i++){
		m_enum[i] = NULL;
	}
	for (i = 0; i < TYPE_NUM; i++){
		m_type[i] = NULL;
	}
	for (i = 0; i < BOOL_NUM; i++){
		m_bool[i] = NULL;
	}
	m_slist = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFClothoidMappingC::~SXFClothoidMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
SXFClothoidMappingC::~SXFClothoidMappingC()
{
	if (m_inst[INST_NUM - 1])
	{
		delete m_inst[INST_NUM - 1];
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	スプラインのMapping

	２．インターフェース
	BOOL MappingStruct(Clothoid_Struct* IN_Struct)
	引数:	型					引数名				内容
			Clothoid_Struct*		IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
BOOL SXFClothoidMappingC::MappingStruct(Clothoid_Struct* IN_Struct)
{
	m_str[0] = new SXFD_StrC(" ");
	double	direction_x = cos(acos(-1.)*IN_Struct->angle/180.0);
	double	direction_y = sin(acos(-1.)*IN_Struct->angle/180.0);
	m_real[0] = new SXFD_AngleC(direction_x);
	m_real[1] = new SXFD_AngleC(direction_y);
	m_aggr[0] = new SXFD_AggrC() ;
	m_aggr[0]->AddElem(m_real[0]) ;
	m_aggr[0]->AddElem(m_real[1]) ;
	m_inst[0] = new SXFE_directionC(m_str[0],m_aggr[0]) ;

	m_str[1] = new SXFD_StrC(" ");
	m_real[2] = new SXFD_RealC(IN_Struct->base_x);
	m_real[3] = new SXFD_RealC(IN_Struct->base_y);
	m_aggr[1] = new SXFD_AggrC() ;
	m_aggr[1]->AddElem(m_real[2]) ;
	m_aggr[1]->AddElem(m_real[3]) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str[1],m_aggr[1]);

	m_str[2] = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str[2], m_inst[1], m_inst[0]);

	CString	strDirection;
	strDirection.Format(_T("%d"), IN_Struct->direction);
	m_str[3] = new SXFD_StrC(strDirection.GetBuffer(strDirection.GetLength() + 1));
	strDirection.ReleaseBuffer();
	m_real[4] = new SXFD_RealC(IN_Struct->parameter);
	m_inst[3] = new SXFE_clothoidC(m_str[3],m_inst[2],m_real[4]);

	CString	strLength;
	strLength.Format(_T("%f,%f"), IN_Struct->start_length, IN_Struct->end_length);
	m_str[4] = new SXFD_StrC(strLength.GetBuffer(strLength.GetLength() + 1));
	strLength.ReleaseBuffer();

	m_real[5] = new SXFD_RealC(IN_Struct->start_length);
	m_type[0] = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type[0]->SetNext(m_real[5]);
	m_aggr[2] = new SXFD_AggrC();
	m_aggr[2]->AddElem(m_type[0]);

	m_real[6] = new SXFD_RealC(IN_Struct->end_length);
	m_type[1] = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type[1]->SetNext(m_real[6]);
	m_aggr[3] = new SXFD_AggrC();
	m_aggr[3]->AddElem(m_type[1]);

	m_bool[0] = new SXFD_BoolC(IN_Struct->start_length < IN_Struct->end_length);
	m_enum[0] = new SXFD_EnumC(DEF_PARAMETER);

	m_inst[4] = new SXFE_trimmed_curveC
				(m_str[4],
				 m_inst[3],
				 m_aggr[2],
				 m_aggr[3],
				 m_bool[0],
				 m_enum[0]);

	m_str[5] = new SXFD_StrC(" ");
	int table_type;
	if (IN_Struct->type < 17)
		table_type = 4;
	else
		table_type = 5;
	m_inst[5] = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->type));
	m_inst[6] = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct->line_width));
	if (IN_Struct->color < 17)
		table_type = 2;
	else
		table_type = 3;
	m_inst[7] = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->color));
	m_inst[8] = new SXFE_curve_styleC(m_str[5],m_inst[5],m_inst[6],m_inst[7]);

	m_aggr[4] = new SXFD_AggrC();
	m_aggr[4]->AddElem(m_inst[8]);
	m_inst[9] = new SXFE_presentation_style_assignmentC(m_aggr[4]);

	m_str[6] = new SXFD_StrC(" ");
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr[5] = new SXFD_AggrC();
	m_aggr[5]->AddElem(m_inst[9]);
	m_inst[10] = new SXFE_styled_itemC(m_str[6],m_aggr[5],m_inst[4],m_slist);

	m_ID = m_inst[INST_NUM - 1]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);
/*
	for(int i=0; i < IN_Struct->number;i++){
		m_real1 = new SXFD_RealC(IN_Struct->x[i]);
		m_real2 = new SXFD_RealC(IN_Struct->y[i]);
		m_aggr1 = new SXFD_AggrC() ;
		m_aggr1->AddElem(m_real1) ;
		m_aggr1->AddElem(m_real2) ;
		m_str1 = new SXFD_StrC(" ");
		m_elem1 = new SXFE_cartesian_pointC(m_str1,m_aggr1);
		m_list_elems.AddTail(m_elem1) ;
	}
	
	m_str2 = new SXFD_StrC(" ");
	m_int1 = new SXFD_IntC(3);
	m_bool1 = new SXFD_BoolC("UNSPECIFIED");
	if(IN_Struct->open_close == 0){
		 m_bool2 = new SXFD_BoolC(TRUE);
	}
	else if (IN_Struct->open_close == 1){
		 m_bool2 = new SXFD_BoolC(FALSE);
	}
	else
		return FALSE;

	m_bool3 = new SXFD_BoolC("UNKNOWN");
	m_list_aggr = new SXFD_ListAggrC();
	for(i = 0; i < IN_Struct->number; i++)
		m_list_aggr->AddElem(m_list_elems.GetAt(m_list_elems.FindIndex(i)));
	m_elem2 = new SXFE_clothoidC(m_str2,m_int1,m_list_aggr,m_bool1,m_bool2,m_bool3);
	m_list_elems.AddTail(m_elem2);

	m_str3 = new SXFD_StrC(" ");
	int table_type;
	if (IN_Struct->type < 17)
		table_type = 4;
	else
		table_type = 5;
		m_ins1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->type));
		m_ins2 = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct->line_width));
	if (IN_Struct->color < 17)
		table_type = 2;
	else
		table_type = 3;
	m_ins3 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->color));
	m_elem3 = new SXFE_curve_styleC(m_str3,m_ins1,m_ins2,m_ins3);
	m_list_elems.AddTail(m_elem3) ;

	int pos1;
	pos1 = m_list_elems.GetCount();
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_list_elems.GetAt(m_list_elems.FindIndex(pos1-1)) ) ;
	m_elem4 = new SXFE_presentation_style_assignmentC(m_aggr3);
	m_list_elems.AddTail(m_elem4) ;

	m_str4 = new SXFD_StrC(" ");
	pos1 = m_list_elems.GetCount();
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_elem4 ) ;
	m_elem5 = new SXFE_styled_itemC(m_str4,m_aggr4,m_elem2,m_slist);
	m_list_elems.AddTail(m_elem5) ;

	m_ID = m_elem5->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);
*/
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	スプラインインスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
BOOL SXFClothoidMappingC::WriteAP202(SXFPart21FileC *IN_File)
{	
	m_inst[INST_NUM - 1]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoidMappingC.cpp								作成日：2007.1.30

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
int SXFClothoidMappingC::GetID()
{
	return m_ID;
}
