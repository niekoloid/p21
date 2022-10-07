/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．クラス概要
	半径寸法のMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include <math.h>
#include "SXFRadiusDimMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFLineMappingC.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_BoolC.h"
#include "SXFE_structured_dimension_calloutC.h"
#include "SXFE_radius_dimensionC.h"
#include "SXFE_dimension_callout_relationshipC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFRadiusDimMappingC::SXFRadiusDimMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFRadiusDimMappingC::SXFRadiusDimMappingC()
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_LineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_text_inst = NULL;
	m_term_inst = NULL;
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
	m_bool1 = NULL;
	m_type1 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFRadiusDimMappingC(SXFTableManagerC* IN_TableManager)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFRadiusDimMappingC::SXFRadiusDimMappingC(SXFTableManagerC* IN_TableManager)
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_TableManager = IN_TableManager;
	m_LineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_text_inst = NULL;
	m_term_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 =NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_bool1 = NULL;
	m_type1 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFRadiusDimMappingC::~SXFRadiusDimMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
SXFRadiusDimMappingC::~SXFRadiusDimMappingC()
{
	if (m_bool1 != NULL)
		delete m_bool1;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_LineMapping != NULL)
		delete m_LineMapping;
	if (m_TermSymbolMapping != NULL)
		delete m_TermSymbolMapping;

/*	if (m_inst[2] != NULL)
		delete m_inst[2];
	if (m_inst[5] != NULL)
		delete m_inst[5];*/
	
	SXFInstanceC::InitDeleteMap();
	if(m_inst[2] != NULL) {
		SXFInstanceC::AddDeleted(m_inst[2]);
		delete	m_inst[2];
	}
	if(m_inst[4] != NULL)
		delete	m_inst[4];
	if(m_inst[5] != NULL)
		delete	m_inst[5];
	SXFInstanceC::EndDeleteMap();
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	半径寸法のMapping

	２．インターフェース
	BOOL MappingStruct(RadiusDim_Struct IN_Struct)
	引数:	型					引数名				内容
			RadiusDim_Struct	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
BOOL SXFRadiusDimMappingC::MappingStruct(RadiusDim_Struct IN_Struct,int IN_AssemType)
{
	Line_Struct Line_str;
	Line_str.layer = IN_Struct.layer;
	Line_str.color = IN_Struct.color;
	Line_str.type = IN_Struct.type;
	Line_str.line_width = IN_Struct.line_width;
	Line_str.start_x = IN_Struct.sun_x1;
	Line_str.start_y = IN_Struct.sun_y1;
	Line_str.end_x = IN_Struct.sun_x2;
	Line_str.end_y = IN_Struct.sun_y2;
	//寸法線のMapping
	m_LineMapping = new SXFLineMappingC(m_TableManager,1);
	m_LineMapping->MappingStruct(Line_str);
	//
	//寸法線のSTYLED_ITEM..のＩＤ
	//DRAUGHTING_CALLOUTに使用
	//またTEMINATOR_SYMBOLにも使用
	int LineID = m_LineMapping->GetID();
	m_ins_line = new SXFD_InstC(LineID);
	m_aggr1 = new SXFD_AggrC();
	m_aggr1->AddElem(m_ins_line);

	//文字のMapping
	Text_Struct TextString_str;
	TextString_str.layer = IN_Struct.layer;
	TextString_str.color = IN_Struct.color;
	TextString_str.font = IN_Struct.font;
	//寸法値有無フラグが0だった場合
	//文字列を" "とする。
	if (IN_Struct.flg == 0){
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,"");
		strcpy_s(TextString_str.str,_countof(TextString_str.str),"");
	}
	else{
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,IN_Struct.str);
		strcpy_s(TextString_str.str,_countof(TextString_str.str),IN_Struct.str);
	}
	TextString_str.text_x = IN_Struct.text_x;
	TextString_str.text_y = IN_Struct.text_y;
	TextString_str.height = IN_Struct.height;
	TextString_str.width = IN_Struct.width;
	TextString_str.spc   = IN_Struct.spc;
	TextString_str.angle = IN_Struct.angle;
	TextString_str.slant = IN_Struct.slant;
	TextString_str.b_pnt = IN_Struct.b_pnt;
	TextString_str.direct = IN_Struct.direct;
	m_TextStringMapping = new SXFTextStringMappingC(m_TableManager,1);
	m_TextStringMapping->MappingStruct(TextString_str);
	int Text_ID = m_TextStringMapping->GetID();
	m_text_inst = new SXFD_InstC(Text_ID);
	m_aggr1->AddElem(m_text_inst);

	//矢印のMapping
	TermSymbol_Struct TermSymbol_str;
	TermSymbol_str.color = IN_Struct.color;
	TermSymbol_str.code = IN_Struct.arr_code1;
	TermSymbol_str.flag = IN_Struct.arr_code2;
	TermSymbol_str.x = IN_Struct.arr_x;
	TermSymbol_str.y = IN_Struct.arr_y;
	TermSymbol_str.scale =IN_Struct.arr_r;
	TermSymbol_str.target_ID = LineID;//寸法線のSTYLED_ITEMのＩＤ
	//DIRECTIONの計算
	if (IN_Struct.arr_code2 != 0){
		if (!CalcArrowDir(IN_Struct,TermSymbol_str.direction_x,TermSymbol_str.direction_y))
			return FALSE;
	}

	//Mapping
	if (IN_Struct.arr_code2 != 0){
		TermSymbol_str.flag = 1;
		m_TermSymbolMapping = new SXFTermSymbolMappingC(m_TableManager,0,1);//矢印は1個だけ,Dimension
		m_TermSymbolMapping->MappingStructDim(TermSymbol_str);
		int termID= m_TermSymbolMapping->GetID();
		m_term_inst = new SXFD_InstC(termID);
		m_aggr1->AddElem(m_term_inst);
	}
	
	m_str1 = new SXFD_StrC(" ");
	m_ins_text = new SXFD_InstC(Text_ID);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_ins_text) ;
	m_inst[0] = new SXFE_structured_dimension_calloutC(m_str1,m_aggr2);
	
	m_str2 = new SXFD_StrC(" ");
	m_inst[1] = new SXFE_radius_dimensionC(m_str2,m_aggr1);
	
	m_str3 = new SXFD_StrC("primary");
	m_str4 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_dimension_callout_relationshipC
			(m_str3,m_str4,m_inst[1],m_inst[0]); 

	//アセンブリ要素（用紙、複合図形）からの参照するＩＤの設定
	//用紙の場合
	//DRAWING_SHEET_REVISION => STYLED_ITEM => STRUCTURED_DIMENSION_CALLOUT()
	//                       => STYLED_ITEM => RADIUS_DIMENSION()
	if (IN_AssemType == 1){
		m_bool1 = new SXFD_BoolC(DEF_NULL);
		m_type1 = new SXFD_TypeC(DEF_NULL_STYLE);
		m_type1->SetNext(m_bool1);
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem(m_type1);
		m_inst[3] = new SXFE_presentation_style_assignmentC(m_aggr3);
		
		m_str5 = new SXFD_StrC(" ");
		m_aggr4 = new SXFD_AggrC();

		m_aggr4->AddElem(m_inst[3]);
		m_inst[4] = new SXFE_styled_itemC(m_str5,m_aggr4,m_inst[0]);
		//アセンブリ要素が参照するIDとして、STYLED_ITEMのIDを登録
		m_ID1 = m_inst[4]->GetInsID();//アセンブリ要素がもつＩＤ
		m_str6 = new SXFD_StrC(" ");
		m_aggr5 = new SXFD_AggrC();
		m_aggr5->AddElem(m_inst[3]);
		m_inst[5] = new SXFE_styled_itemC(m_str6,m_aggr5,m_inst[1]);
		//アセンブリ要素が参照するIDとして、STYLED_ITEMのIDを登録
		m_ID2 =m_inst[5]->GetInsID();//アセンブリ要素がもつＩＤ
	}
	//
	//複合図形の場合
	//DRAUGHTING_SUBFIGURE_REPRESENTATION => STRUCTURED_DIMENSION_CALLOUT()
	//                                    => RADIUS_DIMENSION()
	else{
		//アセンブリ要素が参照するIDとして、STRUCTURED_DIMENSION_CALLOUTのIDを登録
		m_ID1 = m_inst[0]->GetInsID();//アセンブリ要素がもつＩＤ
		//アセンブリ要素が参照するIDとして、RADIUS_DIMENSIONのIDを登録
		m_ID2 = m_inst[1]->GetInsID();//アセンブリ要素がもつＩＤ;
	}

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	半径寸法インスタンスのファイルへの出力

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
BOOL SXFRadiusDimMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	if (m_LineMapping != NULL)
		m_LineMapping->WriteAP202(IN_File);
	if (m_TextStringMapping != NULL)
		m_TextStringMapping->WriteAP202(IN_File);
	if (m_TermSymbolMapping != NULL)
		m_TermSymbolMapping->WriteAP202(IN_File);
	if (m_inst[2] != NULL)
		m_inst[2]->WriteP21(IN_File);
	if (m_inst[4] != NULL)
		m_inst[4]->WriteP21(IN_File);
	if (m_inst[5] != NULL)
		m_inst[5]->WriteP21(IN_File);
	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	インスタンスIDの返却

	２．インターフェース
	void GetID(int &OUT_ID1,int &OUT_ID2)
	引数:	型					引数名				内容
			int &				OUT_ID1				インスタンスID
			int &				OUT_ID2				インスタンスID
	
	 復帰値	なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
void SXFRadiusDimMappingC::GetID(int &OUT_ID1,int &OUT_ID2)
{
	OUT_ID1 = m_ID1;
	OUT_ID2 = m_ID2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDimMappingC.cpp								作成日：2001.06.17

	１．機能概要
	半径寸法Mapping時に矢印のDIRECTIONの計算を行う。

	２．インターフェース
	int CalcArrowDir(RadiusDim_Struct IN_Struct, double &OUT_Arrow_x, double &OUT_Arrow_y)
	引数:	型					引数名			内容
			LinearDim_Struct	IN_Struct		構造体
			double&				OUT_Arrow_x		矢印のDIRECTION X
			double&				OUT_Arrow_y		矢印のDIRECTION Y

	復帰値	正常時：1
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.17			佐々木(FQS)			なし。

**/
int SXFRadiusDimMappingC::CalcArrowDir(RadiusDim_Struct IN_Struct, double &OUT_Arrow_x, double &OUT_Arrow_y)
{
	//寸法線の方向ベクトルを計算する
	double Dim_x = IN_Struct.sun_x2 - IN_Struct.sun_x1;
	double Dim_y = IN_Struct.sun_y2 - IN_Struct.sun_y1;
	//矢印の方向ベクトルを設定する
	//矢印の内外コードが２（内向き）のとき、寸法線の方向ベクトルと同方向に設定する
	if(IN_Struct.arr_code2 == 2){
		OUT_Arrow_x = -Dim_x;
		OUT_Arrow_y = -Dim_y;
	}
	//矢印の内外コードが１（外向き）のとき、寸法線の方向ベクトルと反対方向に設定する
	else if(IN_Struct.arr_code2 == 1){
		OUT_Arrow_x = Dim_x;
		OUT_Arrow_y = Dim_y;
	}
	else{
		//矢印内外コードが0から2以外のとき
		SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr_code2,DEF_ANGULAR_DIMENSION);
		return SXFARRCODE;
	}
	return 1;
}
