/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						作成日：2000.04.17

	１．クラス概要
		COLOUR_RGBを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_COLOUR_RGBC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC()
{

//#101 = COLOUR_RGB('COLOUR_RGB1', (0., 0.));

//	<初期化>
	m_EntityName = DEF_COLOUR_RGB;
//
//	<エンティティデータ>
//  ENTITY colour_rgb
//    SUBTYPE OF (colour_specification);
//      red   : REAL;
//      green : REAL;
//      blue  : REAL;
//    WHERE
//      wr1: (0 <= red) AND (red <= 1);
//      wr2: (0 <= green) AND (green <= 1);
//      wr3: (0 <= blue) AND (blue <= 1);
//  END_ENTITY; -- colour_rgb
//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(色名）>
	m_name.Empty();

//	<RGB値>	
	m_R = m_G = m_B = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名					内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//#101 = COLOUR_RGB('COLOUR_RGB1', (0., 0.));

//	<初期化>
	m_EntityName = DEF_COLOUR_RGB;
//	<エンティティデータ>
//  ENTITY colour_rgb
//    SUBTYPE OF (colour_specification);
//      red   : REAL;
//      green : REAL;
//      blue  : REAL;
//    WHERE
//      wr1: (0 <= red) AND (red <= 1);
//      wr2: (0 <= green) AND (green <= 1);
//      wr3: (0 <= blue) AND (blue <= 1);
//  END_ENTITY; -- colour_rgb
//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(色名）>
	m_name.Empty();

//	<RGB値>	
	m_R = m_G = m_B = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_COLOUR_RGBC::~SXFMapE_COLOUR_RGBC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::~SXFMapE_COLOUR_RGBC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapE_COLOUR_RGBC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/


int SXFMapE_COLOUR_RGBC::SetParameter()

{
	SXFMapEntAConvC convent(m_EntityArray);
	//<name(色名)>
	convent.GetCString(0,m_name);

	//	<RGB値>	
	double color;

//	m_R = m_G = m_B = 0;
	convent.GetDouble(1,m_R);
	convent.GetDouble(2,m_G);
	convent.GetDouble(3,m_B);

//      wr1: (0 <= red) AND (red <= 1);
	for( int i=0 ; i<3 ; i++ ){
		if ( i == 0 ) color = m_R;
		if ( i == 1 ) color = m_G;
		if ( i == 2 ) color = m_B;

		if ( color<0. || color>1. ){
			//COLOUR_RGBのRGB値にに異常があります。
			SXFErrorMsgC::RecordError(
				SXFRGBERROR,		//errメッセージ番号
				m_EntityName,		//エンティティ名
				1,					//パラメタの個数
				color				//パラメタ
			);
			return SXFRGBERROR;	
		}
	}

	return 0;
}
