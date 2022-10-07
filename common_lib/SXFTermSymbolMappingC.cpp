/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．クラス概要
	矢印のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。
	更新			2002.02.20			K.Naono				改修対応

**/
#include "stdafx.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_targetC.h"
#include "SXFE_pre_defined_terminator_symbolC.h"
#include "SXFE_defined_symbolC.h"
#include "SXFE_symbol_colourC.h"
#include "SXFE_symbol_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_terminator_symbolC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_EnumC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTermSymbolMappingC::SXFTermSymbolMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFTermSymbolMappingC::SXFTermSymbolMappingC()
:	m_TableManager(NULL),
	m_slist(NULL),
	m_ins1(NULL),
	m_ins2(NULL),
	m_ins3(NULL),
	m_aggr1(NULL),
	m_aggr2(NULL),
	m_aggr3(NULL),
	m_str1(NULL),
	m_str2(NULL),
	m_str3(NULL),
	m_str4(NULL),
	m_str5(NULL),
	m_str6(NULL),
	m_str7(NULL),
	m_str8(NULL),
	m_enum1(NULL),
	m_real1(NULL),
	m_real2(NULL),
	m_real3(NULL),
	m_real4(NULL),
	m_real5(NULL),
	m_real6(NULL)
{
	m_DimFlag = -1;
	m_Flag = -1;
	m_assignID = -1;
	m_ID = -1;
	for(int i=0; i<10; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTermSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_Flag,int IN_DimFlag)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager
			int 				IN_Flag
			int 				IN_DimFlag				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFTermSymbolMappingC::SXFTermSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_Flag,int IN_DimFlag)
:	m_slist(NULL),
	m_ins1(NULL),
	m_ins2(NULL),
	m_ins3(NULL),
	m_aggr1(NULL),
	m_aggr2(NULL),
	m_aggr3(NULL),
	m_str1(NULL),
	m_str2(NULL),
	m_str3(NULL),
	m_str4(NULL),
	m_str5(NULL),
	m_str6(NULL),
	m_str7(NULL),
	m_str8(NULL),
	m_enum1(NULL),
	m_real1(NULL),
	m_real2(NULL),
	m_real3(NULL),
	m_real4(NULL),
	m_real5(NULL),
	m_real6(NULL)
{
	m_TableManager = IN_TableManager;
	m_Flag = IN_Flag;//何番目の矢印か？
	m_DimFlag = IN_DimFlag;//1:Dim 0:Label
	m_assignID = -1;
	m_ID = -1;
	for(int i=0; i<10; ++i)
		m_inst[i] = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFTermSymbolMappingC::~SXFTermSymbolMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFTermSymbolMappingC::~SXFTermSymbolMappingC()
{

	if (m_inst[9] != NULL)
		delete m_inst[9];

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	矢印のMapping

	２．インターフェース
	BOOL MappingStruct(TermSymbol_Struct IN_Struct)
	引数:	型					引数名				内容
			TermSymbol_Struct	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
BOOL SXFTermSymbolMappingC::MappingStructDim(TermSymbol_Struct IN_Struct)
{
	m_str1 = new SXFD_StrC(" ");
	m_real1 =  new SXFD_AngleC(IN_Struct.direction_x);
	m_real2 =  new SXFD_AngleC(IN_Struct.direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_directionC(m_str1,m_aggr1);

	m_str2 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.x);
	m_real4 = new SXFD_RealC(IN_Struct.y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real3) ;
	m_aggr2->AddElem(m_real4) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2);

	m_str3 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str3,m_inst[1],m_inst[0]);

	m_str4 = new SXFD_StrC(" ");
//	MOD(S)	改修対応	K.Naono	02.02.20
/*
	m_real5 = new SXFD_RealC(IN_Struct.scale);
	m_real6 = new SXFD_RealC(IN_Struct.scale);
*/
	m_real5 = new SXFD_AngleC(IN_Struct.scale);
	m_real6 = new SXFD_AngleC(IN_Struct.scale);
//	MOD(E)	改修対応	K.Naono	02.02.20
	m_inst[3] = new SXFE_symbol_targetC(m_str4,m_inst[2],m_real5,m_real6);

	char arrow_name[20];
	switch(IN_Struct.code){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"blanked arrow");
		strcpy_s(arrow_name,_countof(arrow_name),"blanked arrow");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"blanked box");
		strcpy_s(arrow_name,_countof(arrow_name),"blanked box");
		break;
	case 3:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"blanked dot");
		strcpy_s(arrow_name,_countof(arrow_name),"blanked dot");
		break;
	case 4:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"dimension origin");
		strcpy_s(arrow_name,_countof(arrow_name),"dimension origin");
		break;
	case 5:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"filled box");
		strcpy_s(arrow_name,_countof(arrow_name),"filled box");
		break;
	case 6:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"filled arrow");
		strcpy_s(arrow_name,_countof(arrow_name),"filled arrow");
		break;
	case 7:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"filled dot");
		strcpy_s(arrow_name,_countof(arrow_name),"filled dot");
		break;
	case 8:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"integral symbol");
		strcpy_s(arrow_name,_countof(arrow_name),"integral symbol");
		break;
	case 9:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"open arrow");
		strcpy_s(arrow_name,_countof(arrow_name),"open arrow");
		break;
	case 10:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"slash");
		strcpy_s(arrow_name,_countof(arrow_name),"slash");
		break;
	case 11:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(arrow_name,"unfilled arrow");
		strcpy_s(arrow_name,_countof(arrow_name),"unfilled arrow");
		break;
	default:
		return FALSE;
		break;
	}

	char tmp_char[64];
	switch(m_Flag){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_arw_1");
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_arw_1");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char,"$$SXF_arw_2");
		strcpy_s(tmp_char,_countof(tmp_char),"$$SXF_arw_2");
		break;
	default:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(tmp_char," ");
		strcpy_s(tmp_char,_countof(tmp_char)," ");
		break;
	}

	if (IN_Struct.flag == 1){
		m_str5 = new SXFD_StrC(arrow_name);
		m_inst[4] = new SXFE_pre_defined_terminator_symbolC(m_str5);

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

		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem(m_inst[7]) ;
		m_inst[8] =new SXFE_presentation_style_assignmentC(m_aggr2);
		m_assignID = m_inst[8]->GetInsID();

		m_enum1 = new SXFD_EnumC("ORIGIN");
		m_str8 = new SXFD_StrC(tmp_char);
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem(m_inst[8]) ;
		m_ins2 = new SXFD_InstC(IN_Struct.target_ID);
		//dimension
		if (m_DimFlag){
			m_inst[9] = new SXFE_terminator_symbolC(
				m_enum1,
				m_str8,
				m_aggr3,
				m_inst[5],
				m_ins2);
		}
		//label,ballon
		else{
			delete m_enum1;	// Leak
			m_inst[9] = new SXFE_terminator_symbolC(
				m_str8,
				m_aggr3,
				m_inst[5],
				m_ins2);
		}
		m_ID = m_inst[9]->GetInsID();
	}
	else{
		m_str5 = new SXFD_StrC(arrow_name);
		m_inst[4] = new SXFE_pre_defined_terminator_symbolC(m_str5);
		m_str6 = new SXFD_StrC(" ");
		m_inst[5] = new SXFE_defined_symbolC(m_str6,m_inst[4],m_inst[3]);
		m_inst[6] = NULL;
		m_inst[7] = NULL;
		m_inst[8] = NULL;
		m_enum1 = new SXFD_EnumC("TARGET");
		m_str7 = new SXFD_StrC(tmp_char);
		m_ins2 = new SXFD_InstC(m_assignID);
		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem(m_ins2) ;
		m_ins3 = new SXFD_InstC(IN_Struct.target_ID);
		m_inst[9] = new SXFE_terminator_symbolC(
			m_enum1,
			m_str7,
			m_aggr2,
			m_inst[5],
			m_ins3);
		m_ID = m_inst[9]->GetInsID();
	}

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

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
	作成			2001.06.17			佐々木(FQS)			なし。

**/
BOOL SXFTermSymbolMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[9]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	void GetTermID(int &OUT_assignID)
	引数:	型					引数名				内容
			int &				OUT_assignID		インスタンスID
	
	 復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
void SXFTermSymbolMappingC::GetTermID(int &OUT_assignID)
{
	OUT_assignID = m_assignID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	インスタンスIDの設定

	２．インターフェース
	void SetTermID(int assignID)
	引数:	型					引数名				内容
			int					assignID			インスタンスID
	
	 復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
void SXFTermSymbolMappingC::SetTermID(int assignID)
{
	m_assignID = assignID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.cpp								作成日：2001.06.17

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
int SXFTermSymbolMappingC::GetID()
{
	return m_ID;
}
