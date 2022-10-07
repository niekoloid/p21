/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．クラス概要
	直線寸法のMapping
	
	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
#include "stdafx.h"
#include <math.h>
#include "SXFLinearDimMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFLineMappingC.h"
#include "SXFProjMappingC.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_BoolC.h"
#include "SXFD_TypeC.h"
#include "SXFE_structured_dimension_calloutC.h"
#include "SXFE_linear_dimensionC.h"
#include "SXFE_dimension_callout_relationshipC.h"
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
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	コンストラクタ
	
	２．インターフェース
	void	SXFLinearDimMappingC::SXFLinearDimMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
SXFLinearDimMappingC::SXFLinearDimMappingC()
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_TableManager = NULL;
	m_LineMapping = NULL;
	m_ProjMapping1 = NULL;
	m_ProjMapping2 = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping1 = NULL;
	m_TermSymbolMapping2 = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_proj1 = NULL;
	m_ins_proj2 = NULL;
	m_ins_text = NULL;
	m_term1_inst = NULL;
	m_term2_inst = NULL;
	m_text_inst = NULL;
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
	m_type1 = NULL;
	m_bool1 = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFLinearDimMappingC(SXFTableManagerC* IN_TableManager)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
SXFLinearDimMappingC::SXFLinearDimMappingC(SXFTableManagerC* IN_TableManager)
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_TableManager = IN_TableManager;
	m_LineMapping = NULL;
	m_ProjMapping1 = NULL;
	m_ProjMapping2 = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping1 = NULL;
	m_TermSymbolMapping2 = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_proj1 = NULL;
	m_ins_proj2 = NULL;
	m_ins_text = NULL;
	m_term1_inst = NULL;
	m_term2_inst = NULL;
	m_text_inst = NULL;
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
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	デストラクタ
	
	２．インターフェース
	void	SXFLinearDimMappingC::~SXFLinearDimMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
SXFLinearDimMappingC::~SXFLinearDimMappingC()
{
	if(m_bool1 != NULL)
		delete	m_bool1;
	if(m_LineMapping != NULL)
		delete	m_LineMapping;
	if(m_ProjMapping1 != NULL)
		delete	m_ProjMapping1;
	if(m_ProjMapping2 != NULL)
		delete	m_ProjMapping2;
	if(m_TextStringMapping != NULL)
		delete	m_TextStringMapping;
	if(m_TermSymbolMapping1 != NULL)
		delete	m_TermSymbolMapping1;
	if(m_TermSymbolMapping2 != NULL)
		delete	m_TermSymbolMapping2;
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
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	直線寸法のMapping

	２．インターフェース
	BOOL MappingStruct(LinearDim_Struct IN_Struct)
	引数:	型					引数名				内容
			LinearDim_Struct	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
BOOL SXFLinearDimMappingC::MappingStruct(LinearDim_Struct IN_Struct,int IN_AssemType)
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
	//寸法線のPRESENTATION_ASSIGNMENTのＩＤ
	//補助線１，２に使用
	int AssignID = m_LineMapping->GetAssignID();
	//寸法線のSTYLED_ITEM..のＩＤ
	//DRAUGHTING_CALLOUTに使用
	//またTEMINATOR_SYMBOLにも使用
	int LineID = m_LineMapping->GetID();
	m_ins_line = new SXFD_InstC(LineID);
	m_aggr1 = new SXFD_AggrC();
	m_aggr1->AddElem(m_ins_line);

	//補助線1のMapping
	if (IN_Struct.flg2 == 1){
		ProjLine_Struct Proj_str1;
		Proj_str1.ho_x0 = IN_Struct.ho1_x0;
		Proj_str1.ho_y0 = IN_Struct.ho1_y0;
		Proj_str1.ho_x1 = IN_Struct.ho1_x1;
		Proj_str1.ho_y1 = IN_Struct.ho1_y1;
		Proj_str1.ho_x2 = IN_Struct.ho1_x2;
		Proj_str1.ho_y2 = IN_Struct.ho1_y2;
		Proj_str1.target_ID = AssignID;
		m_ProjMapping1 = new SXFProjMappingC(1);
		m_ProjMapping1->MappingStructDim(Proj_str1);
		int Proj1ID = m_ProjMapping1->GetID();
		m_ins_proj1 = new SXFD_InstC(Proj1ID);
		m_aggr1->AddElem(m_ins_proj1);
	}
	//補助線2のMapping
	if (IN_Struct.flg3 == 1){
		ProjLine_Struct Proj_str2;
		Proj_str2.ho_x0 = IN_Struct.ho2_x0;
		Proj_str2.ho_y0 = IN_Struct.ho2_y0;
		Proj_str2.ho_x1 = IN_Struct.ho2_x1;
		Proj_str2.ho_y1 = IN_Struct.ho2_y1;
		Proj_str2.ho_x2 = IN_Struct.ho2_x2;
		Proj_str2.ho_y2 = IN_Struct.ho2_y2;
		Proj_str2.target_ID = AssignID;
		m_ProjMapping2 = new SXFProjMappingC(2);
		m_ProjMapping2->MappingStructDim(Proj_str2);	
		int Proj2ID = m_ProjMapping2->GetID();
		m_ins_proj2 = new SXFD_InstC(Proj2ID);
		m_aggr1->AddElem(m_ins_proj2);
	}
	//文字のMapping
	Text_Struct TextString_str;
	TextString_str.layer = IN_Struct.layer;
	TextString_str.color = IN_Struct.color;
	TextString_str.font = IN_Struct.font;
	//寸法値有無フラグが0だった場合
	//文字列を" "とする。
	if (IN_Struct.flg4 == 0){
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,"");
		strcpy_s(TextString_str.str,_countof(TextString_str.str),"");
	}
	else
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,IN_Struct.str);
		strcpy_s(TextString_str.str,_countof(TextString_str.str),IN_Struct.str);
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

		//矢印1のMapping
		TermSymbol_Struct TermSymbol_str1;
		TermSymbol_str1.color = IN_Struct.color;
		TermSymbol_str1.code = IN_Struct.arr1_code1;
		TermSymbol_str1.flag = IN_Struct.arr1_code2;
		TermSymbol_str1.x = IN_Struct.arr1_x;
		TermSymbol_str1.y = IN_Struct.arr1_y;
		TermSymbol_str1.scale =IN_Struct.arr1_r;
		TermSymbol_str1.target_ID = LineID;//寸法線のSTYLED_ITEMのＩＤ

		TermSymbol_Struct TermSymbol_str2;
		TermSymbol_str2.color = IN_Struct.color;
		TermSymbol_str2.code = IN_Struct.arr2_code1;
		TermSymbol_str2.flag = IN_Struct.arr2_code2;
		TermSymbol_str2.x = IN_Struct.arr2_x;
		TermSymbol_str2.y = IN_Struct.arr2_y;
		TermSymbol_str2.scale =IN_Struct.arr2_r;
		TermSymbol_str2.target_ID = LineID;//寸法線のSTYLED_ITEMのＩＤ
		//DIRECTIONの計算
		if (IN_Struct.arr1_code2 != 0 || IN_Struct.arr2_code2 != 0){
			if (!CalcArrowDir(IN_Struct,TermSymbol_str1.direction_x,TermSymbol_str1.direction_y,TermSymbol_str2.direction_x,TermSymbol_str2.direction_y))
				return FALSE;
	}

	//Mapping
	int colorID;
	if (IN_Struct.arr1_code2 != 0){
		TermSymbol_str1.flag = 1;
		m_TermSymbolMapping1 = new SXFTermSymbolMappingC(m_TableManager,1,1);//１番目の矢印,Dimension
		m_TermSymbolMapping1->MappingStructDim(TermSymbol_str1);
		m_TermSymbolMapping1->GetTermID(colorID);
		int term1ID= m_TermSymbolMapping1->GetID();
		m_term1_inst = new SXFD_InstC(term1ID);
		m_aggr1->AddElem(m_term1_inst);
	}
	if (IN_Struct.arr2_code2 != 0){
		m_TermSymbolMapping2 = new SXFTermSymbolMappingC(m_TableManager,2,1);//2番目の矢印,Dimension
		if (TermSymbol_str1.flag == 1){
			TermSymbol_str2.flag = 2;//2個矢印がある
			m_TermSymbolMapping2->SetTermID(colorID);
		}
		else
			TermSymbol_str2.flag = 1;//1個だけ
		m_TermSymbolMapping2->MappingStructDim(TermSymbol_str2);
		int term2ID= m_TermSymbolMapping2->GetID();
		m_term2_inst = new SXFD_InstC(term2ID);
		m_aggr1->AddElem(m_term2_inst);
	}
	
	m_str1 = new SXFD_StrC(" ");
	m_ins_text = new SXFD_InstC(Text_ID);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_ins_text) ;
	m_inst[0] = new SXFE_structured_dimension_calloutC(m_str1,m_aggr2);
	
	m_str2 = new SXFD_StrC(" ");
	m_inst[1] = new SXFE_linear_dimensionC(m_str2,m_aggr1);
	
	m_str3 = new SXFD_StrC("primary");
	m_str4 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_dimension_callout_relationshipC
			(m_str3,m_str4,m_inst[1],m_inst[0]); 

	//アセンブリ要素（用紙、複合図形）からの参照するＩＤの設定
	//用紙の場合
	//DRAWING_SHEET_REVISION => STYLED_ITEM => STRUCTURED_DIMENSION_CALLOUT()
	//                       => STYLED_ITEM => LINEAR_DIMENSION()
	if (IN_AssemType == 1){
		m_bool1 = new SXFD_BoolC(DEF_NULL);
		m_type1 = new SXFD_TypeC(DEF_NULL_STYLE);
		m_type1->SetNext(m_bool1);
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem(m_type1);
		m_inst[3] = new SXFE_presentation_style_assignmentC(m_aggr3);
		
		m_aggr4 = new SXFD_AggrC();
		m_str5 = new SXFD_StrC(" ");
		m_aggr4->AddElem(m_inst[3]);
		m_inst[4] = new SXFE_styled_itemC(m_str5,m_aggr4,m_inst[0]);
		//アセンブリ要素が参照するIDとして、STYLED_ITEMのIDを登録
		m_ID1 = m_inst[4]->GetInsID();//アセンブリ要素がもつＩＤ
		
		m_aggr5 = new SXFD_AggrC();
		m_str6 = new SXFD_StrC(" ");
		
		m_aggr5->AddElem(m_inst[3]);
		m_inst[5] = new SXFE_styled_itemC(m_str6,m_aggr5,m_inst[1]);
		//アセンブリ要素が参照するIDとして、STYLED_ITEMのIDを登録
		m_ID2 =m_inst[5]->GetInsID();//アセンブリ要素がもつＩＤ
	}
	
	//複合図形の場合
	//DRAUGHTING_SUBFIGURE_REPRESENTATION => STRUCTURED_DIMENSION_CALLOUT()
	//                                    => LINEAR_DIMENSION()
	else{
		//アセンブリ要素が参照するIDとして、STRUCTURED_DIMENSION_CALLOUTのIDを登録
		m_ID1 = m_inst[0]->GetInsID();//アセンブリ要素がもつＩＤ
		//アセンブリ要素が参照するIDとして、LINEAR_DIMENSIONのIDを登録
		m_ID2 = m_inst[1]->GetInsID();//アセンブリ要素がもつＩＤ;
	}

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

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
		作成		2001.06.17	佐々木(FQS)	なし。
**/
BOOL SXFLinearDimMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	if (m_LineMapping != NULL)
		m_LineMapping->WriteAP202(IN_File);
	if (m_ProjMapping1 != NULL)
		m_ProjMapping1->WriteAP202(IN_File);
	if (m_ProjMapping2 != NULL)
		m_ProjMapping2->WriteAP202(IN_File);
	if (m_TextStringMapping != NULL)
		m_TextStringMapping->WriteAP202(IN_File);
	if (m_TermSymbolMapping1 != NULL)
		m_TermSymbolMapping1->WriteAP202(IN_File);
	if (m_TermSymbolMapping2 != NULL)
		m_TermSymbolMapping2->WriteAP202(IN_File);
	if (m_inst[2] != NULL)
		m_inst[2]->WriteP21(IN_File);
	if (m_inst[4] != NULL)
		m_inst[4]->WriteP21(IN_File);
	if (m_inst[5] != NULL)
		m_inst[5]->WriteP21(IN_File);

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	SXFLinearDimMappingC

	２．インターフェース
	int GetID()
	引数:	型					引数名				内容
			なし
	
	 復帰値	インスタンスID

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
void SXFLinearDimMappingC::GetID(int &OUT_ID1,int &OUT_ID2)
{
	OUT_ID1 = m_ID1;
	OUT_ID2 = m_ID2;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDimMappingC.cpp					作成日：2001.06.17

	１．機能概要
	直線寸法Mapping時に矢印のDIRECTIONの計算を行う。

	２．インターフェース
	int CalcArrowDir(LinearDim_Struct IN_Struct, double &OUT_Arrow1_x, double &OUT_Arrow1_y, double &OUT_Arrow2_x, double &OUT_Arrow2_y)
	引数:	型					引数名			内容
			LinearDim_Struct	IN_Struct		構造体
			double&				OUT_Arrow1_x	矢印１のDIRECTION X
			double&				OUT_Arrow1_y	矢印１のDIRECTION Y
			double&				OUT_Arrow2_x	矢印２のDIRECTION X
			double&				OUT_Arrow2_y	矢印２のDIRECTION Y

	復帰値	正常時：1
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.17	佐々木(FQS)	なし。
**/
//矢印が２つの場合
BOOL SXFLinearDimMappingC::CalcArrowDir(LinearDim_Struct IN_Struct, double &OUT_Arrow1_x, double &OUT_Arrow1_y, double &OUT_Arrow2_x, double &OUT_Arrow2_y)
{
	//矢印が2つの場合
	if ((IN_Struct.arr1_code2 != 0) && (IN_Struct.arr2_code2 != 0)){
		//矢印１と寸法線始点の長さ
		double Length1 = fabs(sqrt(pow((IN_Struct.arr1_x - IN_Struct.sun_x1),2) + pow((IN_Struct.arr1_y - IN_Struct.sun_y1),2)));
		//矢印２と寸法線始点の長さ
		double Length2 = fabs(sqrt(pow((IN_Struct.arr2_x - IN_Struct.sun_x1),2) + pow((IN_Struct.arr2_y - IN_Struct.sun_y1),2)));
		//寸法線の長さ
		double Line_Length = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		//寸法線の方向ベクトル
		double Line_Dir_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / Line_Length;
		double Line_Dir_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / Line_Length;
		//矢印１が寸法線の始点に近いとき
		if (Length1 <= Length2){
			//矢印１の方向ベクトルを設定する
			//矢印１の内外コードが２（内向き）のとき、寸法線の方向ベクトルと同方向に設定する
			if(IN_Struct.arr1_code2 == 2){
				OUT_Arrow1_x = Line_Dir_x;
				OUT_Arrow1_y = Line_Dir_y;
			}
			//矢印１の内外コードが１（外向き）のとき、寸法線の方向ベクトルと反対方向に設定する
			else if(IN_Struct.arr1_code2 == 1){
				OUT_Arrow1_x = - Line_Dir_x;
				OUT_Arrow1_y = - Line_Dir_y;
			}
			else{
				return FALSE;
			}

			//矢印２の方向ベクトルを設定する
			//矢印２の内外コードが２（内向き）のとき、寸法線の方向ベクトルと反対方向に設定する
			if(IN_Struct.arr2_code2 == 2){
				OUT_Arrow2_x = -Line_Dir_x;
				OUT_Arrow2_y = -Line_Dir_y;
			}
			//矢印２の内外コードが１（外向き）のとき、寸法線の方向ベクトルと同方向に設定する
			else if(IN_Struct.arr2_code2 == 1){
				OUT_Arrow2_x = Line_Dir_x;
				OUT_Arrow2_y = Line_Dir_y;
			}
			else{
				return FALSE;
			}
		}
		//矢印２が寸法線始点に近いとき
		else {
			//矢印２の方向ベクトルを設定する
			//矢印２の内外コードが２（内向き）のとき、寸法線の方向ベクトルと同方向に設定する
			if(IN_Struct.arr2_code2 == 2){
				OUT_Arrow2_x = Line_Dir_x;
				OUT_Arrow2_y = Line_Dir_y;
			}
			//矢印２の内外コードが１（外向き）のとき、寸法線の方向ベクトルと反対方向に設定する
			else if(IN_Struct.arr2_code2 == 1){
				OUT_Arrow2_x = -Line_Dir_x;
				OUT_Arrow2_y = -Line_Dir_y;
			}
			else{
				return FALSE;
			}
			//矢印１の方向ベクトルを設定する
			//矢印１の内外コードが２（内向き）のとき、寸法線の方向ベクトルと反対方向に設定する
			if(IN_Struct.arr1_code2 == 2){
				OUT_Arrow1_x = -Line_Dir_x;
				OUT_Arrow1_y = -Line_Dir_y;
			}
			//矢印１の内外コードが１（外向き）のとき、寸法線の方向ベクトルと同方向に設定する
			else if(IN_Struct.arr1_code2 == 1){
				OUT_Arrow1_x = Line_Dir_x;
				OUT_Arrow1_y = Line_Dir_y;
			}
			else{
				return FALSE;
			}
		}
	}
	//矢印が一つの場合(矢印1の場合）
	else if ((IN_Struct.arr1_code2 != 0) && (IN_Struct.arr2_code2 == 0)){
		//寸法線の方向ベクトルを計算する
		//寸法線の始点から終点までの長さ
		double L1 = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		double Dim_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / L1;
		double Dim_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / L1;
		//矢印１の方向ベクトルを設定する
		//矢印１の内外コードが２（内向き）のとき、寸法線の方向ベクトルと同方向に設定する
		if(IN_Struct.arr1_code2 == 2){
			OUT_Arrow1_x = Dim_x;
			OUT_Arrow1_y = Dim_y;
		}
		//矢印１の内外コードが１（外向き）のとき、寸法線の方向ベクトルと反対方向に設定する
		else if(IN_Struct.arr1_code2 == 1){
			OUT_Arrow1_x = -Dim_x;
			OUT_Arrow1_y = -Dim_y;
		}
		else
			return FALSE;
	}
	//矢印が一つの場合（矢印２の場合）
	else if ((IN_Struct.arr1_code2 == 0) && (IN_Struct.arr2_code2 != 0)){
		//寸法線の方向ベクトルを計算する
		//寸法線の始点から終点までの長さ
		double L1 = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		double Dim_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / L1;
		double Dim_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / L1;
		//矢印２の方向ベクトルを設定する
		//矢印２の内外コードが２（内向き）のとき、寸法線の方向ベクトルと反対方向に設定する
		if(IN_Struct.arr2_code2 == 2){
			OUT_Arrow2_x = -Dim_x;
			OUT_Arrow2_y = -Dim_y;
		}
		//矢印２の内外コードが１（外向き）のとき、寸法線の方向ベクトルと同方向に設定する
		else if(IN_Struct.arr2_code2 == 1){
			OUT_Arrow2_x = Dim_x;
			OUT_Arrow2_y = Dim_y;
		}
		else 
			return FALSE;
	}
	else 
		FALSE;
	return TRUE;
}

