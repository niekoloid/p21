/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．クラス概要
	角度寸法をMappingする。

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFAngularDimMappingC.h"
#include <math.h>
#include "SXFLinearDimMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFArcMappingC.h"
#include "SXFProjMappingC.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_BoolC.h"
#include "SXFE_structured_dimension_calloutC.h"
#include "SXFE_angular_dimensionC.h"
#include "SXFE_dimension_callout_relationshipC.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFutyFunctionC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	コンストラクタ

	２．インターフェース
		void	SXFAngularDimMappingC::SXFAngularDimMappingC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
SXFAngularDimMappingC::SXFAngularDimMappingC()
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_ArcMapping = NULL;
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
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	コンストラクタ

	２．インターフェース
	void SXFAngularDimMappingC(SXFTableManagerC* IN_TableManager)

	引数:	型					引数名			内容
			SXFTableManagerC*	IN_TableManager	定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
SXFAngularDimMappingC::SXFAngularDimMappingC(SXFTableManagerC* IN_TableManager)
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_TableManager = IN_TableManager;
	m_ArcMapping = NULL;
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
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	デストラクタ

	２．インターフェース
		void SXFAngularDimMappingC::~SXFAngularDimMappingC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
SXFAngularDimMappingC::~SXFAngularDimMappingC()
{
	if (m_bool1 != NULL)
		delete m_bool1;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_TermSymbolMapping1 != NULL)
		delete m_TermSymbolMapping1;
	if (m_TermSymbolMapping2 != NULL)
		delete m_TermSymbolMapping2;
	if (m_ProjMapping1 != NULL)
		delete m_ProjMapping1;
	if (m_ProjMapping2 != NULL)
		delete m_ProjMapping2;
	if (m_ArcMapping != NULL)
		delete m_ArcMapping;

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
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	角度寸法のMapping

	２．インターフェース
	BOOL MappingStruct(AngularDim_Struct IN_Struct)
	引数:	型					引数名				内容
			AngularDim_Struct	IN_Struct			構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
int SXFAngularDimMappingC::MappingStruct(AngularDim_Struct IN_Struct,int IN_AssemType)
{
	Arc_Struct Arc_Str;
	Arc_Str.layer = IN_Struct.layer;
	Arc_Str.color = IN_Struct.color;
	Arc_Str.type = IN_Struct.type;
	Arc_Str.line_width = IN_Struct.line_width;
	Arc_Str.center_x = IN_Struct.sun_x;
	Arc_Str.center_y = IN_Struct.sun_y;
	Arc_Str.radius = IN_Struct.sun_radius;
	Arc_Str.start_angle = IN_Struct.sun_angle0;
	Arc_Str.end_angle = IN_Struct.sun_angle1;
	Arc_Str.direction = 1;
	//寸法線のMapping
	m_ArcMapping = new SXFArcMappingC(m_TableManager,1);
	m_ArcMapping->MappingStruct(Arc_Str);
	//寸法線のPRESENTATION_ASSIGNMENTのＩＤ
	//補助線１，２に使用
	int AssignID = m_ArcMapping->GetAssignID();
	
	//寸法線のSTYLED_ITEM..のＩＤ
	//DRAUGHTING_CALLOUTに使用
	//またTEMINATOR_SYMBOLにも使用
	int ArcID = m_ArcMapping->GetID();
	m_ins_line = new SXFD_InstC(ArcID);
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

	//矢印1のMapping
	TermSymbol_Struct TermSymbol_str1;
	TermSymbol_str1.color = IN_Struct.color;
	TermSymbol_str1.code = IN_Struct.arr1_code1;
	TermSymbol_str1.flag = IN_Struct.arr1_code2;
	TermSymbol_str1.x = IN_Struct.arr1_x;
	TermSymbol_str1.y = IN_Struct.arr1_y;
	TermSymbol_str1.scale =IN_Struct.arr1_r;
	TermSymbol_str1.target_ID = ArcID;//寸法線のSTYLED_ITEMのＩＤ

	TermSymbol_Struct TermSymbol_str2;
	TermSymbol_str2.color = IN_Struct.color;
	TermSymbol_str2.code = IN_Struct.arr2_code1;
	TermSymbol_str2.flag = IN_Struct.arr2_code2;
	TermSymbol_str2.x = IN_Struct.arr2_x;
	TermSymbol_str2.y = IN_Struct.arr2_y;
	TermSymbol_str2.scale =IN_Struct.arr2_r;
	TermSymbol_str2.target_ID = ArcID;//寸法線のSTYLED_ITEMのＩＤ
	//DIRECTIONの計算
	if ((IN_Struct.arr1_code2 != 0) || (IN_Struct.arr2_code2 != 0)){
		int ret = CalcArrowDir(IN_Struct,TermSymbol_str1.direction_x,TermSymbol_str1.direction_y,TermSymbol_str2.direction_x,TermSymbol_str2.direction_y);
		if (ret < 0)
			return ret;
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
	m_inst[1] = new SXFE_angular_dimensionC(m_str2,m_aggr1);

	m_str3 = new SXFD_StrC("primary");
	m_str4 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_dimension_callout_relationshipC
			(m_str3,m_str4,m_inst[1],m_inst[0]); 


	//アセンブリ要素（用紙、複合図形）からの参照するＩＤの設定
	//用紙の場合
	//DRAWING_SHEET_REVISION => STYLED_ITEM => STRUCTURED_DIMENSION_CALLOUT()
	//                       => STYLED_ITEM => ANGULAR_DIMENSION()
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
	//                                    => ANGULAR_DIMENSION()
	else{
		//アセンブリ要素が参照するIDとして、STRUCTURED_DIMENSION_CALLOUTのIDを登録
		m_ID1 = m_inst[0]->GetInsID();//アセンブリ要素がもつＩＤ
		//アセンブリ要素が参照するIDとして、ANGULAR_DIMENSIONのIDを登録
		m_ID2 = m_inst[1]->GetInsID();//アセンブリ要素がもつＩＤ;
	}
			
	return 1;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	角度寸法インスタンスのファイルへの出力

	２．インターフェース
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
BOOL SXFAngularDimMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	if (m_ArcMapping != NULL)
		m_ArcMapping->WriteAP202(IN_File);
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
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	インスタンスIDを返却する

	２．インターフェース
	GetID(int &OUT_ID1,int &OUT_ID2)
	引数:	型					引数名			内容
			int&				OUT_ID1			インスタンスID
			int&				OUT_ID2			インスタンスID

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
void SXFAngularDimMappingC::GetID(int &OUT_ID1,int &OUT_ID2)
{
	OUT_ID1 = m_ID1;
	OUT_ID2 = m_ID2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFAngularDimMappingC.cpp								作成日：2001.06.18

	１．機能概要
	角度寸法Mapping時に矢印のDIRECTIONの計算を行う

	２．インターフェース
	int CalcArrowDir(AngularDim_Struct IN_Struct, double &OUT_Arrow1_x, double &OUT_Arrow1_y, double &OUT_Arrow2_x, double &OUT_Arrow2_y)
	引数:	型					引数名			内容
			AngularDim_Struct	IN_Struct		構造体
			double&				OUT_Arrow1_x	矢印１のDIRECTION X
			double&				OUT_Arrow1_y	矢印１のDIRECTION Y
			double&				OUT_Arrow2_x	矢印２のDIRECTION X
			double&				OUT_Arrow2_y	矢印２のDIRECTION Y

	復帰値	正常時：1
			異常時：エラー番号

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。
	作成			2007.07.07(七夕)	(FQS)			なし。

**/
int SXFAngularDimMappingC::CalcArrowDir(AngularDim_Struct IN_Struct, double &OUT_Arrow1_x, double &OUT_Arrow1_y, double &OUT_Arrow2_x, double &OUT_Arrow2_y)
{
	//長さと角度の許容誤差を取得
	double eps,angle_eps;
	gl_Man->GetInfo().Get_Tolerance(eps,angle_eps);
	//角度寸法のみで利用する特別な許容誤差
	//  角度寸法では、フィーチャで角度で保持する寸法円弧始角終角度と、
	//  座標で保持する、矢印１，２の座標と、を比較する必要があり、
	//  その際、利用する長さか角度のどちらの許容誤差を利用するか検討した。
	//  現在は、長さ、角度の許容誤差のうち、甘いものを利用する。
	double eps_sp;
	if (eps>angle_eps){
		eps_sp=eps;
	}
	else{
		eps_sp=angle_eps;
	}

	//矢印１、２の方向ベクトル
	double vector1_x,vector1_y,vector2_x,vector2_y;
	//矢印１，２と寸法線原点との距離
	double L1,L2;
	//
	//矢印１，２の角度
	double angle1,angle2;
	//寸法円弧の始角、終角、半径
	double start_angle,end_angle;
	//寸法円弧の始角、終角の方向ベクトル
	double start_vector_x,start_vector_y,end_vector_x,end_vector_y;
	//円弧の始角と終角のなす角度
	//円弧の始角から、矢印１、矢印２のなす角度
	double angle_diff, angle1_start_diff, angle1_end_diff, angle2_start_diff, angle2_end_diff, angle1_2_diff;
	//***********************************************************************************
	//  矢印がふたつの場合
	//***********************************************************************************
	if ((IN_Struct.arr1_code2 != 0)&&(IN_Struct.arr2_code2 != 0)){
		///////////////////////////////////////////////////////////////////
		//寸法円弧原点と矢印1,2の配置座標から角度を求める
		///////////////////////////////////////////////////////////////////
		//矢印１，２と寸法線原点との距離
		L1 = fabs(sqrt(pow(IN_Struct.arr1_x - IN_Struct.sun_x, 2)+pow(IN_Struct.arr1_y - IN_Struct.sun_y, 2)));
		L2 = fabs(sqrt(pow(IN_Struct.arr2_x - IN_Struct.sun_x, 2)+pow(IN_Struct.arr2_y - IN_Struct.sun_y, 2)));
		//寸法線原点と矢印１配置位置のベクトル
		vector1_x = (IN_Struct.arr1_x - IN_Struct.sun_x) / L1;
		vector1_y = (IN_Struct.arr1_y - IN_Struct.sun_y) / L1;
		//寸法線原点と矢印２配置位置のベクトル
		vector2_x = (IN_Struct.arr2_x - IN_Struct.sun_x) / L2;
		vector2_y = (IN_Struct.arr2_y - IN_Struct.sun_y) / L2;
		//矢印１の角度を求める。
		CalcAngle(IN_Struct.sun_x,IN_Struct.sun_y,IN_Struct.arr1_x,IN_Struct.arr1_y,angle1);
		//矢印２の角度を求める。
		CalcAngle(IN_Struct.sun_x,IN_Struct.sun_y,IN_Struct.arr2_x,IN_Struct.arr2_y,angle2);
		///////////////////////////////////////////////////////////////////
		//寸法円弧の始角、終角とベクトルを求める
		///////////////////////////////////////////////////////////////////
		//寸法円弧の始角、終角(radian)
		//ラジアン＝角度×π÷１８０
		start_angle = IN_Struct.sun_angle0 * acos(-1.) / 180.0;
		end_angle = IN_Struct.sun_angle1 * acos(-1.) / 180.0;
		//寸法円弧の始角、終角のベクトルを求める
		start_vector_x = cos(start_angle);
		start_vector_y = sin(start_angle);
		end_vector_x = cos(end_angle);
		end_vector_y = sin(end_angle);
		//
		///////////////////////////////////////////////////////////////////
		//寸法円弧の始角と終角のなす角度を求める
		///////////////////////////////////////////////////////////////////
		CalcAngleSub(start_angle, end_angle, angle_diff);
		///////////////////////////////////////////////////////////////////
		//円弧の始角又は終角から、矢印１又は矢印２のなす角度を求める
		///////////////////////////////////////////////////////////////////
		CalcAngleSub(start_angle, angle1, angle1_start_diff);
		CalcAngleSub(end_angle, angle1, angle1_end_diff);
		CalcAngleSub(start_angle, angle2, angle2_start_diff);
		CalcAngleSub(end_angle, angle2, angle2_end_diff);
		///////////////////////////////////////////////////////////////////
		//円弧の始角をＸ軸（０度）とした、矢印１と矢印２のなす角度を求める
		///////////////////////////////////////////////////////////////////
		CalcAngleSub2(angle1_start_diff, angle2_start_diff, angle1_2_diff);
		/*	==>	Added by S.Kakizawa(KLS) on 2006/03/15	*/
		//	角度寸法が表示されない場合があるという不具合の対応
		if( angle1_2_diff < 0.0 )
		{
			if( AngleIsInside( start_angle, end_angle, angle1, eps_sp )	&&
				AngleIsInside( start_angle, end_angle, angle2, eps_sp )	&&
				AngleIsInside( start_angle, angle2, angle1, eps_sp )	)
			{
				angle1_2_diff	+= acos( -1.0 ) * 2.0;
			}
		}
		else
		{
			if( TRUE != AngleIsInside( start_angle, end_angle, angle1, eps_sp )	||
				TRUE != AngleIsInside( start_angle, end_angle, angle2, eps_sp )	||
				TRUE != AngleIsInside( start_angle, angle2, angle1, eps_sp )	)
			{
				angle1_2_diff	-= acos( -1.0 ) * 2.0;
			}
		}
		/*	<==	Added by S.Kakizawa(KLS) on 2006/03/15	*/

/*
		///////////////////////////////////////////////////////////////////
		//円弧の始角と終角が重なっていない場合
		///////////////////////////////////////////////////////////////////
		if ( fabs(start_vector_x - end_vector_x)>=eps_sp||fabs(start_vector_y - end_vector_y)>=eps_sp ){ 
*/
			///////////////////////////////////////////////////////////////////
			//矢印１、２角度が始角終角内にある場合。
			///////////////////////////////////////////////////////////////////
			if ((
				  (fabs(vector1_x - start_vector_x)<eps_sp&&fabs(vector1_y - start_vector_y)<eps_sp) || //矢印１が始角近く
				  (fabs(vector1_x - end_vector_x  )<eps_sp&&fabs(vector1_y - end_vector_y  )<eps_sp) || //矢印１が終角近く
				  (angle1_start_diff>=0.0 && angle1_start_diff<=angle_diff) //矢印１が始角終角内
				 )&&(
				  (fabs(vector2_x - start_vector_x)<eps_sp&&fabs(vector2_y - start_vector_y)<eps_sp) || //矢印２が始角近く
				  (fabs(vector2_x - end_vector_x  )<eps_sp&&fabs(vector2_y - end_vector_y  )<eps_sp) || //矢印２が終角近く
				  (angle2_start_diff>=0.0 && angle2_start_diff<=angle_diff) //矢印２が始角終角内
				 )){
				///////////////////////////////////////////////////////////////////
				//矢印１角度が矢印２角度より小さい場合。
				///////////////////////////////////////////////////////////////////
				if ( (fabs(vector2_x - vector1_x)<eps_sp&&fabs(vector2_y - vector1_y)<eps_sp)||//矢印１と２が近い
					 ( ((fabs(cos(angle1_start_diff)-1.0)<eps_sp) && (fabs(sin(angle1_start_diff))<eps_sp)) &&
					   ((fabs(vector2_x - vector1_x)>=eps_sp||fabs(vector2_y - vector1_y)>=eps_sp)) ) ||//矢印１が始角近く
					 ( ((fabs(cos(angle2_end_diff)-1.0)<eps_sp) && (fabs(sin(angle2_end_diff))<eps_sp)) &&
					   ((fabs(vector2_x - vector1_x)>=eps_sp||fabs(vector2_y - vector1_y)>=eps_sp)) ) ||//矢印２が終角近く
					 ( angle1_2_diff>= 0.0 ) ){	//矢印１より矢印２が大きい 矢印２＞＝矢印１
					//順向き
					//矢印１の内外コードが２(内向き)の場合(-90)
					//X1 = -Y
					//Y1 = +X
					if (IN_Struct.arr1_code2 == 2){
						OUT_Arrow1_x = -vector1_y;
						OUT_Arrow1_y = vector1_x;
					}
					//矢印１の内外コードが１(外向き）の場合(+90)
					//X1 = +Y
					//Y1 = -X
					else if (IN_Struct.arr1_code2 == 1){
						OUT_Arrow1_x = vector1_y;
						OUT_Arrow1_y = - vector1_x;
					}
					else{
						//矢印1内外コードが0から2以外のとき
						SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr1_code2,DEF_ANGULAR_DIMENSION);
						return SXFARRCODE;
					}
					//矢印２の内外コードが２（内向き）の場合(90)
					//X2 = +Y
					//Y2 = -X
					if (IN_Struct.arr2_code2 == 2){
						OUT_Arrow2_x = vector2_y;
						OUT_Arrow2_y = -vector2_x;
					}
					//矢印２の内外コードが１（外向き）の場合(-90)
					//X2 = -Y
					//Y2 = +X
					else if (IN_Struct.arr2_code2 == 1){
						OUT_Arrow2_x = - vector2_y;
						OUT_Arrow2_y = vector2_x;
					}
					else{
						//矢印2内外コードが0から2以外のとき
						SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr2_code2,DEF_ANGULAR_DIMENSION);
						return SXFARRCODE;
					}
				}
				///////////////////////////////////////////////////////////////////
				//矢印２角度が矢印１角度より小さい場合は、エラー
				///////////////////////////////////////////////////////////////////
				else{
					SXFErrorMsgC::RecordError(SXFARRORERROR,DEF_ANGULAR_DIMENSION,6,"-",IN_Struct.arr1_x,IN_Struct.arr1_y,IN_Struct.arr2_x,IN_Struct.arr2_y,DEF_ANGULAR_DIMENSION);
					return SXFARRORERROR;
					//逆向き
					//矢印１の内外コードが２(内向き)の場合(90)
					//X1 = +Y
					//Y1 = -X
				}
				
			}
			///////////////////////////////////////////////////////////////////
			//矢印１、２角度が始角終角内にない場合：エラー
			///////////////////////////////////////////////////////////////////
			else{
				SXFErrorMsgC::RecordError(SXFARRORERROR,DEF_ANGULAR_DIMENSION,6,"-",IN_Struct.arr1_x,IN_Struct.arr1_y,IN_Struct.arr2_x,IN_Struct.arr2_y,DEF_ANGULAR_DIMENSION);
				return SXFARRORERROR;
			}
/*
		}
		///////////////////////////////////////////////////////////////////
		//始角終角が等しい：エラー
		///////////////////////////////////////////////////////////////////
		else{
			SXFErrorMsgC::RecordError(SXFSAMEANGLE,DEF_ANGULAR_DIMENSION,4,"-",IN_Struct.sun_angle0,IN_Struct.sun_angle1,DEF_ANGULAR_DIMENSION);
			return SXFSAMEANGLE;
		}
*/
	}
	//矢印が一つの場合(矢印１のとき）***********************************************************************************
	else if ((IN_Struct.arr1_code2 != 0)&&(IN_Struct.arr2_code2 == 0)){
		//矢印１と寸法線原点との距離
		L1 = fabs(sqrt(pow(IN_Struct.arr1_x - IN_Struct.sun_x, 2)+pow(IN_Struct.arr1_x - IN_Struct.sun_y, 2)));
		//寸法線原点と矢印１配置位置のベクトル
		vector1_x = (IN_Struct.arr1_x - IN_Struct.sun_x) / L1;
		vector1_y = (IN_Struct.arr1_y - IN_Struct.sun_y) / L1;
		//矢印１の内外コードが２(内向き)の場合(-90)
		//X1 = -Y
		//Y1 = +X
		if (IN_Struct.arr1_code2 == 2){
			OUT_Arrow1_x = -vector1_y;
			OUT_Arrow1_y = vector1_x;
		}
		//矢印１の内外コードが１(外向き）の場合(+90)
		//X1 = +Y
		//Y1 = -X
		else if (IN_Struct.arr1_code2 == 1){
			OUT_Arrow1_x = vector1_y;
			OUT_Arrow1_y = - vector1_x;
		}
		else{
			//矢印1内外コードが0から2以外のとき
			SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr1_code2,DEF_ANGULAR_DIMENSION);
			return SXFARRCODE;
		}
	}
	//矢印が一つの場合(矢印２のとき）***********************************************************************************
	else if ((IN_Struct.arr1_code2 == 0)&&(IN_Struct.arr2_code2 != 0)){
		//矢印２と寸法線原点との距離
		L2 = fabs(sqrt(pow(IN_Struct.arr2_x - IN_Struct.sun_x, 2)+pow(IN_Struct.arr2_x - IN_Struct.sun_y, 2)));
		//寸法線原点と矢印２配置位置のベクトル
		vector2_x = (IN_Struct.arr2_x - IN_Struct.sun_x) / L2;
		vector2_y = (IN_Struct.arr2_y - IN_Struct.sun_y) / L2;
		//矢印２の内外コードが２（内向き）の場合(90)
		//X2 = +Y
		//Y2 = -X
		if (IN_Struct.arr2_code2 == 2){
			OUT_Arrow2_x = vector2_y;
			OUT_Arrow2_y = -vector2_x;
		}
		//矢印２の内外コードが１（外向き）の場合(-90)
		//X2 = -Y
		//Y2 = +X
		else if (IN_Struct.arr2_code2 == 1){
			OUT_Arrow2_x = - vector2_y;
			OUT_Arrow2_y = vector2_x;
		}
		else{
			//矢印2内外コードが0から2以外のとき
			SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr2_code2,DEF_ANGULAR_DIMENSION);
			return SXFARRCODE;
		}
	}
	else{
		//矢印1内外コードが0から2以外のとき
		SXFErrorMsgC::RecordError(SXFARRCODE,DEF_ANGULAR_DIMENSION,3,"-",IN_Struct.arr1_code2,DEF_ANGULAR_DIMENSION);
		return SXFARRCODE;
	}
	return 1;

}

void SXFAngularDimMappingC::CalcAngle(double IN_x1,double IN_y1,double IN_x2,double IN_y2,double& OUT_angle)
{
	double LA;
	double Ax,Ay;

	//寸法線原点と矢印配置座標との長さ
	LA = fabs(sqrt(pow(IN_x2 - IN_x1, 2)+pow(IN_y2 - IN_y1, 2)));
	//ベクトル
	Ax = (IN_x2 - IN_x1) / LA;
	Ay = (IN_y2 - IN_y1) / LA;

	//	角度を求める
	if (Ay >= 0){
		//第１、２象限
			OUT_angle = atan2(Ay,Ax);
	}
	else{
		//第３，４象限
		OUT_angle = 2 * acos(-1.) + atan2(Ay,Ax);
	}

}

///////////////////////////////////////////////////////////////////////////////////////////
// 0 < OUT_angle > 2π

void SXFAngularDimMappingC::CalcAngleSub(double IN_angle1,double IN_angle2,double& OUT_angle)
{
	double Ax,Ay;

	//ベクトル
	Ax = cos(IN_angle2 - IN_angle1);
	Ay = sin(IN_angle2 - IN_angle1);

	//	角度を求める
	if (Ay >= 0){
		//第１、２象限
			OUT_angle = atan2(Ay,Ax);
	}
	else{
		//第３，４象限
		OUT_angle = 2 * acos(-1.) + atan2(Ay,Ax);
	}

}


///////////////////////////////////////////////////////////////////////////////////////////
// -2π < OUT_angle > 2π

void SXFAngularDimMappingC::CalcAngleSub2(double IN_angle1,double IN_angle2,double& OUT_angle)
{
	double Angle1_sin, Angle2_sin, Ax,Ay;
	//
	Angle1_sin = sin(IN_angle1);
	Angle2_sin = sin(IN_angle2);	
	//ベクトル
	Ax = cos(IN_angle2 - IN_angle1);
	Ay = sin(IN_angle2 - IN_angle1);

	//	角度を求める
	if (Angle1_sin >= 0 && Angle2_sin >= 0){
		//第１、２象限
			OUT_angle = atan2(Ay,Ax);
	}
	else{
		if(Ay >= 0.0){
			//第１、２象限
			OUT_angle = atan2(Ay,Ax) - 2 * acos(-1.);
		}
		else{
			//第３，４象限
			OUT_angle = atan2(Ay,Ax) + 2 * acos(-1.);
		}
	}

}

/*	==>	Added by S.Kakizawa(KLS) on 2006/03/14	*/
//------------------------------------------------------------------------------------------------
//	Method Name:
//		SXFAngularDimMappingC::AngleIsInside
//	Exposition:
//		The Specified Check Angle Is Inside between the Two Angle.
//	Protective:
//		private
//	Return Value:
//		BOOL : Result of the Check.
//				TRUE	: Is Inside
//				FALSE	: Is Outside
//	Parameters:
//		const double& dbAngleStart : Start Angle.
//		const double& dbAngleEnd : End Angle.
//		const double& dbAngleCheck : Checked Angle.
//		const double& dbEps : Allowance.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/03/14.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
BOOL	SXFAngularDimMappingC::AngleIsInside( const double& dbAngleStart, const double& dbAngleEnd, const double& dbAngleCheck, const double& dbEps ) const
{
	static	double	dbRadian180	= acos( -1.0 );
	static	double	dbRadian360	= dbRadian180 * 2.0;

	double	dbAngleStart2	= dbAngleStart;
	double	dbAngleEnd2		= dbAngleEnd;
	double	dbAngleCheck2	= dbAngleCheck;

	while( 0.0 > (double)dbAngleStart2	)	dbAngleStart2	+= dbRadian360;
	while( 0.0 > (double)dbAngleEnd2	)	dbAngleEnd2		+= dbRadian360;
	while( 0.0 > (double)dbAngleCheck2	)	dbAngleCheck2	+= dbRadian360;

	double	dbAngleMiddle	= dbAngleStart2 - dbAngleEnd2;
	if( dbAngleStart2 >= ( dbAngleEnd2 + dbEps ) )
	{
		dbAngleMiddle	+= dbRadian360;
	}

	if( fabs( dbAngleMiddle ) <= dbEps )
	{
		if( fabs( dbAngleStart2 - dbAngleCheck2 ) <= dbEps )
		{
			return	TRUE;
		}

		return	FALSE;
	}

	dbAngleMiddle	= ( dbAngleStart2 + dbAngleEnd2 ) * 0.5;
	if( dbAngleStart2 >= ( dbAngleEnd2 + dbEps ) )
	{
		dbAngleMiddle	+= dbRadian180;
	}

	double	dbSinCheck			= sin( dbAngleCheck2 );
	double	dbCosCheck			= cos( dbAngleCheck2 );
	double	dbVectorProduct1	= cos( dbAngleMiddle	) * dbSinCheck - sin( dbAngleMiddle	) * dbCosCheck;

	if( dbVectorProduct1 >= - dbEps && ( cos( dbAngleEnd2 ) * dbSinCheck - sin( dbAngleEnd2 ) * dbCosCheck ) <= dbEps )
	{
		return	TRUE;
	}

	if( ( cos( dbAngleStart2 ) * dbSinCheck - sin( dbAngleStart2 ) * dbCosCheck ) >= - dbEps && dbVectorProduct1 <= dbEps )
	{
		return	TRUE;
	}

	return	FALSE;
}
/*	<==	Added by S.Kakizawa(KLS) on 2006/03/14	*/
