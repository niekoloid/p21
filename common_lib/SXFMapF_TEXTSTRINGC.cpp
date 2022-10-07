/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp					作成日：2001.06.17

	１．クラス概要
		文字フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2001.06.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_TEXTSTRINGC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.06.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_TEXTSTRINGC::SXFMapF_TEXTSTRINGC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
SXFMapF_TEXTSTRINGC::SXFMapF_TEXTSTRINGC()
{

	m_font = 0;
	m_text_x = 0.0;
	m_text_y = 0.0;
	m_height = 0.0;
	m_width = 0.0;
	m_spc = 0.0;
	m_angle = 0.0;
	m_slant = 0.0;
	m_b_pnt = -1;
	m_direct = -1;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.06.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_TEXTSTRINGC::~SXFMapF_TEXTSTRINGC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
SXFMapF_TEXTSTRINGC::~SXFMapF_TEXTSTRINGC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.06.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_TEXTSTRINGC::GetStructData(Text_Struct* INOUT_Struct)

	引数  ：	型				引数名				内容
				Text_Struct* 	INOUT_Struct    	構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
BOOL SXFMapF_TEXTSTRINGC::GetStructData( Text_Struct* INOUT_Struct )
{
	INOUT_Struct->layer   = m_layer ;		//レイヤコード
	INOUT_Struct->color   = m_color ;		//色コード
	INOUT_Struct->font    = m_font;

	//strcpy( INOUT_Struct->str, m_str );
	/* 文字列の長さを調べる */
	size_t ilen = strlen(m_str);
	if (ilen <= 256) {	// 2012.07.03  255->256
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy( INOUT_Struct->str, m_str );
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str );
	}
	else {
		/* メッセージを出力 */

		// ここでは m_RootID = 0,m_TypeName == "" になっている。
		// 本来は m_RootID = フィーチャID,m_TypeName == "TEXT" などにしたかったのでは?
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* 先頭から256バイト切り取る */
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy( INOUT_Struct->str, m_str.Left(256) );
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str.Left(256) );
	}

	INOUT_Struct->text_x =  m_text_x;
	INOUT_Struct->text_y =  m_text_y;
	INOUT_Struct->height =  m_height;
	INOUT_Struct->width  =  m_width;
	INOUT_Struct->spc    =  m_spc;
	INOUT_Struct->angle  =  m_angle;
	INOUT_Struct->slant  =  m_slant;
	INOUT_Struct->b_pnt  =  m_b_pnt;
	INOUT_Struct->direct =  m_direct;

	return TRUE;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.07.13

	１．機能概要
		文字配置基点フラグの設定
	２．インターフェイス
		BOOL SXFMapF_TEXTSTRINGC::SetBasePoint(
			CString& IN_name,		//	TEXT_LITERALのNAMEパラメタ 
			CString& IN_Alignment	//	TEXT_LITERALのALIGNMENTパラメタ
			)

	引数  ：	型			引数名				内容
				CString& 	IN_name				TEXT_LITERALのNAMEパラメタ
				CString& 	IN_Alignment		TEXT_LITERALのALIGNMENTパラメタ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.13	大村(FQS)
**/
//	<文字配置基点フラグの設定>
BOOL SXFMapF_TEXTSTRINGC::SetBasePoint( 
		CString& IN_name, 			//	TEXT_LITERALのNAMEパラメタ 
		CString& IN_Alignment		//	TEXT_LITERALのALIGNMENTパラメタ
		)
{
// 初期化 
	
//	文字配置基点判定用データ
	CStringArray b_point_name;

	CString a7(" ");
	CString a8("$$SXF_baseline left");
	CString a9("$$SXF_baseline centre");
	CString a10("$$SXF_baseline right");
	CString a11("$$SXF_middleline left");
	CString a12("$$SXF_middleline centre");
	CString a13("$$SXF_middleline right");
	CString a14("$$SXF_topline left");
	CString a15("$$SXF_topline centre");
	CString a16("$$SXF_topline right");

	b_point_name.Add((LPCTSTR)a7);
	b_point_name.Add((LPCTSTR)a8);
	b_point_name.Add((LPCTSTR)a9);
	b_point_name.Add((LPCTSTR)a10);
	b_point_name.Add((LPCTSTR)a11);
	b_point_name.Add((LPCTSTR)a12);
	b_point_name.Add((LPCTSTR)a13);
	b_point_name.Add((LPCTSTR)a14);
	b_point_name.Add((LPCTSTR)a15);
	b_point_name.Add((LPCTSTR)a16);

//	文字配置位置判定用データ
	CStringArray b_point;
	CString a0(" ");
	CString a1("baseline left");
	CString a2("baseline centre");
	CString a3("baseline right");

	b_point.Add((LPCTSTR)a0);
	b_point.Add((LPCTSTR)a1);
	b_point.Add((LPCTSTR)a2);
	b_point.Add((LPCTSTR)a3);


//	基点の判定
	m_b_pnt = -1;
	for(int j=1;j<=9;j++){
		if(IN_name==b_point_name.GetAt(j)){
			m_b_pnt=j;
			break;
		}
	}

//	SCADEC ファイル以外（のはず）
	if (m_b_pnt == -1){
		for (int j = 1; j <= 3; j++){
			if ( IN_Alignment == b_point.GetAt(j)){
				m_b_pnt = j;
				break;
			}
		}
		return FALSE;

	}

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.07.13

	１．機能概要
		文字書き出し方向の設定
	２．インターフェイス
		BOOL SXFMapF_TEXTSTRINGC::SetBasePoint(
			CString& IN_Path )		//	TEXT_LITERALのPATHパラメタ 


	引数  ：	型			引数名				内容
				CString& 	IN_Path				TEXT_LITERALのPATHパラメタ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.13	大村(FQS)
**/
//	<文字書き出し方向の設定>
BOOL SXFMapF_TEXTSTRINGC::SetDirect(
		CString& IN_Path )			//	TEXT_LITERALのPATHパラメタ 
{
//初期化
//文字書き出し方向判定用データ
/* TYPE text_path = ENUMERATION OF
    (left,
     right,
     up,
     down);
  END_TYPE; -- text_path*/

	CStringArray direction;
	CString a4(" ");
	CString a5(DEF_D_RIGHT);
	CString a6(DEF_D_DOWN);
	direction.Add((LPCTSTR)a4);
	direction.Add((LPCTSTR)a5);
	direction.Add((LPCTSTR)a6);

	CStringArray Extdirection;
	CString a17(DEF_D_LEFT);
	CString a18(DEF_D_UP);
	Extdirection.Add((LPCTSTR)a4);
	Extdirection.Add((LPCTSTR)a17);
	Extdirection.Add((LPCTSTR)a18);

//文字書き出し方向の判定
	m_direct = -1;
	for(int i=1;i<=2;i++){
		if( IN_Path==direction.GetAt(i)){
			m_direct=i;
			break;
		}
	}

//SCADEC以外のデータ（のはず）
	for(i=1;i<=2;i++){
		if( IN_Path==Extdirection.GetAt(i)){
			m_direct=i;
			break;
		}

		return FALSE;

	}
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TEXTSTRINGC.cpp						作成日：2001.07.13

	１．機能概要
		文字配置位置の算出と設定

	２．インターフェイス
		BOOL SXFMapF_TEXTSTRINGC::SetXYPoint(
			double IN_x,		//	文字書き出し位置X
			double IN_y,		//	文字書き出し位置Y 
			double IN_Ascent,
			double IN_Decent,


	引数 ：	型			引数名				内容
			double		IN_x				文字書き出し位置X
			double		IN_y				文字書き出し位置Y
			double		IN_Ascent
			double		IN_Decent

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.07.13	大村(FQS)
**/
BOOL  SXFMapF_TEXTSTRINGC::SetXYPoint(
		double IN_x,		//	文字書き出し位置X
		double IN_y,		//	文字書き出し位置Y 
		double IN_Ascent,
		double IN_Decent
		)

{

// データのチェック	
	if ( m_b_pnt == -1 ) return FALSE;

	double ascent1 = IN_Ascent;
	double decent1 = IN_Decent;
	double centre1 = ascent1 - (ascent1 + decent1) / 2;
	double ascent2 = m_height * ascent1 / (ascent1 + decent1);
	double decent2 = m_height * centre1 / (ascent1 + decent1);
	double centre2 = m_height * (ascent1 - (ascent1 + decent1) / 2)
										/ (ascent1 + decent1);

	double rotate_angle = m_angle * acos(-1.) /180.0;//文字列回転角
	
	if (m_b_pnt <= 3){
		m_text_x = IN_x + decent2 * sin(rotate_angle);
		m_text_y = IN_y - decent2 * cos(rotate_angle);
	}
	else if ((m_b_pnt >= 4) && (m_b_pnt <= 6)){
		m_text_x = IN_x - centre2 * sin(rotate_angle);
		m_text_y = IN_y + centre2 * cos(rotate_angle);
	}
	else{
		m_text_x = IN_x - ascent2 * sin(rotate_angle);
		m_text_y = IN_y + ascent2 * cos(rotate_angle);
	}

	return TRUE;

}
