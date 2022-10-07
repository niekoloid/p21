/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．クラス概要
	ハッチング(パターン)のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include <math.h>
#include "SXFFillTilesMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFExSymbolMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SXFD_RealC.h"
#include "SXFE_annotation_fill_areaC.h"
#include "SXFE_fill_area_style_tile_symbol_with_styleC.h"
#include "SXFE_directionC.h"
#include "SXFE_vectorC.h"
#include "SXFE_two_direction_repeat_factorC.h"
#include "SXFE_fill_area_style_tileC.h"
#include "SXFE_fill_area_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFFillTilesMappingC::SXFFillTilesMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFFillTilesMappingC::SXFFillTilesMappingC()
{
	m_ExSymbolMapping= NULL;
	for (int i = 0; i < 11; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_inst4 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_aggr6 = NULL;
	m_aggr7 = NULL;
	m_aggr8 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_str10 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_real7 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFFillTilesMappingC(SXFTableManagerC* IN_TableManager,CUIntArray* IN_AssemblyTable)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			CUIntArray* 		IN_AssemblyTable	ｱｾﾝﾌﾞﾘﾃｰﾌﾞﾙ			

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFFillTilesMappingC::SXFFillTilesMappingC(SXFTableManagerC* IN_TableManager,CUIntArray* IN_AssemblyTable)
{
	m_ExSymbolMapping= NULL;
	m_TableManager = IN_TableManager;
	m_AssemblyTable = IN_AssemblyTable;
	for (int i = 0; i < 11; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_inst4 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_aggr6 = NULL;
	m_aggr7 = NULL;
	m_aggr8 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_str10 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_real7 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFFillTilesMappingC::~SXFFillTilesMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFFillTilesMappingC::~SXFFillTilesMappingC()
{
	if (m_ExSymbolMapping!= NULL)
		delete m_ExSymbolMapping;
	if (m_inst4 != NULL)
		delete m_inst4;
	if (m_str9 != NULL)
		delete m_str9;
	if (m_inst[10] != NULL)
		delete m_inst[10];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．機能概要
	ハッチング(パターン)のMapping

	２．インターフェース
	BOOL MappingStruct(Fill_area_style_tiles_Struct* IN_Struct)
	引数:	型								引数名				内容
			Fill_area_style_tiles_Struct*	IN_Struct			構造体

	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
BOOL SXFFillTilesMappingC::MappingStruct(Fill_area_style_tiles_Struct *IN_Struct)
{
	/////////////////
	///既定義シンボル
	/////////////////
	Externally_Defined_Symbol_Struct ExSymbol_Str;
	ExSymbol_Str.layer = IN_Struct->layer;
	ExSymbol_Str.color_flag = 1;//ハッチング(パターン)の時は常に１（表示）
	ExSymbol_Str.color = IN_Struct->hatch_color;
	//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(ExSymbol_Str.name,IN_Struct->name);
	strcpy_s(ExSymbol_Str.name,_countof(ExSymbol_Str.name),IN_Struct->name);
	ExSymbol_Str.start_x = IN_Struct->hatch_pattern_x;
	ExSymbol_Str.start_y = IN_Struct->hatch_pattern_y;
	ExSymbol_Str.rotate_angle = IN_Struct->hatch_pattern_angle;
	ExSymbol_Str.scale = IN_Struct->hatch_pattern_scale_x;
	
	m_ExSymbolMapping = new SXFExSymbolMappingC(m_TableManager,1);
	m_ExSymbolMapping->SetSymbolScale(IN_Struct->hatch_pattern_scale_y);
	m_ExSymbolMapping->MappingStruct(ExSymbol_Str);
	int ExSymbolID = m_ExSymbolMapping->GetID();

	int out_ID = 0;
	if(IN_Struct->out_id < 1 || IN_Struct->out_id > m_AssemblyTable->GetSize())
		return FALSE;
	else
		out_ID = m_AssemblyTable->GetAt(IN_Struct->out_id-1);

	///アセンブリテーブルより外形のコードからＩＤを取得
	m_inst1 = new SXFD_InstC(out_ID);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_inst1) ;
	
	for(int i = 0;i < IN_Struct->number; i++){
		int in_ID = 0;
		if(IN_Struct->in_id[i] < 1 || IN_Struct->in_id[i] > m_AssemblyTable->GetSize())
			return FALSE;
		else
			in_ID = m_AssemblyTable->GetAt(IN_Struct->in_id[i]-1);
			//アセンブリテーブルより中抜きのコードからＩＤを取得
			m_inst2 = new SXFD_InstC(in_ID);
			m_aggr1->AddElem(m_inst2) ;
	}
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_annotation_fill_areaC(m_str1,m_aggr1) ;
	
	m_str2 = new SXFD_StrC(" ");
	m_inst3 = new SXFD_InstC(ExSymbolID);
	m_inst[1] = new SXFE_fill_area_style_tile_symbol_with_styleC(m_str2,m_inst3);
	
	m_str3 = new SXFD_StrC(" ");
	m_real1 = new SXFD_AngleC(cos(IN_Struct->hatch_pattern_vector1_angle * acos(-1.) / 180));
	m_real2 = new SXFD_AngleC(sin(IN_Struct->hatch_pattern_vector1_angle * acos(-1.) / 180));
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real1);
	m_aggr2->AddElem(m_real2);
	m_inst[2] = new SXFE_directionC(m_str3,m_aggr2);
	
	m_str4 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct->hatch_pattern_vector1);
	m_inst[3] = new SXFE_vectorC(m_str4,m_inst[2],m_real3);
	
	m_str5 = new SXFD_StrC(" ");
	m_real4 = new SXFD_AngleC(cos(IN_Struct->hatch_pattern_vector2_angle * acos(-1.)/ 180));
	m_real5 = new SXFD_AngleC(sin(IN_Struct->hatch_pattern_vector2_angle * acos(-1.) / 180));
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem(m_real4);
	m_aggr3->AddElem(m_real5);
	m_inst[4] = new SXFE_directionC(m_str5,m_aggr3);

	m_str6 = new SXFD_StrC(" ");
	m_real6 = new SXFD_RealC(IN_Struct->hatch_pattern_vector2);
	m_inst[5] = new SXFE_vectorC(m_str6,m_inst[4],m_real6);

	m_str7 = new SXFD_StrC(" ");
	m_inst[6] = new SXFE_two_direction_repeat_factorC(m_str7,m_inst[5],m_inst[3]);

	m_aggr4= new SXFD_AggrC();
	m_aggr4->AddElem(m_inst[1]);
	m_real7 = new SXFD_RealC(1.0);
	m_str10 = new SXFD_StrC(" ");
	m_inst[7] = new SXFE_fill_area_style_tileC(m_str10,m_inst[6],m_aggr4,m_real7);

	m_str8 = new SXFD_StrC(" ");
	m_aggr5 = new SXFD_AggrC();
	m_aggr5->AddElem(m_inst[7]);
	m_inst[8] = new SXFE_fill_area_styleC(m_str8,m_aggr5);

	m_aggr6 = new SXFD_AggrC();
	m_aggr6->AddElem(m_inst[8]);
	m_inst[9] = new SXFE_presentation_style_assignmentC(m_aggr6);

	int CartesianID = m_ExSymbolMapping->GetCartesianID();
	//既定義シンボルのCARTESIAN_POINTのＩＤ
	m_inst4 = new SXFD_InstC(CartesianID);
	m_type2 = new SXFD_TypeC(DEF_ANNOTATION_FILL_AREA_OCCURRENCE);
	m_type2->SetNext(m_inst4);
	m_type3 = new SXFD_TypeC(DEF_ANNOTATION_OCCURRENCE);
	m_type4 = new SXFD_TypeC(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_type5 = new SXFD_TypeC(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_str9 = new SXFD_StrC(" ");
	m_type6 = new SXFD_TypeC(DEF_REPRESENTATION_ITEM);
	m_type6->SetNext(m_str9);

	m_aggr7 = new SXFD_AggrC();
	m_aggr7->AddElem(m_type2);
	m_aggr7->AddElem(m_type3);
	m_aggr7->AddElem(m_type4);
	m_aggr7->AddElem(m_type5);
	m_aggr7->AddElem(m_type6);

	m_aggr8 = new SXFD_AggrC() ;
	m_aggr8->AddElem( m_inst[9] ) ;
	m_inst[10] = new SXFE_styled_itemC(m_aggr7,m_aggr8,m_inst[0]) ;
	m_ID = m_inst[10]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

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
	作成			2001.06.19			佐々木(FQS)			なし。

**/
BOOL SXFFillTilesMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_ExSymbolMapping->WriteAP202(IN_File);
	m_inst[10]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTilesMappingC.cpp								作成日：2001.06.19

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
int SXFFillTilesMappingC::GetID()
{
	return m_ID;
}
