/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_LINEC.cpp						作成日：2000.04.17

	１．クラス概要
		線分フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_LINEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_LINEC::SXFMapF_LINEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_LINEC::SXFMapF_LINEC()
{
//	<初期化>

	m_Type = line_feature ;
	m_TypeName = "line_feature";

	m_start_x=0.;		//始点Ｘ座標
	m_start_y=0.;		//始点Ｙ座標
	m_end_x=0.;			//終点Ｘ座標
	m_end_y=0.;			//終点Ｙ座標

//------------------------------------------------
//	PROJECTION LINE 固有
//------------------------------------------------
	m_flag=0;			//端点１２フラグ（0:初期値,1:端点１側, 2:端点２側)
	m_org_x=0.;			//基点Ｘ座標
	m_org_y=0.;			//基点Ｙ座標

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_LINEC::~SXFMapF_LINEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_LINEC::~SXFMapF_LINEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						作成日：2000.05.13

	１．機能概要
		補助線のフラグ設定
	２．インターフェイス
		BOOL SXFMapF_LINEC::Set12flg(
			CString& IN_name )		//	BODY の NAMEパラメタ 


	引数  ：	型			引数名				内容
				CString& 	IN_name

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.05.13	大村(FQS)
**/

//	<補助線の端点１，２どちらか？を表わすフラグ設定>
BOOL SXFMapF_LINEC::Set12flg(CString& IN_name)
{

	CStringArray pojflg;
	CString a1(" ");
	CString a2("$$SXF_prj_1");
	CString a3("$$SXF_prj_2");
	pojflg.Add((LPCTSTR)a1);
	pojflg.Add((LPCTSTR)a2);
	pojflg.Add((LPCTSTR)a3);

//端点１２フラグ（0:初期値,1:端点１側, 2:端点２側)
	m_flag = 0;
	for(int i=1;i<=2;i++){
		if( IN_name==pojflg.GetAt(i)){
			m_flag=i;
			break;
		}
	}
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体取得

	２．インターフェイス
    BOOL GetStructData( Line_Struct* INOUT_Struct );

	引数  ：	型				引数名				内容
				Line_Struct* 	INOUT_Struct

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_LINEC::GetStructData( Line_Struct* INOUT_Struct )

{

//	<1. エンティティパラメタの設定>
	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->start_x	=	m_start_x;		//始点Ｘ座標
	INOUT_Struct->start_y	=	m_start_y;		//始点Ｙ座標
	INOUT_Struct->end_x		=	m_end_x;		//終点Ｘ座標
	INOUT_Struct->end_y		=	m_end_y;		//終点Ｙ座標

	return TRUE;
}
