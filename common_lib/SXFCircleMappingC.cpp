/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．クラス概要
	円フィーチャのMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFCircleMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_circleC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	コンストラクタ

	２．インターフェース
		void	SXFCircleMappingC::SXFCircleMappingC()
		
	引数	：	型		引数名				内容
		なし
	
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFCircleMappingC::SXFCircleMappingC()
{
	m_ID = -1;
	m_AssignID = -1;
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_slist = NULL;

	m_TableManager = NULL;
	m_LabelFlag = NULL;
	for (int i = 0; i < 6; i++){
		m_inst[i] = NULL;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFCircleMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag)
		
	引数	：	型		引数名				内容
	SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
	int					IN_LabelFlag		ラベルフラグ
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFCircleMappingC::SXFCircleMappingC(SXFTableManagerC* IN_TableManager,int IN_LabelFlag)
{
	m_TableManager = IN_TableManager;
	m_LabelFlag = IN_LabelFlag;
	m_ID = -1;
	m_AssignID = -1;
	for (int i = 0; i < 6; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_slist = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	デストラクタ

	２．インターフェース
		void	SXFCircleMappingC::~SXFCircleMappingC()
		
	引数	：	型		引数名				内容
		なし
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFCircleMappingC::~SXFCircleMappingC()
{
	if (m_inst[5] != NULL)
		delete m_inst[5];
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	円フィーチャのMapping

	２．インターフェース
	BOOL MappingStruct(Circle_Struct IN_Struct)
	
	引数:	型					引数名				内容
			Circle_Struct		IN_Struct			構造体
	
	復帰値	正常時：TRUE
			異常時：FALSE
	
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
BOOL SXFCircleMappingC::MappingStruct(Circle_Struct IN_Struct)
{
	m_str1 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.center_x);
	m_real2 = new SXFD_RealC(IN_Struct.center_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_str3 = new SXFD_StrC(DEF_DOLLAR);
	m_inst[1] = new SXFE_axis2_placement_2dC(m_str2, m_inst[0], m_str3);

	m_str4 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.radius);
	m_inst[2] = new SXFE_circleC(m_str4, m_inst[1], m_real3);

	if (m_LabelFlag){
		m_str5 = new SXFD_StrC(" ");
		m_slist = new CStringList();
		m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
		m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
		m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
		m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
		m_ins1 = new SXFD_InstC(m_AssignID);
		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem(m_ins1) ;
		m_inst[5] = new SXFE_styled_itemC(m_str5,m_aggr2,m_inst[2],m_slist) ;
		m_ID = m_inst[5]->GetInsID();
	}
	else{
		m_str5 = new SXFD_StrC(" ");
		int table_type;
		if (IN_Struct.type < 17)
			table_type = 4;
		else
			table_type = 5;
		m_ins1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.type));
		m_ins2 = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct.line_width));
		if (IN_Struct.color < 17)
			table_type = 2;
		else
			table_type = 3;
		m_ins3 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
		m_inst[3] = new SXFE_curve_styleC(m_str5, m_ins1, m_ins2, m_ins3);

		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem( m_inst[3] ) ;
		m_inst[4] = new SXFE_presentation_style_assignmentC(m_aggr2) ;

		m_str6 = new SXFD_StrC(" ");
		m_slist = new CStringList();
		m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
		m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
		m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
		m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem( m_inst[4] ) ;
		m_inst[5] = new SXFE_styled_itemC(m_str6,m_aggr3,m_inst[2],m_slist) ;
		m_ID = m_inst[5]->GetInsID();
		m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);
	}
	return TRUE;	
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	円インスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
BOOL SXFCircleMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[5]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID
	
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
int SXFCircleMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleMappingC.cpp					作成日：2000.04.15

	１．機能概要
	PRESENTATION_STYLED_ASSIGNMENTのインスタンスIDを返却

	２．インターフェース
	int GetAssignID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	PRESENTATION_STYLED_ASSIGNMENTのインスタンスID
	
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
void SXFCircleMappingC::SetAssignID(int IN_AssignID)
{
	m_AssignID = IN_AssignID;
}
