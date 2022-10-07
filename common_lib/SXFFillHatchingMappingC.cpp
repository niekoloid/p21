/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．クラス概要
	ハッチング(ユーザ定義）のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include <math.h>
#include "SXFFillHatchingMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SXFD_RealC.h"
#include "SXFE_annotation_fill_areaC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_directionC.h"
#include "SXFE_vectorC.h"
#include "SXFE_one_direction_repeat_factorC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_fill_area_style_hatchingC.h"
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
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFFillHatchingMappingC::SXFFillHatchingMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
SXFFillHatchingMappingC::SXFFillHatchingMappingC()
{
	for (int i = 0; i < 28; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_inst4 = NULL;
	m_inst5 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_aggr6 = NULL;
	m_aggr7 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_ID = -1;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFFillHatchingMappingC(SXFTableManagerC* IN_TableManager,
									CUIntArray* IN_AssemblyTable)
	引数:	型						引数名				内容
			SXFTableManagerC* 		IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			CUIntArray* 			IN_AssemblyTable	ｱｾﾝﾌﾞﾘﾃｰﾌﾞﾙ				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
SXFFillHatchingMappingC::SXFFillHatchingMappingC(SXFTableManagerC* IN_TableManager,	CUIntArray* IN_AssemblyTable)
{
	m_TableManager = IN_TableManager;
	m_AssemblyTable = IN_AssemblyTable;
	for (int i = 0; i < 28; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
	m_inst4 = NULL;
	m_inst5 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_aggr6 = NULL;
	m_aggr7 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_ID = -1;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFFillHatchingMappingC::~SXFFillHatchingMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
SXFFillHatchingMappingC::~SXFFillHatchingMappingC()
{
	if (m_inst5 != NULL)
		delete m_inst5;
	if (m_str9 != NULL)
		delete m_str9;
	if (m_inst[27] != NULL)
		delete m_inst[27];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．機能概要
	ハッチング(ユーザ定義)のMapping

	２．インターフェース
	BOOL MappingStruct(Fill_area_style_hatching_Struct* IN_Struct)
	引数:	型									引数名				内容
			Fill_area_style_hatching_Struct*	IN_Struct			構造体

	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
BOOL SXFFillHatchingMappingC::MappingStruct(Fill_area_style_hatching_Struct* IN_Struct)
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
		//アセンブリテーブルより中抜きのコードからＩＤを取得
		m_inst2 = new SXFD_InstC(in_ID);
		m_aggr1->AddElem(m_inst2) ;
	}
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_annotation_fill_areaC(m_str1,m_aggr1) ;
	
	for (i = 0; i < IN_Struct->hatch_number; i++){
		m_str2 = new SXFD_StrC(" ");
		m_real1 = new SXFD_RealC(IN_Struct->hatch_start_x[i]);
		m_real2 = new SXFD_RealC(IN_Struct->hatch_start_y[i]);
		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem(m_real1);
		m_aggr2->AddElem(m_real2);
		m_inst[1+i*6] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;
		
		m_str3 = new SXFD_StrC(" ");
		m_real3 = new SXFD_AngleC(-sin(IN_Struct->hatch_angle[i]*acos(-1.)/180)) ;
		m_real4 = new SXFD_AngleC(cos(IN_Struct->hatch_angle[i]*acos(-1.)/180));
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem(m_real3) ;
		m_aggr3->AddElem(m_real4) ;
		m_inst[2+i*6] = new SXFE_directionC(m_str3,m_aggr3) ;
		
		m_str4 = new SXFD_StrC(" ");
		m_real5 = new SXFD_RealC(IN_Struct->hatch_spacing[i]);
		m_inst[3+i*6] = new SXFE_vectorC(m_str4,m_inst[2+i*6],m_real5);
		
		m_str5 = new SXFD_StrC(" ");
		m_inst[4+i*6] = new SXFE_one_direction_repeat_factorC(m_str5,m_inst[3+i*6]);
		
		m_str6 = new SXFD_StrC(" ");
		int table_type;
		if (IN_Struct->hatch_type[i] < 17)
			table_type = 4;
		else
			table_type = 5;
		m_inst1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->hatch_type[i]));
		m_inst2 = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct->hatch_line_width[i]));
		if (IN_Struct->hatch_color[i] < 17)
			table_type = 2;
		else
			table_type = 3;
		m_inst3 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct->hatch_color[i]));
		m_inst[5+i*6] = new SXFE_curve_styleC(m_str6,m_inst1,m_inst2,m_inst3);
			
		m_str7 = new SXFD_StrC(" ");
		m_real6 = new SXFD_AngleC(IN_Struct->hatch_angle[i]* acos(-1.)/180);
		m_inst4 = new SXFD_InstC(m_inst[1+i*6]->GetInsID());
		m_inst[6+i*6] = new SXFE_fill_area_style_hatchingC(m_str7,m_inst[5+i*6],m_inst[4+i*6],m_inst4,m_inst[1+i*6],m_real6);
	}
	m_aggr4 = new SXFD_AggrC();
	for (int j = i-1 ; j >= 0; j--){
		m_aggr4->AddElem(m_inst[6+j*6]);
	}
	
	m_str8 = new SXFD_StrC(" ");
	m_inst[25] = new SXFE_fill_area_styleC(m_str8,m_aggr4);
	
	m_aggr5 = new SXFD_AggrC();
	m_aggr5->AddElem(m_inst[25]);
	m_inst[26] = new SXFE_presentation_style_assignmentC(m_aggr5);
	
	m_type1 = new SXFD_TypeC(DEF_ANNOTATION_FILL_AREA_OCCURRENCE);
	m_inst5 = new SXFD_InstC(m_inst[1]->GetInsID() );
	m_type1->SetNext(m_inst5);
	m_type2 = new SXFD_TypeC(DEF_ANNOTATION_OCCURRENCE);
	m_type3 = new SXFD_TypeC(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_type4 = new SXFD_TypeC(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_str9 = new SXFD_StrC(" ");
	m_type5 = new SXFD_TypeC(DEF_REPRESENTATION_ITEM);
	m_type5->SetNext(m_str9);

	m_aggr6 = new SXFD_AggrC();
	m_aggr6->AddElem(m_type1);
	m_aggr6->AddElem(m_type2);
	m_aggr6->AddElem(m_type3);
	m_aggr6->AddElem(m_type4);
	m_aggr6->AddElem(m_type5);

	m_aggr7 = new SXFD_AggrC() ;
	m_aggr7->AddElem( m_inst[26] ) ;
	m_inst[27] = new SXFE_styled_itemC(m_aggr6,m_aggr7,m_inst[0]) ;

	m_ID = m_inst[27]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);
	
	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

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
	作成			2001.06.20			佐々木(FQS)			なし。

**/
BOOL SXFFillHatchingMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[27]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatchingMappingC.cpp								作成日：2001.06.20

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.20			佐々木(FQS)			なし。

**/
int SXFFillHatchingMappingC::GetID()
{
	return m_ID;
}
