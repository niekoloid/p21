/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．クラス概要
	線分のMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFLineMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFD_EnumC.h"
#include "SXFPart21FileC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_directionC.h"
#include "SXFE_vectorC.h"
#include "SXFE_lineC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	コンストラクタ
	
	２．インターフェース
	void	SXFLineMappingC::SXFLineMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFLineMappingC::SXFLineMappingC()
{
	m_ID = -1;
	m_assign_ID = -1;
	m_DimFlag = -1;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	コンストラクタ
	
	２．インターフェース
	void	SXFLineMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ		
			int 				IN_DimFlag			Dim or Label	

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFLineMappingC::SXFLineMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag)
{
	m_ID = -1;
	m_assign_ID = -1;
	m_TableManager = IN_TableManager;
	m_DimFlag = IN_DimFlag;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	デストラクタ
	
	２．インターフェース
	void	SXFLineMappingC::~SXFLineMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
SXFLineMappingC::~SXFLineMappingC()
{
	if (m_inst[8] != NULL)
		delete m_inst[8];
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	線分のMapping

	２．インターフェース
	BOOL MappingStruct(Line_Struct IN_Struct)
	引数:	型					引数名				内容
			Line_Struct			IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
BOOL SXFLineMappingC::MappingStruct(Line_Struct IN_Struct)
{
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem( new SXFD_RealC(IN_Struct.end_x) ) ;
	m_aggr1->AddElem( new SXFD_RealC(IN_Struct.end_y) ) ;
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.start_x);
	m_real2 = new SXFD_RealC(IN_Struct.start_y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real1) ;
	m_aggr2->AddElem(m_real2) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;

	m_str3 = new SXFD_StrC(" ");
	double m_direction_x = IN_Struct.end_x - IN_Struct.start_x;
	double m_direction_y = IN_Struct.end_y - IN_Struct.start_y;
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
	m_ins1 = new SXFD_InstC(m_inst[1]->GetInsID());
	m_inst[4] = new SXFE_lineC(m_str5,m_ins1,m_inst[3]) ;

	m_str6 = new SXFD_StrC(" ");
	m_aggr4 = new SXFD_AggrC();
	m_aggr4->AddElem(m_inst[1]);
	m_aggr5 = new SXFD_AggrC();
	m_aggr5->AddElem(m_inst[0]);
	m_bool1 = new SXFD_BoolC(TRUE);
	m_enum1 = new SXFD_EnumC("CARTESIAN");
	m_inst[5] = new SXFE_trimmed_curveC
					(m_str6,
					 m_inst[4],
					 m_aggr4,
					 m_aggr5,
					 m_bool1,
					 m_enum1) ;
	
	m_str7 = new SXFD_StrC(" ");
	int table_type;
	if (IN_Struct.type < 17)
		table_type = 4;
	else
		table_type = 5;
	m_ins2 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.type));
	m_ins3 = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct.line_width));
	if (IN_Struct.color < 17)
		table_type = 2;
	else
		table_type = 3;
	m_ins4 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
	m_inst[6] = new SXFE_curve_styleC(m_str7,m_ins2,m_ins3,m_ins4) ;

	m_aggr6 = new SXFD_AggrC() ;
	m_aggr6->AddElem( m_inst[6] ) ;
	m_inst[7] = new SXFE_presentation_style_assignmentC(m_aggr6) ;
	m_assign_ID = m_inst[7]->GetInsID();

	m_str8 = new SXFD_StrC(" ");
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);

	if (m_DimFlag)
		m_slist->AddTail(DEF_DIMENSION_CURVE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr7 = new SXFD_AggrC() ;
	m_aggr7->AddElem( m_inst[7] ) ;
	m_inst[8] = new SXFE_styled_itemC(m_str8,m_aggr7,m_inst[5],m_slist) ;
	m_ID = m_inst[8]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

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
		作成		2000.04.15	宮園(FQS)	なし。
**/
BOOL SXFLineMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[8]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
int SXFLineMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLineMappingC.cpp					作成日：2000.04.15

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetAssignID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.15	宮園(FQS)	なし。
**/
int SXFLineMappingC::GetAssignID()
{
	return m_assign_ID;
}
