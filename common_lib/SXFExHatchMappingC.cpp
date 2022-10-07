/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatchMappingC.cpp								作成日：2001.06.17

	１．クラス概要
	ハッチング(既定義）のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。
	更新			2001.09.18			K.Naono				ハッチング障害対応

**/
#include "stdafx.h"
#include "SXFExHatchMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SXFE_annotation_fill_areaC.h"
#include "SXFE_external_sourceC.h"
#include "SXFE_externally_defined_hatch_styleC.h"
#include "SXFE_fill_area_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
//	ADD(S)	ハッチング障害対応	K.Naono		01.09.18
#include "SXFD_RealC.h"
#include "SXFE_cartesian_pointC.h"
//	ADD(E)	ハッチング障害対応	K.Naono		01.09.18
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	void	SXFExHatchMappingC::SXFExHatchMappingC()		
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
		更新		2001.09.18	K.Naono		ハッチング障害対応
**/
SXFExHatchMappingC::SXFExHatchMappingC()
{
	for (int i = 0; i < 6; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
	m_type7 = NULL;
	m_ID = -1;

//	ADD(S)	ハッチング障害対応	K.Naono		01.09.18
	m_inst_point = NULL;
//	ADD(E)	ハッチング障害対応	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	void	SXFExHatchMappingC(SXFTableManagerC* IN_TableManager,
							   CUIntArray* IN_AssemblyTable,
							   CUIntArray* IN_PointTable)		
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			CUIntArray* 		IN_AssemblyTable	ｱｾﾝﾌﾞﾘﾃｰﾌﾞﾙ
			CUIntArray* 		IN_PointTable		ﾎﾟｲﾝﾄﾃｰﾌﾞﾙ		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
		更新		2001.09.18	K.Naono		ハッチング障害対応
**/
SXFExHatchMappingC::SXFExHatchMappingC(
				SXFTableManagerC*	IN_TableManager,
				CUIntArray*			IN_AssemblyTable,
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//				CUIntArray*			IN_PointTable)
				CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable)
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
{
	m_TableManager = IN_TableManager;
	m_AssemblyTable = IN_AssemblyTable;
	m_PointTable = IN_PointTable;
	for (int i = 0; i < 6; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
	m_type7 = NULL;
	m_ID = -1;

//	ADD(S)	ハッチング障害対応	K.Naono		01.09.18
	m_inst_point = NULL;
//	ADD(E)	ハッチング障害対応	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
	デストラクタ
		
	２．インターフェイス
	void	SXFExHatchMappingC::~SXFExHatchMappingC()		
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
		更新		2001.09.18	K.Naono		ハッチング障害対応
**/
SXFExHatchMappingC::~SXFExHatchMappingC()
{
	if (m_str2 != NULL)
		delete m_str2;
	if (m_str3 != NULL)
		delete m_str3;
	if (m_str6 != NULL)
		delete m_str6;
	if (m_inst3 != NULL)
		delete m_inst3;
	if (m_inst[5] != NULL)
		delete m_inst[5];

//	ADD(S)	ハッチング障害対応	K.Naono		01.09.18
	if (m_inst_point)
		delete m_inst_point;
//	ADD(E)	ハッチング障害対応	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
	ハッチング(既定義）のMapping

	２．インターフェース
	BOOL MappingStruct(Externally_Defined_Hatch_Struct IN_Struct)
	引数:	型									引数名				内容
			Externally_Defined_Hatch_Struct		IN_Struct			構造体

	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
		更新		2001.09.18	K.Naono		ハッチング障害対応
**/
BOOL SXFExHatchMappingC::MappingStruct(Externally_Defined_Hatch_Struct* IN_Struct)
{
	int out_ID = 0;
	if(IN_Struct->out_id < 1 || IN_Struct->out_id > m_AssemblyTable->GetSize())
		return FALSE;
	else
		out_ID = m_AssemblyTable->GetAt(IN_Struct->out_id-1);

	//アセンブリテーブルより外形のコードからＩＤを取得
	m_inst1 = new SXFD_InstC(out_ID);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_inst1) ;
	
	for(int i = 0;i < IN_Struct->number; i++){
		int in_ID = 0;
		if(IN_Struct->in_id[i] < 1 || IN_Struct->in_id[i] > m_AssemblyTable->GetSize())
			return FALSE;
		else
			in_ID = m_AssemblyTable->GetAt(IN_Struct->in_id[i]-1);
		m_inst2 = new SXFD_InstC(in_ID);/////////アセンブリテーブルより中抜きのコードからＩＤを取得
		m_aggr1->AddElem(m_inst2) ;
	}
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_annotation_fill_areaC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC("scadec");
	m_type1 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type1->SetNext(m_str2);
	m_inst[1] = new SXFE_external_sourceC(m_type1) ;

	m_str3 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_str4 = new SXFD_StrC(" ");
	m_type2 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type2->SetNext(m_str3);
	m_inst[2] = new SXFE_externally_defined_hatch_styleC(m_type2,m_inst[1],m_str4) ;

	m_str5 = new SXFD_StrC(" ");
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_inst[2]);
	m_inst[3] = new SXFE_fill_area_styleC(m_str5,m_aggr2);

	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem(m_inst[3]);
	m_inst[4] = new SXFE_presentation_style_assignmentC(m_aggr3);

	m_type3 = new SXFD_TypeC(DEF_ANNOTATION_FILL_AREA_OCCURRENCE);
	int pointID = 0;
	if(IN_Struct->out_id < 1 || IN_Struct->out_id > m_PointTable->GetSize())
		return FALSE;
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
/*
	else
		pointID = m_PointTable->GetAt(IN_Struct->out_id-1);
*/
	else {
		SXF_POINT	point = m_PointTable->GetAt(IN_Struct->out_id-1);
		SXFD_AggrC*	aggr = new SXFD_AggrC() ;
		aggr->AddElem(new SXFD_RealC(point.x)) ;
		aggr->AddElem(new SXFD_RealC(point.y)) ;
		m_inst_point = new SXFE_cartesian_pointC(new SXFD_StrC(" "), aggr);
		pointID = m_inst_point->GetInsID();
	}
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
	m_inst3 = new SXFD_InstC(pointID);//CARTESIAN_POINTのＩＤ
	m_type3->SetNext(m_inst3);
	m_type4 = new SXFD_TypeC(DEF_ANNOTATION_OCCURRENCE);
	m_type5 = new SXFD_TypeC(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_type6 = new SXFD_TypeC(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_str6 = new SXFD_StrC(" ");
	m_type7 = new SXFD_TypeC(DEF_REPRESENTATION_ITEM);
	m_type7->SetNext(m_str6);

	m_aggr4 = new SXFD_AggrC();
	m_aggr4->AddElem(m_type3);
	m_aggr4->AddElem(m_type4);
	m_aggr4->AddElem(m_type5);
	m_aggr4->AddElem(m_type6);
	m_aggr4->AddElem(m_type7);

	m_aggr5 = new SXFD_AggrC() ;
	m_aggr5->AddElem( m_inst[4] ) ;
	m_inst[5] = new SXFE_styled_itemC(m_aggr4,m_aggr5,m_inst[0]) ;

	m_ID = m_inst[5]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
	インスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
		更新		2001.09.18	K.Naono		ハッチング障害対応
**/
BOOL SXFExHatchMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
//	ADD(S)	ハッチング障害対応	K.Naono		01.09.18
	if( m_inst_point )
		m_inst_point->WriteP21(IN_File);
//	ADD(E)	ハッチング障害対応	K.Naono		01.09.18

	m_inst[5]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						作成日：2001.06.18

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.18	佐々木(FQS)	なし。
**/
int SXFExHatchMappingC::GetID()
{
	return m_ID;
}
