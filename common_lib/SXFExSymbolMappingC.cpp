/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．クラス概要
	既定義シンボルのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。
	更新			2002.02.20			K.Naono				改修対応

**/
#include "stdafx.h"
#include <math.h>
#include "SXFExSymbolMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_TypeC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_targetC.h"
#include "SXFE_external_sourceC.h"
#include "SXFE_externally_defined_symbolC.h"
#include "SXFE_defined_symbolC.h"
#include "SXFE_symbol_colourC.h"
#include "SXFE_symbol_styleC.h"
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
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFExSymbolMappingC::SXFExSymbolMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFExSymbolMappingC::SXFExSymbolMappingC()
{
	m_HatchFlag = -1;
	m_Scale = 0.0;
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
	for (int i = 0; i < 11; i++){
		m_inst[11] = NULL;
	}
	m_ins1 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_ID = -1;
	m_CartesianID = -1;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFExSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_HatchFlag)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			int 				IN_HatchFlag		ハッチフラグ				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFExSymbolMappingC::SXFExSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_HatchFlag)
{
	m_TableManager = IN_TableManager;
	m_HatchFlag = IN_HatchFlag;
	m_Scale = 0.0;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_str10 = NULL;
	for (int i = 0; i < 11; i++){
		m_inst[11] = NULL;
	}
	m_ins1 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_ID = -1;
	m_CartesianID = -1;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFExSymbolMappingC::~SXFExSymbolMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
SXFExSymbolMappingC::~SXFExSymbolMappingC()
{

	if (m_str5 != NULL)
		delete m_str5;
	if (m_str6 != NULL)
		delete m_str6;
	if (m_inst[10] != NULL)
		delete m_inst[10];

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	既定義シンボルのMapping

	２．インターフェース
	BOOL MappingStruct(Externally_Defined_Symbol_Struct IN_Struct)
	引数:	型									引数名				内容
			Externally_Defined_Symbol_Struct	IN_Struct			構造体

	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
BOOL SXFExSymbolMappingC::MappingStruct(Externally_Defined_Symbol_Struct IN_Struct)
{
	m_str1 = new SXFD_StrC(" ");
	double	m_direction_x = cos(acos(-1.)*IN_Struct.rotate_angle/180.0);
	double	m_direction_y = sin(acos(-1.)*IN_Struct.rotate_angle/180.0);
	m_real1 = new SXFD_AngleC(m_direction_x);
	m_real2 = new SXFD_AngleC(m_direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem( m_real1) ;
	m_aggr1->AddElem( m_real2) ;
	m_inst[0] = new SXFE_directionC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.start_x);
	m_real4 = new SXFD_RealC(IN_Struct.start_y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real3) ;
	m_aggr2->AddElem(m_real4) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;
	m_CartesianID = m_inst[1]->GetInsID();//ハッチング(パターン)で使用

	m_str3 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str3,m_inst[1],m_inst[0]) ;

	m_str4 = new SXFD_StrC(" ");
//	MOD(S)	改修対応	K.Naono	02.02.20
/*
	m_real5 = new SXFD_RealC(IN_Struct.scale);
	if (m_HatchFlag)
		m_real6 = new SXFD_RealC(m_Scale);
	else
		m_real6 = new SXFD_RealC(IN_Struct.scale);
*/
	m_real5 = new SXFD_AngleC(IN_Struct.scale);
	if (m_HatchFlag)
		m_real6 = new SXFD_AngleC(m_Scale);
	else
		m_real6 = new SXFD_AngleC(IN_Struct.scale);
//	MOD(E)	改修対応	K.Naono	02.02.20
	m_inst[3] = new SXFE_symbol_targetC(m_str4,m_inst[2],m_real5,m_real6);

	m_str5 = new SXFD_StrC("scadec");
	m_type1 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type1->SetNext(m_str5);
	m_inst[4] = new SXFE_external_sourceC(m_type1) ;

	m_str6 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct.name);
	m_type2 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type2->SetNext(m_str6);
	m_inst[5] = new SXFE_externally_defined_symbolC(m_type2,m_inst[4]);

	m_str7 = new SXFD_StrC(" ");
	m_inst[6] = new SXFE_defined_symbolC(m_str7,m_inst[5],m_inst[3]) ;

	if (IN_Struct.color_flag == 0){
		m_inst[7] = NULL;
		m_str8 = new SXFD_StrC(" ");
		m_str9 = new SXFD_StrC(DEF_DOLLAR);
		m_inst[8] = new SXFE_symbol_styleC(m_str8,m_str9) ;
	}
	else if (IN_Struct.color_flag == 1){
		int table_type;
		if (IN_Struct.color < 17)
			table_type = 2;
		else
			table_type = 3;
		m_ins1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
		m_inst[7] = new SXFE_symbol_colourC(m_ins1);
		m_str8 = new SXFD_StrC(" ");
		m_inst[8] = new SXFE_symbol_styleC(m_str8,m_inst[7]) ;
	}

	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_inst[8] ) ;
	m_inst[9] = new SXFE_presentation_style_assignmentC(m_aggr3) ;

	m_str10 = new SXFD_StrC(" ");
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_SYMBOL_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_inst[9] ) ;
	m_inst[10] = new SXFE_styled_itemC(m_str10,m_aggr4,m_inst[6],m_slist) ;
	m_ID = m_inst[10]->GetInsID();
	if (!m_HatchFlag)
		m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);//ハッチングのときはレイヤには登録しない
	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

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
BOOL SXFExSymbolMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[10]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

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
int SXFExSymbolMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	ハッチング時のスケール設定

	２．インターフェース
	SetSymbolScale(double IN_Scale)
	引数:	型					引数名				内容
			double				IN_Scale
	
	 復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
void SXFExSymbolMappingC::SetSymbolScale(double IN_Scale)
{
	m_Scale = IN_Scale;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbolMappingC.cpp								作成日：2001.06.19

	１．機能概要
	CartesianIDを返却する
	２．インターフェース
	int GetCartesianID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	CARTESIAN_POINTのID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.19			佐々木(FQS)			なし。

**/
int SXFExSymbolMappingC::GetCartesianID()
{
	return m_CartesianID;
}
