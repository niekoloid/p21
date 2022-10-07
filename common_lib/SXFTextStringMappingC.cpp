/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．クラス概要
	文字フィーチャのMapping

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。
	更新			2002.02.20			K.Naono				改修対応

**/
#include "stdafx.h"
#include <math.h>
#include "SXFTextStringMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFD_EnumC.h"
#include "SXFD_TypeC.h"
#include "SXFE_planar_extentC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_text_literal_with_extentC.h"
#include "SXFE_text_style_for_defined_fontC.h"
#include "SXFE_text_style_with_box_characteristicsC.h"
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
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTextStringMappingC::SXFTextStringMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTextStringMappingC::SXFTextStringMappingC()
{
	m_DimFlag = -1;
	m_ID = -1;
	m_TableManager = NULL;

	for (int i = 0; i < 9; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
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
	m_str8 = NULL;
	m_str9 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_real7 = NULL;
	m_real8 = NULL;
	m_real9 = NULL;
	m_real10 = NULL;
	m_real11 = NULL;
	m_real12 = NULL;
	m_enum1 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTextStringMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag)
	引数:	型					引数名				内容
			SXFTableManagerC* 	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			int 				IN_DimFlag			Dim or Label	
	

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTextStringMappingC::SXFTextStringMappingC(SXFTableManagerC* IN_TableManager,int IN_DimFlag)
{
	m_TableManager = IN_TableManager;
	m_DimFlag = IN_DimFlag;
	m_ID = -1;

	for (int i = 0; i < 9; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
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
	m_str8 = NULL;
	m_str9 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_real7 = NULL;
	m_real8 = NULL;
	m_real9 = NULL;
	m_real10 = NULL;
	m_real11 = NULL;
	m_real12 = NULL;
	m_enum1 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFTextStringMappingC::~SXFTextStringMappingC()
	引数:	型				引数名				内容
			なし				

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTextStringMappingC::~SXFTextStringMappingC()
{
	if (m_inst[8] != NULL)
		delete m_inst[8];
	if (m_real7 != NULL)
		delete m_real7;
	if (m_real8 != NULL)
		delete m_real8;
	if (m_real9 != NULL)
		delete m_real9;
	if (m_real10 != NULL)
		delete m_real10;
	if (m_real11 != NULL)
		delete m_real11;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	Mappingを行う。

	２．インターフェース
	BOOL MappingStruct(Text_Struct IN_Struct)
	引数:	型					引数名				内容
			Text_Struct	IN_Struct			構造体
	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTextStringMappingC::MappingStruct(Text_Struct IN_Struct)
{
	char temp_char1[64];
	char temp_char2[64];
	char temp_char3[64];
	m_str1 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.width);
	m_real2 = new SXFD_RealC(IN_Struct.height);
	m_inst[0] = new SXFE_planar_extentC(m_str1,m_real1,m_real2);

	m_str2 = new SXFD_StrC(" ");
	double m_direction_x = cos(acos(-1.)*IN_Struct.angle/180.0);
	double m_direction_y = sin(acos(-1.)*IN_Struct.angle/180.0);
	m_real3 = new SXFD_AngleC(m_direction_x);
	m_real4 = new SXFD_AngleC(m_direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real3) ;
	m_aggr1->AddElem(m_real4) ;
	m_inst[1] = new SXFE_directionC(m_str2,m_aggr1);

	//文字要素のベースライン比率を計算する。
	double ascent=1.0,decent=0.0;
	m_TableManager->GetTextFontProperty(IN_Struct.font,ascent,decent);
	double ascent1 = ascent;
	double decent1 = decent;
	double centre1 = ascent1 - (ascent1 + decent1) / 2;
	double ascent2 = IN_Struct.height * ascent1 / (ascent1 + decent1);
	double decent2 = IN_Struct.height * centre1 / (ascent1 + decent1);
	double centre2 = IN_Struct.height * (ascent1 - (ascent1 + decent1) / 2) / (ascent1 + decent1);
	double x1= 0.0,y1= 0.0;//文字配置基点
	double rotate_angle = acos(-1.)*IN_Struct.angle/180.0;//文字列回転角
	switch(IN_Struct.b_pnt){
	case 1:
		x1 = IN_Struct.text_x - decent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y + decent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline left");
		//strcpy(temp_char3,"$$SXF_baseline left");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline left");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_baseline left");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 2:
		x1 = IN_Struct.text_x - decent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y + decent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline centre");
		//strcpy(temp_char3,"$$SXF_baseline centre");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline centre");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_baseline centre");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 3:
		x1 = IN_Struct.text_x - decent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y + decent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline right");
		//strcpy(temp_char3,"$$SXF_baseline right");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline right");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_baseline right");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 4:
		x1 = IN_Struct.text_x + centre2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - centre2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline left");
		//strcpy(temp_char3,"$$SXF_middleline left");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline left");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_middleline left");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 5:
		x1 = IN_Struct.text_x + centre2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - centre2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline centre");
		//strcpy(temp_char3,"$$SXF_middleline centre");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline centre");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_middleline centre");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 6:
		x1 = IN_Struct.text_x + centre2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - centre2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline right");
		//strcpy(temp_char3,"$$SXF_middleline right");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline right");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_middleline right");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 7:
		x1 = IN_Struct.text_x + ascent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - ascent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline left");
		//strcpy(temp_char3,"$$SXF_topline left");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline left");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_topline left");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 8:
		x1 = IN_Struct.text_x + ascent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - ascent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline centre");
		//strcpy(temp_char3,"$$SXF_topline centre");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline centre");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_topline centre");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	case 9:
		x1 = IN_Struct.text_x + ascent2 * sin(rotate_angle);
		y1 = IN_Struct.text_y - ascent2 * cos(rotate_angle);
	//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char1,"baseline right");
		//strcpy(temp_char3,"$$SXF_topline right");
		strcpy_s(temp_char1,_countof(temp_char1),"baseline right");
		strcpy_s(temp_char3,_countof(temp_char3),"$$SXF_topline right");
	//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		break;
	default:
		break;
	}
	m_str3 = new SXFD_StrC(" ");
	m_real5 = new SXFD_RealC(x1);
	m_real6 = new SXFD_RealC(y1);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real5) ;
	m_aggr2->AddElem(m_real6) ;
	m_inst[2] = new SXFE_cartesian_pointC(m_str3,m_aggr2);
	
	m_str4 = new SXFD_StrC(" ");
	m_inst[3] = new SXFE_axis2_placement_2dC(m_str4,m_inst[2],m_inst[1]);
	
	m_ins1 = new SXFD_InstC(m_TableManager->GetID(7,IN_Struct.font));
	switch(IN_Struct.direct){
	case 1:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char2,"RIGHT");
		strcpy_s(temp_char2,_countof(temp_char2),"RIGHT");
		break;
	case 2:
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(temp_char2,"DOWN");
		strcpy_s(temp_char2,_countof(temp_char2),"DOWN");
		break;
	default:
		break;
	}

	m_str5 = new SXFD_StrC(temp_char3);
	m_str6 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct.str);
	m_str7 = new SXFD_StrC(temp_char1);
	m_enum1 = new SXFD_EnumC(temp_char2);
	m_inst[4] = new SXFE_text_literal_with_extentC(
				m_str5,
				m_str6,
				m_inst[3],
				m_str7,
				m_enum1,
				m_ins1,
				m_inst[0]
				);
	
	int table_type;
	if (IN_Struct.color < 17){
		table_type = 2;
	}
	else{
		table_type = 3;
	}
	m_ins2 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
	m_inst[5] = new SXFE_text_style_for_defined_fontC(m_ins2);
	
	m_str8 = new SXFD_StrC(" ");
	m_aggr3 = new SXFD_AggrC();
	m_real7 = new SXFD_RealC(IN_Struct.height);
	m_type1 = new SXFD_TypeC(DEF_BOX_HEIGHT);
	m_type1->SetNext(m_real7);
	m_aggr3->AddElem(m_type1);

	m_real8 = new SXFD_RealC(IN_Struct.height*0.8);
	m_type2 = new SXFD_TypeC(DEF_BOX_WIDTH);
	m_type2->SetNext(m_real8);
	m_aggr3->AddElem(m_type2);

	m_real9 = new SXFD_AngleC(acos(-1.)*IN_Struct.slant/180.0);
	m_type3 = new SXFD_TypeC(DEF_BOX_SLANT_ANGLE);
	m_type3->SetNext(m_real9);
	m_aggr3->AddElem(m_type3);

	m_real10 = new SXFD_AngleC(acos(-1.)*IN_Struct.angle/180.0);
	m_type4 = new SXFD_TypeC(DEF_BOX_ROTATE_ANGLE);
	m_type4->SetNext(m_real10);
	m_aggr3->AddElem(m_type4);

	m_real11 = new SXFD_RealC(IN_Struct.spc);
	m_type5 = new SXFD_TypeC(DEF_LENGTH_MEASURE);
	m_type5->SetNext(m_real11);
	m_inst[6] = new SXFE_text_style_with_box_characteristicsC(
				m_str8,
				m_inst[5],
				m_aggr3,
				m_type5
				);
	
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem(m_inst[6]) ;
	m_inst[7] = new SXFE_presentation_style_assignmentC(m_aggr4);
	
	CStringList* slist = new CStringList();
	slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	slist->AddTail(DEF_ANNOTATION_TEXT_OCCURRENCE);
	slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr5 = new SXFD_AggrC() ;
	m_aggr5->AddElem(m_inst[7]);
	if (m_DimFlag){
//	MOD(S)	改修対応	K.Naono	02.02.20
//		m_str9 = new SXFD_StrC("dimension_value");
		m_str9 = new SXFD_StrC("dimension value");
//	MOD(E)	改修対応	K.Naono	02.02.20
	}
	else{
		m_str9 = new SXFD_StrC(" ");
	}
	m_inst[8] = new SXFE_styled_itemC(m_str9,m_aggr5,m_inst[4],slist);
	///レイヤに文字要素のＩＤを追加
	m_ID = m_inst[8]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	文字要素フィーチャのファイルへの出力を行う。

	２．インターフェース
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	引数:	型					引数名			内容
			SXFPart21FileC*		IN_File			ファイルオブジェクトのアドレス

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTextStringMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[8]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextStringMappingC.cpp								作成日：2001.06.14

	１．機能概要
	文字要素フィーチャの代表インスタンスIDを返す。

	２．インターフェース
	int GetID()
	引数:	型					引数名			内容
			なし

	復帰値	インスタンスID

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
int SXFTextStringMappingC::GetID()
{
	return m_ID;
}

