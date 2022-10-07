/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						作成日：2000.04.17

	１．クラス概要
		SYMBOL_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_TEXT_STYLEC.h"
#include "SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h"

#include "SXFMapEntCConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC()
{
//	<初期化>
	m_EntityName = DEF_SXF_COMPLEX_INSTANCE;
//<エンティティデータ>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	//	1.nameパラメタ
	m_name.Empty();

	//	2.symbol_colour へのインスタンスID
	m_text_appe_Inst = 0;

	//	symbol_colourへのポインタ
	m_text_appe_P =NULL;

//	<文字高さ>
	m_height=0.;
//	<文字幅>
	m_width=0.;
//	<スラント角度 radian>
	m_slant_angle=0.;
//	<文字列角度 radian>
	m_rotate_angle=0.;
//	<文字間隔>
	m_spacing=0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_SYMBOL_STYLE;
//<エンティティデータ>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	//	1.nameパラメタ
	m_name.Empty();

	//	2.symbol_colour へのインスタンスID
	m_text_appe_Inst = 0;

	//	symbol_colourへのポインタ
	m_text_appe_P =NULL;

	//	<文字高さ>
	m_height=0.;
	//	<文字幅>
	m_width=0.;
	//	<スラント角度 radian>
	m_slant_angle=0.;
	//	<文字列角度 radian>
	m_rotate_angle=0.;
	//	<文字間隔>
	m_spacing=0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_STYLEC::~SXFMapE_TEXT_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::~SXFMapE_TEXT_STYLEC()
{
	if(m_text_appe_P != NULL)
	{
		delete m_text_appe_P;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_TEXT_STYLEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_TEXT_STYLEC::SetParameter()

{
//	<1. エンティティパラメタの設定>

	int ircode=0;
//<エンティティデータ>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	SXFMapEntCConvC convert(m_EntityArray);

	//	TEXT_STYLE のもつパラメタを取り出す
	convert.SplitComplex(DEF_TEXT_STYLE);
	//	1.nameパラメタ
	convert.GetCString(0,m_name);

	//	2.text_style_for_defined_font へのインスタンスID
	convert.GetInst(1,m_text_appe_Inst);

	//	参照先のtext_style_for_defined_font作成

	//エンティティインスタンスを作成
//	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC m_text_appe_P(m_InstanceIDManager);
	m_text_appe_P = new SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(m_InstanceIDManager);
	ircode = m_text_appe_P->SetRootID(m_text_appe_Inst);
	if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_text_appe_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//	TEXT_STYLE_WITH_BOX_CHARACTERISTICS のもつパラメタを取り出す
	convert.SplitComplex(DEF_TEXT_STYLE_WITH_BOX_CHARACTERISTICS);

	CArray<double,double> OUT_array;
	int OUT_Num;

	//	SELECT型の値を取り出す
	//	<文字高さ>
	convert.GetSetSelectDouble(0,DEF_BOX_HEIGHT,OUT_Num,OUT_array);
	m_height	=	OUT_array[0];
	//	<文字幅>
	convert.GetSetSelectDouble(0,DEF_BOX_WIDTH,OUT_Num,OUT_array);
	m_width			=	OUT_array[0];
	//	<スラント角度 radian>
	convert.GetSetSelectDouble(0,DEF_BOX_SLANT_ANGLE,OUT_Num,OUT_array);
	m_slant_angle	=	OUT_array[0];
	//	<文字列角度 radian>
	convert.GetSetSelectDouble(0,DEF_BOX_ROTATE_ANGLE,OUT_Num,OUT_array);
	m_rotate_angle	=	OUT_array[0];

	//	TEXT_STYLE_WITH_SPACING のもつパラメタを取り出す
	convert.SplitComplex(DEF_TEXT_STYLE_WITH_SPACING);
	//	SELECT型の値を取り出す
	//	<文字間隔さ>
	convert.GetSelectDouble(0,DEF_LENGTH_MEASURE,m_spacing);

	return 0;
}
