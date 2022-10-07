/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．クラス概要
	点マーカのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。
	更新			2002.02.20			K.Naono				改修対応

**/
#include "stdafx.h"
#include <math.h>
#include "SXFPointMarkerMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_targetC.h"
#include "SXFE_pre_defined_point_marker_symbolC.h"
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
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPointMarkerMappingC::SXFPointMarkerMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
SXFPointMarkerMappingC::SXFPointMarkerMappingC()
{
	m_TableManager = NULL;
	m_ID = -1;
	for (int i = 0; i < 10; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_slist = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFPointMarkerMappingC(SXFTableManagerC* IN_TableManager)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ			

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
SXFPointMarkerMappingC::SXFPointMarkerMappingC(SXFTableManagerC* IN_TableManager)
{
	m_TableManager = IN_TableManager;
	m_ID = -1;
	for (int i = 0; i < 10; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_slist = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFPointMarkerMappingC::~SXFPointMarkerMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
SXFPointMarkerMappingC::~SXFPointMarkerMappingC()
{
	if (m_inst[9] != NULL)
		delete m_inst[9];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	点マーカのMapping

	２．インターフェース
	BOOL MappingStruct(Point_Marker_Struct IN_Struct)
	引数:	型					引数名				内容
			Point_Marker_Struct	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
BOOL SXFPointMarkerMappingC::MappingStruct(Point_Marker_Struct IN_Struct)
{
	double	m_direction_x = cos(acos(-1.)*IN_Struct.rotate_angle/180.0);
	double	m_direction_y = sin(acos(-1.)*IN_Struct.rotate_angle/180.0);
	m_str1 = new SXFD_StrC(" ");
	m_real1 = new SXFD_AngleC(m_direction_x);
	m_real2 = new SXFD_AngleC(m_direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_directionC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.start_x);
	m_real2 = new SXFD_RealC(IN_Struct.start_y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem( m_real1) ;
	m_aggr2->AddElem( m_real2 ) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;

	m_str3 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str3, m_inst[1], m_inst[0]);

	m_str4 = new SXFD_StrC(" ");
//	MOD(S)	改修対応	K.Naono	02.02.20
/*
	m_real3 = new SXFD_RealC(IN_Struct.scale);
	m_real4 = new SXFD_RealC(IN_Struct.scale);
*/
	m_real3 = new SXFD_AngleC(IN_Struct.scale) ;
	m_real4 = new SXFD_AngleC(IN_Struct.scale) ;
//	MOD(E)	改修対応	K.Naono	02.02.20
	m_inst[3] = new SXFE_symbol_targetC(m_str4,m_inst[2],m_real3,m_real4);

	char temp_char[16];
	switch(IN_Struct.marker_code){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"asterisk");
		strcpy_s(temp_char,_countof(temp_char),"asterisk");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"circle");
		strcpy_s(temp_char,_countof(temp_char),"circle");
		break;
	case 3:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"dot");
		strcpy_s(temp_char,_countof(temp_char),"dot");
		break;
	case 4:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"plus");
		strcpy_s(temp_char,_countof(temp_char),"plus");
		break;
	case 5:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"square");
		strcpy_s(temp_char,_countof(temp_char),"square");
		break;
	case 6:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"triangle");
		strcpy_s(temp_char,_countof(temp_char),"triangle");
		break;
	case 7:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char,"x");
		strcpy_s(temp_char,_countof(temp_char),"x");
		break;
	default:
		return FALSE;
		break;
	}
	m_str5 = new SXFD_StrC(temp_char);
	m_inst[4] = new SXFE_pre_defined_point_marker_symbolC(m_str5);

	m_str6 = new SXFD_StrC(" ");
	m_inst[5] = new SXFE_defined_symbolC(m_str6,m_inst[4],m_inst[3]);

	int table_type;
	if (IN_Struct.color < 17)
		table_type = 2;
	else
		table_type = 3;
	m_ins1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
	m_inst[6] = new SXFE_symbol_colourC(m_ins1);

	m_str7 = new SXFD_StrC(" ");
	m_inst[7] = new SXFE_symbol_styleC(m_str7,m_inst[6]);

	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_inst[7] ) ;
	m_inst[8] = new SXFE_presentation_style_assignmentC(m_aggr3) ;

	m_str8 = new SXFD_StrC(" ");
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_SYMBOL_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_inst[8] ) ;
	m_inst[9] = new SXFE_styled_itemC(m_str8,m_aggr4,m_inst[5],m_slist) ;

	m_ID = m_inst[9]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
int SXFPointMarkerMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPointMarkerMappingC.cpp								作成日：2001.05.27

	１．機能概要
	点マーカインスタンスのファイルへの出力

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス
	 復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.27			佐々木(FQS)			なし。

**/
BOOL SXFPointMarkerMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[9]->WriteP21(IN_File);
	return TRUE;

}
