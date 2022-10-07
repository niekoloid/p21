/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						作成日：2000.04.17

	１．クラス概要
		引出し線フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_LABELC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_LABELC::SXFMapF_LABELC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_LABELC::SXFMapF_LABELC()
{
	m_vertex_number = 0;
	m_arr_code = 0;
	m_arr_r = 0.0;

	m_flg = 0;
	m_font = 0;
	m_text_x = 0.0;
	m_text_y = 0.0;
	m_height = 0.0;
	m_width = 0.0;
	m_spc = 0.0;
	m_angle = 0.0;
	m_slant = 0.0;
	m_b_pnt = 0;
	m_direct = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_LABELC::~SXFMapF_LABELC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_LABELC::~SXFMapF_LABELC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LABELC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_LABELC::GetStructData( Label_Struct* INOUT_Struct)

	引数  ：	型				引数名				内容
				Label_Struct 	INOUT_Struct   		構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_LABELC::GetStructData( Label_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->vertex_number = m_vertex_number;

	INOUT_Struct->vertex_x.Copy( m_vertex_x );
	INOUT_Struct->vertex_y.Copy( m_vertex_y );

	INOUT_Struct->arr_code =  m_arr_code;
	INOUT_Struct->arr_r    =  m_arr_r;

	INOUT_Struct->flg  = m_flg;
	INOUT_Struct->font = m_font;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->str, m_str );

	// 文字要素と同じく257バイト以上の文字列は256に切り詰める
	size_t ilen = strlen(m_str);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str );
	}
	else {
		/* メッセージを出力 */
		// ここも m_RootID = 0,m_TypeName == "" だけど文字要素と同じ処理にしておく
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* 先頭から256バイト切り取る */
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str.Left(256) );
	}
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

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
	SXFMapF_LABELC.cpp						作成日：2000.04.17

	１．機能概要
		引出線の座標を矢印に近い方を始点としてセット

	２．インターフェイス
		void	SXFMapF_LABELC::SetVertex()

	引数 ：	型			引数名				内容
			double		IN_arr_x		矢印のX座標
			double		IN_arr_y		矢印のY座標
			int			IN_number		矢印数
			CArray		IN_vertex_x		折れ線のX座標
			CArray		IN_vertex_y		折れ線のY座標

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_LABELC::SetVertex(
	double IN_arr_x, double IN_arr_y,
	int		IN_number,
	CArray<double,double>& IN_vertex_x,
	CArray<double,double>& IN_vertex_y)
{

	if (IN_number>IN_vertex_x.GetSize() || IN_number>IN_vertex_y.GetSize() )
		return FALSE;

	double L1, L2;

//	矢印と折れ線の始点との距離算出
	L1 = fabs(sqrt(pow(IN_arr_x - IN_vertex_x[0], 2)
					+pow(IN_arr_y - IN_vertex_y[0], 2)));
//	矢印と折れ線の終点との距離算出
	L2 = fabs(sqrt	(pow(IN_arr_x - IN_vertex_x[IN_number-1], 2)
						+pow(IN_arr_y - IN_vertex_y[IN_number-1], 2)));

//	判定しセットする。
	//始点が矢印と近い場合
	if (L1<L2){
		m_vertex_x.Copy( IN_vertex_x );
		m_vertex_y.Copy( IN_vertex_y );
	}
	//終点が矢印に近い場合＝＞入れ替える
	else{
		for (int i=0;i<IN_number;i++){
			m_vertex_x[i]=IN_vertex_x[IN_number-1-i];
			m_vertex_y[i]=IN_vertex_y[IN_number-1-i];
		}
	}
	return TRUE;
}
