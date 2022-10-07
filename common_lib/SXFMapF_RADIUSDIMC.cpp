/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						作成日：2000.04.17

	１．クラス概要
		半径寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_RADIUSDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_RADIUSDIMC::SXFMapF_RADIUSDIMC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_RADIUSDIMC::SXFMapF_RADIUSDIMC()
{
	m_sun_x1 = 0.0;
	m_sun_y1 = 0.0;
	m_sun_x2 = 0.0;
	m_sun_y2 = 0.0;
//
	m_arr_code1 = 0;
	m_arr_code2 = 0;
	m_arr_x = 0.0;
	m_arr_y = 0.0;
	m_arr_r = 0.0;
//
	m_flg = 0;
	m_font = 0;
	//CString m_str;
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
	SXFMapF_RADIUSDIMC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_RADIUSDIMC::~SXFMapF_RADIUSDIMC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_RADIUSDIMC::~SXFMapF_RADIUSDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_RADIUSDIMC::GetStructData(RadiusDim_Struct* INOUT_Struct)

	引数  ：	型					引数名			内容
				RadiusDim_Struct 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_RADIUSDIMC::GetStructData( RadiusDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->sun_x1 = m_sun_x1;
	INOUT_Struct->sun_y1 = m_sun_y1;
	INOUT_Struct->sun_x2 = m_sun_x2;
	INOUT_Struct->sun_y2 = m_sun_y2;
//
	INOUT_Struct->arr_code1 = m_arr_code1;
	INOUT_Struct->arr_code2 = m_arr_code2;
	INOUT_Struct->arr_x     = m_arr_x;
	INOUT_Struct->arr_y     = m_arr_y;
	INOUT_Struct->arr_r     = m_arr_r;
//
	INOUT_Struct->flg  = m_flg;
	INOUT_Struct->font = m_font;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->str, m_str);

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

	INOUT_Struct->text_x = m_text_x;
	INOUT_Struct->text_y = m_text_y;
	INOUT_Struct->height = m_height;
	INOUT_Struct->width  = m_width;
	INOUT_Struct->spc    = m_spc;
	INOUT_Struct->angle  = m_angle;
	INOUT_Struct->slant  = m_slant;
	INOUT_Struct->b_pnt  = m_b_pnt;
	INOUT_Struct->direct = m_direct;

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_RADIUSDIMC.cpp						作成日：2000.04.17

	１．機能概要
		矢印の向きフラグ設定

	２．インターフェイス
		void	SXFMapF_ANGULARDIMC::SetArrFlag(
				int IN_term1,	//矢印の有り無しフラグ
				double IN_sun_x1,	//寸法線の始点
				double IN_sun_y1,	//寸法線の始点
				double IN_sun_x2,	//寸法線の終点
				double IN_sun_y2,	//寸法線の終点
				double IN_tmvec_x,	//矢印１のベクトルX
				double IN_tmvec_y	//矢印１のベクトルY)

	引数 ：	型			引数名				内容
			int 		IN_term1		//矢印の有り無しフラグ
			double		 IN_sun_x1		//寸法線の始点
			double		 IN_sun_y1		//寸法線の始点
			double		 IN_sun_x2		//寸法線の終点
			double		 IN_sun_y2		//寸法線の終点
			double		 IN_tmvec_x		//矢印１のベクトルX
			double		 IN_tmvec_y		//矢印１のベクトルY	

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_RADIUSDIMC::SetArrFlag(  
				int IN_term1,	//矢印の有り無しフラグ
				double IN_sun_x1,	//寸法線の始点
				double IN_sun_y1,	//寸法線の始点
				double IN_sun_x2,	//寸法線の終点
				double IN_sun_y2,	//寸法線の終点
				double IN_tmvec_x,	//矢印１のベクトルX
				double IN_tmvec_y	//矢印１のベクトルY
			)
{
	double eps;
	double L1;
	double Dim_x,Dim_y;
	double tmvec_x,tmvec_y;
	double tm_L;

	eps = 0.000001;
	m_arr_code2 = 0;

	if (IN_term1 != 0){
		//矢印の方向ベクトルから内外コードを計算する
		//寸法線の方向ベクトルを計算する
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = ( IN_sun_x2 - IN_sun_x1 )/L1;
		Dim_y = ( IN_sun_y2 - IN_sun_y1 )/L1;
		//矢印ベクトルの単位ベクトルを求める。
		tm_L = fabs(sqrt(pow(IN_tmvec_x, 2)+pow(IN_tmvec_y, 2)));
		tmvec_x = IN_tmvec_x / tm_L;
		tmvec_y = IN_tmvec_y / tm_L;
		//矢印の内外コードを設定する
		//矢印の方向ベクトルが寸法線の方向ベクトルと同方向のとき、２（内向き）に設定する
		if((fabs(tmvec_x - Dim_x) < eps) && (fabs(tmvec_y - Dim_y) < eps)){
			m_arr_code2 = 2;
			m_arr_code2 = 1;
		}
		//矢印１の方向ベクトルが寸法線の方向ベクトルと反対方向のとき、１（外向き）に設定する
		else if((fabs(tmvec_x + Dim_x) < eps) && (fabs(tmvec_y + Dim_y) < eps)){
			m_arr_code2 = 1;
			m_arr_code2 = 2;
		}
	}
	return TRUE;
}

