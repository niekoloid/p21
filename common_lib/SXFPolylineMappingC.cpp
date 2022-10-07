/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．クラス概要
	折線のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFPolylineMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_EnumC.h"
#include "SXFD_BoolC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_polylineC.h"
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
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPolylineMappingC::SXFPolylineMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFPolylineMappingC::SXFPolylineMappingC()
{
	m_ID = -1;
	m_AssignID = -1;
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_ins4 = NULL;
	m_write_inst = NULL;
	m_elem1 = NULL;
	m_elem2 = NULL;
	m_elem3 = NULL;
	m_elem4 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_list_aggr = NULL;	
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_slist = NULL;
	m_bool1 = NULL;
	m_enum1 = NULL;
	m_LabelFlag = 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPolylineMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			int 				IN_LabelFlag		ラベルフラグ		

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFPolylineMappingC::SXFPolylineMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag)
{
	m_ID = -1;
	m_AssignID = -1;
	m_TableManager = IN_TableManager;
	m_LabelFlag = IN_LabelFlag;
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_ins4 = NULL;
	m_elem1 = NULL;
	m_elem2 = NULL;
	m_elem3 = NULL;
	m_elem4 = NULL;
	m_write_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_list_aggr = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_slist = NULL;
	m_bool1 = NULL;
	m_enum1 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFPolylineMappingC::~SXFPolylineMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
SXFPolylineMappingC::~SXFPolylineMappingC()
{
	if (m_list_elems.GetTail() != NULL)
		delete (SXFD_InstC*)m_list_elems.GetTail();
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	折線のMapping

	２．インターフェース
	BOOL MappingStruct(Polyline_Struct* IN_Struct)
	引数:	型					引数名				内容
			Polyline_Struct*	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
BOOL SXFPolylineMappingC::MappingStruct(Polyline_Struct* IN_Struct)
{

	INT_PTR pos1;
	for(int i = 0; i < IN_Struct->number; i++){
		m_str1 = new SXFD_StrC(" ");
		m_real1 = new SXFD_RealC(IN_Struct->x[i]);
		m_real2 = new SXFD_RealC(IN_Struct->y[i]);
		m_aggr1 = new SXFD_AggrC() ;
		m_aggr1->AddElem(m_real1) ;
		m_aggr1->AddElem(m_real2) ;
		m_elem1 = new SXFE_cartesian_pointC(m_str1,m_aggr1);
		m_list_elems.AddTail(m_elem1) ;
	}

	m_str2 = new SXFD_StrC(" ");
	m_list_aggr = new SXFD_ListAggrC();
	for(i = 0 ; i < IN_Struct->number; i++)
		m_list_aggr->AddElem(m_list_elems.GetAt(m_list_elems.FindIndex(i)));
	m_elem2 = new SXFE_polylineC(m_str2,m_list_aggr);
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
	m_ins4 = new SXFE_curve_styleC(m_str3,m_ins1,m_ins2,m_ins3);
	m_list_elems.AddTail(m_ins4) ;

	pos1 = m_list_elems.GetCount();
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_list_elems.GetAt(m_list_elems.FindIndex(pos1-1)) ) ;
	m_elem3 = new SXFE_presentation_style_assignmentC(m_aggr3);
	m_AssignID = m_elem3->GetInsID();//Balloonで使用
	m_list_elems.AddTail(m_elem3) ;

	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	if (m_LabelFlag)
		m_slist->AddTail(DEF_LEADER_CURVE);
	m_str4 = new SXFD_StrC(" ");
	pos1 = m_list_elems.GetCount();
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_list_elems.GetAt(m_list_elems.FindIndex(pos1-1)) ) ;
	m_elem4 = new SXFE_styled_itemC(m_str4,m_aggr4,(SXFD_InstC*)m_list_elems.GetAt(m_list_elems.FindIndex(pos1-3)),m_slist);
	m_list_elems.AddTail(m_elem4) ;
	m_ID = m_elem4->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);

	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	折線インスタンスのファイルへの出力

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
BOOL SXFPolylineMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_write_inst = (SXFD_InstC*)(m_list_elems.GetTail());
	m_write_inst->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

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
int SXFPolylineMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	複合曲線上の折線のMapping

	２．インターフェース
	BOOL MappingStructCurve(Polyline_Struct* IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN)
	引数:	型					引数名				内容
			Polyline_Struct*	IN_Struct			構造体
			double&				INOUT_PointX		ハッチング内部の点X
			double&				INOUT_PointY		ハッチング内部の点Y
			int&				INOUT_PointN		ハッチング内部の点個数

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
BOOL SXFPolylineMappingC::MappingStructCurve(Polyline_Struct *IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN)
{
//	int pos1;
	for(int i = 0; i < IN_Struct->number; i++){
		m_str1 = new SXFD_StrC(" ");
		m_real1 = new SXFD_RealC(IN_Struct->x[i]);
		m_real2 = new SXFD_RealC(IN_Struct->y[i]);
		m_aggr1 = new SXFD_AggrC() ;
		m_aggr1->AddElem(m_real1) ;
		m_aggr1->AddElem(m_real2) ;
		m_elem1 = new SXFE_cartesian_pointC(m_str1,m_aggr1);
		m_list_elems.AddTail(m_elem1) ;
	}

	m_str2 = new SXFD_StrC(" ");
	m_list_aggr = new SXFD_ListAggrC();
	for(i = 0 ; i < IN_Struct->number; i++)
		m_list_aggr->AddElem(m_list_elems.GetAt(m_list_elems.FindIndex(i)));
	m_elem2 = new SXFE_polylineC(m_str2,m_list_aggr);
	m_list_elems.AddTail(m_elem2);

	m_enum1 = new SXFD_EnumC(DEF_CONTINUOUS);
	m_bool1 = new SXFD_BoolC(DEF_TRUE);
	m_elem3 = new SXFE_composite_curve_segmentC(m_enum1,m_bool1,m_elem2);
	m_list_elems.AddTail(m_elem3);

	m_ID = m_elem3->GetInsID();
	//ハッチング内部の点の計算
	for (i = 0; i < IN_Struct->number; i++){
		INOUT_PointX += IN_Struct->x[i];
		INOUT_PointY += IN_Struct->y[i];
	}
	INOUT_PointN += IN_Struct->number;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolylineMappingC.cpp								作成日：2000.4.17

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetAssignID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.17			宮園(FQS)			なし。

**/
int SXFPolylineMappingC::GetAssignID()
{
	return m_AssignID;
}
